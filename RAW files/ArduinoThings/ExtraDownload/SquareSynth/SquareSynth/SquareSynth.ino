//SquareSynth
//  by Robbi-985 aka SomethingUnreal
//    for Arduino Mega
//
//A retro-style MIDI synth. Includes support for pitch-bends, modulation, volume/expression (3 volume levels in total), mono/poly channel modes, 
//multiple percussion channels, some GM/GS/XG sysex messages, and running status.
//
//Requires Fast Division library - Info and download: https://forum.arduino.cc/index.php?topic=172635.msg1283483#msg1283483
//
//                                *****   HARDWARE INFO:   *****
//
// -> Listens on the USB serial port for incoming MIDI data at 115200 baud - to use a serial port as a MIDI port on Windows, I use
//    http://www.midiox.com/myoke.htm (virtual MIDI cable driver) and https://projectgus.github.io/hairless-midiserial (echoes MIDI to serial).
// -> If you want to build a real MIDI input circuit, see https://learn.sparkfun.com/tutorials/midi-tutorial/hardware--electronic-implementation
//    and change the #define of UseRealMIDIPort to True (affects the baud rate).
// -> Connect an 8-bit DAC (digital-to-analogue converter) to the 8 digital pins 30 (MSB) to 37 (LSB). Don't forget a 9th ground wire, too.
//    Connect headphones or an audio amplifier + speaker to the DAC's output.
//    You can build a super-simple "R-2R" DAC yourself using only resistors (it's what I use!) - see https://en.wikipedia.org/wiki/Resistor_ladder for info.
// -> See https://www.arduino.cc/en/Hacking/PinMapping2560 for information on which pins correspond to which ports on the Arduino Mega.

#include <avr/pgmspace.h>
#include <FastDivision.h>

//Configuration:
  #define PORTAudio       PORTC                                                                           //Determines the group of 8 pins to output to (Arduino board-specific).
  #define  DDRAudio       DDRC                                                                            //Change last letter to match the PORT you're using. Used to set pins to output mode.
  #define NumSoundChans   15                                                                              //Maximum number of notes to play at once. High value = high memory and max CPU usage.
  #define pinToneDebug    30                                                                              //For debugging - square-wave tones can be output to here with ToneDelay().
  #define pinLED          13                                                                              //LED is currently only used to indicate "reset" MIDI messages being processed.
  #define UseRealMIDIPort False

//Audio:
  #define IndSoundChanMax (NumSoundChans - 1)
  //#define  EnvStart     (1 << 4)                                                                        //(Maximum) volume envelope level for notes to start at.
  //#define  EnvSus       (1 << 2)                                                                        //Volume envelope level for held notes in the "sustain" envelope state.
  #define EnvStartShift   3                                                                               //Right-shift start envelope of all notes by this to avoid clipping.
  #define EnvDecaySus     2                                                                               //Decay (right-shift) envelope this many times until sustaining.
  
  struct SoundChanStruct {
    unsigned long usOscInc, usOscNext;
    unsigned long usOscIncBase;                                                                           //Like usOscInc, but for interval of frequency of note BEFORE pitch-bends.
    byte          usDecayIncO1024;
    unsigned long usDecayNext;
    byte          DecayPitchO8;                                                                           //When decaying envelope, increase usOscInc by this (decays pitch).
    boolean       IsNoise;                                                                                //True = plays samples in WaveNoise[], false = plays square wave.
    byte          IndWaveNoise;                                                                           //Next index of of the noise wave table to play, when IsNoise is true.
    byte          WaveCycleState;                                                                         //Noise: Table value; Square: True = first half (on), false = second half (off).
    byte          EnvCurBase, EnvCurAfter; //, EnvTarget;                                                 //EnvCurBase is right-shifted regularly. EnvCurAfter is with exp/vol applied.
    byte          EnvDecayCur, EnvDecayTarget;                                                            //First increments when EnvCurBase is R-shifted, happens until EnvDecayTarget.
    boolean       IsHeld;
    byte          PlayingMIDIChan;
    byte          PlayingMIDINote;
  };
  SoundChanStruct SoundChan[NumSoundChans];
  byte IndSoundChanPrev = IndSoundChanMax;                                                                //Index of sound chan used by last note-on (search from this+1 to this, wrapping).
  
  //Waveform lookup tables:
  #define WaveNoiseSpeed 128                                                                              //Used as reference to keep constant speed through table (previously, used LenWaveNoise).
  #define LenWaveNoise   256                                                                              //Real length of table below.
  const PROGMEM byte WaveNoise[LenWaveNoise] = {255,   0,   0, 255,   0, 255, 255, 255,   0,   0, 255, 255, 255,   0,   0, 255, 255, 255,   0, 255,   0,   0, 255,   0, 
                                                255, 255,   0, 255,   0, 255, 255,   0,   0,   0, 255,   0, 255,   0,   0, 255,   0,   0,   0, 255,   0,   0, 255,   0, 
                                                255,   0,   0,   0,   0, 255, 255, 255, 255,   0,   0,   0, 255,   0,   0,   0, 255,   0, 255,   0, 255,   0, 255,   0, 
                                                  0,   0,   0,   0, 255,   0, 255, 255,   0,   0,   0,   0, 255,   0,   0,   0, 255, 255,   0, 255,   0, 255,   0, 255, 
                                                255,   0,   0,   0, 255, 255,   0, 255,   0, 255, 255, 255, 255, 255,   0, 255,   0, 255,   0,   0, 255, 255, 255,   0, 
                                                255,   0,   0, 255,   0,   0, 255, 255, 255, 255, 255,   0,   0,   0, 255, 255,   0,   0, 255,   0, 255,   0, 255, 255, 
                                                  0, 255, 255,   0,   0, 255, 255, 255,   0,   0, 255, 255,   0,   0, 255, 255,   0, 255,   0,   0, 255, 255,   0, 255, 
                                                  0,   0, 255, 255, 255,   0,   0,   0, 255,   0, 255, 255, 255, 255,   0,   0,   0,   0,   0, 255,   0,   0, 255, 255, 
                                                255,   0,   0,   0,   0,   0, 255,   0, 255,   0, 255,   0, 255,   0, 255,   0,   0,   0, 255, 255, 255,   0,   0, 255, 
                                                  0, 255, 255, 255,   0, 255,   0,   0,   0, 255, 255, 255, 255,   0,   0,   0,   0,   0,   0, 255,   0, 255,   0,   0, 
                                                  0,   0, 255,   0, 255, 255,   0, 255,   0, 255, 255,   0,   0, 255, 255, 255                                         };
  
