#version 450
#include "compiled.inc"
#include "std/gbuffer.glsl"
in vec3 wnormal;
out vec4 fragColor[2];
void main() {
	vec3 n = normalize(wnormal);
	vec3 basecol;
	float roughness;
	float metallic;
	float occlusion;
	float specular;
	vec3 NormalMap_Normal_res = n;
	n = NormalMap_Normal_res;
	basecol = vec3(0.24284212291240692, 0.2667361795902252, 0.24143286049365997);
	roughness = 0.5;
	metallic = 0.0;
	occlusion = 1.0;
	specular = 1.0;
	n /= (abs(n.x) + abs(n.y) + abs(n.z));
	n.xy = n.z >= 0.0 ? n.xy : octahedronWrap(n.xy);
	const uint matid = 0;
	fragColor[0] = vec4(n.xy, roughness, packFloatInt16(metallic, matid));
	fragColor[1] = vec4(basecol, packFloat2(occlusion, specular));
}
