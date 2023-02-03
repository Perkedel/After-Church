--Engine by Sasha from Russia
--Presented by JOELwindows7
function init(is_sandbox)
i = 1 -- takt
-- MUSIC GAMMA (C moll) ---------------------------------------------
F0 = 0.098
FIS0 = 0.103
G0 = 0.11 -- small octave 
AED0 = 0.116
A0 = 0.123
B0 = 0.13
H0 = 0.138
C = 0.146 -- first octave
CIS = 0.154
D = 0.164
ED = 0.174
E = 0.184
F = 0.195
FIS = 0.206
G = 0.22
AED = 0.232
A = 0.246
B = 0.26
H = 0.276
C1 = 0.293
CIS1 = 0.308
D1 = 0.327
ED1 = 0.348
E1 = 0.368
F1 = 0.39
FIS1 = 0.412
G1 = 0.44
AED1 = 0.464
A1 = 0.492 -- second octave
---------------------------------------
song_title = "Guruku Tersayang" -- The name of melody
game: message(song_title)
end
function step(count)

--TRANSPOSITION--------
transposition = 1 -- C dur/moll (1.685 - A dur/moll; 1.26 - E dur/moll; 1.507 - G dur/moll; Other: TON dur/moll = TON / C)
-----------------------


-- WRITE MUSIC HERE ----------------
-- "AFI Junior-Guruku Tersayang" G-moll --

