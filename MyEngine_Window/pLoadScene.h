#pragma once
#include "pSceneManager.h"
#include "pPlayScene.h"
#include "pTitleScene.h"
#include "pToolScene.h"
#include "pLoadingScene.h"
namespace p {
	void LoadScenes() {
		SceneManager::CreateScene<LoadingScene>(L"LoadingScene");
		SceneManager::LoadScene(L"LoadingScene");
	}
}
