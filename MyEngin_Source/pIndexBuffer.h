#pragma once
#include "pGraphicDevice.h"

namespace p::graphics {
	class IndexBuffer : public GpuBuffer
	{
	public:
		IndexBuffer();
		~IndexBuffer();
		bool Create(const std::vector<UINT>& indices);
		void Bind()const;
		UINT GetIndexCount() const { return mIndexCount; }

	private:
		UINT mIndexCount;
	};
}


