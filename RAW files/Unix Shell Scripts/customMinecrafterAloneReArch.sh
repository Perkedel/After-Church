#!/bin/sh
# by JOELwindows7
# Perkedel Technologies
# GNU GPL v3
# https://www.minecraft.net/en-us/download/
# https://www.planetminecraft.com/blog/how-to-change-your-minecraft-directoryadvanced-guide/
# https://minecraft.gamepedia.com/Tutorials/Custom_minecraft_directory
# https://linuxhandbook.com/symbolic-link-linux/
# https://linuxhandbook.com/hard-link/
# https://stackoverflow.com/questions/1951742/how-can-i-symlink-a-file-in-linux
# https://stackoverflow.com/questions/9422461/check-if-directory-mounted-with-bash
# https://www.linux.com/training-tutorials/and-ampersand-and-linux/
# https://ryanstutorials.net/bash-scripting-tutorial/bash-functions.php
# https://ryanstutorials.net/bash-scripting-tutorial/bash-variables.php
# https://www.shellscript.sh/variables1.html
# https://stackoverflow.com/questions/2268104/command-not-found-error-in-bash-variable-assignment
# https://stackoverflow.com/questions/1714603/bash-variable-assignment-and-command-not-found
# https://stackoverflow.com/questions/4181703/how-to-concatenate-string-variables-in-bash
# https://linuxhint.com/variables-bash-programming/

MC_WORKDIR="/run/media/joelwindows7/OS/Users/joelr/AppData/Roaming/.minecraft/"
MC_MOUNDIR="/run/media/joelwindows7/OS"

wowFoundText="Running Minecraft with workdir of \n$MC_WORKDIR\nof $MC_MOUNDIR"
werrorNotFoundText="Minecraft Mount at \n${MC_WORKDIR}\n in ${MC_MOUNDIR}\n not found\!\n\nPlease mount the Minecraft drive first!"

coolAndGoodSay='cool and good! Enjoy your Minecraft'
warmAndBadSay='warm and bad! Please mount the Minecraft drive first'

RunTheMinecraft () {
	echo "Going to Minecraft now"&
	notify-send "Start Minecraft at $MC_WORKDIR ..." --urgency=low --expire-time=1500&
	minecraft-launcher --workDir=${MC_WORKDIR}&
}

if mount | grep $MC_MOUNDIR > /dev/null; then
    echo $wowFoundText&
    flite -t "$coolAndGoodSay" -voice rms &
    RunTheMinecraft
else
    echo $werrorNotFoundText&
    zenity --text="$werrorNotFoundText" --width=600 --height=200 --title="Werror 404! Warm & Bad!" --error&
    flite -t "$warmAndBadSay" -voice rms&
fi

