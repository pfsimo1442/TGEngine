#pragma once
#include "tgGraphicDevice_DX11.h"

namespace tg::graphics
{
	class VertexBuffer : public GpuBuffer
	{
	public:
		VertexBuffer();
		~VertexBuffer();

		bool Create(const std::vector<Vertex>& vertexes);
		void Bind();

	private:

	};
}