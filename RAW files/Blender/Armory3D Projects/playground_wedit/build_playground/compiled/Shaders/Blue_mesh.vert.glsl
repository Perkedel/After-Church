#version 450
in vec4 pos;
in vec2 nor;
in vec2 tex;
out vec3 wnormal;
out vec2 texCoord;
uniform mat3 N;
uniform mat4 WVP;
uniform float texUnpack;
void main() {
	vec4 spos = vec4(pos.xyz, 1.0);
	wnormal = normalize(N * vec3(nor.xy, pos.w));
	texCoord = tex * texUnpack;
	gl_Position = WVP * spos;
}
