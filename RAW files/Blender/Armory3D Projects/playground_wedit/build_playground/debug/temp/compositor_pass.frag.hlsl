uniform float2 texStep;
Texture2D<float4> tex : register(t0);
SamplerState _tex_sampler : register(s0);

static float2 texCoord;
static float4 fragColor;

struct SPIRV_Cross_Input
{
    float2 texCoord : TEXCOORD0;
};

struct SPIRV_Cross_Output
{
    float4 fragColor : SV_Target0;
};

float3 tonemapFilmic(float3 color)
{
    float3 x = max(0.0f.xxx, color - 0.0040000001899898052215576171875f.xxx);
    return (x * ((x * 6.19999980926513671875f) + 0.5f.xxx)) / ((x * ((x * 6.19999980926513671875f) + 1.7000000476837158203125f.xxx)) + 0.0599999986588954925537109375f.xxx);
}

void frag_main()
{
    float2 texCo = texCoord;
    float2 tcrgbNW = texCo + ((-1.0f).xx * texStep);
    float2 tcrgbNE = texCo + (float2(1.0f, -1.0f) * texStep);
    float2 tcrgbSW = texCo + (float2(-1.0f, 1.0f) * texStep);
    float2 tcrgbSE = texCo + (1.0f.xx * texStep);
    float2 tcrgbM = float2(texCo);
    float3 rgbNW = tex.SampleLevel(_tex_sampler, tcrgbNW, 0.0f).xyz;
    float3 rgbNE = tex.SampleLevel(_tex_sampler, tcrgbNE, 0.0f).xyz;
    float3 rgbSW = tex.SampleLevel(_tex_sampler, tcrgbSW, 0.0f).xyz;
    float3 rgbSE = tex.SampleLevel(_tex_sampler, tcrgbSE, 0.0f).xyz;
    float3 rgbM = tex.SampleLevel(_tex_sampler, tcrgbM, 0.0f).xyz;
    float3 luma = float3(0.2989999949932098388671875f, 0.58700001239776611328125f, 0.114000000059604644775390625f);
    float lumaNW = dot(rgbNW, luma);
    float lumaNE = dot(rgbNE, luma);
    float lumaSW = dot(rgbSW, luma);
    float lumaSE = dot(rgbSE, luma);
    float lumaM = dot(rgbM, luma);
    float lumaMin = min(lumaM, min(min(lumaNW, lumaNE), min(lumaSW, lumaSE)));
    float lumaMax = max(lumaM, max(max(lumaNW, lumaNE), max(lumaSW, lumaSE)));
    float2 dir;
    dir.x = -((lumaNW + lumaNE) - (lumaSW + lumaSE));
    dir.y = (lumaNW + lumaSW) - (lumaNE + lumaSE);
    float dirReduce = max((((lumaNW + lumaNE) + lumaSW) + lumaSE) * 0.03125f, 0.0078125f);
    float rcpDirMin = 1.0f / (min(abs(dir.x), abs(dir.y)) + dirReduce);
    dir = min(8.0f.xx, max((-8.0f).xx, dir * rcpDirMin)) * texStep;
    float3 rgbA = (tex.SampleLevel(_tex_sampler, texCo + (dir * (-0.16666667163372039794921875f)), 0.0f).xyz + tex.SampleLevel(_tex_sampler, texCo + (dir * 0.16666667163372039794921875f), 0.0f).xyz) * 0.5f;
    float3 rgbB = (rgbA * 0.5f) + ((tex.SampleLevel(_tex_sampler, texCo + (dir * (-0.5f)), 0.0f).xyz + tex.SampleLevel(_tex_sampler, texCo + (dir * 0.5f), 0.0f).xyz) * 0.25f);
    float lumaB = dot(rgbB, luma);
    if ((lumaB < lumaMin) || (lumaB > lumaMax))
    {
        fragColor = float4(rgbA, 1.0f);
    }
    else
    {
        fragColor = float4(rgbB, 1.0f);
    }
    float3 _281 = tonemapFilmic(fragColor.xyz);
    fragColor = float4(_281.x, _281.y, _281.z, fragColor.w);
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    texCoord = stage_input.texCoord;
    frag_main();
    SPIRV_Cross_Output stage_output;
    stage_output.fragColor = fragColor;
    return stage_output;
}
