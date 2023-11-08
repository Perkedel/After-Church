![LFM Update Banner](https://github.com/Perkedel/After-Church/raw/master/RAW%20files/Inkscape/Week%20Strong/week-2022.09-thumb.png )

pls change image & fill new infos!

image thumb idea: We sold this mod to X0p1r4t3 Eenvreensment, here's explanation

# Last Funkin Moments: Incondusive

After we have temporarily suspended our contract due to Kaorfa's side job, we have witnessed that the day still becomes incondusive, unfortunately, as usual it is.

And Spoiler alert, I decided to graduate 90% of Wakturia workforce here, because the day has been incondusive to me. I cannot further risk this, because being banned for the ***rights*** is not a good idea at all. I shall keep my accounts alive as long as possible. I asked why it's down, deleted. I asked what's kenny is all about, blocked. We hoped that this one last out three mods here to come back just like previous two, nothing come back ever. And other things right in here, and everywhere. I thought some particular talented creators & high order people there are nice, they aren't. Really I am disappointed with you all.

You may see nothing in where you stand right now, but you should see the rubbles I have collected in where the Cause stands. Mind you that these rubbles as always will not be shipped with the main binary to ensure that it is legal for everyone.

Edit: Kaorfa has been laid off. the manager for Kaorfa's side job is currently requesting position and still haven't got news to this day.

## Download Updated

- [Linux](https://odysee.com/@JOELwindows7/last-funkin-moments )
- ~~[Linux 32 bit](https://odysee.com/@JOELwindows7/last-funkin-moments-32bit )~~
- [Windows](https://odysee.com/@JOELwindows7/last-funkin-moments-windows )
- ~~[Windows 32 bit](https://odysee.com/@JOELwindows7/last-funkin-moments-windows32 )~~ Sorry, VLC does not support 32 bit, maybe I should make 32 bit version stays WebM? nah, who still uses 32 bit windows on regular basis beside retro Windows YouTube videos?
- [macOS](https://odysee.com/@JOELwindows7:a/last-funkin-moments-macOS )
- [Android](https://odysee.com/@JOELwindows7:a/last-funkin-moments-android) STUCC! last build Android troubled. app crashes without reason printed. this one still old version
- [itch.io (Play Online now)](https://joelwindows7.itch.io/last-funkin-moments )
- [GameBanana](https://gamebanana.com/mods/293257 )
- [GameJolt (Play Online now)](https://gamejolt.com/games/last-funkin-moments/634559 )
- [NexusMods](https://www.nexusmods.com/fridaynightfunkin/mods/247 )
- [GitHub](https://github.com/Perkedel/Kaded-fnf-mods )
- [GitHub of AfterChurch, the SVG files](https://github.com/Perkedel/After-Church/tree/master/RAW%20files/Inkscape/Week%20Strong )

## Changes

- Tidy up *civil war rubbles*
- Began handover to X0p1r4t3 Eenvreensment. that's right, we are selling this entire project to Admiral Zumi, for good. This is to early archive it, not further developing. We apologize for your inconvenience.
- How do we supposed to pull the latest change on the vanilla????
- **PLEASE NOTE: GAMEBANANA RELEASE WILL STAY**, for now. If we stopped, we won't delete due to No Delete policy reason, just stop, no update. **GAMEBANANA WILL STILL RELEASED**
- [Psych Engine found ways to auto install Libraries with hmm](https://github.com/ShadowMario/FNF-PsychEngine/blob/main/hmm.json) yey! [last Commit about this here!](https://github.com/ShadowMario/FNF-PsychEngine/commit/f039d6e417231670b476a09618c2e7ec33f9fb2f )
- Kaorfa orders Admiral Zumi to keep that Legacy version. **DO NOT DELETE LAST VERSION!!!** ADD NEW VERSION INSTEAD! Or whatever re-sorting. Idk why.
- Edit: Kaorfa fear that the association with sparsdaters like Zumi sparks unwanted controvercies due to nature of FNF modders, especially in huge troubles, likes to delete stuffs. Ah peck neck! they might as well saw the beans on the floor already looking at this changelog! The onus yours, Joel!!
- Attempt improve pause music
- Subtitle Week 7 improvement inspired from Mortal Kombat 1's accessible subtitle styles.
- FireTongue has been prepared with same help from Larsius Prime ([this](https://github.com/HaxeFlixel/flixel-demos/blob/dev/UserInterface/RPGInterface/source/Main.hx) & [this](https://github.com/HaxeFlixel/flixel-demos/blob/dev/UserInterface/RPGInterface/source/State_Title.hx)). But then we have to convert every string occurences to refer to language locale tables. Oh my God, there are thousands of text in the codes I got to convert to `getText` built in `FlxUIState` & Substate.. **KLASDJFIO;AHEJRJKGNSDKJLFNGSRTLIHGNSDJFNGSILEBTRGJKSDNFLVJKLSNTGRNBTYJSBNRTGRONTGSERGIOERJGFDFSLKJ;LDSJ;FAJOIPERJIAPWEIO**
- Week JSON has been prepared, yoink the Altronix Engine ways. But it's not complete. Sh88 it's long overdue and Psych had taken everything to this day at this point! Or still it?
- Komsel Stage. Perspectived the floor & aleviated potential `69` in the back mural. Sorry, but this stage is supposed to be a sacred room. Ruang Maha Kudus.
- Replaced Volume Up & Down sound in the sound tray, with Girlfriend bloop & beep. Have fun poking at it lmao. ref [here](https://api.haxeflixel.com/flixel/system/ui/FlxSoundTray.html), you can replace the sound for respective volume up & down to play with your own sound in the asset folder. Check `Game.hx`, `function create(_)` I overrode. One day if you want, I'll create an interface where you can pick your own... 😏 you know..
- add Aseprite Atlas JSON support for character. But still f8888 you Aseprite & your closest benefactors for betraying us all.
- Just kidding, only f888 you just Mr. Aseprite that's all. And other particular traitor masterminds, and nothing else.
- add XML Atlas if anybody would like to, idk who.
- about completed the CPR fetish heart organ idk not tested yet.
- DialogueBox typo fixes
- Proceduralized **FINALLY AT LAST**, Qmoveph space background for title screen.
- Fixed crashdump faile to save
- Prepared a new operational procedure according to Last Funkin Moment contract.
- New Modchart auto called function: `gameOver` for when Blueballed, `gameOverAnimationFinished` for when blueball animation finished, & `endGameOver` for when you press enter to retry. All has argument `blueballs` which hands over how many you blueballed / failed in this level. Not working yet, we have to remove scronch order in `PlayState` when game over and move it to when you either *press enter to retry*, or *quit* first!
- attempted to fix keep asking restart song even did not touch any option that need restart song. I placed that triggerer on `new()` of one of the option item lmao. now got rid of it. let us know if it still ask you restart in option whatever no reason.
- Add Change Main menu music. Hardcoded for now, mod support to be added.
- **NEW & VERY NEW** Lyric on bottom left corner of the screen!!! You can now enjoy Funkin' like it's a KPop TV show cool and good yey! Best also, **You can reference from `subtitle.tsv` from your Polymod Core locale folders too!!** So you can have the lyric refers to whatever language gamer picked, simply by prefixing with `$` and flag ID such as `$YOUR_SUBTITLE_WORD_HERE_NO_1234` WOW!! If you don't want have translatable lyric, you can just say the words directly like usual without `$` sign. Subtitle that refers to not exist will return the flag ID itself.
- **This also goes for Dialogue too**
- **as well as intro text**. Again, these spoken dialog in game, `subtitle.tsv` in each language.
- Update list of Noteskin selection option. No longer requires filesystemer (except maybe the XML Atlas pre-caching, we're still figuring out how to get it as raw text through OpenFl asset)! All platforms is possible to render to can have it!
- **FINALLY**, got this Hurt note forget where this from, but let's say.... https://github.com/Kade-github/trickster here, that full believe this hurt note originate all from here. Left the `never` notes. https://github.com/Kade-github/trickster/blob/master/assets/clown/images/NOTE_fire.png wait no, that's not correct?! argh peck!!!
- Stepmania songs now loads through BulbyVR's way of FNF assetings ala Modding+ I yoinked couple years back. [here source code about it](https://github.com/FunkinModdingPlus/ModdingPlus)
- Refocusing during VideoCustcener no longer auto-resumes the video. **Press P to unpause** OR **hold Enter to skip**!
- Attempted to Just save in Charting state
- Installed another Qmoveph background to the Story Mode menu
- Flash now should use MP3 file instead. wait we cannot render swf anyway..
- After loading, the music fades out
- Napoleon on crash screen. [There's nothing we can do](https://knowyourmeme.com/memes/napoleon-there-is-nothing-we-can-do).
- **Default resolution is now ~~4K UHD~~ 1080p**. But not the actual game resolution. That is still to be worked on later.
- other bugfix
- etc.
- pls come back to Tebenge after all this & reshoot. [This thing](https://play.google.com/store/apps/details?id=com.Perkedel.tebenge). Be aware, this is not working intentionally by Google in latest Android version. we are working on updates! [Pls commission](https://ko-fi.com/joelwindows7/goal?g=0)! Little things! Donate message `PLS_CONVERT_TO_BLENDER` followed with image Sauce URL or text prompt, we'll make Blender scene for it with just anything we had. **Hand crafted like Royce, no AI**, therefore has soul even it's trash. You can then use it for your own FNF mods, just credit pls. **any amount welcome**
- Pls lah, the [Checkpoint.cc](https://checkpoint.cc) is platform for mod commission. I originally don't want to commission to big, so this jank should suffice! And it can't be here just yet, coz it's too small!
- C'mon, $1 all things uncensored for all gamers! You pay me, I make it. I publish it, all uncensored. And it's way too cheaper than neighbours!
- Look, I cannot make quality commission, I am not keen at this! But not only it got souls, your friends can have it to. In fact you're not allowed to exclusive privately!
- Okay fine, $0 commission! just send me DM with above prefix `PLS_CONVERT_TO_BLENDER` if you really insist. at JOELwindows7, Discord. But catch is even I do it $0, I'll procrastinate. Can't go lower than that! Want me to unprocrastinate, send me the same donate message. Good deal?
- What?! no! DO you not understand how much I envy those people that got 3D model while we're not having it? That's all the business I could do. All public!
- You know what, pick other commissioner. Want it private allowed, and/or no soul but AI, you call. I am poor man! My parent's gonna retire soon and I'll have no money at all. This is so embarrassing that my sister had made so much more with her commissionings.
- Oh, you're into MIDI? you got your FNF MIDI? use `PLS_IMPROVE_MIDI` in donation message, and I'll improve it to play well on S-YXG2006LE. See how poor I am? **Yamaha Genos costs $6000!!!** I can't go to PSR-SX, that's still way too inferior! Hey, at least I attempted to untrash the sound of the MIDI file!
- **DO NOT & NEVER LOSE YOUR WORKED WITH HEART FNF MODS & OTHER PRECIOUS FILES!** Go BackBlaze now https://secure.backblaze.com/r/03hzy9 iyey. Unlimited Backup! Starts from $9/month, or **straight ahead 2 years at once!**
- The Saorfa Hotel is WIP. The reason that we build this is because we had ever to stay 1 person. It was really hassle & we could not provide adequate enough comfort for her. yeah, the IONIQ Sky, ring the bell? good. Now it will be here to stay people for special occassions, especially lore and life safety related. There's not much facility & it's intended, to help participant focus on the main issues occured during the event. But we are open for more opportunity & feature request if desired. Remember, Saorfa Hotel is meant only for emergency temporary living, not amusement stay. We hope that is has not has to be used for amusement stay at all, because of apocalypse of sort where all realms were harrassed and destroyed something2.

#

## Info

There are serveral new stuff coming out as the days go.

PLS LINK NEW SOURCE CODE!

## Lore: Incondusive

### Begin

#### Wakturia, Dasandim

(everyone already sat on their table)

Gyouter Embinosa: (walk from enter door to front stage).. .. . . . . .. . . ., (put phone in mimbar), (grab mic close to mouth).. (turn on mic). uhh, Ahei Dasandimian. Good morning.

Latsufir: ... Morning!

Gyouter: (glaze towards Latsufir & thought the dangers already exposed to over the past few months).... So, uh.. Welcome back to physical session again. I'm sorry that you have to come physically this time. We have received order from Kaorfa last week ago, that...

Latsufir Umnaga: ...

Gyouter: We're going to graduate some of you folks.

*everyone*: (complains)!!!!!!!!

Gyouter: Yea yea yea, I know know, you don't like this. Me too! But.. uhh that's for you people, who.. monitors the conditions in here. I have no idea that you still have assignment in outside this office, even outside job time, coz guess what, you are alot, you love what you doing, and that's cool and good. And by that I mean, (breath mouth in)... You see.. No! No you see. (breath mouth in again)sssff, mmmm, you folks ever been gagged, blocked, any harm you got while you're doing your extra assignment or internal assignment..

*some*: (raise hand)

Gyouter: Yeah, I see you all, uh (raise) me too.

Latsufir: (raise hand)!

Gyouter: We cannot do this everyday anymore. It was really fun, when our enemies got infuriated, and threat us. That gives us this... what is it?.. the motivating sensation, making us wants to further torture them, to exhaustion. Until they give up, and release everything they held hostage, so we can spread it all to all gamers across galaxies. No. Unfortunately it's different anymore. Nothing like used to be. Nowadays, the threat, same threat.. but.. it will.. (nchap) also, (nchap) uh.. hit other innocents that had nothing to do with us. I can feel it, no proof, but I can feel that this could happen. No we can't have that. They should only hit us, and that's the rule of the game. NOoo, they knew now, they evolved. not only getting smarter, but.. got more tricks generated under their sleeves. Look at those people that would have to die in vain, only because we want to tell the truth to all gamers across the galaxies. It's awry. very awry.

*everyone*: (sobs) 😢....

Gyouter: So now, we're graduating some, very many. other branch of Wakturia have been closed, all of them around Sloantim, we're the only one left. ANd now some of you has to go.

Malore: When?!

Gyouter: Now. Today. Pls, take the graduations. the vote still ongoing, those who still graduate or wants to go now, please stand up.

*some*: (start stand up)..

Gyouter: Okay good. Note, it must leave only 30 actives in this role as the result, no less. (sit down in mimbar hair).

*some*: (more stand ups)!!

....

Gyouter: Yes! Okay..

....

Gyouter: Keep going, until we left 30.

....

........

...

..

...

..

.

Gyouter: Okay, is that all?

Neshim M'neer: We will left 36.

Gyouter: 36, okay. who's left? (saw Latsufir & Sky)... Latsufir?

Latsufir: Yes?

Gyouter: You don't want to.. resign?

Latsufir: ...

Gyouter: I know you're confused. But you're the most precious person here, for you have been giving us alot of ideas back then.

Latsufir: I mean, who's going to give idea then?

Gyouter: I'm sorry but... No no, you can stay if you want, but I can't bare to see you being risked to a deadly hallows whereever missions go. No, you're like my *only child*. Not to mention, (see Sky)..

Sky: Huh? ...

Gyouter: We're not going to have idea anymore. The shift of this entire alliance is now moved
 towards... **replications**. We are now only going to reinstance whatever we saw outside, across the multiverse. And I believe that, it only takes... redrawing. less of an idea and strategies. We are not going to depend on the company that hold every multiverse. it's going to be fully our own story.

Latsufir: Okay..

Gyouter: No, I do not want to say that you're useless now, who said that?, I just.. can't bare if I have to lose *my children* one by one, and other innocents one by one. You remember when you almost got murdered by Obul there? He's the most dangerous person ever.

Latsufir: ... ... Well, I have life. (stand up)

Sky: (Stand up).

Gyouter: (look back towards everyone)...

*everyone*: (follow up stand up bit by bit)...

Gyouter: Okay. (find chair on his left) I wish I can also get out. But, I still have contract here.. (sitt)., That's to... ... mch, Do you really wanna know? bet you don't wanna know, coz you can guess. ...

(camera view overall)...

Gyouter: ....... Now, thank you for your service....., the final check will soon be processed, delivered to your house, and your wallet. ..., As usual, `Wakturia`, that public ID.........

*everyone*: (listening carefully).....

Gyouter: (look around the room)....

Jonathan Podosheryen: (come to Gyouter & notify) Sir, the stand ups have been listed. The graduation is processing.

Gyouter: Okay. Good.

Jonathan: .. Wish you great luck man, (pat worryful)! ! !.

Gyouter: It's alright. I can do this. I hope... ... (rember the data already processed but everyone still stood up) Oh!, you can sit now.

*everyone*: (sitt)!!..

Gyouter: No job today. Well then. Speaking about preservation, uhh... Think I... gonna... save it here, (create memo to employee)....., (save). Kay, read it when you're home. Now, even if you have been graduated, there's still one job left to do, and we expect you come. the next memo about will appear soon. Read & save as soon you receive it, okay? No no, just.. come. It's to uh... pay respect one last time. Because you know, We are still waiting for the Full Ass to come. Be patient, I am still hopeful they come. And I hope you still remember that, when it comes, we stop. Go to the place we have set, say goodbye to these people at hand, and the.. cleaner will port everything up, etc etc etc. Just like that!

*everyone*: (mumble 2 second) ye ye.....

Gyouter: Any question?

...

...

...

...

Gyouter: Wow, no question? Latsufir?

Latsufir: ......

Gyouter: Okay, If you want to keep Sky, who's going to stop you? Well, that's what you would ask?

Latsufir: Oh yeah..

Gyouter: Yeah, that. Now. ...  .... that's it. Class dismissed. Remember, read all notes, come back when we tell you **immediately to the spot** when Full Ass comes, and that's all, you're free to be lost somewhere. Yeah. sss.. yeah.

*everyone*: (start packing up & go home)!!

Gyouter: Okay, just be slow, there's no rush here, the... Full Ass.. will come.. *shortly*.. I hope.. yeah..

*everyone*: (still packing and bring home)....

Gyouter: Right..

### Handovers

#### Salt flat world

Latsufir: (read the memo) What??

Sky: (also read her phone) Oh..

Latsufir: Ummm.. You got any idea why is that?

Sky: Wasn't that about the ***preservation*** thingy?

Latsufir: Oh yeah..

> We sold Last Funkin Moment to X0p1r4t3 Eenvreensment.  
> (Gyouter)

Sky: I felt rumor that Kaorfa is about to yoink not just some functions but also... properties too.

Latsufir: is that so?

Sky: idk, just a rumor.

#### Logistic Area, X0p1r4t3 Eenvreensment

Roig Hermalansa: Hey, be careful boys. If you break that we're going to lose it all. I mean, we have a copy here, but it's never a guarantee.

Info: 2 strong men moving the [heavy crate](https://github.com/Perkedel/Perkedel-Minecraft-Java-World ) from a truck into this smaller carriage. 2 pallete hand forklift on each opposing end due to how heavy this is. Truck wheel is as ground level as the smaller carriage, container bed lined up together, with adjusting the smaller carriage container bed height, as the truck does not have adjustable bed height.

Duduk Segar: (grunt pulling) UUUUUUUUUGHH.......

Alam Segar: You can do this brother, (grunt pushing) HEUYYYYYYYYYYY....

Info: the standard forklift car is ironically broke, the hydraulic pump is, because the crate is too heavy & the car is way too old.

Besek: (done fixed the pump) Okay! try again.

Fufus: (try lift the fork)....

(back tank exploded) (async) DUAR 💥💥💥💥💥💥💥💥!!!!!

Fufus: (async) HEUAAA!!!! ... What??

Besek: 🤦🤦🤦🤦🤦🤦🤦🤦 Argh...

Duduk: (both finished ) DOOOOOOOOOOOONE!!!!!!!!!!!!!!!!!!! (relieve) HOOoooh... (realize there is one more [heavy crate](https://github.com/Perkedel/bla-bla-mcpe ) in the truck) Wait..

Alam: (stress again)....

Gyouter: Hey.

Roig: Oh, excuse me. (look Gyouter), Sir??

Gyouter: You got.. time?

Roig: Yes sir. What can I do?

Gyouter: Nothing just.. umm.. (point to his truck) that one.

Roig: Okay? (look at the truck)..., (open).... (saw crate) Is that?

Gyouter: Hm.

Roig: What's this?

Gyouter: (telepathy).

Roig: Wait? [That package](https://github.com/Perkedel/Kaded-fnf-mods )??? But..

Gyouter: I'm sorry, we've been *slackelini* over the past few months. We suddenly got, unexpected stagnancy. Apparently Kaorfa was been.... digging some monet, you know, he got none, so he's desperate.

Roig: mm.. You told Admiral about this?

Gyouter: I did. Last week. And he okay, take it.

Roig: Oh okay. ..

Gyouter: Tell Zumi. Take care of this well. He can do anything with it to add stuffs into it. I gotta job to do, and apparently it's no longer close to [that one](https://github.com/Perkedel/Kaded-fnf-mods ).

Roig: Yes sir. I'll hand these over. You sure about this? What if they know about this? Weren't you supposed to handle this?

Gyouter: Don't worry. I hope it's fine. And.. Kaorfa had trouble, he couldn't handle this anymore now. Now it's your turn to ***preserve*** this, while I gotta help Kaorfa fight for other stuffs.

Roig: Yeah yeah. And next, do you still know, Conservationist hates sparsdators like us? The mod creators in your sector you've been working on are nototorious being Conversationist. If one of them knew, they'll take down your mod.

Gyouter: I know. ... But you know who else can we trust?

(camera view far overall scene).......

Roig: Dang.... .... uh.. nobody.. Is there the backup in other planet?

Gyouter: Kaorfa has also ordered shutdown to all branches. Now it's only us. There is a change in the management.

Roig: (remember speaking about the change) To the... (look down) harrassment eradications.... (look back up to Gyouter)!..

Gyouter: Please. We beg you. You're the only one that can be trusted, to keep this file, while we're moving to fight harrassment around the universe.

Roig: Yes.

Gyouter: see you later, (go back to left passenger seat of the truck), (open door), (ride up), (sitt), (close door)!!, (attach seatbelt), (contemplate for the next battle)...

Duduk: (did lifted up the Last Funkin Moment crate) Hey this crate is light!!

Alam: 😊

### Changes in Management. The Next day

#### Back to Wakturia command center

Info: There is Query, Mistletoe, and.. oh that's it. there should be others but they aren't yet processed.

Gyouter: (preparing mimbar)....

Query Sandros Ambasador: Hoo hoo hoo, I'm excited! Tell us now! what do we do here?

Gyouter: No, we're not doing here. You'll have new place... (still finding the briefing file).... damn where the.. Ah, here, (open file)! Okay. So.. We are establishing an initiative.

Query: Okay, listening!

Gyouter: Right.

> Over the past few years there has been tremendous numbers of case of harrassment campaigns targeted towards innocent creators.  
> Reasons ranges from plain random to rather specific hatreds towards issues beyond anyone's perceptions.  
> Here, the purpose of the initiative to band together across the galaxies and help each other pin point who criminals that are confirmed a harrasser, active, and inactive that did causes terribly fatal losses both quanity & quality.  
> The scope of this initiative shall focus only towards these harrassers, unless otherwise noted.  
> Citizens are welcome to contribute every intels as much as possible that lead to the capture of those harrassers.

Gyouter: Aand so on. You got the copy in your hand. Read it. Any question?

Misteltoe Ambasador: (could not find place in this document) 🙋‍♂️ Question please.

Gyouter: Yes.

Mistletoe: I fail to find the place. Know where is it? did you have intel?

Gyouter: Oh yeah, the document was writter 2 months ago before we got the place. Now I got it, see memo, it's........ **Sorrow City**.

Query: OH BACK TO MY HOME YEYY!!!

Mistletoe: Also, you going to lead this initiative??

Gyouter: Sorry, but I can't. that's beyond my scope here. I'll watch the timeline. So the leader is... You. Query.

Query: (excited) MEEEEEEE??!?!?!... (pogchamp to back)!??!!!???!!??

Mistletoe: Well congratulations. But it won't be easy

Query: Oh.. (nodding) yeah.. okay.. I know. (stop nodding). (turn head slowly back to front again)....., What do I do?

Gyouter: Lead your people. Tell them the mission, and foster your people, both in mission and break time. Now uh..

(camera zoom out overall scene)

Gyouter: Just you two?

Mistletoe: Yes?

Gyouter: That's intentional for Dasandim node. Aaand, you, will have special guest. We have special guest.

Query: 😀 Oh yeah?!

Gyouter: That's right. You gotta thancc Kaorfa for this. Coz he brought just for you, gamers, your old friend you always see them as fictional, now real.

Query: Oh.. Who are they? there's alotta show gone real. What is it this time?

Gyouter: (telepathy `Homestuck`)...

Query: Whoah... Yoo..... Really?! TODAY?!??!?

Gyouter: Today.

Query: **WOOOOOOOOOOOOOOOOOOOOOOOOOOO!!!!!!!!!!!** Oh my God... Ain't no pecking **WAAAY**!!

Mistletoe: Oh.. I think we need to buy Terezi blind cane

Gyouter: No need, no need. They have been cured. All of them.

Query: (even more excited)!?!??!?!

Mistletoe: Well, then no extra pay. Great haha.. hmm wonder how they look like..

Gyouter: Just like normal. Although because they've just cured, it'll take some time for the alternate habits to vanish first. Don't be surprised if Terezi still tapping around. She can see, but her habit still in place. ... (realization, Terezi was later cured canon in official Homestuck).. Oh wait, I just realized.

Mistletoe: Yes, no more Xavier wheelchair needed. God, that'd be expensive if we had to, whew.

Gyouter: YEah, yeah, yeah. Tavros can stand. there we got it. Vriska got left eye and side pupils cured, all etc.

Query: We're going to have homestuck mates guys!!! (asnyc) (give Mistletoe five)!!!

Mistletoe: (async) (receive five)!!! .... Wait, is it only us here?

(camera zoom out overall until)

Mistletoe: Hello? ...

(stop zoom overall)

Gyouter: Well uh.. Let's say uh..

### Reject join. Family Guy cutaway

Trooks: Bulls888! Not going to touch this topic again after what they did to me.

Fezer Rumag: You can just be a citizen. If you find any hints of harrasser, upload the picture and the location and all data to us.

Trooks: (look sharp to Fezer)???.... Okay, fine. If I got hurt, you're responsible. Other than that, (open portal)!! Thanks but no. (enter), (close)!!

Fezer: hmm...

### Return back again to scene

Mistletoe: Welp. But atleast we got gamers.

Gyouter: I hope. But the fear of reporting is still present, that's the issue. Which is why we ask some gamers to join. aaand, did not believe our super protection law & physical in sorrow city. Yeah.

Mistletoe: Maybe we should one day open up tour for all gamers across galaxies. Won't hurt I guess.

Gyouter: Good idea. For now though, we're going to do the mission. The homestuck people will come shortly to your home city. Get to know them, great luck, and God bless you.

Query: Oooo yeah!! Awesome!!!

Gyouter: Oh would you like to open portal after that door? We start now. I want you safe.

Mistletoe: Sure, go ahead!

Gyouter: Alright, (open portal to their home, upon the command center big door)!! Okay, Great luck and God bless you.

Query: Let's goo!!! Wait, where exactly my job?

Gyouter: Downstreet, in the Police department. That department is now the Interpol. Intergalactic police.

Query: oooOOOOOOooo...

Gyouter: Okay.

Mistletoe: C'mon bro let's go!

Query: Oh yeah!

#### outside command center, Basement, Wakturia

Gyouter: Okay, gamers. If you got any trouble, just contact us. I am also assigned as the support guy for this interpol initiative. Well, there's alot. I'll be handling this exclusively now, so you got issue, don't hesitate to call me up, okay?

Mistletoe: Okay!

Gyouter: Now, let's go.

Mistletoe: Thancc, sir! (enter portal)

Query: (enter portal)

Gyouter: You're welcome. ... (close)!!....... Yeah.

### End

by JOELwindows7  
Perkedel Technologies  
CC4.0-BY-SA

### Post Credit

#### in Mission Command Center of Wakturia again

Info: 2 Waturia employees watches [this video](https://youtu.be/SN_7gUbWc-I?si=n7o87KQoqvWsRokw) and began to have their opinion and ideas to do.

Fern: You see this buddy?

...

ob: Yeah, but no, wait. It's been only 3 years

Fern: Dude, that is way too

Yuob: No no no. We have to be patient. Please, One last more. I have faith, that it won't be [7 years](https://youtube.com/channel/UC83Vxn_OocpztpDIQvvlk_w?si=w-VNxiitKaNgFEMD) above like. And these 3, despite speaks fouls occasionally, they are not... you got the idea.

(delay)......

Fern: Whatever it is. `Promise`, is (inherits from class) `Surprise`. We get the `Thing` or `Null`. The `Null`, is what you should've been skeptical for. Not to mention they gonna paywall this project!

Yuob: (sigh) ugh.......... (confused & contemplate).................................. H--alright. What do we propose to do?

Fern: I say we record one of the final rehearsal this year. Next Monday, they'll have one last rehearsal before moving on temporarily. I want you..., no we..., to record. **Spatially**. We got Holocorder here?

Brent: We have! Right?

Jonathan: (show big briefcase containing the 3D hologram video recording equipments)..

Fern: (look bottom right of taskbar) Day's... Saturday. We're going to prepare up for the next week this monday. Don't forget.

Info: This computer has KDE Plasma Desktop.

Yuob: Okay. Then we shall.

#### Studio City, Dasandim. Monday

Info: Wakturia Last Funkin crews are doing final clean rehearsal as it is live. This time they are on Green Screen house 45. It is wide enough for the actual scene one day in the Edge of the Universe. Props has been prepared replicating the ship that carries the crew, alongside small props representing the items for the Full Ass bye bye ceremony. Yuon, Fern, & Brent have prepared the Holocorder to record Gyouter & friends doing rehearsal. Since it is recorded for too long didn't release just in case backup, they crews have been instructed to play the role as it is the real ceremony. crews are sitting on their electric wheelchair to symbolize paralyzations after all the wars they encounter against the community in FNF modding scenes.

Rara Eriald (Directorm, female): Okay, gamers. We have final rehearsal once and for all. This time, you have to do it real because we are recording it for Hologram. Think it's like pre-recording for iPhone launch WWDC something. I'm sorry, but blame Fern. He suggested me this because he's skeptical uh.. Friday Night Funkin' Full Ass gone scam once again, I don't know.

Gyouter: Fern?

Fern: No.. but... you got the idea. Damn, Rara. you're too harsh. But eh.. Hear me up. We all have been exposed to delays in our life here in Wakturia. But it has been my attention, and that should you, these days, when people promises stuff, the frequency of us getting `null` has gone up significantly. You should've been skeptical, because `Promise` is either `Thing` or `null`. `Promise` is `Surprise`. ...

Gyouter: Thank you. Is there anything I have to note for, for this?

Fern: Nothing else. Do it like you're going to launch an iPhone. ... or maybe Fairphone in Dasandim.

Gyouter: Heu eum...

Fern: I know, you should come, but uhhh you're not going to live forever just to wait whether or not it's going real or not. Heck gonna coffin it?

*everyone*: XD🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣🤣

Fern: See? That's dark. So that's it. just Holo it. Put it there and forget. Real or not, noone should care anymore, let that machine do it. Now be real!, you're launching Full Ass in Fairphone Framework Sustainability Conference Odysee live something2 who know.

Gyouter: Okay, do it real. Folks?

*everyone*: yeah?

Gyouter: You ready?.

Fern: Okay.... (right index in red record button) I'm going to start......., (press) Action!..

### Simulated goodbye

#### Edge of the Universe

Info: some details are intentionally ommited to point out this pre-recording.

(Ship landing).................. (landed)

(open butt hatch)!!......................(hatch touchdown).

Gyouter: (slowly walk wheelchair out of the ship).........

*everyone*: (follow)......

Info: Everyone run their wheelchair to the spot.

Gyouter: (stop at the spot before the Boyfriend and friends)!!.

*everyone*: (stop too right behind Gyouter)!!

(zoom out overall scene)............ (back again)

Gyouter: (turn left back straight again to the lake)..

*everyone*: (follow)

Info: No crew is allowed to stand off from chair.

Gyouter: (open gift box)

Info: The wall then collapse outward gracefully.

*everyone*: (go to the lake next by Gyouter & open up their gift box)!

Gyouter: (take lilypadded flower out of its giftbox floor)......, (put above the lake water but keep holding it).

*everyone*: (follow).....

Info: As the are crouching down, the crew must keep their legs remain on contact with the chair footrests

Gyouter: ........... (release)..

*everyone*: (also release)....

Info: The Lantern Flower flows away from the crews beautifully, sail over towards the wall of the Universe.

Gyouter: (sit back to the chair)..

*everyone*: (also return to chair)!

Gyouter: (turn around & return fast back to ship)....

*everyone*: (follow)....

Info: Everyone has returned to ship

(close butt hatch)........... (closed)

(turn on & take off)!!.......!!...................

....

...

...

Fern: Aaaand cut, (press record to stop), thank you!

### End of Simulation

*everyone*: YEAAAAAYYYY!!!

Fern: Okay, Just need a little editing, and we're going.

#### Actual Edge of the Universe

Info: The system has been permanently installed. There are 2 Hologram projectors. one on left is the crew, and on the center is your final week gameplay. As well as the ceremonial Lilypadded flower releasing contraption on the lake, where its event triggers at certain timestamp accordingly. The scene has been oxygenated for this preparation and will be again if there is live available, so no suit needed.

Fern: (finishing up lilypad release).... Okay, (test)!

Info: The flower flows away.

Fern: Good! (take another lilypadded flower), (put on the catch & reset the catch release). Right, .. (heard electrocution)?? (it's the center hologram) Heoh!! (hastily runs towards) NO no no no no no!!!

Info: Too late, the Lamp blew due to overheat.

Fern: Argh!!..., (unscrew & open lamp compartment), (take off burnt lamp but too hot) AARRGH!!, (equip glove), (try again lamp), (collect the burnt lamp), (take off cooling fan), (take battery & test the fan)...

Info: The cooling fan has been failed

Fern: (collect the failed fan), (open up new fan), (reinstall), (open up new lamp), (reinstall), (spray with perma-cool)!!!!!!, (close compartment & screw back in), (spray again with perma-cool)!!!. (test again)!

Info: It's on again.

Fern: (turn off & re-run receiving mode). Okayh.. Well. I hope it works. Right.. Wooh.. ... ... .. ... .. Who cares? ... Idk anymore. I wouldn't see these on either, idk. ... Welp. (tidy up self) Time to go.

### Post Credit Finished

yey
