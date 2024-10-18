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
		void SetData(void* data)const;
		void Bind(eShaderStage stage)const;
	private:
		UINT mSize;
		eCBType mType;
	};
}

