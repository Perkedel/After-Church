# This new Week takes time to build!
Status: READY, 100%
- Started week meta. charting the Getting Freaky
- finished week meta.
# Update Last Funkin Moments
- [Linux](https://odysee.com/@JOELwindows7/last-funkin-moments )
- [Linux 32 bit](https://odysee.com/@JOELwindows7/last-funkin-moments-32bit )
- [Windows](https://odysee.com/@JOELwindows7/last-funkin-moments-windows )
- [Windows 32 bit](https://odysee.com/@JOELwindows7/last-funkin-moments-windows32 )
- [macOS](https://odysee.com/@JOELwindows7:a/last-funkin-moments-macOS )
- [Android](https://odysee.com/@JOELwindows7:a/last-funkin-moments-android)
- [itch.io (Play Online now)](https://joelwindows7.itch.io/last-funkin-moments )
- [GameBanana](https://gamebanana.com/mods/293257 )
- [NexusMods](https://www.nexusmods.com/fridaynightfunkin/mods/247 )
- [GitHub](https://github.com/Perkedel/Kaded-fnf-mods )
- [GitHub of AfterChurch, the SVG files](https://github.com/Perkedel/After-Church/tree/master/RAW%20files/Inkscape/Week%20Strong )

# Amfrost
## Kade Engine Updated again! ~~1.5.4~~ 1.6
~~https://github.com/KadeDev/Kade-Engine/blob/stable/docs/changelogs/changelog-1.5.4.md ~~
https://github.com/KadeDev/Kade-Engine/blob/stable/docs/changelogs/changelog-1.6.md

## What's new in ~~2021.07.154~~ 2021.07.160
- NEW Week Meta! Featuring internal UI musics! Getting Freaky, Game Over, and Breakfast. if it is safe to GameBanana, we'll have Test.ogg which the chart JSON we used the yoinked thanks to someone we'll soon put in the credit. We will edit it these to have the moddefoids.
- Minor version reflects Kade Engine version minus the dots. so if it is 1.5.4, in LFM it's 154. Yeah, 2021.07.154
- Amfrost Stage!
- (Kade) NEW!!! GAMEPAD SUPPORT YAY FINALLY! although before this version technically can be played with Gamepad, it wasn't as smooth as that [Week7 on Newgrounds](https://www.newgrounds.com/portal/view/770371 ) where it even is configurable.
- (Kade) now the Keybind you set won't affect main menu anymore! yeah! that's should've been kept hard coded by standard. ui_control action is meta and may not be screwed up!
- (Kade) image assets  newesten
- (Kade) fix Spookez audio syncre
- (Kade) fix input drop / disappearing note
- (Kade) fix Hitgraph result screen bug.
- (Kade) no more stuck in the loop (go to Playstate class again) if score screen option if off. This is the Middle Ass era, not Ludum Dare Ass anymore! So stop stuck in the loop!
- (Kade) fix chart editor
- (Kade) fix HTML5 issues werror
- Further built the Stage Chart JSON. using this switchover defined by the song chart `SONG.useCustomStage:Bool`. with this on, it will search through the paths of special stage image folder named in that `checkStage`, instead of predefined ones. So, basically switches to procedural loading mode instead of hard-coded stage loading in usual FNF. I think that's how it supposed it to be but also thought of the compatibility. Also we proposed the Lua stage loading too aswell! yay!
- Proposed the Meta songs. We chose Main menu song, Game Over, and Breakfast. Oh, the Test too. we chart that again if it isn't exist.
- Experimentalist in 4'33" song. we added change player 2 character by direction keypresses! Up for Pico, Left for Daddy Dearest, Down for Hookx, Right for Mommy Mearest. You know, based on the signature color! This is possible with Modchart Lua. SO, only works for platform that is compatible with `linc_luajit` compilations.
- Proposed week menu images! so far these are all the images for week that would come for the era of Last Funkin Moment until the *death, abandonment, & derelevancy* at Full Ass Game release (which costs >$0, and that's why we called it that). Oh, sorry, I was too much. but it's reality. Not a big surprise. If not JOELwindows7's idea, expect less. Damn, I can't be arrogant with this. afraid the opposite of me came out, so NO! *distractions*, go away!
- btw, we still have respect and try our best to backport our weeks back to that Full Ass asset loading formats. No idea for the Stepmania yet. However we have been researching how to build cranviad here.
- Proposed a little of mod loading format of https://gamebanana.com/tools/7094 Kade Modding Tool. Well, we just added Weeks Folder, and Base folder in it. The coding is not yoinked yet (why the peck often I forgot to say negation words!?!?!?!?), and we do not plan to yoink the mechanism either. We got another way to make procedural assets loading, so just hang in there.
- what else buddy?
- (Kade) Stepmania file support. Load your SM file and let them be seen in Freeplay menu yay amazing!
- (Kade) New main menu music, Test music (I still have the original Test vanilla Madbrine yoinked)
- (Kade) Moar Option!!!
- (Kade) Brand new chart editor guys! no more page by page per measure. all are seamless WHOAHOW!!
- (Kade) Toggle Anti-aliasing
- (Kade) Lock week!
- (LFM) However if you'd like to preUnlock all weeks we have the option for you. (Kade) on Debug build though all weeks are always preUnlocked.
- Install Kade Engine's Test song chart to the FreePlay menu, harnessing the power of week -1.