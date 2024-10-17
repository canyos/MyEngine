#pragma once
#include "pGraphicDevice.h"
namespace p::graphics {
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


