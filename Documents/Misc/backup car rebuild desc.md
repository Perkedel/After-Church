## How to control:
Slider - Speed control  
1. `A` - Hold to activate Reverse
2. `F` - Hold to brake. Toggle G to activate/deactivate ABS gimmicky mode
3. `G` - ABS On/Off/Auto (ABS default AUTO). Auto means tue the ABS activate only if Speed > Required speed to ABS. More Usefull if sudden brake when you don't want flip but also want quickly stop to save a child.
4. `H` - Comfort accelerate On/Off. Default On. On means the acceleration starts slowly (due to a filter via Moving average formula) even the slider is solid sudden raise since at the next tick for e.g.: this tick is Slider 0.0, then next tick is Slider 1.0, so the Speed will increase slowly from 0 to 1 eventually. Useful to prevent accelerate flip caused by conventional sudden accelerate that been done by motorcycle beginner. Off means the Slider is always equal to Speed, so the acceleration flip will be present.

## Debugger:
1. `Left Grapher` - Speed
2. `Mid Lamp` - ABS mode is Active or De-Active?
3. `Right Grapher` - Reverse

In theory, the ABS work by blink the brake function On and Off every tick.
So we made the sequence like this: based on (I forgot who, maybe that guy?)
-1, 0, 1, 0, and back again.

Basically it appended full zero (Speed and Reverse are 0) in between change shift. It was originally -1, 1, -1, 1, (with all time the Speed is 0.001) and back again. With ABS, the Reverse and Speed is zero in between -1 and 1 (to result sequence on the most top mentioned before), creating blinking brake illusion.

But this System kinda useless since the plane on this Principia is 2D, causing the car only move back and forth (Y coordinate) without ability to turn to different layer (Z coordinate). Maybe useful on bird eye car which benefits X and Y?
I wish the next Apparatus game is 3D, so I can benefit X, Y, and Z.

Edit: I've tested between 2 brake modes. ABS reduces chance to flip the car on sudden brake event compared to no ABS.

New! Switch OFF, ON, or AUTO the ABS. Auto will activate ABS only if you sudden brake from fast enough run. It will off again if the car slow enough again to make stol quicker compared to stay on ABS.

Now! With slow acceleration using Moving Average formula!
`Output=(Input*Weight)+(Output*(1-Weight))`
No more flip from sudden accelerate! Press toggle H to On/Off Comfort Accelerate mode!
ABS defaulted to Auto.

Moving average formula now has 0 reset. When the slider is 0, the moving average will be reset entirely to 0 it did when braking.
Pressing Reverse and releasing reverse will trigger moving average reset!
Why car still flip on gear change to reverse and unreverse?!

# Wow, Duper Awesome!!!
by JOELwindows7
Perkedel Technologies
CC4.0-BY-SA

# version shorte

# Control
- `Slider` - Speed Control
- `A` - Hold to reverse
- `F` - Hold to Brake
- `G` - Toggle ABS On/Off/Auto (Default: Auto); Auto activates at high speed only
- `H` - Toggle Comfort On/Off; Slowly accelerate despite sudden up spike in slider control.

# Debugger
- `Left Grapher` - Speed
- `Mid Lamp` - ABS Mode Active/Inactive
- `Right Grapher - Reverse