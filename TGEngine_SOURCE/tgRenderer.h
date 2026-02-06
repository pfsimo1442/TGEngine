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

	extern Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerStates[(UINT)eSamplerType::End];
	extern Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerStates[(UINT)eRasterizerState::End];
	extern Microsoft::WRL::ComPtr<ID3D11BlendState> blendStates[(UINT)eBlendState::End];
	extern Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilStates[(UINT)eDepthStencilState::End];

	void Initialize();
	void Release();
}