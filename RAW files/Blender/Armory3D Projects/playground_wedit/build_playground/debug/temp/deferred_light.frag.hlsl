uniform float4x4 LWVPSpot[1];
Texture2D<float4> shadowMapSpot[1] : register(t0);
SamplerComparisonState _shadowMapSpot_sampler[1] : register(s0);
Texture2D<float4> gbuffer0 : register(t1);
SamplerState _gbuffer0_sampler : register(s1);
Texture2D<float4> gbuffer1 : register(t2);
SamplerState _gbuffer1_sampler : register(s2);
Texture2D<float4> gbufferD : register(t3);
SamplerState _gbufferD_sampler : register(s3);
uniform float3 eye;
uniform float3 eyeLook;
uniform float2 cameraProj;
Texture2D<float4> gbuffer2 : register(t4);
SamplerState _gbuffer2_sampler : register(s4);
Texture2D<float4> senvmapBrdf : register(t5);
SamplerState _senvmapBrdf_sampler : register(s5);
uniform float4 shirr[7];
uniform int envmapNumMipmaps;
Texture2D<float4> senvmapRadiance : register(t6);
SamplerState _senvmapRadiance_sampler : register(s6);
uniform float envmapStrength;
Texture3D<float4> voxels : register(t7);
SamplerState _voxels_sampler : register(s7);
uniform float voxelBlend;
Texture3D<float4> voxelsLast : register(t8);
SamplerState _voxelsLast_sampler : register(s8);
Texture2D<float4> ssaotex : register(t9);
SamplerState _ssaotex_sampler : register(s9);
uniform float3 pointPos;
uniform float3 pointCol;
uniform float pointBias;
uniform float2 spotData;
uniform float3 spotDir;
uniform float4 casData[20];

static float2 texCoord;
static float3 viewRay;
static float4 fragColor;

struct SPIRV_Cross_Input
{
    float2 texCoord : TEXCOORD0;
    float3 viewRay : TEXCOORD1;
};

struct SPIRV_Cross_Output
{
    float4 fragColor : SV_Target0;
};

float2 octahedronWrap(float2 v)
{
    return (1.0f.xx - abs(v.yx)) * float2((v.x >= 0.0f) ? 1.0f : (-1.0f), (v.y >= 0.0f) ? 1.0f : (-1.0f));
}

void unpackFloatInt16(float val, out float f, inout uint i)
{
    i = uint(int((val / 0.06250095367431640625f) + 1.525902189314365386962890625e-05f));
    f = clamp((((-0.06250095367431640625f) * float(i)) + val) / 0.06248569488525390625f, 0.0f, 1.0f);
}

float2 unpackFloat2(float f)
{
    return float2(floor(f) / 255.0f, frac(f));
}

float3 surfaceAlbedo(float3 baseColor, float metalness)
{
    return lerp(baseColor, 0.0f.xxx, metalness.xxx);
}

float3 surfaceF0(float3 baseColor, float metalness)
{
    return lerp(0.039999999105930328369140625f.xxx, baseColor, metalness.xxx);
}

float3 getPos(float3 eye_1, float3 eyeLook_1, float3 viewRay_1, float depth, float2 cameraProj_1)
{
    float linearDepth = cameraProj_1.y / (((depth * 0.5f) + 0.5f) - cameraProj_1.x);
    float viewZDist = dot(eyeLook_1, viewRay_1);
    float3 wposition = eye_1 + (viewRay_1 * (linearDepth / viewZDist));
    return wposition;
}

