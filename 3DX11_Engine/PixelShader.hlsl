Texture2D Texture: register(t0);
sampler TextureSampler: register(s0);

struct PS_INPUT
{
	float4 position: SV_POSITION;
	float2 texcoord: TEXCOORD0;
	float3 normal: NORMAL0;
};

cbuffer constant: register(b0)
{
	row_major float4x4 m_world;
	row_major float4x4 m_view;
	row_major float4x4 m_proj;

	float4 m_light_direction;
};

float4 psmain(PS_INPUT input) : SV_TARGET
{
	// Ambient Light
	float ka = 0.1;
	float3 ia = float3(1.0, 1.0, 1.0);

	float3 ambient_light = ka * ia;

	//DIFFUSE LIGHT
	float kd = 0.7;
	float3 id = float3(1.0, 1.0, 1.0);
	float amount_diffuse_light = max(0.0, dot(m_light_direction.xyz, input.normal));

	float3 diffuse_light_amount = kd * amount_diffuse_light * id;

	float3 diffuse_light = kd * id * diffuse_light_amount;

	// Final Light
	float3 diffuse_ambient_light = ambient_light + diffuse_light;
	return float4(diffuse_ambient_light, 1.0);
}