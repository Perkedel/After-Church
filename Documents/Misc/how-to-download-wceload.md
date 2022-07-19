# shoutout to u/kiwatiger for Windows CE ROM image for tablet & netbook provided

[Reddit Comment Article https://www.reddit.com/r/OldHandhelds/comments/id9wx0/reinstalling_windows_ce_for_datawind_ubisurfer/g28f7gp?utm_source=share&utm_medium=web2x&context=3](https://www.reddit.com/r/OldHandhelds/comments/id9wx0/reinstalling_windows_ce_for_datawind_ubisurfer/g28f7gp?utm_source=share&utm_medium=web2x&context=3)

&#x200B;

# Go to u/kiwatiger's archive here

[https://archive.org/details/winCEforTabletsandNetbooks](https://archive.org/details/winCEforTabletsandNetbooks)

On the Download widget space, click `SHOW ALL`.

# Choose your Windows CE version

say I have Windows CE 6 device, so I chose `WinCe6-wm8650-Netbook dot zip`

if you had other version of CE, say `Windows CE 7`, then choose file that has Windows CE 7 and is image of Windows CE, not the App collections.

# Don't click the file name!!! Click View content next to that file

Ctrl + F to Find

type `wceload.exe` to find that file. Found it! click that file name to download

put inside your device. We recommend that you keep it inside the T-Flash storage, SD Card, External storage something like that.

# Follow this HPCfactor guide [here yess](https://www.hpcfactor.com/support/cesd/s/0131.asp)

Copy of the reg file in case HPCfactor down:

```
[HKEY_CLASSES_ROOT\.cab]
@="cabfile"

[HKEY_CLASSES_ROOT\cabfile]
"EditFlags"=hex: 00,00,01,00
@="CAB File"

[HKEY_CLASSES_ROOT\cabfile\DefaultIcon]
@="\(Path to file without brackets)\wceload.exe,-101"

[HKEY_CLASSES_ROOT\cabfile\Shell]

[HKEY_CLASSES_ROOT\cabfile\Shell\Open]

[HKEY_CLASSES_ROOT\cabfile\Shell\Open\Command]
@="\(Path to file without brackets)\wceload.exe "%1""
```

Now you have read the instruction, and make sure `wceload.exe` is placed where it will survive after reboot i.e. external storage. putting on Windows folder may not help as some device will reset the content per reboot.

The Reg file content is provided there on step 3. Simply copy that reg script inside the little box of reg content, make new file whatever name `.reg`, paste inside it.

change `(Path to file without brackets)` to where folder did `wceload.exe` placed at. If your device do not reset like in `/Windows/wceload.exe` then point it to there at `Windows`. Otherwise point to wherever it was placed. My device resets Windows folder per reboot so I put it on e.g. `Storage Card/wceloaded`. You should get the idea.

After you created the reg file and added the content, save, and then inject it to your Device. You need the reg edit application! steal it from here [Windows CE GPS](https://www.youtube.com/watch?v=_2XTDzsdBYQ) ! the download link of files how to hack your GPS contains regedit! take `regedit.exe`!

# Import the new registry!

after making sure wceload is at the according directory & the reg file points to that directory, open regedit included with the GPS hack kit.

* File
* Import New Registry
* select that `.reg` file you've just had

# Whoops! Syntax Error? Import Registry Successful!

Wait, not done yet!

stay in regedit! now open folder pane `HKEY_CLASSES_ROOT\cabfile\Shell\Open\Command` . now click the entry `Default`. in value, append `"%1"` and `OK`. This make sure Windows know where to put input read cab filepath string. Yeah I think that was the error, because conflict of double quote.

# Close all apps and then reboot!

your Windows CE Cab install capability should work. if not, oh no.

# VHD images
https://www.reddit.com/r/wceload/comments/uxnul7/windows_ce_images_vhds/

# Reddit version of article
https://www.reddit.com/r/wceload/comments/iu0krk/how_to_find_download_and_reinstall_wceloadexe/

https://spee.ch/7/f5935830b4d36a4b.png
