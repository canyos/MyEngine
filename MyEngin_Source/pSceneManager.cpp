#include "pSceneManager.h"

namespace p {
	std::map<const std::wstring, Scene*> SceneManager::mScene;
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
	}
	Scene* SceneManager::LoadScene(const std::wstring & name)
	{
		if (mActiveScene)
			mActiveScene->OnExit();
		std::map<const std::wstring, Scene*>::iterator iter = mScene.find(name);
		if (iter == mScene.end())
			return nullptr;
		mActiveScene = iter->second;
		mActiveScene->OnEnter();
		return iter->second;
	}
	void SceneManager::Update()
	{
		mActiveScene->Update();
	}
	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}
	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}
}

