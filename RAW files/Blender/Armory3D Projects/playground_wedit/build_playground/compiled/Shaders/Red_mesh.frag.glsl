#version 450
#include "compiled.inc"
#include "std/gbuffer.glsl"
in vec3 wnormal;
in vec2 texCoord;
out vec4 fragColor[2];
uniform sampler2D ImageTexture;
void main() {
	vec3 n = normalize(wnormal);
	vec4 ImageTexture_texread_store = texture(ImageTexture, texCoord.xy);
	vec3 basecol;
	float roughness;
	float metallic;
	float occlusion;
	float specular;
	vec3 ImageTexture_Color_res = ImageTexture_texread_store.rgb;
	basecol = vec3(0.774237871170044, 0.1310441493988037, 0.08840523660182953);
	roughness = (((ImageTexture_Color_res.r * 0.3 + ImageTexture_Color_res.g * 0.59 + ImageTexture_Color_res.b * 0.11) / 3.0) * 2.5);
	metallic = 0.0;
	occlusion = 1.0;
	specular = 1.0;
	n /= (abs(n.x) + abs(n.y) + abs(n.z));
	n.xy = n.z >= 0.0 ? n.xy : octahedronWrap(n.xy);
	const uint matid = 0;
	fragColor[0] = vec4(n.xy, roughness, packFloatInt16(metallic, matid));
	fragColor[1] = vec4(basecol, packFloat2(occlusion, specular));
}
