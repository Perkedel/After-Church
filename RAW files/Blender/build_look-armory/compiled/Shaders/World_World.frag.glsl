#version 450
#include "compiled.inc"
in vec3 normal;
out vec4 fragColor;
void main() {
	vec3 n = normalize(normal);
	fragColor.rgb = vec3(0.05087608844041824, 0.05087608844041824, 0.05087608844041824);
	fragColor.a = 0.0;
}
