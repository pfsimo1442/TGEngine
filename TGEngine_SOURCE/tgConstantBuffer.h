#pragma once
#include "tgGraphicDevice_DX11.h"

namespace tg::graphics
{
	class ConstantBuffer : public GpuBuffer
	{
	public:
		ConstantBuffer(eCBType type);
		~ConstantBuffer();

		bool Create(UINT size, void* data = NULL);

		void SetData(void* data) const;
		void Bind(eShaderStage stage) const;

	private:
		UINT mSize;
		eCBType mType;
	};
}