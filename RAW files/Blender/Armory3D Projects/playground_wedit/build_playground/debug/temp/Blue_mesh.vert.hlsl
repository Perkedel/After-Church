uniform float3x3 N;
uniform float texUnpack;
uniform float4x4 WVP;

static float4 gl_Position;
static float4 pos;
static float3 wnormal;
static float2 nor;
static float2 texCoord;
static float2 tex;

struct SPIRV_Cross_Input
{
    float2 nor : TEXCOORD0;
    float4 pos : TEXCOORD1;
    float2 tex : TEXCOORD2;
};

struct SPIRV_Cross_Output
{
    float2 texCoord : TEXCOORD0;
    float3 wnormal : TEXCOORD1;
    float4 gl_Position : SV_Position;
};

void vert_main()
{
    float4 spos = float4(pos.xyz, 1.0f);
    wnormal = normalize(mul(float3(nor, pos.w), N));
    texCoord = tex * texUnpack;
    gl_Position = mul(spos, WVP);
    gl_Position.z = (gl_Position.z + gl_Position.w) * 0.5;
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    pos = stage_input.pos;
    nor = stage_input.nor;
    tex = stage_input.tex;
    vert_main();
    SPIRV_Cross_Output stage_output;
    stage_output.gl_Position = gl_Position;
    stage_output.wnormal = wnormal;
    stage_output.texCoord = texCoord;
    return stage_output;
}
