#include "pPlayScene.h"
#include "pGameObject.h"
#include "pPlayer.h"
#include "pTransform.h"
#include "pSpriteRenderer.h"
#include "pInput.h"
#include "pTitleScene.h"
#include "pSceneManager.h"
#include "pObject.h"
namespace p
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		{
			//bg = new Player();
			//Transform* tr
			//	= bg->AddComponent<Transform>();
			//tr->SetPosition(Vector2(0, 0));

			//tr->SetName(L"TR");

			//SpriteRenderer* sr
			//	= bg->AddComponent<SpriteRenderer>();
			//sr->SetName(L"SR");
			//sr->ImageLoad(L"C:\\Users\\45819\\Documents\\github\\MyEngine\\Editor_Window\\Resources\\CloudOcean.png");


			//AddGameObject(bg, enums::eLayerType::BackGround);
			bg = object::Instantiate<Player>(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));
			SpriteRenderer* sr	= bg->AddComponent<SpriteRenderer>();
			sr->ImageLoad(L"C:\\Users\\45819\\Documents\\github\\MyEngine\\Editor_Window\\Resources\\CloudOcean.png");
		}
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::N)) {
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Play  Scene";
		TextOutW(hdc, 0, 0, str, lstrlenW(str));
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		Transform* tr= bg->GetComponent<Transform>();
		tr->SetPosition(Vector2(0, 0));
	}
}