//MIDI:
  //Protocol (unchangable):
    //Message Status:
      #define mmsNoteOff        0x80
      #define mmsNoteOn         0x90
      #define mmsCC             0xB0
      #define mmsPitchBend      0xE0
      #define mmsSysexStart     0xF0
      #define mmsSysexEnd       0xF7
    //Control Changes:
      #define mmcModulation     1
      #define mccDataEntry      6
      #define mccVolume         7
      #define mccExpression    11
      #define mccNRPNL         98
      #define mccNRPNH         99
      #define mccRPNL         100
      #define mccRPNH         101
      #define mmcAllSoundOff  120
      #define mmcResetAllCCs  121
      #define mmcAllNotesOff  123
      #define mmcMono         126
      #define mmcPoly         127
    //Percussion note names:
      #define PTKick1          35
      #define PTKick2          36
      #define PTSnare1         38
      #define PTSnare2         40
      #define PTSideStick      37
      #define PTClap           39
      #define PTTomHigh        50
      #define PTTomMidHigh     48
      #define PTTomMidLow      47
      #define PTTomLow         45
      #define PTTomFloorHigh   43
      #define PTTomFloorLow    41
      #define PTHihatClosed    42
      #define PTHihatPedal     44
      #define PTHihatOpen      46
      #define PTCymbalCrash1   49
      #define PTCymbalCrash2   57
      #define PTCymbalSplash   55
      #define PTCymbalRide1    51
      #define PTCymbalRide2    59
      #define PTBellRide1      53
      #define PTTriangleClosed 80
      #define PTTriangleOpen   81
      #define PTShaker         82
      #define PTCabasa         69
      #define PTMaracas        70
      #define PTCastanet       85
    
    #define NumMIDIChans       16
    #define NumMIDINotes      127
    #define PNUnused          127
    
    //Modulation:
      #define usModInc   (1000000 / (5 * 2))                                                              //Speed of modulation "positve/negative cycle" clock, shared by all MIDI channels.

    //The below arrays of note frequency intervals (1/Hz) omit the first 1 and last 2 octaves (can't represent lowest's intervals in 16 bits, can't play highests' without aliasing).
      //MIDINoteInt   = Half interval (on/off times for 50% square wave).
      //MIDINoteIntP1 = Interval for pulse wave (20%)'s ON  part.
      //MIDINoteIntP0 = Interval for pulse wave (20%)'s OFF part.
      const PROGMEM unsigned int MIDINoteInt[96]    = { 30578, 28862, 27242, 25713, 24270, 22908, 21622, 20408, 19263, 18182, 17161, 16198, 
                                                        15289, 14431, 13621, 12856, 12135, 11454, 10811, 10204,  9631,  9091,  8581,  8099, 
                                                         7645,  7215,  6810,  6428,  6067,  5727,  5405,  5102,  4816,  4545,  4290,  4050, 
                                                         3822,  3608,  3405,  3214,  3034,  2863,  2703,  2551,  2408,  2273,  2145,  2025, 
                                                         1911,  1804,  1703,  1607,  1517,  1432,  1351,  1276,  1204,  1136,  1073,  1012, 
                                                          956,   902,   851,   804,   758,   716,   676,   638,   602,   568,   536,   506, 
                                                          478,   451,   426,   402,   379,   358,   338,   319,   301,   284,   268,   253, 
                                                          239,   225,   213,   201,   190,   179,   169,   159,   150,   142,   134,   127 };

    //Lookup table for pitch-bends for one octave (10 values per semitone): *****   256 / (2 ^ (-4 + "Bends within one octave")):   *****
      #define NumBendPowers      (10 * 12)
      const PROGMEM unsigned int BendPowers256[NumBendPowers] = { 4096, 4072, 4049, 4026, 4002, 3979, 3956, 3934, 3911, 3889, 
                                                                  3866, 3844, 3822, 3800, 3778, 3756, 3734, 3713, 3692, 3670, 
                                                                  3649, 3628, 3607, 3586, 3566, 3545, 3525, 3505, 3484, 3464, 
                                                                  3444, 3424, 3405, 3385, 3366, 3346, 3327, 3308, 3289, 3270, 
                                                                  3251, 3232, 3214, 3195, 3177, 3158, 3140, 3122, 3104, 3086, 
                                                                  3069, 3051, 3033, 3016, 2998, 2981, 2964, 2947, 2930, 2913, 
                                                                  2896, 2880, 2863, 2847, 2830, 2814, 2798, 2782, 2766, 2750, 
                                                                  2734, 2718, 2702, 2687, 2671, 2656, 2641, 2625, 2610, 2595, 
                                                                  2580, 2565, 2551, 2536, 2521, 2507, 2492, 2478, 2464, 2450, 
                                                                  2435, 2421, 2408, 2394, 2380, 2366, 2353, 2339, 2326, 2312, 
                                                                  2299, 2286, 2272, 2259, 2246, 2233, 2220, 2208, 2195, 2182, 
                                                                  2170, 2157, 2145, 2133, 2120, 2108, 2096, 2084, 2072, 2060 };
  
  #define MIDINoteMin          12
  #define MIDINoteMax         107
  #define UnusedMisc          255
  #define MaxNumMIDIMsgData     2
  #define MaxSysexLen           9
  
  //MIDI channel flags (boolean value with this name is stored in the bit in the "Flags" byte which represents this numerical value):
    #define mcfPNIsRPN (1 << 0)                                                                           //True if RPN, false if NRPN.
    #define mcfIsPerc  (1 << 1)                                                                           //True if StartPerc() should handle MIDI chan's note-ons, false if tone.
    #define mcfSustain (1 << 2)                                                                           //True if sustain pedal is currently on.
    #define mcfMono    (1 << 3)                                                                           //True if MIDI channel is in monophonic mode, false if in polyphonic mode.

  struct MIDIChanStruct {
    byte         Flags;                                                                                   //See the #defines for mcf* above.
    byte         PNHigh, PNLow;                                                                           //MSB/LSB of RPN (if PNIsRPN) or NRPN.
    float        BendSens;                                                                                //In 10ths of semitones, then divided by 8192 (see SetBendSens() for explanation).
    unsigned int BendMult256;                                                                             //Multiply sound chan's usOscIncBase by (this/256) to apply pitch-bend.
    byte         ExpShift;                                                                                //Right-shift sound chan's EnvCurBase by this to apply expression.
    byte         VolShift;                                                                                //Right-shift sound chan's VolCur by this to apply volume.
    byte         VolAndExpShift;
    char         ModVal;                                                                                  //Added to "pitch bend multiplier *256"; char to allow negative vals (-8 to 8).
  };
  MIDIChanStruct MIDIChan[NumMIDIChans];
  byte MIDIMsgStatus  = 0;
  byte MIDIMsgData[max(MaxNumMIDIMsgData, MaxSysexLen)];
  byte IndMIDIMsgData = 0;                                                                                //0 = first data byte after status byte, etc...

////MAYBE DO HERE: Customise timer2 (allows us to use our own, faster micros()).



void setup() {
  DDRAudio  = B11111111;                                                                                  //Set all pins on port to output mode.
  //PORTAudio = WaveCentre;                                                                               //Output at centre position.
  PORTAudio = 0;
  pinMode(pinLED, OUTPUT);
  Serial.begin(UseRealMIDIPort ? 31250 : 115200);                                                        //Receive "real MIDI", or MIDI over serial port from "Hairless MIDI<->Serial Bridge".
  SystemReset();                                                                                          //Initialises MIDI and sound channels.
}

void SystemReset() {
  digitalWrite(pinLED, HIGH);                                                                             //Indicate reset by pulsing LED.
    InitMIDIChans();
    InitSoundChans();
    delay(4); //20
  digitalWrite(pinLED, LOW);
  while (Serial.available()) {Serial.read();}                                                           //Discard any buffered unprocessed MIDI data.
}

