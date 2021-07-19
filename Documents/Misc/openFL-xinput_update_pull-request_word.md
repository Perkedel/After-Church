# Reupdate the syntax and stuff now!
There are some syntaxes which has been unsupported in today's Haxe version.

# Error!
```
C:/HaxeToolkit/haxe/lib/xinput/git/com/furusystems/openfl/input/xinput/XBox360Controller.hx:171: characters 16-22 : id: Custom property accessor is no longer supported, please use `get`
C:/HaxeToolkit/haxe/lib/xinput/git/com/furusystems/openfl/input/xinput/XBox360Controller.hx:197: characters 27-44 : vibrationLeft: Custom property accessor is no longer supported, please use `get`
C:/HaxeToolkit/haxe/lib/xinput/git/com/furusystems/openfl/input/xinput/XBox360Controller.hx:197: characters 46-63 : vibrationLeft: Custom property accessor is no longer supported, please use `set`
C:/HaxeToolkit/haxe/lib/xinput/git/com/furusystems/openfl/input/xinput/XBox360Controller.hx:198: characters 31-52 : vibrationLeftNorm: Custom property accessor is no longer supported, please use `get`
C:/HaxeToolkit/haxe/lib/xinput/git/com/furusystems/openfl/input/xinput/XBox360Controller.hx:198: characters 54-75 : vibrationLeftNorm: Custom property accessor is no longer supported, please use `set`
C:/HaxeToolkit/haxe/lib/xinput/git/com/furusystems/openfl/input/xinput/XBox360Controller.hx:224: characters 28-46 : vibrationRight: Custom property accessor is no longer supported, please use `get`
C:/HaxeToolkit/haxe/lib/xinput/git/com/furusystems/openfl/input/xinput/XBox360Controller.hx:224: characters 48-66 : vibrationRight: Custom property accessor is no longer supported, please use `set`
C:/HaxeToolkit/haxe/lib/xinput/git/com/furusystems/openfl/input/xinput/XBox360Controller.hx:225: characters 32-54 : vibrationRightNorm: Custom property accessor is no longer supported, please use `get`
C:/HaxeToolkit/haxe/lib/xinput/git/com/furusystems/openfl/input/xinput/XBox360Controller.hx:225: characters 56-78 : vibrationRightNorm: Custom property accessor is no longer supported, please use `set`
C:/HaxeToolkit/haxe/lib/xinput/git/com/furusystems/openfl/input/xinput/XBox360ThumbStick.hx:87: characters 22-34 : deadZone: Custom property accessor is no longer supported, please use `get`
C:/HaxeToolkit/haxe/lib/xinput/git/com/furusystems/openfl/input/xinput/XBox360ThumbStick.hx:87: characters 36-48 : deadZone: Custom property accessor is no longer supported, please use `set`
C:/HaxeToolkit/haxe/lib/xinput/git/com/furusystems/openfl/input/xinput/XBox360ThumbStick.hx:88: characters 26-42 : deadZoneNorm: Custom property accessor is no longer supported, please use `get`
C:/HaxeToolkit/haxe/lib/xinput/git/com/furusystems/openfl/input/xinput/XBox360ThumbStick.hx:88: characters 44-60 : deadZoneNorm: Custom property accessor is no longer supported, please use `set`
```

You see, it was used to be like `(get_variableThing, set_variableThing)`. but now, it's just `(get, set), since you would just make getter & setter function callback name just be like that anyway to match with the name of the variable itself. pretty much simpler!

That's right. you just have to `(get, set)` from now on. and it'll automatically match the getter and setter. to read only however, you can `(get, never)`. now, only the `get_variableThing` callback will be expected.