![](https://github.com/Perkedel/After-Church/raw/master/RAW%20files/Inkscape/Week%20Strong/week-2021.11-thumb.png )

pls change image & fill new infos!
# Download Updated
- [Linux](https://odysee.com/@JOELwindows7/last-funkin-moments )
- ~~[Linux 32 bit](https://odysee.com/@JOELwindows7/last-funkin-moments-32bit )~~
- [Windows](https://odysee.com/@JOELwindows7/last-funkin-moments-windows )
- [Windows 32 bit](https://odysee.com/@JOELwindows7/last-funkin-moments-windows32 )
- [macOS](https://odysee.com/@JOELwindows7:a/last-funkin-moments-macOS )
- [Android](https://odysee.com/@JOELwindows7:a/last-funkin-moments-android)
- [itch.io (Play Online now)](https://joelwindows7.itch.io/last-funkin-moments )
- [GameBanana](https://gamebanana.com/mods/293257 )
- [GameJolt (Play Online now)](https://gamejolt.com/games/last-funkin-moments/634559 )
- [NexusMods](https://www.nexusmods.com/fridaynightfunkin/mods/247 )
- [GitHub](https://github.com/Perkedel/Kaded-fnf-mods )
- [GitHub of AfterChurch, the SVG files](https://github.com/Perkedel/After-Church/tree/master/RAW%20files/Inkscape/Week%20Strong )

# NEWESTED Kade Engine 1.8 yuss
but unfortunately, Kade quit FNF modding. and uh. his [twitter](https://twitter.com/KadeDeveloper) has been suspended 😭. Warm and bad!

# Changes
- Enhance the `_meta.json` capabilities yey!
- Conduct experiments
- FALLBACK OFFSET! if your character isn't the one specified, it will then go back to default fallback per stage rather than letting it unset. HAHA PER STAGE CHARACTER OFFSET GO **!!!!BRRRR** wait why `!!!!` are on the other side lol!
- reinstall our custom options into that new Kade's option menu + optimization to get this all work correctly at least
- Update GameJolter https://github.com/TentaRJ/GameJolt-FNF-Integration . Now features Toast message whoahow!!!
- Update MP4 VLC https://github.com/brightfyregit/Friday-Night-Funkin-Mp4-Video-Support
- **FINALLY FIGURED OUT HOW TO SMOOTHLY CHANGE WEEK COLOR & FREEPLAY COLOR JUST LIKE HD & VANILLA TANKMAN WHOAHOW!!!**
- DialogueBox character name! Now each character in turn of speaking has name on the prefix! yay see https://github.com/HaxeFlixel/flixel-demos/blob/master/UserInterface/FlxTypeText/source/MenuState.hx & https://haxeflixel.com/demos/FlxTypeText/
- This also means that character will have On screen readable name rather than recycling ID, because different IDs may means different version of character with the same name. yes, `var name:String`. Also finally using `name` variable in that JSON to copy that over this brand new `name` Haxe variable woohoo! thancc Eric. yey. Kade & friend prepared this already lol!
- Wait! use `displayName:String` instead if you want to show actual name on screen. the `name:String` already has variation name in it!
- Use FlxTween.Color instead to change color idk anymore. see https://github.com/HaxeFlixel/flixel-demos/blob/master/Effects/FlxTween/source/PlayState.hx & https://haxeflixel.com/demos/FlxTween/. you can have Color tween! there's more! Angle and stuffs!
- This means you can set how long this color change from former to the new one. try 0 and it goes to there instantly, I guess. as Always the modchart function both HaxeScript & Lua has been updated to have this. argument `InHowLong:Float` yess.
- Manually download all JSONed Character datas now https://github.com/KadeDev/Kade-Engine/tree/master/assets/preload/data/characters because unfortunately again, Kade quit FNF mod & communities, except Week 7 coming. [oh God](https://gamebanana.com/mods/44291?post=9638622 ).
- (IDEA PROPOSE) Should we remove `Kade Engine` branding? because that always become opportunity for toxicities, so rewent it as `Last Funkin Moments engine` of some sort. I chose `NO`. what about you?
- Proposing to obsolette the JSONed Week list. 
- Yeah I love but.. the.. the mod, Modcore. The Appender seems to only support adding new line at the end of the file. well, JSON does has `}` always at the end of the line. this won't work that easy then. you have to know how to sneak the modline into it above that `}` not to mention the complexity of JSON it could be. Yeah basically you will append JSON data through special command. idk man. just make it simple, less screw up and that's it I guess.
- First Kade had `weekNames.txt`. and also week counter. wait, how? basically uh later.
- uh..
- now we have 
- `weekStuffs.txt` to adjust the week display. the characters in it & color
- `weekLoads.txt` which each lines represents how many songs in that week. 
- basically it. yeah idk. will discuss this later.
- No more invisiblize health icon after song finish. the layer issue has since already been fixed.
- **Changed the way week loads**. Now use the Text file based. there are NEW `weekStuffs.txt` for LCD display, & `weekLoads.txt` for what songs in that week each line. simple. this should also make ModCore appending also easier yeah! idk should let people go back to Amalgamated JSON we previously had? First I don't want anymore because it's hard to append.
- (PROPOSE) But thankfully, ShadowMario gave us idea how about making it [granularized](https://github.com/ShadowMario/FNF-PsychEngine/tree/main/assets/preload/weeks ). Yeah each week is its own JSON file. the list & order of the weekID / filename JSON are put into the `weekList.txt`. Well it's just proposal, not working yet. Psych's week parameter has another stuffs to it, idk which one could be essential and not, idk. SO yeah maybe later.
- NEW!!! Week Click Sound. You can change the sound when a story week menu is clicked yey!
- attempted to fix Colorable FlxSprite. using color tweener yey!
- unbreak result touchscreen & mouseoid
- Auto Pause just add whatever you can in VLC finally!
- Shake camera event!
- Replaced Background gameplay video thingy with VLC for pecking finally
- okay what else?
- (Kade) Kade Engine v1.8! changelog [here](https://github.com/KadeDev/Kade-Engine/blob/stable/docs/changelogs/changelog-1.8.md )
- (Kade) Newested option menu
- (Kade) Asset replacing mods support
- (Kade) Adjust Lane transparency
- (Kade) Change noteskin in option menu
- (Kade) Circle Noteskin
- (Kade) `R` in freeplay to reset rate
- (Kade) New FPS Counter
- (Kade) New Animation debug screen
- (Kade) On Window Focus Lost detection!!! No need to freeze while out of focus. Just tell it to pause gameplay when that happens.
- what else?

# Previous Lores
- lbry://@JOELwindows7#a/lfm-lore-2021.06#b
- lbry://@JOELwindows7#a/lfm-lore-2021.07#1
- lbry://@JOELwindows7#a/lfm-lore-2021.08#f
- lbry://@JOELwindows7#a/lfm-lore-2021.10#b

# (LORE) A Dreadful Day
## Tomhamos long sand beach, Texcity, Dasandim
Gyouter Embinosa: (sleep on the beach lie-down chair)

Denosa Hatchener: babe! tea lunch time's ready!

Gyouter: (awake) Oh yeah, hold on. (go back inside hut house)... Right.

Denosa: Here's your favourite tea, my dear!

Gyouter: Oh yess! Coronation Strawberry, my favourite. (drincc immediately one shot full slurp)!!! ahhh! (put tea glass a bit abrupt). (burp)!!! Ouf, pardon me. Does this tea has gas on it?

Denosa: um... Carbon Dioxide 5%, to attract and hold vitamin C.

Gyouter: huh, that explains it. What is that again?

Denosa: Coronation Hungery, Strawberry flavour.

Gyouter: wow, SDEXM kept making new teas these days. Even the one that fills the hunger?

Denosa: yup.

Gyouter: wow, impressive. I gotta know how do they achieve that.

(Gyouter's phone ring)!!

Gyouter: excuse me. (go towards phone), (pickup)!, Hello, Gyouter from Wakturia. what can I help you?

Yume Kamerline (female): uhh... help!

Gyouter: Yume, what's going on?

Yume: Saubo wants to go out!

Gyouter: UH OH..

## Wakturia HQ. Earlier
(Yume is doing her cleaning task, enter the item storage room next by after mission command center to the right)

Saubo (redacted name for safety reason. Protoglin Amexamlef): (finally go back to her appartment) Oh, is this it? is this working? (MOMENT SYNC) WOOHOO!!!!!..... oh..

Yume: (ASYNC) Alright, (evaluate hygene level in this room).. (activate flying), (inspect).. (MOMENT SYNC) (saw somebody) 😮!?

Saubo: uh... who are you?

Yume: I am... Yume. the.. ththe Janitor.

Saubo: What's going on?

Yume: Nothing. I just want to clean this room..

Saubo: Where's everybody?

Yume: Everybody was on vaca

Saubo: Where's the appartment?

Yume: uh, your appartment cell moved here. the appartment building over there still fine.

Saubo: ... Where am I?

Yume: You are in Wakturia. Where we watch & guards the flow of the time, moments, and happenings, in real time.

Saubo: Okay, is there an exit?

Yume: Oh yess. wai wait. Are you sure? it might not be safe right now. So, I shall call guards to accompany you, shall we?

Saubo: Okay.

Yume: (go down immediately) whew, okay. Oh no. (go outside of command center and stop just by beside entry way)! Oh no, she's going out! she wants to out!! uh, uh, oh yess! (call Gyouter)

(and so Gyouter picked up and the continue goes now)

## Communicationing
Gyouter: Alright. Don't panic. wait here. don't move. (call front door security)..

Lissmey Urun: (pick up phone)! Lisssmey, front door..

Gyouter: Hey, uh. Somebody we just rescued yesterweek wants to go out, and... she is a vulnerable target.

Lissmey: Oh okay, so you want me to deploy virtual world?

Gyouter: Unfortunately, yes. I'm sorry.

Lissmey: Uh, I don't like this.

Gyouter: I know! I know. We have no choice! the appartment cell owner suddenly came back, and she is being a target my millions of bad guys!

Lissmey: Okey, right away (start taking virtual world portal from the box just underneath the floor mat. (install the portal)! Charging up. ... Okay, it's ready.

Gyouter: Great! keep your eye on her, both your premise & outside the dome. She has blue hair with red checkmark white shirt & blue pants, or skirt idk.

Lissmey: Alright. guards on.

Gyouter: great. Okay Yume, you can bring her out. (going to call the tour guide but..) Wait. all but janitors & securities are in vacation. Ah damn! Uh, Yume, I'm sorry, but you know most things in Dasandim?

Yume: Yea I do.

Gyouter: Yea great I hope so. Maybe you can accompany her to uh.. restaurant or something? Don't worry, everything is virtual, we now have virtual services too. Now, go. Lissmey, bring the body guards for someone with blue hair, white shirt, & ... blue skirt.

Yume: Okay. here we go. (go back inside the storage room).. (approach Saubo). Uh hey, you can go now. I'll be your guide to this vast planet of Dasandim. You hungry? Man! there are alots of restaurants here. you coming?

Saubo: Oh yeah, I guess. (go out but) (almost fall) whoah!!! 

Yume: Oh sorry! careful (pick up Saubo).. Okay, let's go!

(went out to the front door)

Yume: So, the restaurant. It's over there! (take out fold car from pocket), (throw to floor to right to expand)! ...(Car expanded explosively) (open front left car door) Come on in!

Saubo: Hm.. (get in the car). (close door).

Yume: Alright, (get onto the front door for it's driver side) to the restaurant yeah! (go to the restaurant)

Gyouter: Great! She should be safe for longest we can. Lissmey, close the portal. 

Lissmey: Yes, sir.

Gyouter: Yume, notify Lissmey or any front door security in shift when you're about to arrive back to Wakturia so they can reopen the portal door.

Yume: aye aye, sir!

Gyouter: Alright, if you got something, tell me. I'll see you around. (close call)! Hoof. wow. that was intensive.

Denosa: I feel pitiful about what's happening with her.

Gyouter: Yeah, me too. Most importantly, she's safe with Yume now, in the second layer dimension. No bad guys should be able to see Saubo hopefully. Alright, I want to explore something. Stay safe, my dear.

Denosa: Yea babe, careful on road! mmmwah 😘!

Gyouter: Yea dear.

# Exploring & Strolling the long sand beach
## Fraun's Bar. Preluded 20th November 2021
Thomas Henderson the spy: (go towards bar table), 1 April's Island please.

Fraun Erut: Certainly, sir.

Thomas: Oh yeah, no alcohol please.

Fraun: Of course. Well, we don't have alcohol, this is no alcohol bar.

Thomas: In case you forgot, 😉.

Fraun: Okay, 1 portion of April's Island coming right up. (prepare milkshake glass), (prepare dual cup (boston) shaker), (prepare pounder bowl & its baster), (put 5 strawberries into the bowl), (crush strawberries)..., (pour into bottom shaker cup), (pour 500 ml Lesson syrup), (pour 250 ml Rogu water), (close shaker with the other boston cup), (shakey shakey)!!!....., (open shaker), (put strainer filter on the bottom shaker), (pour into milkshake glass)... Sir, would you like to also have the strawberries?

Thomas: Oh, yeah. Except the ice.

Fraun: Siip! (take out ice, throw away), (pour the crushed strawbereries into the milkshake glass)...

Thomas: Ah! perfect!

Fraun: That'll be US$ 12.00.

Thomas: Crypto pls?

Fraun: Kivrontz (point to the payment QR poster). 12 Kvz.

Thomas: (open Dasandim ID app), (engage payment QR scan), (scan the QR on the poster)... Okay, here.. 12. (pay now)! Is it in?

Fraun: (saw the notification that it's in) Great, enjoy your drink. Have a nice day.

Thomas: Thancc. (eat strawberries), (then proceed to drink)

(3 Spreaders arrive to bar)

*Codename person A*: (sit at bar chair by the bar table) Hey, did you remember Kenny called [week 7 all trap song](https://twitter.com/cval_brown/status/1461520461058043904 )?

*Codename person B*: Jesus Christ! was he really?

Pisor Runin: What's `Kenny` he's talking?

Exurim Rodinand: Yeah, I should ask which. Stay there. What kenny? That [public domain](https://kenney.nl/ ) or uh...

Pisor: wait, that's Kenney with `ey`, not `y`

*Codename person A*: (turn head creepily)!... [wat](https://twitter.com/cval_brown/status/1461785884903288832?s=20 )

Exurim: uh south parke..

Dolim Maverick: Okay, maybe we should watch our mouth..

(expelled)!!! (fall to ground)!, (gate to realm permanently closed).

Exurim: No no nono nonononono NO!! NO! NO NO NOOOO!!! STUPID S88888 B8888 MOTHERF8888!!!, ffffF888! noooh..

Pisor: I'm sorry buddy, I

Exurim: No, it's not none of us fault. It's him.

Dolim: Whoa, he's just a kid. don't hurt him..

Exurim: So then *where's his parent*? Question is.

... ...

Dolim: Hey you wanna,,

Exurim: No tea this time. We should go back home now.

Pisor: Okay, uh what's the report then?

Exurim: Okay, (take out phone, open job app)... (share report data). And oh, **this is between us, and the boss**.

Dolim: Wise choice.

Exurim: Yeah. he's just the kid. I could've done it so now, but uh.. Forget it. Shall I face myself.

Dolim: You better not, buddy.

Exurim: (menacing stare)..

Dolim: Yeah, I hope you know that. We are not bandwagon builders.

Exurim: I know. let's go.

## Meanwhile in the bar again..
Thomas: (stared at that person A with disappointment face for its immaturity & hurting his kind's mentality, he thought) ☹️...

Fraun: (also witnessed this scene)..

Thomas: excuse me (stand up), (walk fast towards leaving the bar with really upset emotion), (slap forward the bar flexible door)!!!, (continue leaving), 

Fraun: Hey careful, the door is brittle!

Thomas: (jump & leave realm)!

## Today
Gyouter: (stroll around beach)... (saw old friend)... Exurim!!

Exurim: Huh? (saw Gyouter), Oh hi!

Gyouter: Hey, long time no see. how & where have you been?

Exurim: Oh.. yeah uhum.. It's great! I've been a good `Spreader` here. People are happy to see us sharing where things comes from. You know, Sauce these days.. are um not shared properly.

Gyouter: Great great, yess. (looked at phone, contains special authorization from boss) Hey what's that on phone?

Exurim: (continue preparing battle suit) Oh nothing. Just uh.. special mission for me, from boss. It's my idea.

Gyouter: Okay. (start getting SUS) Careful over there.

Exurim: Don't worry, I think it's time for me to excercise my other hobby once again. YEaha!!! (turn on battle suit jetpack). You kiddo, you're gonna take this. (start flying)! (Gyouter grappled right leg) Hey?

Gyouter: What did you say?

Exurim: I just said `You kiddo, you're gonna take this.`, what's wrong?!

Gyouter: (scan mind).... (found that Exurim is going to revenge by spreading blocked screenshot)

Exurim: ... Uuugh! Okay! I admit! that kid just f888888 blocked me on Twitter just because I said `Which kenny, public domain one or what` stuff like that! He thought that I am not cool guy with that so he blocked me! Was I mean it?! I don't think so! HE's litterally just another spoiled brats!!! He,... Cut my throat (larynx) **before I,... could say `I'm sorry`.!* .. 😥 (drop to ground)! (stand & crouch wrinkle wrap contemplation).

Gyouter: Okay. is he foreigner?

Exurim: Yes, from USA, Earth. presumably.

Gyouter: (already know that the kid blocked Kaorfa is one of the well known people in the community during this contract).. Okay. Here's the thing. You better not to fiddle ever again with him anymore. let it go just like usual.

Exurim: What?! Hey, We have been blocked mysteriously everyday. If the blocker is a bad guy, I'm okay with it. This,... This f888 sh88 (not meaning bad, it's general reference `object` to Exurim's culture) man! You already know that kid is well known in your contract, the community section. Don't you remember, He is the one that gave you the `badge` so that you can come into the community section while you people kickstarted your contract! Because he betrayed us, then so be it should you.

Gyouter: I know! He is. But please. I do not want to cause war. we don't want war. do you?

Exurim: 😢

Gyouter: We are not the people to cause the war. We are supposedly [**talk about the war**](https://gamejolt.com/games/last-funkin-moments/634559 ), especially what war [devastated us extremely terrible & traumatic](https://gamebanana.com/mods/44555 ), the true background why Kaorfa gave us this contract, Saubo. Point is, we still have another one (friends like [bbpanzu](https://twitter.com/bbsub3 )). And Pls, we do not want our connection & bridges be [destroyed](https://en.wikipedia.org/wiki/Ban_(law) ) at all. we will never know if we need the same bridge beyond this contract, and we'll never know when reputation requirement be ended (it never ends). Don't we?

Exurim: ... But, isn't.. the block.. is also related to this contract? We have ended up involed with the drama ourselves!

Gyouter: Correct. We will spread it, [our way](https://github.com/Perkedel/Kaded-fnf-mods ). And that, is the better way to vent it out. Bandwagon can happen, yes. But it's hard to figure out first, until gamers tries to figure out.

Exurim: Okay. I guess. Uh, btw, (the boss gonna take the revenge also)

Gyouter: (called Spreader boss) I know.

Exurim: Also, pls don't talk like Kaorfa's mother. I do not like when somebody **refuse to help**.

Gyouter: I'm sorry, but I have to. Now you know, this better way.

Exurim: Okay, pardoned.

Nhodle Suzle: (pick up phone) Yes hello, Spreader here. What's going on?

Gyouter: Hey, you remember me?

Nhodle: What, is it the new Sauce?

Gyouter: ...

Nhodle: Just kidding, HAHA 😀!! Gyouter!! Long time no see! How has your day been, man?!

Gyouter: Yeah cool and good. We have just finished our first season. uh, the new season Work in Progress.

Nhodle: Alright, `cool and good` (he's excercising this new word from this Dasandim & looking forward to learn its culture). hehe! So what is it?

Gyouter: So you gonna,

Nhodle: Whoa, is it not allowed?

Gyouter: I'm sorry. That will destroy the bridge.

Nhodle: Oh. why is that?

Gyouter: `Harrassment`. We are supposed to talk about it, not doing it.

Nhodle: Oh, that's harrassment. Should I,

Gyouter: Yeah.

Nhodle: Okay, is my best friend here?

Gyouter: (point selfie camera towards Exurim) With me.

Nhodle: Oh, hey bud. I'm sorry we gotta cancel this.

Exurim: It's okay I guess. After all I just, already tired harrassing billions of lives. It's time for me to retire from this other hobby I guess.

Nhodle: Yeah. Okay, so, it's canceled. done. Okay, Gyouter what's your idea again

(tell idea was about using mods to reupload & pack mods easily. Kade-LFM port, Cut first, continue in section `The Special Meeting`)

# Go back to hotel house
## Tomhamos long sand beach, again.
Gyouter: my dear, I'm home!

Denosa: Wow, how's your journey.

Gyouter: met my old friends. long time no see, whoahow.

Denosa: (giggle)!!..

Gyouter: So what's the dinner here?

Denosa: Check this out, Tomhamos got new preset today.

Gyouter: What is it? lemme see.

Denosa: (share the menu image)!

Gyouter: Okay, (found this new menu) whoa! `Negurim Shimas`? Interesting. it's a.. burger with Wagyu patty on it, seasoned with Ultimate seasons. Spiciness Level 1 coming from its Quertino pepper. Okay, Let's try this. Like usual.

Denosa: Okay, (request 2 Negurim Shimas) here it is!

(B roll dinner consume the borgir)

## bedroom
Gyouter: (partially lie onto bed), (take phone again), (reread special meeting notes)

### The Special Meeting
Gyouter: So, we wanted to make our contract execution customizable. So other gamers can adapt & build for this contract. We will not host, neither bring restriction to what can they do as long their action complies with our basic rules. Right, so here's what we got so far. So, we gonna use this modification system, harness it, Aaand there are these: the display information, the load informations, and it this since it has one, the name.

Exurim: (read how the modification system work & linked to Gyouter's idea) So, this should be easy to fill up with. the Gamers just have to fill that in order and call it a day, I see.

Nhodle: (also have examined it) Well, isn't this unstable? What if one of the customization broke? Like, one of the information container uh missing something. That could dislocate the order of the supposed information to where it goes to.

Gyouter: Yeah I know. I did not have thought far right now, So any suggestion here? Yeah I just uh.. gonna take the amalgamated information because it's complicated and it would ended up needing [surgery](https://enigmaengine.github.io/docs/modding-basics/#merging ) to get the customization done.

Nhodle: Perhaps you can just deamalgate the information and make it granular. (find source of the granular) uh.... (found it) here, (share the [link](https://github.com/ShadowMario/FNF-PsychEngine/tree/main/assets/preload/weeks )). This is what they did. Make the information granular, and put the ID [in order](https://github.com/ShadowMario/FNF-PsychEngine/blob/main/assets/preload/weeks/weekList.txt ). I think this also easy to reverse engineer, take a look at.. this (share [link](https://github.com/ShadowMario/FNF-PsychEngine/blob/main/source/WeekData.hx )).

Gyouter: Hmmm yeah! that's what we need!

Exurim: Wai wai wait, I think we just stumbled upon the same but different version. What was it?

Nhodle: Oh yeah! (find another version) uh... here (share [link](https://github.com/EnigmaEngine/EnigmaEngine/tree/stable/assets/preload/data/storymenu ))! Oh btw, there's also character display information too!

Gyouter: Ouw yeah. (reading the Enigma's system)... hmm, wow. Hoof, this is many.

Exurim: Yeah, you gotta pick and choose. I suggest take both, but uh yeah take one is okay, but eventually you also has to get the other one.

Gyouter: Right, is that all?

Nhodle: I think that is it. Oh, btw. Since you already going to provide customizability, why not tell [Admiral Zumi](lbry://@X0P1R4T3-33NSVREENMNT-0FFICIAL#f ) to harness this customizationer to uh, you know, kinda nasty stuff. You know that PTSD, no need to tell name.

Exurim: Ah yess! of course!! I want them **3** back! yess!!!

Gyouter: Aaaah! great idea!! wait ssshhhhh! watch your mouth! (check surrounding).... (surrounding is clear of Copyright strikers) Whew. Okay. We got it.

Exurim: Yes, you gotta tell him. This is huge!

Nhodle: This is secret between us and Admiral Zumi, okay.

Gyouter: Of course, *I'm gonna deliver the water back into its tower*. this gonna be.. *cheap*.

Exurim: Yeah, be careful, *don't let any contaminants touches it* (the related party knows), otherwise... *it will be unconsumable* (be blocked by another who you recognize again).

Gyouter: Okay, I gotta go. *This water is rare & expensive*, Admiral Zumi has *to try it first*.

Nhodle: Alright, take care! Great luck & God Bless you!

Exurim: Great luck & God bless you all too!

Gyouter: You people too. (leave scene)

(everyone leave)

### End of meeting notes, now call Admiral Zumi
Gyouter: (closes meeting note). ... (call Admiral Zumi)

## Xop1r4t3 EenVreensment HQ, Ground floor, Podser (city of dome bubbles in ground & underground), Dasandim.
Pocingklik Normaz: (playing bounce rubber ball towards wall)... I'm bored. Do you got new stuff?

Admiral Zumi: Not yet. I forgot count days.

Pocingklik: (sigh)...

(Zumi's phone ring)

Zumi: (pick up)! Yeah, it's me your favourite yoinkers in the universe.

Gyouter: Hey, you got nothing here?

Zumi: Whoah... (unlean into proper sitting position).., Gyouter? Hey, sup! Yeah we are bored. nothing to do here.

Gyouter: Great! Coz this, ... will be your big day. Starting from now, you'll be back again in your glory, and it's a new glory though. (share the modding support information)!

Zumi: (read the information)... Whoah, wow. This..

Gyouter: Is amazing isn't it?

Zumi: Wow, I think I can do something just like my glorious day ha yess.

Gyouter: Not only that!, (share the Protoglin Amexamlef)! You still 3 of those right?

Zumi: OooO!.. Yeah I still have 3. 4 if you consider the Copiar vs uh you know, separate.

Gyouter: perfect! Remember, as usual.

Zumi: `Sssshhh`.

Gyouter: Great luck, God Bless you. (close call).

Zumi: (further examine informations he got)...

Pocingklik: Did you just,

Zumi: Yes. (immediately, go to the announcement balcony)!

Pocingklik: wow, finally. after all these years! (then also follow Zumi)

## Announcement balcony
Zumi: Your attention Please.

(employees pause working to pay attention to this new announcement)

Zumi: Tomorrow, we will have a big day. Biggest day. unlike before, (write on white board this modding support & plan to do) We.. will do... `Tandon Minum`. damn, I lack a good name! something oblivious, but only us knows. Well, take it up, somebody needs *rehydration*, right? So that's, it is.

(employee applause for 2 seconds)!!!.

Zumi: Because this time we also let some few outsiders knows our product, we want to make sure that we do this not explosively because again, Strikes exist and they are ready to hunt their prey, us.

Pelfor: Of course!! we'll be oblivious!

(employees): yea yea that's right! okay okay!.

Zumi: (telepathically tell introducer employee to reveal the box), So our product will be packaged in this box. It's yellow and has radioactive ☢️ & biohazard ☣️ symbols in it. No, we're not literally selling actual isotopes or whatever, you know that. the isotopes are digital. And they are biohazard, especially for these (show Protoglin Amexamlef note skins to that whiteboard). This is why, we must be even more vigilant than ever before. Strikers looks for our action with these, and use these for courts they carry and have with. Any question? ... Okay, I hope you people understand.

Motugal: Oh wait! yess! I have question! What if somebody ask us to take our product away from shelf? How do we respond this time?

Zumi: umm we have not figured that out. As usual. Say `yes`, then `ghost` them.

Motugal: Yeah I know but, (what if they insist and dox to arrest us)

Zumi: Also not figured out yet. Pretend that we took it down but actually moved to somewhere at another.

Motugal: Okay, I hope that this time is not that bad. Thancc.

Zumi: You're welcome. Okay, I think this already the clock. and.. (saw all employees already ate earlier that evening range due to lack of significant activities), ... take break. We're gonna do this. Put it on the buffer (storage of finished product package for to be sent), and when I say go, there it goes. Okay, Great luck, and God Bless you. dismiss.

(employee dismiss & go home)

## Go back to Gyouter, Bedroom
Gyouter: (open up monitoring Saubo goes out)..

## Virtual Dasandim
Yume: (call security) anyone in the security, pls open up the virtual portal, we're going home!

Kosen Urun: Okay, portal opening (redeploy portal to virtual Dasandim)... (turn on portal)! It's on

Yume: Thancc, (close call). Alright, how was it?

Saubo: Amazing! I shall go there again

Yume: Yeah.. I agree! (arrived, press park the car button). We're home!

Saubo: (open door) (get our of car)! yeay!

Yume: Whoa careful! (open car), (get out of car), (press close door & lock car)!

Kosen: She got spirit, isn't she?

Yume: Yeah. Glad to see her in her happy.

## Storage room
Yume: Alright, uh yeah. That's how Dasandim looks like.

Saubo: Maybe we can explore more places around it can we?

Yume: (sad that know she can't live in Dasandim or anywhere in the overworld due to that war) uh.. yeah! One day.

Saubo: woohoo! yeah!

Yume: Okay, but you have to sleep. btw, You can explore this virtually. (share the link) here map.

Saubo: (take digital map) wooo!

Yume: get some sleep, it's already night. Great luck & God Bless you.

Saubo: God bless you.. too.

Yume: Right, see ya, (close apartment cell front door), (leave).

## Go back to Gyouter once again, Bedroom
Gyouter: whew!

Yume: Saubo is safe now.

Gyouter: Hoof, thancc God.

Yume: She's really thrilled to know more about our planet and uh..

Gyouter: it's okay. I get it. I hope there's a day she can be free to the war.

Yume: yeah.

Gyouter: Alright, good night. Great luck aaand God Bless you.

Yume: you too.

Gyouter: (close monitor).

# END
Thancc for your attention. Last Funkin Moments can now be modded just with ModCore of Kade. It's still unstable, & documentation coming soon.

by JOELwindows7  
Perkedel Technologies  
CC4.0-BY-SA