void ProcessAnyByte() {
  if (Serial.available()) {
    byte NewVal = Serial.read();
    if (NewVal >= 0x80) {                                                                                 //If this byte is a new status byte (not a data byte)...
      MIDIMsgStatus = NewVal;                                                                             //Make a note of the new status byte for use when later bytes are received.
      if (MIDIMsgStatus == mmsSysexEnd) {DealWithSysex();}                                                //Deal with IndMIDIMsgData number of bytes of Sysex data stored in MIDIMgData[].
      IndMIDIMsgData = 0;                                                                                 //We have received 0 data bytes for this message so far.
    } else {                                                                                              //Else, if this byte is a data byte...
      if (MIDIMsgStatus == mmsSysexStart) {                                                               //If this is a data byte of a SysEx message...
        if (IndMIDIMsgData < MaxSysexLen) {                                                               //If we've not yet received maximum possible number of SysEx bytes...
          MIDIMsgData[IndMIDIMsgData] = NewVal;                                                           //Store this new value as a Sysex data byte for use either below or later.
          IndMIDIMsgData ++;                                                                              //Move on to storing next data byte next time.
        }                                                                                                 //Ended if we've not received maximum number of SysEx bytes.
      } else {                                                                                            //Else, if this is a data byte of a 2-byte message...
        if (IndMIDIMsgData < MaxNumMIDIMsgData) {                                                         //If we have not received too many data bytes to be understood...
          MIDIMsgData[IndMIDIMsgData] = NewVal;                                                           //Store this new value as a message data byte for use either below or later.
          switch (MIDIMsgStatus & 0xF0) {                                                                 //Pay attention to left nibble of status byte.
            case mmsNoteOff:                                                                              //[STATUS: Note-off]
              if (IndMIDIMsgData == 0) {NoteOff(MIDIMsgStatus & 0x0F, MIDIMsgData[0]);}                   //As long as we have the first data byte, we can process the note-off.
              break;
            case mmsNoteOn:                                                                               //[STATUS: Note-on]
              if (IndMIDIMsgData == 1) {                                                                  //If message is complete...
                if (MIDIMsgData[1] == 0) {                                                                //If velocity is 0...
                  NoteOff(MIDIMsgStatus & 0x0F, MIDIMsgData[0]);                                          //Treat note-on as note-off.
                } else {                                                                                  //Else, if velocity is non-zero...
                  NoteOn( MIDIMsgStatus & 0x0F, MIDIMsgData[0], MIDIMsgData[1]);                          //Start playing this note.
                }
              }
              break;
            case mmsCC:                                                                                   //[STATUS: Control Change]
              if (IndMIDIMsgData == 1) {DealWithCC(MIDIMsgStatus & 0x0F, MIDIMsgData[0], MIDIMsgData[1]);}  //If we have CC number and value, process the control change.
              break;
            case mmsPitchBend:                                                                            //[STATUS: Pitch Bend]
              if (IndMIDIMsgData == 1) {PitchBend(MIDIMsgStatus & 0x0F, \
                                                  ((MIDIMsgData[1] << 7) + MIDIMsgData[0]) - 8192);}      //Merge high and low bytes together and process bend.
              break;
            case mmsSysexStart:                                                                           //[STATUS: System] (e.g. Sysex, Clock, Start, etc.)
              //Do nothing, just let data bytes continue to be stored (which has already happened above).
              break;
          }                                                                                               //Ended switch on left nibble of MIDIMsgStatus.
        }                                                                                                 //Ended if we can store (or process) another 2-byte message data byte.
        
        if (IndMIDIMsgData == MaxNumMIDIMsgData) {                                                        //If we've received both status bytes (will already have been processed)...
          IndMIDIMsgData = 0;                                                                             //Next time, store first data byte, even without status (supports running status).
        } else {                                                                                          //Else, if we've not yet stored all data bytes for a message...
          IndMIDIMsgData ++;                                                                              //Move on to storing next data byte next time.
        }                                                                                                 //Ended if both data bytes have been received or not.
        
      }                                                                                                   //Ended if this is a sysex data byte or a 2-byte message data byte.
    }                                                                                                     //Ended if this is a status byte or a data byte.
  }                                                                                                       //Ended if any new byte is available on MIDI input.
}

void DealWithSysex() {                                                                                    //Deal with IndMIDIMsgData number of bytes of Sysex data stored in MIDIMgData[].
  switch (MIDIMsgData[0]) {                                                                               //Check manufacturer byte.
    case 0x7E:                                                                                            //[MANUFACTURER: Universal Non-realtime]
      if (MIDIMsgData[2] == 0x09) {SystemReset();}                                                        //[GM: Resets (GM mode: On 1, On 2, Off)]
      break;
    case 0x41:                                                                                            //[MANUFACTURER: Roland (GS)]
      if (MIDIMsgData[2] == 0x42) {                                                                       //[DEVICE: Sound Canvas (parameter)]
        if (MIDIMsgData[3] == 0x12) {
          switch (MIDIMsgData[4]) {
            case 0x40:                                                                                    //Setting a MIDI channel's parameter.
              #define _IndMIDIChan   DecodeGSMIDIChan(MIDIMsgData[5] & 0x0F)                              //Right-hand nibble gives MIDI channel (with channel 00/09 silliness - fix that).
              #define _MIDIChan      MIDIChan[_IndMIDIChan]
              #define _Data2         MIDIMsgData[7]                                                       //Parameter value, similar to MsgData[2] (controller value) in CC messages.
              switch (MIDIMsgData[5] >> 4) {                                                              //Check left-hand nibble.
                case 0x0:                                                                                 //0?: Potentially a GS reset!
                  DWSSPotentialGSReset();                                                                 //Check later bytes and perform a reset if they're correct.
                  break;
                case 0x1:                                                                                 //1?: Ended potential GS reset.
                  switch (MIDIMsgData[6]) {                                                               //Determines which one parameter to change.
                    case 0x15:                                                                            //Part to rhythm allocation: Norm/Drum1/Drum2.
                      switch (_Data2) {                                                                   //Check percussion status.
                        case 0:                                                                           //[GS: Normal (not percussion)]
                          SetFlag(&(_MIDIChan.Flags), mcfIsPerc, false);
                          break;
                        case 1:                                                                           //[GS: Drum set 1]
                        case 2:                                                                           //[GS: Drum set 2]
                          SetFlag(&(_MIDIChan.Flags), mcfIsPerc, true);
                          break;
                      }
                      break;
                    case 0x19:                                                                            //[GS: Set volume]
                      SetAndUpdateExpVol(&(_MIDIChan.VolShift), _IndMIDIChan, _Data2);
                      break;
                    case 0x13:                                                                            //[GS: Mono/Poly Mode (0 = Mono)]
                      SetMonoMode(_IndMIDIChan, (_Data2 == 0));
                      break;
                  }
                  break;
              }
              #undef _IndMIDIChan
              #undef _MIDIChan
              #undef _Data2
              break;
            case 0x00:
              DWSSPotentialGSReset();                                                                     //Check later bytes and perform a reset if they're correct.
          }                                                                                               //Ended checking MIDIMsgData[4].
        }                                                                                                 //Ended checking MIDIMsgData[3]
      }                                                                                                   //Ended checking MIDIMsgData[2] (DEVICE).
      break;
    case 0x43:                                                                                            //[MANUFACTURER: Yamaha (XG)]
      switch (MIDIMsgData[3]) {
        case 0x00:
          if (MIDIMsgData[4] == 0x00) {
            if (MIDIMsgData[5] == 0x7E) {
              if (MIDIMsgData[6] == 0x00) {                                                               //[XG: Reset]
                SystemReset();
              }
            }
          }
          break;
        case 0x08:                                                                                        //Change a parameter of a channel...
          #define _IndMIDIChan MIDIMsgData[4]
          #define _MIDIChan    MIDIChan[_IndMIDIChan]
          #define _Data2       MIDIMsgData[6]                                                             //Parameter value, similar to MsgData[2] (controller value) in CC messages.
          if (_IndMIDIChan > 0x0F) {return;}                                                              //Byte 4 gives MIDI channel; we don't support >16.
          switch (MIDIMsgData[5]) {                                                                       //Determines which parameter to set.
            case 0x07:                                                                                    //Set part mode.
              switch (_Data2) {
                case 0:                                                                                   //[XG: Normal (not percussion)]
                  SetFlag(&(_MIDIChan.Flags), mcfIsPerc, false);
                  break;
                case 1:                                                                                   //[XG: Drum set 1]
                case 2:                                                                                   //[XG: Drum set 2]
                case 3:                                                                                   //[XG: Drum set 3]
                  SetFlag(&(_MIDIChan.Flags), mcfIsPerc, true);
                  break;
              }
              break;
            case 0x0B:                                                                                    //[XG: Set volume]
              SetAndUpdateExpVol(&(_MIDIChan.VolShift), _IndMIDIChan, _Data2);
              break;
            case 0x05:                                                                                    //[XG: Mono/Poly Mode (0 = Mono)]
              SetMonoMode(_IndMIDIChan, (_Data2 == 0));
              break;
          }
          #undef _IndMIDIChan
          #undef _MIDIChan
          #undef _Data2
          break;
      }
      break;
  } 
}

inline void DWSSPotentialGSReset() {
  if ((MIDIMsgData[5] == 0) && (MIDIMsgData[6] == 0x7F)) {SystemReset();}                                 //[GS: Reset]
}

inline byte DecodeGSMIDIChan(byte GSMC) {
  return (GSMC == 0) ? 9 : ((GSMC <= 9) ? (GSMC - 1) : GSMC);                                             //[1-9] -> [0-8], [0] -> [9], [A-F] -> [A-F].
}

inline void SetBendSens(MIDIChanStruct* RefMIDIChan, byte NumSemitones) {
  RefMIDIChan->BendSens = float(NumSemitones) * ((1.0 / 8192.0) * 10.0);                                  //Effectively divide future bend wheel values by 8192 in advance, and multiply
                                                                                                          //by 10 (for lookup table in 10ths of semitone) here once.
}

