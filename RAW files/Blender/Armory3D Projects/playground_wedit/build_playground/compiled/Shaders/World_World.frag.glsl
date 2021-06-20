#version 450
#include "compiled.inc"
in vec3 normal;
out vec4 fragColor;
uniform vec3 A;
uniform vec3 B;
uniform vec3 C;
uniform vec3 D;
uniform vec3 E;
uniform vec3 F;
uniform vec3 G;
uniform vec3 H;
uniform vec3 I;
uniform vec3 Z;
uniform vec3 hosekSunDirection;
uniform float envmapStrength;
vec3 hosekWilkie(float cos_theta, float gamma, float cos_gamma) {
	vec3 chi = (1 + cos_gamma * cos_gamma) / pow(1 + H * H - 2 * cos_gamma * H, vec3(1.5));
	return (1 + A * exp(B / (cos_theta + 0.01))) * (C + D * exp(E * gamma) + F * (cos_gamma * cos_gamma) + G * chi + I * sqrt(cos_theta));
}
void main() {
	vec3 n = normalize(normal);
	float cos_theta = clamp(n.z, 0.0, 1.0);
	float cos_gamma = dot(n, hosekSunDirection);
	float gamma_val = acos(cos_gamma);
	vec3 SkyTexture_Color_res = Z * hosekWilkie(cos_theta, gamma_val, cos_gamma) * envmapStrength;;
	fragColor.rgb = SkyTexture_Color_res;
	fragColor.a = 0.0;
}
