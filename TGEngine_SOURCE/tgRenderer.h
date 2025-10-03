#pragma once
#include "tgCamera.h"
#include "tgGraphicDevice_DX11.h"

namespace tg::renderer
{
	extern Camera* mainCamera;

	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};

	extern Vertex vertexes[3];
	extern std::vector<UINT> indices;

	extern ID3D11Buffer* vertexBuffer;
	extern ID3D11Buffer* indexBuffer;
	extern ID3D11Buffer* constantBuffer;

	extern ID3D11InputLayout* inputLayouts;


	void Initialize();
	void Release();
}