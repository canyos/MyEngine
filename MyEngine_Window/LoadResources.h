#pragma once
#include "pResources.h"
#include "pTexture.h"

namespace p {
	void LoadResources() {
		Resources::Load<graphics::Texture>(L"Map", L"..\\MyEngine_Window\\Resources\\img\\map\\map_pure.png");
		Resources::Load<graphics::Texture>(L"PACMAN", L"..\\MyEngine_Window\\Resources\\img\\pacman\\1.png");
		Resources::Load<graphics::Texture>(L"Effect", L"..\\MyEngine_Window\\Resources\\effect2.png");
		Resources::Load<graphics::Texture>(L"ocean", L"..\\MyEngine_Window\\Resources\\CloudOcean.png");
		Resources::Load<graphics::Texture>(L"cat", L"..\\MyEngine_Window\\Resources\\ChickenAlpha.bmp");
		Resources::Load<graphics::Texture>(L"player", L"..\\MyEngine_Window\\Resources\\Player.bmp");
	}
}