layer1 = 
{H  ,G  ,D  ,H  ,C1 ,G  ,E  ,000,D  ,FIS,A  ,C1 ,000,H  ,000,000,
 H  ,G  ,D  ,H  ,C1 ,G  ,E  ,000,D  ,000,FIS,000,G  ,G  ,000,000, --
 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000, --
 H  ,G  ,D  ,H  ,C1 ,0  ,E  ,000,D  ,FIS,A  ,C1 ,000,H  ,000,000,    --Pagiku Cerahku, matahari bersinar
 H  ,G  ,D  ,H  ,C1 ,G  ,E  ,000,D  ,000,FIS,000,G  ,000,000,000, --   Kugendong tas merahku, dipundak
 H  ,G  ,D  ,H  ,C1 ,G  ,E  ,000,D  ,FIS,A  ,C1 ,000,H  ,000,000,    --Selamat pagi semua, kunantikan dirimu (II)
 H  ,G  ,D  ,H  ,C1 ,000,E  ,000,D  ,000,A  ,FIS,000,000,G  ,000, --   Didepan kelasmu, menantikan kami
 G  ,FIS,G  ,H0 ,C  ,G  ,000,000,FIS,E  ,FIS,H0 ,000,000,FIS,000,    --Guruku tersayang, guru tercinta (III)
 E  ,ED ,E  ,000,E  ,FIS,G  ,A  ,G  ,FIS,000,000,000,000,000,000, --   tanpamu, apa jadinya aku?
 G  ,FIS,G  ,H0 ,C  ,G  ,000,000,FIS,E  ,FIS,H0 ,000,000,FIS,000,    --Tak bisa baca tulis, mengerti banyak hal
 E  ,ED ,E  ,000,E  ,FIS,G  ,A  ,H  ,A  ,000,000,000,000,000,000, --   Guruku, terima kasih ku (IIIend)
 H  ,G  ,D  ,H  ,C1 ,0  ,E  ,000,D  ,FIS,A  ,C1 ,000,H  ,000,000,    --Nyatanya diriku, kadang buatmu marah
 H  ,G  ,D  ,H  ,C1 ,G  ,E  ,000,D  ,000,A  ,FIS,000,G  ,000,000, --   Namun segala maaf, kau berikan.
 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
 000,000,000,000,000,000,000,000,E  ,E  ,ED ,FIS,FIS,FIS,FIS,000, --
 G  ,B  ,A  ,G  ,FIS,E  ,E  ,000,B  ,A  ,G  ,FIS,E  ,D  ,D  ,000,000,
 G  ,FIS,E  ,D  ,CIS,CIS,000,G  ,000,000,000,FIS,A  ,A  ,A  ,A  , --
 B  ,D1 ,D1 ,D1 ,D1 ,D1 ,D1 ,000,A  ,B  ,CIS1,D1,D1 ,D1 ,D1 ,D1 ,
 H  ,G  ,D  ,H  ,C1 ,G  ,E  ,000,D  ,FIS,A  ,C1 ,000,H  ,000,000, --   Selamat pagi semua, kunantikan dirimu (II)
 H  ,G  ,D  ,H  ,C1 ,000,E  ,000,D  ,000,A  ,FIS,000,000,G  ,000,    --Didepan kelasmu, menantikan kami
 G  ,FIS,G  ,H0 ,C  ,G  ,000,000,FIS,E  ,FIS,H0 ,000,000,FIS,000, --   Guruku tersayang, guru tercinta (III)
 E  ,ED ,E  ,000,E  ,FIS,G  ,A  ,G  ,FIS,000,000,000,000,000,000,    --tanpamu, apa jadinya aku?
 G  ,FIS,G  ,H0 ,C  ,G  ,000,000,FIS,E  ,FIS,H0 ,000,000,FIS,000, --   Tak bisa baca tulis, mengerti banyak hal
 E  ,ED ,E  ,000,E  ,FIS,G  ,A  ,H  ,A  ,000,000,000,000,000,000,    --guruku, terima kasih mu (IIIend)
 H  ,G  ,D  ,H  ,C1 ,0  ,E  ,000,D  ,FIS,A  ,C1 ,000,H  ,000,000, --   Nyatanya diriku, kadang buatmu marah
 H  ,G  ,D  ,H  ,C1 ,G  ,E  ,000,D  ,000,A  ,FIS,000,G  ,000,000,    --Namun segala maaf, kau berikan.
 G  ,FIS,G  ,H0 ,C  ,G  ,000,000,FIS,E  ,FIS,H0 ,000,000,FIS,000, -- ((Guruku tersayang, guru tercinta (III)(again)
 E  ,ED ,E  ,000,E  ,FIS,G  ,A  ,G  ,FIS,000,000,000,000,000,000,    --tanpamu, apa jadinya aku?
 G  ,FIS,G  ,H0 ,C  ,G  ,000,000,FIS,E  ,FIS,H0 ,000,000,FIS,000, --   Tak bisa baca tulis, mengerti banyak hal
 E  ,ED ,E  ,000,E  ,FIS,G  ,A  ,H  ,A  ,000,000,000,000,000,000,    --Guruku, terima kasih mu (IIIend)
 A  ,AED,A  ,CIS,D  ,000,A  ,A  ,AED,000,H0 ,CIS,000,AED,AED    , --   Guruku tersaayaang, Guru tercinta(pitch)
 FIS,E  ,FIS,000,FIS,AED,A  ,H  ,A  ,AED,000,000,000,000,000,000,    --tanpamu, apa jadinya aku?(pitch)
 A  ,AED,A  ,CIS,D  ,000,A  ,000,AED,FIS,AED,H0 ,CIS,000,AED,AED, --   Tak bisa baca tulis, mengerti banyak hal(pitch)
 FIS,E  ,FIS,000,FIS,AED,A  ,H  ,CIS1,H ,000,000,000,000,A  ,A  ,    --Guruku, terima kasih ku...u
 000,D  ,FIS,A  ,H  ,000,CIS1,00,                                 --   uuuuuuuuuuuuuuuuuuuuu
 CIS1,A ,E  ,CIS1,D1,A  ,FIS,000,E  ,AED,H  ,D1 ,000,CIS1,000,00,    --ending1
 CIS1,A ,E  ,CIS1,D1,A  ,FIS,000,E  ,E  ,0  ,AED,AED,0  ,A  ,A  , --   ending2
 A  ,A  ,A  ,A  ,A  ,A  ,A  ,000,000,000,000,000,000,000,000,000}    --THE END

layer2 = 
{000,000,000,000,000,000,000,000,000,000,000,000,C1 ,000,H  ,000,
 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000, --
 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000, --
 000,000,000,000,C1 ,000,E  ,000,000,000,000,000,C1 ,000,H  ,000,    --(1
 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000, --   (2
 000,000,000,000,000,000,000,000,000,000,000,000,C1 ,000,H  ,000,    --(3 II
 000,000,000,000,000,000,000,000,000,D  ,000,000,FIS,FIS,000,000, --   (4
 000,000,000,000,000,000,G  ,000,000,000,000,000,H0 ,000,FIS,000,    --(5 III
 000,000,000,000,000,000,000,000,000,000,FIS,FIS,FIS,FIS,000,000, --   (6
 000,000,000,000,000,000,G  ,000,000,000,000,000,H0 ,000,FIS,000,    --(7
 000,000,000,000,000,000,000,000,000,000,A  ,A  ,A  ,A  ,000,000, --   (8 IIIend
 000,000,000,000,000,000,000,000,000,000,000,000,C1 ,000,H  ,000,    --(9
 000,000,000,000,000,000,000,000,D  ,000,A  ,000,FIS,000,G  ,000, --   (10
 G  ,FIS,E  ,D  ,C  ,C  ,000,G  ,FIS,E  ,D  ,C  ,H0 ,H0 ,000,000,
 E  ,D  ,C  ,H0 ,A0 ,A0 ,000,E  ,000,000,ED ,FIS,FIS,FIS,FIS,000, --
 G  ,B  ,A  ,G  ,FIS,E  ,E  ,000,B  ,A  ,G  ,FIS,E  ,D  ,D  ,000,000,
 G  ,FIS,E  ,D  ,CIS,CIS,000,000,G  ,G  ,000,FIS,A  ,A  ,A  ,A  , --
 B  ,D1 ,D1 ,D1 ,000,000,000,D1 ,A  ,B  ,CIS1,D1,D1 ,D1 ,D1 ,D1 ,
 000,000,000,000,000,000,000,000,000,000,000,000,C1 ,000,H  ,000, --   (3 II
 000,000,000,000,000,000,000,000,000,D  ,000,000,FIS,FIS,000,000,    --(4
 000,000,000,000,000,000,G  ,000,000,000,000,000,H0 ,000,FIS,000, --   (5
 000,000,000,000,000,000,000,000,000,000,FIS,FIS,FIS,FIS,000,000,    --(6
 000,000,000,000,000,000,G  ,000,000,000,000,000,H0 ,000,FIS,000, --   (7
 000,000,000,000,000,000,000,000,000,000,A  ,A  ,A  ,A  ,000,000,    --(8
 000,000,000,000,000,000,000,000,000,000,000,000,C1 ,000,H  ,000, --   (9
 000,000,000,000,000,000,000,000,D  ,000,A  ,000,FIS,000,G  ,000,    --(10
 000,000,000,000,000,000,G  ,000,000,000,000,000,H0 ,000,FIS,000, --   ((5 III
 000,000,000,000,000,000,000,000,000,000,FIS,FIS,FIS,FIS,000,000,    --((6
 000,000,000,000,000,000,G  ,000,000,000,000,000,H0 ,000,FIS,000, --   ((7
 000,000,000,000,000,000,000,000,000,000,A  ,A  ,A  ,A  ,000,000,    --((8 IIIend
 000,000,000,000,000,A  ,000,000,000,AED,000,000,000,AED,AED    , --   (pitch(5
 000,000,000,000,000,000,000,000,000,000,AED,AED,AED,AED,000,000,    --(pitch(6
 000,000,000,000,000,A  ,000,000,000,000,000,000,000,000,AED,AED, --   (pitch(7
 000,000,000,000,000,000,000,000,000,000,H  ,H  ,H  ,H  ,000,000,    --(pitch(8
 A  ,A  ,A  ,A  ,A  ,A  ,A  ,A  ,                                 --   (pitch(cont
 CIS1,A ,E  ,CIS1,D1,A  ,FIS,000,000,000,000,000,D1 ,000,CIS1,00,    --(ending1
 000,000,000,000,000,000,000,000,E  ,E  ,0  ,AED,AED,0  ,A  ,A  , --   (ending2
 A  ,A  ,A  ,A  ,A  ,A  ,A  ,000,000,000,000,000,000,000,000,000}    --(THE END

layer3 = 
{000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
 H  ,G  ,D  ,H  ,C1 ,G  ,E  ,000,D  ,FIS,A  ,C1 ,000,H  ,000,000,
 H  ,G  ,D  ,H  ,C1 ,G  ,E  ,000,D  ,000,FIS,000,G  ,G  ,000,000,
 000,000,000,000,C1 ,000,E  ,000,000,000,000,000,H  ,000,G  ,000,
 H  ,G  ,D  ,H  ,C1 ,G  ,E  ,000,D  ,000,FIS,000,G  ,000,000,000}

layer4 = 
{000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,
 000,000,000,000,000,000,000,000,000,000,000,000,C1 ,000,H  ,000,
 H  ,G  ,D  ,H  ,C1 ,G  ,E  ,000,D  ,000,FIS,000,G  ,G  ,000,000,
 G  ,D1 ,H  ,D1 ,G  ,D1 ,H  ,000,D  ,E  ,FIS,H  ,000,G  ,000,000,
 G  ,D1 ,H  ,D1 ,G  ,D1 ,H  ,000,D  ,000,FIS,000,G  ,000,000,000}
-----8 beats rhythm-----------------



i = i+this: read(0)

-- CHANNELS (LAYERS) ----------
this: write(0,layer1[i]*transposition) -- ON
this: write(1,layer2[i]*transposition) -- ON
this: write(2,layer3[i]/4*transposition) -- ON; (-2 Octaves; if coefficient = 2 then -1 Octave)
this: write(3,layer4[i]/4*transposition) -- ON; (-2 Octaves)
-------------------------------
end

-- REPEAT to 0 if all layer are nil
--if layer1[i] == nil and layer2[i] == nil and layer3[i] == nil and layer4[i] == nil then
--i=0
--game:message(song_title.. ("Play again"))
--end
-- error, layer1 is nil value?!



















--Song brought to you by JOELwindows7,Engine originally by Sasha from Russia
--for Principia Lua script
