#pragma once
#include "pGraphicDevice.h"

namespace p::graphics
{
	class InputLayout
	{
	public:
		InputLayout();
		~InputLayout();
		void CreateInputLayout(UINT vertexCount, D3D11_INPUT_ELEMENT_DESC* layout, const void* pShaderBytecodeWithInputSignature, SIZE_T BytecodeLength);
		void Bind();
	private:
		Microsoft::WRL::ComPtr<ID3D11InputLayout> mInputLayout;
	};
}

