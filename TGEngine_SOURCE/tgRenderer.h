#pragma once
#include "tgCamera.h"
#include "tgGraphicDevice_DX11.h"

#include "tgMesh.h"
#include "tgConstantBuffer.h"

using namespace tg::math;
using namespace tg::graphics;

namespace tg::renderer
{
	extern Camera* mainCamera;

	extern std::vector<Vertex> vertexes;
	extern std::vector<UINT> indices;

	extern Mesh* mesh;
	extern ConstantBuffer constantBuffers[(UINT)eCBType::End];

	extern ID3D11Buffer* constantBuffer;
	extern ID3D11InputLayout* inputLayouts;

	void Initialize();
	void Release();
}