inline void PitchBend(byte IndMIDIChan, int BendVal) {                                                    //NOTE: BendVal is signed (0 = centre).
  unsigned int* RefBendMult256 = &(MIDIChan[IndMIDIChan].BendMult256);
  //Below, BendSens(*10/8192) * BendVal is the number of st 10ths to bend by now. BendMult WAS set to 256/powf(2, here). To avoid call to powf(), we now use a 1-octave-long lookup table
  //with 120 entries (10 per semitone) to get "256 / powf(2, this "note" within an octave)". Afterwards, we right-shift the calculated bend multiplier to get it into the correct octave.
  //Note that the lookup table itself is made 4 octaves down (i.e. 0->1 is actually 4->3), for extra accuracy, so we always shift right by 4 more than OctaveNum suggests that we should.
  
  BendVal = MIDIChan[IndMIDIChan].BendSens * float(BendVal);                                              //Convert to number of 10ths of semitone to bend up by (negative = down).
  //unsigned int OctaveNum;
  byte         IndBend;
  unsigned int NewBendMult256;                                                                            //To save memory, we set as "OctaveNum" on "ON=" lines, and use as it on "=ON" lines.
  if (BendVal >= 0) {                                                                                     //If bend is positive...
    NewBendMult256 = divu60((unsigned int)BendVal) >> 1;                                          //ON=   //Div 120; Number of times we need to repeat the effect of the 1-octave table.
    IndBend        = BendVal - (NewBendMult256 * 120);                                            //=ON   //Position within the octave (in 10ths of a semitone).
    NewBendMult256 = pgm_read_word_near(BendPowers256 + IndBend) >> (4 + NewBendMult256);         //=ON    //Calculate how much to multiply each oscillator interval by (*256).
  } else {                                                                                                //Else, if bend is negative...
    BendVal        = -BendVal;                                                                            //Flip bend value to be positive (we'll interpret it differently later).
    NewBendMult256 = divu60((unsigned int)BendVal) >> 1;                                          //ON=   //Calculate otctave number in the same way as above.
    IndBend        = (120 - 1)  - byte(BendVal - (NewBendMult256 * 120));                         //=ON   //Use inverted index (count back from end instead of forward from beginning).
    if (NewBendMult256 <= 3) {                                                                            //If we will want to shift right by a positive number (or 0)...
      NewBendMult256 = pgm_read_word_near(BendPowers256 + IndBend) >> (3 - NewBendMult256);       //=ON   //IndBend is backwards now and end of table is high; reduce by 1 oct more than above.
    } else {                                                                                              //Else, if we will want to shift right by a positive number...
      NewBendMult256 = pgm_read_word_near(BendPowers256 + IndBend) << (NewBendMult256 - 3);       //=ON   //Shift left instead (by a positive version of that number).
    }
  }
  
  if (NewBendMult256 != *RefBendMult256) {                                                                //If that multiplier has changed (enough to look different in 16-bit range)...
    *RefBendMult256 = NewBendMult256;                                                                     //Copy its value over to the MIDI channel.
    
    //Update all relevant sound channels to take this new bend into account.
      UpdateMIDIChanFreqIfHeld(IndMIDIChan, MIDIChan[IndMIDIChan].ModVal);                                //Update frequency of sound channels playing a HELD note for this MIDI channel.                                                                                               //Ended for each sound channel.
  }                                                                                                       //Ended if the multiplier has changed.
}

void UpdateMIDIChanFreqIfHeld(byte IndMIDIChan, char ModVal) {                                            //Update sound channel frequency ONLY IF NOTES ARE HELD (e.g. for pitch-bends).
  for (byte IndSoundChan = 0; IndSoundChan < NumSoundChans; IndSoundChan ++) {                            //Check each sound channel.
    if (SoundChan[IndSoundChan].PlayingMIDIChan == IndMIDIChan) {                                         //If this sound channel is (or was) playing a note on this MIDI channel...
      if (SoundChan[IndSoundChan].IsHeld) {                                                               //If the note for this sound channel is still being held...
        UpdateSoundChanFreq(IndSoundChan, ModVal);                                                        //Set sound channel's frequency, taking into account the new modulation value.
      }                                                                                                   //Ended if sound channel is making sound.
    }                                                                                                     //Ended if sound channel is/was playing for this MIDI channel.
  }                                                                                                       //Ended for each sound channel.
}

void UpdateMIDIChanFreqAlways(byte IndMIDIChan, char ModVal) {                                            //Update sound channel frequency REGARDLESS OF IF HELD (e.g. for modulation).
  for (byte IndSoundChan = 0; IndSoundChan < NumSoundChans; IndSoundChan ++) {                            //Check each sound channel.
    if (SoundChan[IndSoundChan].PlayingMIDIChan == IndMIDIChan) {                                         //If this sound channel is (or was) playing a note on this MIDI channel...
      if (SoundChan[IndSoundChan].EnvCurBase) {                                                           //If it's making sound right now...
        UpdateSoundChanFreq(IndSoundChan, ModVal);                                                        //Set sound channel's frequency, taking into account the new modulation value.
      }                                                                                                   //Ended if sound channel is making sound.
    }                                                                                                     //Ended if sound channel is/was playing for this MIDI channel.
  }                                                                                                       //Ended for each sound channel.
}

inline void UpdateSoundChanFreq(byte IndSoundChan, char ModVal) {
  SoundChanStruct* RefSoundChan = &SoundChan[IndSoundChan];                                               //Allow us to easily refer to the sound channel we're dealing with now.
  //RefSoundChan->usOscInc = float(RefSoundChan->usOscIncBase) * MIDIChan[RefSoundChan->PlayingMIDIChan].BendMult;
  RefSoundChan->usOscInc = (RefSoundChan->usOscIncBase * (MIDIChan[RefSoundChan->PlayingMIDIChan].BendMult256 + ModVal)) \
                           >> 8;                                                                          //Multiply by "*256" bend multiple, then divide by 256 efficiently.
}

inline void UpdateSoundChanEnvCurAfter(SoundChanStruct* RefSoundChan, byte CurVolAndExpShift) {           //Stores MIDI VolAndExp applied to current base env level as EnvCurAfter.
  RefSoundChan->EnvCurAfter = RefSoundChan->EnvCurBase >> CurVolAndExpShift;
}

void UpdateSoundChansEnvCurAfter(byte IndMIDIChan) {
  byte NewVolAndExpShift = MIDIChan[IndMIDIChan].VolAndExpShift;
  for (byte IndSoundChan = 0; IndSoundChan < NumSoundChans; IndSoundChan ++) {                            //Check all sound channels.
    if (SoundChan[IndSoundChan].PlayingMIDIChan == IndMIDIChan) {                                         //If this sound channel is/was playing a note for this MIDI channel...
      if (SoundChan[IndSoundChan].EnvCurBase) {                                                           //If channel is currently playing...
        UpdateSoundChanEnvCurAfter(&SoundChan[IndSoundChan], NewVolAndExpShift);                          //Recalculate final volume envelope with MIDI vol/exp applied.
      }
    }
  }
}

inline void UpdateMIDIChanVolAndExp(byte IndMIDIChan) {
  MIDIChanStruct* RefMIDIChan = &MIDIChan[IndMIDIChan];                                                   //Allow us to easily refer to the MIDI channel we're dealing with now.
  RefMIDIChan->VolAndExpShift = RefMIDIChan->VolShift + RefMIDIChan->ExpShift;
}

inline byte ExpVolCCToShift(byte ValCC) {
  return (ValCC < 10   ?   8   :   (127 - ValCC) / 64);                                                   //0-9 = (>> 8), 1-63 = (>> 1), 64-127 = (>> 0).
}

inline void SetAndUpdateExpVol(byte* ExpOrVol, byte IndMIDIChan, byte ValCC) {
  byte NewShift = ExpVolCCToShift(ValCC);
  if (NewShift != *ExpOrVol) {
    *ExpOrVol = NewShift;
    UpdateMIDIChanVolAndExp(IndMIDIChan);
    UpdateSoundChansEnvCurAfter(IndMIDIChan);
  }
}

