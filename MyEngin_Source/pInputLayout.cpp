#include "pInputLayout.h"

namespace p::graphics
{
	InputLayout::InputLayout()
		: mInputLayout(nullptr)
	{
	}
	InputLayout::~InputLayout()
	{
	}
	void InputLayout::CreateInputLayout(UINT vertexCount, D3D11_INPUT_ELEMENT_DESC* layout
		, const void* pShaderBytecodeWithInputSignature, SIZE_T BytecodeLength)
	{
		if (FAILED(GetDevice()->CreateInputLayout(layout, vertexCount
			, pShaderBytecodeWithInputSignature
			, BytecodeLength
			, mInputLayout.GetAddressOf())))
			assert(NULL && "Create input layout failed!");
	}
	void InputLayout::Bind()
	{
		if (mInputLayout)
			GetDevice()->BindInputLayout(mInputLayout.Get());
	}
}