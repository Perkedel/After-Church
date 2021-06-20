	RWTexture3D<float> voxels;
	struct SPIRV_Cross_Input { float3 wpos : TEXCOORD0; };
	struct SPIRV_Cross_Output { float4 FragColor : SV_TARGET0; };
	void main(SPIRV_Cross_Input stage_input) {
	  if (abs(stage_input.wpos.z) > 0.5 || abs(stage_input.wpos.x) > 1 || abs(stage_input.wpos.y) > 1) return;
	  voxels[int3(64, 64, 32) * (stage_input.wpos * 0.5 + 0.5)] = 1.0;
	
	}
