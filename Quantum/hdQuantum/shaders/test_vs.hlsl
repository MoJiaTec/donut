
void main(
	in uint iVertex : SV_VertexID,
	out float4 o_posClip : SV_Position)
{
	uint u = iVertex;
	uint v = iVertex;

	o_posClip = float4(float(u) * 2 - 1, 1 - float(v) * 2, 1, 1);
}