float3 shIrradiance(float3 nor, float4 shirr_1[7])
{
    float3 cl00 = float3(shirr_1[0].x, shirr_1[0].y, shirr_1[0].z);
    float3 cl1m1 = float3(shirr_1[0].w, shirr_1[1].x, shirr_1[1].y);
    float3 cl10 = float3(shirr_1[1].z, shirr_1[1].w, shirr_1[2].x);
    float3 cl11 = float3(shirr_1[2].y, shirr_1[2].z, shirr_1[2].w);
    float3 cl2m2 = float3(shirr_1[3].x, shirr_1[3].y, shirr_1[3].z);
    float3 cl2m1 = float3(shirr_1[3].w, shirr_1[4].x, shirr_1[4].y);
    float3 cl20 = float3(shirr_1[4].z, shirr_1[4].w, shirr_1[5].x);
    float3 cl21 = float3(shirr_1[5].y, shirr_1[5].z, shirr_1[5].w);
    float3 cl22 = float3(shirr_1[6].x, shirr_1[6].y, shirr_1[6].z);
    return ((((((((((cl22 * 0.429042994976043701171875f) * ((nor.y * nor.y) - ((-nor.z) * (-nor.z)))) + (((cl20 * 0.743125021457672119140625f) * nor.x) * nor.x)) + (cl00 * 0.88622701168060302734375f)) - (cl20 * 0.2477079927921295166015625f)) + (((cl2m2 * 0.85808598995208740234375f) * nor.y) * (-nor.z))) + (((cl21 * 0.85808598995208740234375f) * nor.y) * nor.x)) + (((cl2m1 * 0.85808598995208740234375f) * (-nor.z)) * nor.x)) + ((cl11 * 1.02332794666290283203125f) * nor.y)) + ((cl1m1 * 1.02332794666290283203125f) * (-nor.z))) + ((cl10 * 1.02332794666290283203125f) * nor.x);
}

float getMipFromRoughness(float roughness, float numMipmaps)
{
    return roughness * numMipmaps;
}

float2 envMapEquirect(float3 normal)
{
    float phi = acos(normal.z);
    float theta = atan2(-normal.y, normal.x) + 3.1415927410125732421875f;
    return float2(theta / 6.283185482025146484375f, phi / 3.1415927410125732421875f);
}

float3 tangent(float3 n)
{
    float3 t1 = cross(n, float3(0.0f, 0.0f, 1.0f));
    float3 t2 = cross(n, float3(0.0f, 1.0f, 0.0f));
    if (length(t1) > length(t2))
    {
        return normalize(t1);
    }
    else
    {
        return normalize(t2);
    }
}

float traceConeAO(Texture3D<float4> voxels_1, SamplerState _voxels_1_sampler, float3 origin, inout float3 dir, float aperture, float maxDist)
{
    dir = normalize(dir);
    float sampleCol = 0.0f;
    float dist = 0.046875f;
    float diam = dist * aperture;
    while ((sampleCol < 1.0f) && (dist < maxDist))
    {
        float3 samplePos = (dir * dist) + origin;
        float mip = max(log2(diam * 64.0f), 0.0f);
        float mipSample = voxels_1.SampleLevel(_voxels_1_sampler, (samplePos * 0.5f) + 0.5f.xxx, mip).x;
        sampleCol += ((1.0f - sampleCol) * mipSample);
        dist += max(diam / 2.0f, 0.03125f);
        diam = dist * aperture;
    }
    return sampleCol;
}

float traceAO(float3 origin, float3 normal, Texture3D<float4> voxels_1, SamplerState _voxels_1_sampler)
{
    float3 o1 = normalize(tangent(normal));
    float3 o2 = normalize(cross(o1, normal));
    float3 c1 = (o1 + o2) * 0.5f;
    float3 c2 = (o1 - o2) * 0.5f;
    float3 param = normal;
    float _436 = traceConeAO(voxels_1, _voxels_1_sampler, origin, param, 0.557851731777191162109375f, 3.4641015529632568359375f);
    float col = _436;
    float3 param_1 = lerp(normal, o1, 0.5f.xxx);
    float _441 = traceConeAO(voxels_1, _voxels_1_sampler, origin, param_1, 0.557851731777191162109375f, 3.4641015529632568359375f);
    col += _441;
    float3 param_2 = lerp(normal, -c2, 0.5f.xxx);
    float _449 = traceConeAO(voxels_1, _voxels_1_sampler, origin, param_2, 0.557851731777191162109375f, 3.4641015529632568359375f);
    col += _449;
    return (col / 3.0f) * 0.930000007152557373046875f;
}

float3 lambertDiffuseBRDF(float3 albedo, float nl)
{
    return albedo * max(0.0f, nl);
}

float d_ggx(float nh, float a)
{
    float a2 = a * a;
    float denom = pow(((nh * nh) * (a2 - 1.0f)) + 1.0f, 2.0f);
    return (a2 * 0.3183098733425140380859375f) / denom;
}

