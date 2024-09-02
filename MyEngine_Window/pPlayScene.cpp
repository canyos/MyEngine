#include "pPlayScene.h"
#include "pGameObject.h"
namespace p {
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		GameObject* obj = new GameObject();
		AddGameObject(obj);
	}

	void PlayScene::Update()
	{
		Scene::Update();//부모 업데이트 호출
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

}

