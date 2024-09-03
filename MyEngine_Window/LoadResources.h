#pragma once
#include "pResources.h"
#include "pTexture.h"
namespace p {
	void LoadResources() {
		Resources::Load<graphics::Texture>(L"Map", L"..\\MyEngine_Window\\Resources\\img\\map\\map_pure.png");
		Resources::Load<graphics::Texture>(L"PACMAN", L"..\\MyEngine_Window\\Resources\\img\\pacman\\1.png");
	}
}