float v_smithschlick(float nl, float nv, float a)
{
    return 1.0f / (((nl * (1.0f - a)) + a) * ((nv * (1.0f - a)) + a));
}

float3 f_schlick(float3 f0, float vh)
{
    return f0 + ((1.0f.xxx - f0) * exp2((((-5.554729938507080078125f) * vh) - 6.9831600189208984375f) * vh));
}

float3 specularBRDF(float3 f0, float roughness, float nl, float nh, float nv, float vh)
{
    float a = roughness * roughness;
    return (f_schlick(f0, vh) * (d_ggx(nh, a) * clamp(v_smithschlick(nl, nv, a), 0.0f, 1.0f))) / 4.0f.xxx;
}

float attenuate(float dist)
{
    return 1.0f / (dist * dist);
}

float PCF(Texture2D<float4> shadowMap, SamplerComparisonState _shadowMap_sampler, float2 uv, float compare, float2 smSize)
{
    float3 _560 = float3(uv + ((-1.0f).xx / smSize), compare);
    float result = shadowMap.SampleCmp(_shadowMap_sampler, _560.xy, _560.z);
    float3 _569 = float3(uv + (float2(-1.0f, 0.0f) / smSize), compare);
    result += shadowMap.SampleCmp(_shadowMap_sampler, _569.xy, _569.z);
    float3 _580 = float3(uv + (float2(-1.0f, 1.0f) / smSize), compare);
    result += shadowMap.SampleCmp(_shadowMap_sampler, _580.xy, _580.z);
    float3 _591 = float3(uv + (float2(0.0f, -1.0f) / smSize), compare);
    result += shadowMap.SampleCmp(_shadowMap_sampler, _591.xy, _591.z);
    float3 _599 = float3(uv, compare);
    result += shadowMap.SampleCmp(_shadowMap_sampler, _599.xy, _599.z);
    float3 _610 = float3(uv + (float2(0.0f, 1.0f) / smSize), compare);
    result += shadowMap.SampleCmp(_shadowMap_sampler, _610.xy, _610.z);
    float3 _621 = float3(uv + (float2(1.0f, -1.0f) / smSize), compare);
    result += shadowMap.SampleCmp(_shadowMap_sampler, _621.xy, _621.z);
    float3 _632 = float3(uv + (float2(1.0f, 0.0f) / smSize), compare);
    result += shadowMap.SampleCmp(_shadowMap_sampler, _632.xy, _632.z);
    float3 _643 = float3(uv + (1.0f.xx / smSize), compare);
    result += shadowMap.SampleCmp(_shadowMap_sampler, _643.xy, _643.z);
    return result / 9.0f;
}

float shadowTest(Texture2D<float4> shadowMap, SamplerComparisonState _shadowMap_sampler, float3 lPos, float shadowsBias)
{
    bool _654 = lPos.x < 0.0f;
    bool _660;
    if (!_654)
    {
        _660 = lPos.y < 0.0f;
    }
    else
    {
        _660 = _654;
    }
    bool _666;
    if (!_660)
    {
        _666 = lPos.x > 1.0f;
    }
    else
    {
        _666 = _660;
    }
    bool _672;
    if (!_666)
    {
        _672 = lPos.y > 1.0f;
    }
    else
    {
        _672 = _666;
    }
    if (_672)
    {
        return 1.0f;
    }
    return PCF(shadowMap, _shadowMap_sampler, lPos.xy, lPos.z - shadowsBias, 1024.0f.xx);
}

float3 sampleLight(float3 p, float3 n, float3 v, float dotNV, float3 lp, float3 lightCol, float3 albedo, float rough, float spec, float3 f0, int index, float bias, bool receiveShadow, bool isSpot, float spotA, float spotB, float3 spotDir_1)
{
    float3 ld = lp - p;
    float3 l = normalize(ld);
    float3 h = normalize(v + l);
    float dotNH = dot(n, h);
    float dotVH = dot(v, h);
    float dotNL = dot(n, l);
    float3 direct = lambertDiffuseBRDF(albedo, dotNL) + (specularBRDF(f0, rough, dotNL, dotNH, dotNV, dotVH) * spec);
    direct *= attenuate(distance(p, lp));
    direct *= lightCol;
    if (isSpot)
    {
        float spotEffect = dot(spotDir_1, l);
        if (spotEffect < spotA)
        {
            direct *= smoothstep(spotB, spotA, spotEffect);
        }
        if (receiveShadow)
        {
            float4 lPos = mul(float4(p + ((n * bias) * 10.0f), 1.0f), LWVPSpot[0]);
            direct *= shadowTest(shadowMapSpot[0], _shadowMapSpot_sampler[0], lPos.xyz / lPos.w.xxx, bias);
        }
        return direct;
    }
    if (receiveShadow)
    {
    }
    return direct;
}