void DealWithCC(byte IndMIDIChan, byte IndCC, byte ValCC) {
  MIDIChanStruct* RefMIDIChan   = &MIDIChan[IndMIDIChan];                                                 //Allow us to easily refer to the MIDI channel we're dealing with now.
  switch (IndCC) {
    case mmcModulation:                                                                                   //[CC: Modulation]
      {                                                                                                   //Block to explicitly limit scope of variables for setting new mod val.
        char* RefModVal = &MIDIChan[IndMIDIChan].ModVal;                                                  //Allow us to easily access the modulation value for this loop's MIDI channel.
        char NewModVal;
        if (*RefModVal >= 0) {                                                                            //If MIDI channel's modulation is currently NOT negative due to cycle state...
          NewModVal = (ValCC >> 4);                                                                       //Scale new moduation from 0~127 down to 0~3.
        } else {                                                                                          //Else, if MIDI channel's modulation is currently in the negative cycle state...
          NewModVal = -(ValCC >> 4);                                                                      //Scale and negate new modulation from 0~127 down to 0~-3.
        }
        if (*RefModVal != NewModVal) {                                                                    //If current mod is different from new mod (after scaling and any negating)...
          *RefModVal = NewModVal;                                                                         //Set to the new modulation value (preserving positive/negative cycle state).
          UpdateMIDIChanFreqAlways(IndMIDIChan, NewModVal);                                               //Update frequency of all sound channels playing for this MIDI channel.
        }
        break;
      }
    case mccVolume:                                                                                       //[CC: Volume]
      SetAndUpdateExpVol(&(RefMIDIChan->VolShift), IndMIDIChan, ValCC);
      break;
    case mccExpression:                                                                                   //[CC: Expression]
      SetAndUpdateExpVol(&(RefMIDIChan->ExpShift), IndMIDIChan, ValCC);
      break;
    case mccRPNL:                                                                                         //[CC: RPN Low]
      RefMIDIChan->PNLow   = ValCC;
      SetFlag(&(RefMIDIChan->Flags), mcfPNIsRPN, true);
      break;
    case mccRPNH:                                                                                         //[CC: RPN High]
      RefMIDIChan->PNHigh  = ValCC;
      SetFlag(&(RefMIDIChan->Flags), mcfPNIsRPN, true);
      break;
    case mccNRPNL:                                                                                        //[CC: NRPN Low]
      RefMIDIChan->PNLow   = ValCC;
      SetFlag(&(RefMIDIChan->Flags), mcfPNIsRPN, false);
      break;
    case mccNRPNH:                                                                                        //[CC: NRPN High]
      RefMIDIChan->PNHigh  = ValCC;
      SetFlag(&(RefMIDIChan->Flags), mcfPNIsRPN, false);
      break;
    case mccDataEntry:                                                                                    //[CC: Data Entry]
      if (GetFlag(RefMIDIChan->Flags, mcfPNIsRPN)) {
        if (RefMIDIChan->PNHigh == 0) {
          if (RefMIDIChan->PNLow == 0) {                                                                  //[DATA ENTRY: Pitch-bend sensitivity]
            SetBendSens(RefMIDIChan, ValCC);
          }
        }
      }
      break;
    case mmcAllNotesOff:                                                                                  //[CC: All Notes Off]
      AllNotesOff(IndMIDIChan);
      break;
    case mmcAllSoundOff:                                                                                  //[CC: All Sound Off]
      AllSoundOff(IndMIDIChan);
      break;
    case mmcResetAllCCs:                                                                                  //[CC: Reset All Controllers]
      ResetMIDIChan(IndMIDIChan);
      break;
    case mmcMono:                                                                                         //[CC: Monophonic Mode]
      SetMonoMode(IndMIDIChan, true);
      break;
    case mmcPoly:                                                                                         //[CC: Polyphonic Mode]
      SetMonoMode(IndMIDIChan, false);
      break;
  }                                                                                                       //Ended switch on IndCC.
}

void SetMonoMode(byte IndMIDIChan, boolean MonoIsOn) {
  AllSoundOff(IndMIDIChan);
  SetFlag(&(MIDIChan[IndMIDIChan].Flags), mcfMono, MonoIsOn);
}

void AllNotesOff(byte IndMIDIChan) {
  unsigned long usCur = micros();
  for (byte IndSoundChan = 0; IndSoundChan < NumSoundChans; IndSoundChan ++) {                            //Check all sound channels.
    if (SoundChan[IndSoundChan].PlayingMIDIChan == IndMIDIChan) {                                         //If this sound channel is/was playing a note for this MIDi channel...
      if (SoundChan[IndSoundChan].IsHeld) {                                                               //If the note for this sound channel is still being held...
        SoundChanNoteOff(IndSoundChan, usCur);                                                            //Release it.
      }
    }
  }
}

void AllSoundOff(byte IndMIDIChan) {
  for (byte IndSoundChan = 0; IndSoundChan < NumSoundChans; IndSoundChan ++) {                            //Check all sound channels.
    if (SoundChan[IndSoundChan].PlayingMIDIChan == IndMIDIChan) {                                         //If this sound channel is/was playing a note for this MIDi channel...
      SoundChan[IndSoundChan].EnvCurBase = 0;                                                             //Ensure that its volume envelope level is 0.
    }
  }
}

void NoteOff(byte OldMIDIChan, byte OldMIDINote) {
  if ((OldMIDINote < MIDINoteMin) || (OldMIDINote > MIDINoteMax)) {return;}                               //Do nothing if MIDI note is outside supported range.
  
  byte IndSoundChan = GetIndSoundChan(OldMIDIChan, OldMIDINote);
  if (IndSoundChan != UnusedMisc) {SoundChanNoteOff(IndSoundChan, micros());}                             //If a sound channel is even playing this MIDI channel's note, release it.
}

void SoundChanNoteOff(byte IndSoundChan, unsigned long usCur) {
  SoundChanStruct* RefSoundChan = &SoundChan[IndSoundChan];                                               //Allow us to easily refer to the sound channel we're dealing with now.
  RefSoundChan->EnvDecayTarget  = 8;                                                                      //Start decaying sound channel's volume envelope towards silence.
  RefSoundChan->IsHeld          = false;                                                                  //Don't attempt to release this channel again in the future.
  RefSoundChan->usDecayNext     = usCur + DecodeO1024(RefSoundChan->usDecayIncO1024);                     //Remove huge built-up delay (next decay should happen immediately but only once).
}

