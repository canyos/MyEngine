#pragma once
#include "../MyEngin_Source/pSceneManager.h"
#include "pPlayScene.h"
#include "pTitleScene.h"

namespace p {
	void LoadScenes() {
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		
		SceneManager::LoadScene(L"TitleScene");
	}
}
