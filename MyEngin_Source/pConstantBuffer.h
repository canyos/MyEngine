#pragma once
#include "pGraphicDevice.h"

namespace p::graphics
{
	class ConstantBuffer : public GpuBuffer
	{
	public:
		ConstantBuffer();
		~ConstantBuffer();
		bool Create(eCBType type, UINT size, void* data = NULL);
		void SetData(void* data);
		void Bind(eShaderStage stage);
	private:
		UINT mSize;
		eCBType mType;
	};
}

