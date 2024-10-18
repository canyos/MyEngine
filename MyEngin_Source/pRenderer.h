#pragma once
#include "pCamera.h"
#include "pGraphicDevice.h"
#include "pMesh.h"
#include "pConstantBuffer.h"

using namespace p::math;
using namespace p::graphics;
namespace p {
	namespace renderer {
		extern Camera* mainCamera;

		extern graphics::ConstantBuffer constantBuffers[(UINT)eCBType::End];
		extern Mesh* mesh;

		extern ID3D11Buffer* constantBuffer;
		extern ID3D11InputLayout* inputLayouts;

		void Initialize();
		void Release();
	}

}


