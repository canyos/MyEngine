#pragma once
#include "pCamera.h"
#include "pGraphicDevice.h"
#include "pConstantBuffer.h"

using namespace p::math;
using namespace p::graphics;
namespace p {
	namespace renderer {
		extern Camera* mainCamera;

		extern graphics::ConstantBuffer* constantBuffers[(UINT)eCBType::End];
		extern Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerStates[(UINT)eSamplerType::End];
		extern Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerStates[(UINT)eRasterizerState::End];
		extern Microsoft::WRL::ComPtr<ID3D11BlendState> blendStates[(UINT)eBlendState::End];
		extern Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilStates[(UINT)eDepthStencilState::End];

		void Initialize();
		void Release();
	}

}


