#pragma once
#include "tgGraphicDevice_DX11.h"

namespace tg::graphics
{
	class IndexBuffer : public GpuBuffer
	{
	public:
		IndexBuffer();
		virtual ~IndexBuffer();

		bool Create(const std::vector<UINT>& indices);
		void Bind() const;

		UINT GetIndexCount() const { return mIndexCount; }

	private:
		UINT mIndexCount;
	};
}