void NoteOn(byte NewMIDIChan, byte NewMIDINote, byte NewVel) {
  if ((NewMIDINote < MIDINoteMin) || (NewMIDINote > MIDINoteMax)) {return;}                               //Do nothing if MIDI note is outside supported range.
  NoteOff(NewMIDIChan, NewMIDINote);                                                                      //Release this held note on this channel if it's already playing.
  
  byte IndSoundChanCur;
  byte ValSoundChanCur;
  byte ValSoundChanBest = 255;
  byte IndSoundChanBest;

  //Overwrite a note playing on this MIDI channel if that's wanted (if monophonic, or perc with any instance of the same note or a note in the same "group", e.g. OHH if starting CHH).
    if (GetFlag(MIDIChan[NewMIDIChan].Flags, mcfMono)) {                                                  //If note is not percussion but channel is monophonic,
      for (IndSoundChanCur = 0; IndSoundChanCur < NumSoundChans; IndSoundChanCur ++) {                    //Go through all sound channels (NOTE: using above-defined IndSoundChanCur!).
        SoundChanStruct* RefSoundChan = &SoundChan[IndSoundChanCur];
        if (RefSoundChan->PlayingMIDIChan == NewMIDIChan) {                                               //If sound channel last played a note for this MIDI channel...
          if (RefSoundChan->EnvCurBase) {                                                                 //If sound channel is still making sound...
            goto AfterSearching;                                                                          //Replace old note on this channel with the new note.
          }                                                                                               //Ended if sound channel is making sound.
        }                                                                                                 //Ended if sound channel last played a note for this MIDI channel.
      }                                                                                                   //Ended for each sound channel.
    } else if (GetFlag(MIDIChan[NewMIDIChan].Flags, mcfIsPerc)) {                                         //Else, if channel is polyphonic but new note is percussion...
      for (IndSoundChanCur = 0; IndSoundChanCur < NumSoundChans; IndSoundChanCur ++) {                    //Go through all sound channels (NOTE: using above-defined IndSoundChanCur!).
        SoundChanStruct* RefSoundChan = &SoundChan[IndSoundChanCur];
        if (RefSoundChan->PlayingMIDIChan == NewMIDIChan) {                                               //If sound channel last played a note for this MIDI channel...
          if (RefSoundChan->EnvCurBase) {                                                                 //If sound channel is still making sound...
            switch (RefSoundChan->PlayingMIDINote) {                                                      //Check the MIDI note which this sound channel is playing.
              case PTHihatClosed:                                                                         //If checked note is a hihat...
              case PTHihatPedal:
              case PTHihatOpen:
                switch (NewMIDINote) {                                                                    //Check new MIDI note.
                  case PTHihatClosed:                                                                     //If new note is also a hihat...
                  case PTHihatPedal:
                  case PTHihatOpen:
                    goto AfterSearching;                                                                  //Cancel the old hihat    (of any kind) and re-use this sound channel for new one.
                  case PTTriangleOpen:                                                                    //If new note is also a triangle...
                  case PTTriangleClosed:
                    goto AfterSearching;                                                                  //Cancel the old triangle (of any kind) and re-use this sound channel for new one..
                }                                                                                         //Ended checking new MIDI note.
                break;
              default:
                if (RefSoundChan->PlayingMIDINote == NewMIDINote) {goto AfterSearching;}                  //If checked note is same as new note, restart (overwrite) this sound channel.
            }                                                                                             //Ended checking MIDI note which this sound channel is playing.
          }                                                                                               //Ended if sound channel is making sound.
        }                                                                                                 //Ended if sound channel last played a note for this MIDI channel.
      }                                                                                                   //Ended for each sound channel.
    } else {                                                                                              //Else, if new MIDI note is not percussion and MIDI channel is polyphonic...
      IndSoundChanCur = NumSoundChans;                                                                    //Act as if we searched for a channel to re-use but found none, to force a search below.
    }                                                                                                     //Ended if new MIDI note should play on a percussion MIDI channel or not.
    //^ At this point, IndSoundCHanCur is NumSoundChans, meaning that either this new MIDI note is not percussion, or it is, but we found no sound channels playing percussion which 
    //  we can re-use (overwrite).
    AfterSearching:                                                                                       //IndSoundChanCur is now IndSoundChanPrev if no sound channel should be overwritten.
  
  if (IndSoundChanCur == NumSoundChans) {                                                                 //If still no sound channel has been chosen...
    IndSoundChanCur = IndSoundChanPrev;                                                                   //We will start searching from "last-used"+1 (var is incremented before use) below.
    do {                                                                                                  //Search for the first free sound channel.
      IndSoundChanCur ++;                                                                                 //Move on to checking next sound channel.
      if (IndSoundChanCur > IndSoundChanMax) {IndSoundChanCur = 0;}                                       //If we've gone past the last sound channel, wrap back to the first one.
      ValSoundChanCur = SoundChan[IndSoundChanCur].EnvCurBase;                                            //Look at this sound channel's current volume envelope level.
      if (ValSoundChanCur == 0) {break;}                                                                  //Stop checking if we've found a free one!
      if (SoundChan[IndSoundChanCur].IsHeld) {ValSoundChanCur <<= EnvStartShift;}                         //If note is still held, penalise much harder (undo start volume scaling).
      if (ValSoundChanCur < ValSoundChanBest) {                                                           //If this envelope is quieter than the best we've seen so far...
        ValSoundChanBest = ValSoundChanCur;                                                               //Make a note of its value.
        IndSoundChanBest = IndSoundChanCur;                                                               //Make a note of its index.
      }
    } while (IndSoundChanCur != IndSoundChanPrev);                                                        //Stop looping once we've just got all the way back to the last-used one.
    if (IndSoundChanCur == IndSoundChanPrev) {IndSoundChanCur = IndSoundChanBest;}                        //If we found no free one, use the best (quietest) one we found.
  }
  
  IndSoundChanPrev = IndSoundChanCur;                                                                     //Next time, start searching from this index + 1.
  StartSoundChan(IndSoundChanCur, micros(), NewMIDIChan, NewMIDINote, NewVel);                            //Actually use this chosen sound channel to play this note!
}

byte GetIndSoundChan(byte IndMIDIChan, byte IndMIDINote) {                                                //Returns ind of sound chan playing this note on this MIDI chan, or UnusedMisc.
  for (byte IndSoundChan = 0; IndSoundChan < NumSoundChans; IndSoundChan ++) {
    SoundChanStruct* RefSoundChan = &SoundChan[IndSoundChan];
    if (RefSoundChan->PlayingMIDINote == IndMIDINote) {
      if (RefSoundChan->PlayingMIDIChan == IndMIDIChan) {
        if (RefSoundChan->IsHeld) {
          return IndSoundChan;
        }
      }
    }
  }
  return UnusedMisc;
}

void InitMIDIChans() {
  for (byte IndMIDIChan = 0; IndMIDIChan < NumMIDIChans; IndMIDIChan ++) {
    ResetMIDIChan(IndMIDIChan);
  }
  MIDIMsgStatus                 = 0;
  IndMIDIMsgData                = 0;
}

void ResetMIDIChan(byte IndMIDIChan) {
  MIDIChanStruct* RefMIDIChan = &MIDIChan[IndMIDIChan];                                                 //Allow us to easily refer to the MIDI channel we're dealing with now.
  SetFlag(&(RefMIDIChan->Flags), mcfPNIsRPN, false);
  SetFlag(&(RefMIDIChan->Flags), mcfIsPerc,  (IndMIDIChan == 9));
  SetFlag(&(RefMIDIChan->Flags), mcfSustain, false);
  SetFlag(&(RefMIDIChan->Flags), mcfMono,    false);
  RefMIDIChan->PNHigh         = PNUnused;
  RefMIDIChan->PNLow          = PNUnused;
  RefMIDIChan->VolShift       = 0;
  RefMIDIChan->ExpShift       = 0;
  RefMIDIChan->VolAndExpShift = 0;
  RefMIDIChan->ModVal         = 0;
  SetBendSens(RefMIDIChan, 2);
  PitchBend(IndMIDIChan, 0);
}

void InitSoundChans() {
  unsigned long usCur = micros() + 100000;                                                                //Only start generating sound after 100ms (gives us time to init everything).
  for (byte IndSoundChan = 0; IndSoundChan < NumSoundChans; IndSoundChan ++) {
    StartSoundChan(IndSoundChan, usCur, UnusedMisc, UnusedMisc, 0);                                       //Ensure all sound chan vars are set, but don't actually play a note yet.
  }
}

