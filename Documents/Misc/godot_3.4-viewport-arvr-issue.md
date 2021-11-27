# Title
Godot 3.4 Viewport ARVR Issue

# Godot Version
3.4 official

# System Information
Windows 10, GLES3, Nvidia GeForce GTX 1050Ti, Nvidia GameReady 496.49

# Issue Description
## Describe
Crash when attempted to open a Viewport tscn that configured for ARVR & has an ARVR camera. It only happens with GLES3. Doing the same with GLES2 won't cause any trouble. 

## Terminal log
### Hexagon Engine
Quick open scene `ZetrixViewport.tscn`
```
...
ERROR: Condition "ret == 0" is true. Returned: ERR_CANT_FORK
   at: execute (platform/windows/os_windows.cpp:2843)
thirdparty/mbedtls/library/ssl_tls.c:5084: mbedtls_ssl_fetch_input() returned -27648 (-0x6c00)
thirdparty/mbedtls/library/ssl_tls.c:4455: ssl_get_next_record() returned -27648 (-0x6c00)
thirdparty/mbedtls/library/ssl_cli.c:1691: mbedtls_ssl_read_record() returned -27648 (-0x6c00)
ERROR: TLS handshake error: -27648
   at: _do_handshake (modules/mbedtls/stream_peer_mbedtls.cpp:87)
mbedtls error: returned -0x6c00

ERROR: GL ERROR: Source: OpenGL Type: Error     ID: 1282        Severity: High  Message: GL_INVALID_OPERATION error generated.
   at: _gl_debug_print (drivers/gles3/rasterizer_gles3.cpp:124)
ERROR: GL ERROR: Source: OpenGL Type: Error     ID: 1282        Severity: High  Message: GL_INVALID_OPERATION error generated.
   at: _gl_debug_print (drivers/gles3/rasterizer_gles3.cpp:124)
ERROR: GL ERROR: Source: OpenGL Type: Error     ID: 1282        Severity: High  Message: GL_INVALID_OPERATION error generated. The required buffer is missing.
   at: _gl_debug_print (drivers/gles3/rasterizer_gles3.cpp:124)
ERROR: GL ERROR: Source: OpenGL Type: Error     ID: 1282        Severity: High  Message: GL_INVALID_OPERATION error generated. The required buffer is missing.
   at: _gl_debug_print (drivers/gles3/rasterizer_gles3.cpp:124)
ERROR: GL ERROR: Source: OpenGL Type: Error     ID: 1282        Severity: High  Message: GL_INVALID_OPERATION error generated. The required buffer is missing.
   at: _gl_debug_print (drivers/gles3/rasterizer_gles3.cpp:124)
ERROR: FATAL: Index p_index = 0 is out of bounds (size() = 0).
   at: get (./core/cowdata.h:156)
PS C:\Users\joelr\Documents\kolmorotzzet (kolmorotshitt)\Artistic Setups\Godot>
```
editor closes.

tried to also remake the similar ARVR viewport & its VR Nodes under `ReplacementZetrixViewport.tscn` to find that closing & reopening it crashes as well under GLES3

### TestViewporto 
#### Open `Zetrixer.tscn`
```
Editing project: C:/Users/joelr/Documents/starring codes/Godot Projects/TestViewporto (C:::Users::joelr::Documents::starring codes::Godot Projects::TestViewporto)
Godot Engine v3.4.stable.official.206ba70f4 - https://godotengine.org
PS C:\Users\joelr\Documents\kolmorotzzet (kolmorotshitt)\Artistic Setups\Godot> OpenGL ES 3.0 Renderer: NVIDIA GeForce GTX 1050 Ti/PCIe/SSE2
OpenGL ES Batching: ON

ERROR: Unsupported locale 'in', falling back to 'en'.
   at: set_locale (core/translation.cpp:980)
ERROR: unsupported format character
   at: (core/variant.cpp:3067)
ERROR: unsupported format character
   at: (core/variant.cpp:3067)
ERROR: unsupported format character
   at: (core/variant.cpp:3067)
ERROR: unsupported format character
   at: (core/variant.cpp:3067)
ERROR: unsupported format character
   at: (core/variant.cpp:3067)
ERROR: unsupported format character
   at: (core/variant.cpp:3067)
ERROR: unsupported format character
   at: (core/variant.cpp:3067)
ERROR: unsupported format character
   at: (core/variant.cpp:3067)
ERROR: unsupported format character
   at: (core/variant.cpp:3067)
ERROR: unsupported format character
   at: (core/variant.cpp:3067)
ERROR: unsupported format character
   at: (core/variant.cpp:3067)
ERROR: unsupported format character
   at: (core/variant.cpp:3067)
ERROR: unsupported format character
   at: (core/variant.cpp:3067)
ERROR: unsupported format character
   at: (core/variant.cpp:3067)
ERROR: unsupported format character
   at: (core/variant.cpp:3067)
ERROR: unsupported format character
   at: (core/variant.cpp:3067)
ERROR: Can't use canvas background mode in a render target configured without sampling
   at: render_scene (drivers/gles3/rasterizer_scene_gles3.cpp:4212)
```
Editor locks up. soft-locked. force close needed.

I have tried other possible configurations, but  none of them crash. only `Zetrixer` does.

# Step to reproduce
## New from scratch
1. Create new project, use GLES3
2. have a new Viewport. configure for ARVR,
3. add new ARVR camera inside that viewport
4. Save that node tscn
5. close that node tscn
6. open it again.

## Using minimal project
1. Open this minimal project
2. Try open following tscn:
   -  `Emti.tscn` Empty viewport
   -  `WithRegularCam.tscn` has just regular Camera node
   -  `WithRegularCam.tscnARVR` same as above, but the viewport checkbox ARVR
   -  `Zetrixer.tscn` minimally configured to be ARVR. with ARVR camera & viewport checkbox ARVR
3. Notice that it crashes whenever `Zetrixer.tscn` being opened. It crashes under GLES3.
4. repeat process but with GLES2. open the same `Zetrixer.tscn` and it does not crash.

## (BIG REPOSITORY) Using [Hexagon Engine](https://github.com/Perkedel/HexagonEngine)
1. Clone & Open Hexagon Engine project
2. Quick open dummy viewport called `Viewportoroso.tscn` which is basically empty viewport with nothing but checkbox ARVR and stuff. Also try open other control scene. As you can see, normally this should opens fine
3. Quick open VR viewport called `ZetrixViewport.tscn` or `ReplacementZetrixViewport.tscn`. If you were in GLES3, the video driver crash, editor closes.
4. repeat with GLES2. open `ZetrixViewport.tscn` or `ReplacementZetrixViewport.tscn` again, won't crash.