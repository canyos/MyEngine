#pragma once
#include "pGraphicDevice.h"

namespace p::graphics
{
	class ConstantBuffer : public GpuBuffer
	{
	public:
		ConstantBuffer(eCBType type);
		~ConstantBuffer();
		bool Create(UINT size, void* data = NULL);
		void SetData(void* data)const;
		void Bind(eShaderStage stage)const;
	private:
		UINT mSize;
		eCBType mType;
	};
}

