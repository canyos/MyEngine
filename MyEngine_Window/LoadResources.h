#pragma once
#include "pResources.h"
#include "pTexture.h"

namespace p {
	void LoadResources() {
		Resources::Load<graphics::Texture>(L"BG", L"C:\\Users\\45819\\Documents\\github\\MyEngine\\Editor_Window\\CloudOcean.png");
	}
}
