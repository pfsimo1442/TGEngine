#pragma once
#include "tgGraphicDevice_DX11.h"

namespace tg::graphics
{
	class ConstantBuffer : public GpuBuffer
	{
	public:
		ConstantBuffer(eCBType type);
		virtual ~ConstantBuffer();

		bool Create(UINT size, void* data = nullptr);

		[[noreturn]] void SetData(void* data) const;
		[[noreturn]] void Bind(eShaderStage stage) const;

	private:
		UINT mSize;
		eCBType mType;
	};
}