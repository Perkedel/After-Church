#ifndef _COMPILED_GLSL_
#define _COMPILED_GLSL_
#define _Irr
#define _Rad
#define _Deferred
#define _ShadowMap
#define _CSM
#define _VoxelCones3
#define _VoxelGITemporal
#define _VoxelAOvar
#define _Spot
#define _SinglePoint
#define _Brdf
#define _SSAO
#define _CToneFilmic
#define _CFXAA
#define _CTexStep
#if defined(HLSL) || defined(METAL)
#define _InvY
#endif
#define _FlipY
const float PI = 3.1415926535;
const float PI2 = PI * 2.0;
const vec2 shadowmapSize = vec2(1024, 1024);
const float shadowmapCubePcfSize = 0.001;
const int shadowmapCascades = 4;
const float ssaoRadius = 1.0;
const float ssaoStrength = 1.0;
const float ssaoScale = 20.0;
const ivec3 voxelgiResolution = ivec3(64, 64, 32);
const vec3 voxelgiHalfExtents = vec3(8, 8, 4);
const float voxelgiOcc = 1.0;
const float voxelgiStep = 1.0;
const float voxelgiRange = 2.0;
const float voxelgiOffset = 1.0;
const float voxelgiAperture = 1.0;
const int skinMaxBones = 65;

#endif // _COMPILED_GLSL_
