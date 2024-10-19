#pragma once
#include "pCamera.h"
#include "pGraphicDevice.h"
#include "pConstantBuffer.h"

using namespace p::math;
using namespace p::graphics;
namespace p {
	namespace renderer {
		extern Camera* mainCamera;

		extern graphics::ConstantBuffer constantBuffers[(UINT)eCBType::End];

		void Initialize();
		void Release();
	}

}


