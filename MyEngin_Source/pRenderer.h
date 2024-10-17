#pragma once
#include "pCamera.h"
#include "pGraphicDevice.h"
#include "pVertexBuffer.h"
#include "pIndexBuffer.h"
#include "pConstantBuffer.h"
using namespace p::math;
using namespace p::graphics;
namespace p {
	namespace renderer {
		extern Camera* mainCamera;

		extern std::vector<graphics::Vertex> vertexes;
		extern std::vector<UINT> indices;

		extern graphics::VertexBuffer vertexBuffer;
		extern graphics::IndexBuffer indexBuffer;
		extern graphics::ConstantBuffer constantBuffers[(UINT)eCBType::End];

		extern ID3D11Buffer* constantBuffer;
		extern ID3D11InputLayout* inputLayouts;

		void Initialize();
		void Release();
	}

}