void frag_main()
{
    float4 g0 = gbuffer0.SampleLevel(_gbuffer0_sampler, texCoord, 0.0f);
    float3 n;
    n.z = (1.0f - abs(g0.x)) - abs(g0.y);
    float2 _803;
    if (n.z >= 0.0f)
    {
        _803 = g0.xy;
    }
    else
    {
        _803 = octahedronWrap(g0.xy);
    }
    n = float3(_803.x, _803.y, n.z);
    n = normalize(n);
    float roughness = g0.z;
    float param;
    uint param_1;
    unpackFloatInt16(g0.w, param, param_1);
    float metallic = param;
    uint matid = param_1;
    float4 g1 = gbuffer1.SampleLevel(_gbuffer1_sampler, texCoord, 0.0f);
    float2 occspec = unpackFloat2(g1.w);
    float3 albedo = surfaceAlbedo(g1.xyz, metallic);
    float3 f0 = surfaceF0(g1.xyz, metallic);
    float depth = (gbufferD.SampleLevel(_gbufferD_sampler, texCoord, 0.0f).x * 2.0f) - 1.0f;
    float3 p = getPos(eye, eyeLook, normalize(viewRay), depth, cameraProj);
    float3 v = normalize(eye - p);
    float dotNV = max(dot(n, v), 0.0f);
    float4 g2 = gbuffer2.SampleLevel(_gbuffer2_sampler, texCoord, 0.0f);
    float2 envBRDF = senvmapBrdf.SampleLevel(_senvmapBrdf_sampler, float2(roughness, 1.0f - dotNV), 0.0f).xy;
    float3 envl = shIrradiance(n, shirr);
    if (g2.z < 0.5f)
    {
        envl = envl;
    }
    else
    {
        envl = 1.0f.xxx;
    }
    float3 reflectionWorld = reflect(-v, n);
    float lod = getMipFromRoughness(roughness, float(envmapNumMipmaps));
    float3 prefilteredColor = senvmapRadiance.SampleLevel(_senvmapRadiance_sampler, envMapEquirect(reflectionWorld), lod).xyz;
    envl *= albedo;
    envl += (((prefilteredColor * ((f0 * envBRDF.x) + envBRDF.y.xxx)) * 1.5f) * occspec.y);
    envl *= (envmapStrength * occspec.x);
    float3 voxpos = p / float3(8.0f, 8.0f, 4.0f);
    envl *= (1.0f - ((traceAO(voxpos, n, voxels, _voxels_sampler) * voxelBlend) + (traceAO(voxpos, n, voxelsLast, _voxelsLast_sampler) * (1.0f - voxelBlend))));
    fragColor = float4(envl.x, envl.y, envl.z, fragColor.w);
    float3 _992 = fragColor.xyz * ssaotex.SampleLevel(_ssaotex_sampler, texCoord, 0.0f).x;
    fragColor = float4(_992.x, _992.y, _992.z, fragColor.w);
    int param_2 = 0;
    float param_3 = pointBias;
    bool param_4 = true;
    bool param_5 = true;
    float param_6 = spotData.x;
    float param_7 = spotData.y;
    float3 param_8 = spotDir;
    float3 _1028 = fragColor.xyz + sampleLight(p, n, v, dotNV, pointPos, pointCol, albedo, roughness, occspec.y, f0, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
    fragColor = float4(_1028.x, _1028.y, _1028.z, fragColor.w);
    fragColor.w = 1.0f;
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    texCoord = stage_input.texCoord;
    viewRay = stage_input.viewRay;
    frag_main();
    SPIRV_Cross_Output stage_output;
    stage_output.fragColor = fragColor;
    return stage_output;
}
