#pragma once
#include "tgCamera.h"
#include "tgGraphicDevice_DX11.h"

#include "tgConstantBuffer.h"

using namespace tg::math;
using namespace tg::graphics;

namespace tg::renderer
{
	extern Camera* mainCamera;

	extern ConstantBuffer constantBuffers[(UINT)eCBType::End];

	extern Microsoft::WRL::ComPtr <ID3D11InputLayout> inputLayout;

	void Initialize();
	void Release();
}