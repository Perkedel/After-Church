#!/bin/sh
haxelib setup ~/haxe/lib
haxelib install lime
haxelib install openfl
haxelib install flixel
haxelib run lime setup flixel -y
haxelib run lime setup -y
haxelib install flixel-tools
haxelib install flixel-addons
haxelib install flixel-ui
haxelib install hscript
haxelib install flixel-addons
haxelib git faxe https://github.com/uhrobots/faxe
haxelib install polymod
haxelib git discord_rpc https://github.com/Aidan63/linc_discord-rpc
haxelib git extension-webm https://github.com/GrowtopiaFli/extension-webm
haxelib run lime rebuild extension-webm linux
haxelib git linc_luajit https://github.com/MasterEric/linc_luajit.git
haxelib git hxvm-luajit https://github.com/nebulazorua/hxvm-luajit.git
haxelib install actuate
haxelib git faxe https://github.com/uhrobots/faxe
haxelib git discord_rpc https://github.com/Aidan63/linc_discord-rpc
haxelib git linc_luajit https://github.com/MasterEric/linc_luajit.git
haxelib git hxvm-luajit https://github.com/nebulazorua/hxvm-luajit.git
haxelib install actuate
haxelib install android6permissions
haxelib git haxe-hardware https://github.com/Perkedel/haxe-hardware.git
haxelib git hscript-ex https://github.com/ianharrigan/hscript-ex # for the alternative against Lua, like BulbyVR's FNFM+
haxelib install tjson #BulbyVR used TJSON for JSON parsing instead of built-in JSON handlers.
haxelib install uniontypes #BulbyVR used this
haxelib install json2object #BulbyVR used this to convert JSON to object
haxelib install extension-webview #luckydog7 for Android
haxelib git xinput https://github.com/furusystems/openfl-xinput.git
haxelib install haxe-files
haxelib install hxcpp-debug-server
haxelib install tink_core
haxelib install grig.audio
haxelib install grig.midi
haxelib git tentools https://github.com/TentaRJ/tentools.git
haxelib git systools https://github.com/haya3218/systools
haxelib run lime rebuild systools linux
haxelib install haxe-strings
haxelib install firetongue
haxelib install hxp
haxelib install svg
haxelib install format
haxelib install lime-tools
haxelib install haxeui
haxelib install haxeui-core
haxelib install haxeui-openfl
haxelib install haxeui-flixel
haxelib git openfl-xinput https://github.com/furusystems/openfl-xinput
haxelib install yagp
haxelib run lime rebuild yagp linux
haxelib install yagp
haxelib git crashdumper http://github.com/larsiusprime/crashdumper
haxelib run lime rebuild yagp linux
haxelib git extension-androidtools https://github.com/jigsaw-4277821/extension-androidtools.git
haxelib git extension-videoview https://github.com/jigsaw-4277821/extension-videoview.git
haxelib git yaml https://github.com/Paidyy/haxe-yaml.git
haxelib git linc_clipboard https://github.com/josuigoa/linc_clipboard.git
haxelib install udprotean
haxelib install markdown
haxelib install openfl-webm
haxelib list