boolean StartPerc(SoundChanStruct* RefSoundChan, byte NewMIDINote) {                                      //Sets EnvCurBase, usOscIncBase, usDecayInc. Returns true if should be played as noise.
  switch (NewMIDINote) {                                                                                  //Decide on start volume, sample rate and decay speed based on percussive note.
    case PTKick1:
      RefSoundChan->EnvCurBase    <<= 2;
      RefSoundChan->usOscIncBase    = 1000000 / 180;
      RefSoundChan->usDecayIncO1024 = 11;
      RefSoundChan->DecayPitchO8    = 128;
      return false;
    case PTKick2:
      RefSoundChan->EnvCurBase    <<= 2;
      RefSoundChan->usOscIncBase    = 1000000 / 280;
      RefSoundChan->usDecayIncO1024 = 12;
      RefSoundChan->DecayPitchO8    = 160;
      return false;
    
    case PTSnare1:
      RefSoundChan->EnvCurBase    <<= 1;                                                                  //Shift wave table's value right by this to decrease its volume.
      RefSoundChan->usOscIncBase    = 1000000 / (WaveNoiseSpeed * 27);                                    //Delay between each sample (affects sample rate). Last number is loop frequency in Hz.
      RefSoundChan->usDecayIncO1024 = 23;                                                                 //Delay between each right-shift of 1 to EnvCurBase (affects sound duration).
      RefSoundChan->DecayPitchO8    = 0;
      return true;
    case PTSnare2:
      RefSoundChan->EnvCurBase    <<= 1;
      RefSoundChan->usOscIncBase    = 1000000 / (WaveNoiseSpeed * 25);
      RefSoundChan->usDecayIncO1024 = 27;
      RefSoundChan->DecayPitchO8    = 0;
      return true;
    case PTSideStick:
      RefSoundChan->EnvCurBase    <<= 1;
      RefSoundChan->usOscIncBase    = 1000000 / (WaveNoiseSpeed * 21);
      RefSoundChan->usDecayIncO1024 = 6;
      RefSoundChan->DecayPitchO8    = 0;
      return true;
    case PTCastanet:
      RefSoundChan->EnvCurBase    <<= 1;
      RefSoundChan->usOscIncBase    = 1000000 / (WaveNoiseSpeed * 24);
      RefSoundChan->usDecayIncO1024 = 5;
      RefSoundChan->DecayPitchO8    = 0;
      return true;

    case PTClap:
      RefSoundChan->EnvCurBase    <<= 1;
      RefSoundChan->usOscIncBase    = 1000000 / (WaveNoiseSpeed * 18);
      RefSoundChan->usDecayIncO1024 = 18;
      RefSoundChan->DecayPitchO8    = 0;
      return true;

    case PTTomHigh:
    case PTTomMidHigh:
    case PTTomMidLow:
    case PTTomLow:
    case PTTomFloorHigh:
    case PTTomFloorLow:
      RefSoundChan->EnvCurBase    <<= 2;
      RefSoundChan->usOscIncBase    = (1000000 / 28) / (NewMIDINote - 35);          //(1000000 / 28) / (NewMIDINote - 36);  //(1000000 / 48) / (NewMIDINote - 38);
      RefSoundChan->usDecayIncO1024 = 28;
      RefSoundChan->DecayPitchO8    = 80;
      return false;
    
    case PTHihatClosed:
      //RefSoundChan->EnvCurBase    >>= 0;
      RefSoundChan->usOscIncBase    = 1000000 / (WaveNoiseSpeed * 120);
      RefSoundChan->usDecayIncO1024 = 3;
      RefSoundChan->DecayPitchO8    = 0;
      return true;
    case PTHihatPedal:
    case PTShaker:
    case PTCabasa:
    case PTMaracas:
      //RefSoundChan->EnvCurBase    >>= 0;
      RefSoundChan->usOscIncBase    = 1000000 / (WaveNoiseSpeed * 120);
      RefSoundChan->usDecayIncO1024 = 8;
      RefSoundChan->DecayPitchO8    = 0;
      return true;
    case PTHihatOpen:
      //RefSoundChan->EnvCurBase    >>= 0;
      RefSoundChan->usOscIncBase    = 1000000 / (WaveNoiseSpeed * 120);
      RefSoundChan->usDecayIncO1024 = 22;
      RefSoundChan->DecayPitchO8    = 0;
      return true;
    
    case PTCymbalCrash1:
      //RefSoundChan->EnvCurBase    >>= 0;
      RefSoundChan->usOscIncBase    = 1000000 / (WaveNoiseSpeed * 60);
      RefSoundChan->usDecayIncO1024 = 150;
      RefSoundChan->DecayPitchO8    = 0;
      return true;
    case PTCymbalCrash2:
      //RefSoundChan->EnvCurBase    >>= 0;
      RefSoundChan->usOscIncBase    = 1000000 / (WaveNoiseSpeed * 70);
      RefSoundChan->usDecayIncO1024 = 150;
      RefSoundChan->DecayPitchO8    = 0;
      return true;
    case PTCymbalSplash:
      //RefSoundChan->EnvCurBase    >>= 0;
      RefSoundChan->usOscIncBase    = 1000000 / (WaveNoiseSpeed * 80);
      RefSoundChan->usDecayIncO1024 = 100;
      RefSoundChan->DecayPitchO8    = 0;
      return true;

    case PTCymbalRide1:
    case PTCymbalRide2:
      RefSoundChan->EnvCurBase    >>= 1;
      RefSoundChan->usOscIncBase    = 1000000 / (WaveNoiseSpeed * 90);
      RefSoundChan->usDecayIncO1024 = 160;
      RefSoundChan->DecayPitchO8    = 0;
      return true;
    case PTBellRide1:
      //RefSoundChan->EnvCurBase    >>= 0;
      RefSoundChan->usOscIncBase    = 1000000 / (WaveNoiseSpeed * 45);
      RefSoundChan->usDecayIncO1024 = 60;
      RefSoundChan->DecayPitchO8    = 0;
      return true;

    case PTTriangleClosed:
      //RefSoundChan->EnvCurBase    >>= 1;
      RefSoundChan->usOscIncBase    = 1000000 / (2700 * 2);
      RefSoundChan->usDecayIncO1024 = 7;
      RefSoundChan->DecayPitchO8    = 0;
      return false;
    case PTTriangleOpen:
      //RefSoundChan->EnvCurBase    >>= 1;
      RefSoundChan->usOscIncBase    = 1000000 / (2700 * 2);
      RefSoundChan->usDecayIncO1024 = 75;
      RefSoundChan->DecayPitchO8    = 0;
      return false;
  }
  //If we're still here, this percussive note is unsupported - don't play it at all.
  RefSoundChan->EnvCurBase = 0;
  return false;
}

void StartSoundChan(byte IndSoundChan, unsigned long usCur, byte NewMIDIChan, byte NewMIDINote, byte NewVel) {
  SoundChanStruct* RefSoundChan    = &SoundChan[IndSoundChan];                                            //Allow us to easily refer to the sound channel we're dealing with now.
  if (NewMIDINote == UnusedMisc) {                                                                        //If sound channel is simply being initialised (not going to play a note now)...
    RefSoundChan->EnvCurBase       = 0;                                                                   //Mark sound channel as unused.
    RefSoundChan->IsHeld           = false;                                                               //Mark channel as not having its note being held.
    RefSoundChan->PlayingMIDIChan  = UnusedMisc;                                                          //Not currently playing a note for any MIDI channel.
    RefSoundChan->PlayingMIDINote  = UnusedMisc;                                                          //Not currently playing any MIDI note.
    RefSoundChan->usOscIncBase     = 1000000; // / (200 + random(1350));                                  //RANDOM: Choose a frequency from 200 to 1550 Hz.
    RefSoundChan->usOscInc         = RefSoundChan->usOscIncBase;                                          //(No need to take pitch-bend into account to set this if using random frequency).
    RefSoundChan->usDecayIncO1024  = 50; // + random(250000);                                             //RANDOM: Decay wave envelope every 50ms to 250ms.
    RefSoundChan->DecayPitchO8     = 0;                                                                   //Don't decay pitch with envelope.
    RefSoundChan->IndWaveNoise     = 0;                                                                   //Mark that we're at the beginning of noise.
  } else {                                                                                                //Else, if sound channel is starting to play a note now...
    RefSoundChan->EnvCurBase       = NewVel >> EnvStartShift;                                             //Start from the volume of this new note (decreased, to avoid wrapping).
    RefSoundChan->PlayingMIDIChan  = NewMIDIChan;                                                         //Not currently playing a note for any MIDI channel.
    RefSoundChan->PlayingMIDINote  = NewMIDINote;                                                         //Not currently playing any MIDI note.

    if (GetFlag(MIDIChan[NewMIDIChan].Flags, mcfIsPerc)) {                                                //---- NOISE: If this note is playing on a percussive MIDI channel...
      RefSoundChan->IsHeld          = false;                                                              //Mark channel as NOT having its note being held (prioritise tone over percussion).
      RefSoundChan->EnvDecayTarget  = 8;                                                                  //Decay enough times to become silent.
      RefSoundChan->WaveCycleState  = 255;                                                                //Start with wave "on".
      RefSoundChan->IndWaveNoise    = 0;                                                                  //Start at first position in the noise lookup table.
      RefSoundChan->IsNoise         = StartPerc(RefSoundChan, NewMIDINote);                               //Set up start volume, decay speed and (base) sample rate based on percussive note.
    } else {                                                                                              //---- SQUARE: Else, if this note is playing on a tone MIDI channel...
      RefSoundChan->IsHeld          = true;                                                               //Mark channel as having its note held now (less likely to be overwritten).
      RefSoundChan->usOscIncBase    = pgm_read_word_near(MIDINoteInt + NewMIDINote - MIDINoteMin);        //Use interval of frequency of the given note.
      RefSoundChan->usDecayIncO1024 = 100;                                                                //Decay wave envelope every 100ms.
      RefSoundChan->DecayPitchO8    = 0;                                                                  //Don't decay pitch with envelope.
      RefSoundChan->EnvDecayTarget  = EnvDecaySus;                                                        //Decay enough times for us to reach the sustain envelope level, for now.
      RefSoundChan->IsNoise         = false;                                                              //Generate a square wave.
      RefSoundChan->WaveCycleState  = true;                                                               //Start with wave cycle in the "on" state.
    }
    UpdateSoundChanFreq(IndSoundChan, MIDIChan[NewMIDIChan].ModVal);                                      //Set usOscInc based on usOscIncBase, taking into account any current pitch-bend.
    UpdateSoundChanEnvCurAfter(RefSoundChan, MIDIChan[NewMIDIChan].VolAndExpShift);                       //Apply MIDI channel expression/volume to envelope.
  }
  RefSoundChan->EnvDecayCur        = 0;                                                                   //We have not started decaying the envelope at all yet.
  RefSoundChan->usOscNext          = usCur + RefSoundChan->usOscInc;
  RefSoundChan->usDecayNext        = usCur; //+ RefSoundChan->usDecayInc;
}

