#pragma once
#include "../MyEngin_Source/pSceneManager.h"
#include "pPlayScene.h"

namespace p {
	void LoadScenes() {
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::LoadScene(L"PlayScene");
	}
}
