Today's on the short tutorial how face reposters & reuploaders especially did not credited it at least.
Not just on the mod file being reuploaded without credit, but also those who recorded, upload to YouTube, but forgot to put the mod page link in the description or comment. Here's how to face those reposter-reuploaders, discredit YouTuber, and pretty much anything that did not grant you shoutouts.

Contains advanced codings & theories. Might be hard to understand and discern.

How to face reuploaders & not crediting YouTubers?
There is no exact way how do we supposed to face this. And, alot of default behaviors when they find that their mod has been reuploaded, or on YouTube but did not got credit, is gone mad, Flag button press everywhere, wishing that kinda stuff go down, beg credit, bla bla. What is that never works? Please, for your sanity, don't let those bad people take your passion away. Focus on your beautiful hard works instead. And, personally, I did this:

Watermark
So, people reuploads your mod file. Now, that your mod file is the key of the attention. And let's say, they don't credit. Anyway, don't rely on the description. Being credited or not credited, what if other reuploader after the reupload did so without credit. You need to make sure that source of obtainment (download link & source code link) stick hard and permanently to your mod file. How? with watermarks.

Not only this would deter if possible, in case that your mod got reuploaded anyway, then they unrealizingly also spread your links as well, HORRAY!!! FREE ADVERTISING WOOHOO!!! LMAO!!! but seriously. that's what I do with my mod.

YOu also better do it in hard code, not filed for this one. This is to make sure that the watermark is stuck, embedded permanently within the binary, giving hard time for reuploader in case they really hate you so much, scrapping of your name and link away from the mod file.

The Coding for it as an example
Please take a look at this mod source code of Last Funkin Moments here https://github.com/Perkedel/Kaded-fnf-mods/tree/stable/source.

I have placed the watermark in the following files of Class States:
MainMenuState.hx . In line 158 (or find reupload), I have placed temporary Text widget called reuploadEdgeCase. This contains URLs where to get source code for Last Funkin Moments, original Kade Engine,  and Original FNF (with the newgrounds play now URL as well). I placed this widget on bottom left, right above version text widget. Yeah uh, I called it edge case because in case no credit was given when reuploaded that's all. the most edge case of reupload you know.
PlayState.hx . In line 1696 .. forget it, find reupload too. Now this one is interesting, why do I placed watermark during gameplay? isn't this annoying? Yeah, I already know that and I know how do I supposed to handle this. First, when you just entered the gameplay, you won't see this, because it is invisible by default. But, when the countdown has reached zero (in function startSong() just find that) it appears, in middle of the screen. Don't worry, it'll invisible again after passing by 8th curBeat (find if(curBeat > 8) inside function update(elapsed) ). is that simple!  yeah. Reason that I do this is because of YouTubers. actually, I fear some YouTubers would not credit my mod in the description or comment at all, no download link whatsoever. Whatever happened, in the recording you'll see that watermark right there and then it disappears. Sure, that should be enough for you to screenshot those frames while it's there, and then type that URL over it. It's not that hard, the small text should be still clear hopefully.

But sir, I want that reuploader down! not just watermark it!
Yeah, if that's what you wish, feel free to report. But unfortunately you can't stop everyone of them. People are naughty as always. We should move on, and instead EMBRACE IT. yess.

We are not talking about confession that we are powerless, we are talking about opportunity. See, with reuploads, those who accessed your mod with the watermark hardcoded will see that link over there and probably would be interested to visit the original source and grants you extra popularity and viral points to yourselves. Therefore, you got extra traffic compared just buying advertisement spots from Google, Facebook, or whatever company you'd like to use. It's free spot then, so don't be angery when your mod is being reuploaded. You've already had your link. If the reuploader found themselves that they turns out advertised and endorsed your links, I think they'll be ashamed lol!

So yeah basically, hardcoding your download link grants you free advertising some sort in case your mod got reuploaded.