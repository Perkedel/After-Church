Texture2D<float4> ImageTexture : register(t0);
SamplerState _ImageTexture_sampler : register(s0);

static float3 wnormal;
static float2 texCoord;
static float4 fragColor[2];

struct SPIRV_Cross_Input
{
    float2 texCoord : TEXCOORD0;
    float3 wnormal : TEXCOORD1;
};

struct SPIRV_Cross_Output
{
    float4 fragColor[2] : SV_Target0;
};

float2 octahedronWrap(float2 v)
{
    return (1.0f.xx - abs(v.yx)) * float2((v.x >= 0.0f) ? 1.0f : (-1.0f), (v.y >= 0.0f) ? 1.0f : (-1.0f));
}

float packFloatInt16(float f, uint i)
{
    return (0.06248569488525390625f * f) + (0.06250095367431640625f * float(i));
}

float packFloat2(float f1, float f2)
{
    return floor(f1 * 255.0f) + min(f2, 0.9900000095367431640625f);
}

void frag_main()
{
    float3 n = normalize(wnormal);
    float4 ImageTexture_texread_store = ImageTexture.Sample(_ImageTexture_sampler, texCoord);
    float3 ImageTexture_Color_res = ImageTexture_texread_store.xyz;
    float3 basecol = float3(0.7742378711700439453125f, 0.1310441493988037109375f, 0.08840523660182952880859375f);
    float roughness = ((((ImageTexture_Color_res.x * 0.300000011920928955078125f) + (ImageTexture_Color_res.y * 0.589999973773956298828125f)) + (ImageTexture_Color_res.z * 0.10999999940395355224609375f)) / 3.0f) * 2.5f;
    float metallic = 0.0f;
    float occlusion = 1.0f;
    float specular = 1.0f;
    n /= ((abs(n.x) + abs(n.y)) + abs(n.z)).xxx;
    float2 _128;
    if (n.z >= 0.0f)
    {
        _128 = n.xy;
    }
    else
    {
        _128 = octahedronWrap(n.xy);
    }
    n = float3(_128.x, _128.y, n.z);
    fragColor[0] = float4(n.xy, roughness, packFloatInt16(metallic, 0u));
    fragColor[1] = float4(basecol, packFloat2(occlusion, specular));
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    wnormal = stage_input.wnormal;
    texCoord = stage_input.texCoord;
    frag_main();
    SPIRV_Cross_Output stage_output;
    stage_output.fragColor = fragColor;
    return stage_output;
}