void loop() {
  //For modulation:
    unsigned long usModNext = micros() + 1000;
    byte ModUpdateMIDIChan = 0;                                                                           //Loops 0~15 to update 1 chan's freq at a time. usModNext is incremented after 15.
  
  while (true) {
    //Update stuff
      ProcessAnyByte();                                                                                   //Process a maximum of one newly-received byte from MIDI input.
      unsigned long usCur = micros();                                                                     //Update the current time (in microseconds).
    
    //Add up the current total envelopes of all waves whose cycles are currently in the "on" state.
      byte EnvTotal = 0;
      for (byte IndSoundChan = 0; IndSoundChan < NumSoundChans; IndSoundChan ++) {
        SoundChanStruct* RefSoundChan = &SoundChan[IndSoundChan];                                         //Allow us to easily refer to the sound channel we're dealing with now.
        if (RefSoundChan->EnvCurBase) {                                                                   //If this sound channel is even playing anything...
          
          if (usCur >= RefSoundChan->usOscNext) {                                                         //If it's time to output the next byte from the wave table...
            if (RefSoundChan->IsNoise) {                                                                  //----- NOISE:
              RefSoundChan->WaveCycleState = pgm_read_byte_near(WaveNoise + RefSoundChan->IndWaveNoise);  //Read the next wave table value (will be 0 or 255, similar to square wave).
              if (RefSoundChan->IndWaveNoise < LenWaveNoise  - 1) {                                       //If we've not just read the last byte of the wave table...
                RefSoundChan->IndWaveNoise ++;                                                            //Next time, read the next byte.
              } else {                                                                                    //Else, if we just read the last byte of the wave table...
                RefSoundChan->IndWaveNoise = 0;                                                           //Next time, read the first byte.
              }
            } else {                                                                                      //----- SQUARE:
              RefSoundChan->WaveCycleState = !RefSoundChan->WaveCycleState;                               //Flip the wave cycle state.
            }                                                                                             //Ended if this sound channel is playing noise or square.
            RefSoundChan->usOscNext += RefSoundChan->usOscInc;                                            //Do it again later.
            /*if (RefSoundChan->WaveCycleState) {
              RefSoundChan->usOscNext += (RefSoundChan->usOscInc >> 1);                                   //Quarter        (25% pulse width).
            } else {
              RefSoundChan->usOscNext += (RefSoundChan->usOscInc >> 1) + (RefSoundChan->usOscInc >> 0);   //Quarter + half (75% pulse width).
            }*/
          }
          
          if (usCur >= RefSoundChan->usDecayNext) {                                                       //If it's time to decay...
            if (RefSoundChan->EnvDecayCur != RefSoundChan->EnvDecayTarget) {                              //If we have not decayed envelope enough times yet...
              RefSoundChan->EnvCurBase  >>= 1;                                                            //Decay the wave envelope.
              RefSoundChan->EnvDecayCur ++;                                                               //Increase our count of the number of times the envelope has been decayed.
              UpdateSoundChanEnvCurAfter(RefSoundChan, MIDIChan[RefSoundChan->PlayingMIDIChan].VolAndExpShift);   //Apply MIDI channel expression/volume to envelope.
              if (RefSoundChan->DecayPitchO8) {                                                           //If this sound channel should have decaying pitch...
                RefSoundChan->usOscInc += DecodeO8(RefSoundChan->DecayPitchO8);                           //Increase usOscInc (decreases pitch).
              }
              RefSoundChan->usDecayNext += DecodeO1024(RefSoundChan->usDecayIncO1024);                    //Do it again later.
            }
          }

          if (RefSoundChan->WaveCycleState) {EnvTotal += RefSoundChan->EnvCurAfter;}                      //If wave's position is currently "on", add its envelope to the running total.
          
        }                                                                                                 //Ended if sound channel is in use.
      }                                                                                                   //Ended for each sound channel.
    //Output this total to the audio port.
      PORTAudio = EnvTotal;

    //If it's time to toggle the global modulation half-cycle state, do so, updating any sound channels as necessary.
    //We update the modulation value for one MIDI channel per main loop, rather than all together (avoids slowing down loop too much).
      if (usCur >= usModNext) {                                                                           //If it's time to toggle the modulation cycle state...
        char* RefModVal = &MIDIChan[ModUpdateMIDIChan].ModVal;                                            //Allow us to easily access the modulation value for this loop's MIDI channel.
        if (*RefModVal) {                                                                                 //If this MIDI channel is using modulation...
          *RefModVal = -(*RefModVal);                                                                     //Toggle the cycle state between positive and negative.
          UpdateMIDIChanFreqAlways(ModUpdateMIDIChan, *RefModVal);                                        //Update frequency of all sound channels making sound for this MIDI channel.
        }                                                                                                 //Ended if this MIDI channel is using modulation.
        if (ModUpdateMIDIChan == (NumMIDIChans - 1)) {                                                    //If this is the last MIDI channel to update...
          usModNext += usModInc;                                                                          //Toggle modulation cycle state for all MIDI channels again in a while.
          ModUpdateMIDIChan = 0;                                                                           //Next time we toggle modulation, update the first MIDI channel.
        } else {                                                                                          //Else, if we have more MIDI channels to update...
          ModUpdateMIDIChan ++;                                                                           //Next time around the loop, update the next MIDI channel.
        }                                                                                                 //Ended if this is the last MIDI channel to update or not.
      }                                                                                                   //Ended if it's time to toggle the modulation cycle state.
      
  }                                                                                                       //Ended infinite loop.
}

inline boolean GetFlag(byte Flags, byte BitRep) {
  return Flags & BitRep;
}
inline void SetFlag(byte* Flags, byte BitRep, boolean NewVal) {
  if (NewVal) {
    *Flags |= BitRep;
  } else {
    *Flags &= ~BitRep;
  }
}

inline unsigned long DecodeO1024(byte ValO1024) {
    return uint32_t(ValO1024) << 10;
}
inline unsigned long DecodeO8(byte ValO8) {
    return uint32_t(ValO8) << 3;
}

void ToneDelay(unsigned int UseHz, unsigned long UseDur) {
  tone(pinToneDebug, UseHz);                                                                              //Play a tone for a certain amount of time,
  delay(UseDur);                                                                                          //freezing while the tone plays.
  noTone(pinToneDebug);
}
