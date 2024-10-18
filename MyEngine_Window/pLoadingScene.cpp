#include "pLoadingScene.h"
#include "pRenderer.h"
#include "pSceneManager.h"
#include "pResources.h"
#include "pTexture.h"

namespace p {
	LoadingScene::LoadingScene()
		: mbLoadCompleted(false)
		, mMutualExclusion()
		, mResourcesLoadThread()
	{
	}
	LoadingScene::~LoadingScene()
	{
		delete mResourcesLoadThread;
		mResourcesLoadThread = nullptr;
	}
	void LoadingScene::Initialize()
	{
		mResourcesLoadThread = new std::thread(&LoadingScene::resourcesLoad, this, std::ref(mMutualExclusion));
	}
	void LoadingScene::Update()
	{
		if (mbLoadCompleted)
		{
			//만약 메인쓰레드가 종료되는데 자식쓰레드가 남아있다면
			//자식쓰레드를 메인쓰레드에 편입시켜 메인쓰레드가 종료되기전까지 block
			mResourcesLoadThread->join();

			//메인쓰레드와 완전 분리 시켜 독립적인 쓰레드 운영가능
			//mResourcesLoadThread->detach();
			SceneManager::LoadScene(L"PlayScene");
		}
	}
	void LoadingScene::LateUpdate()
	{
	}
	void LoadingScene::Render()
	{
	}
	void LoadingScene::OnEnter()
	{
	}
	void LoadingScene::OnExit()
	{
	}
	//다른 쓰레드에서 실행할 함수
	void LoadingScene::resourcesLoad(std::mutex& m)
	{
		m.lock();
		{
			Resources::Load<graphics::Texture>(L"Map", L"..\\Resources\\img\\map\\map_pure.png");
			Resources::Load<graphics::Texture>(L"PACMAN", L"..\\Resources\\img\\pacman\\1.png");
			Resources::Load<graphics::Texture>(L"Effect", L"..\\Resources\\effect2.png");
			Resources::Load<graphics::Texture>(L"ocean", L"..\\Resources\\CloudOcean.png");
			Resources::Load<graphics::Texture>(L"cat", L"..\\Resources\\ChickenAlpha.bmp");
			Resources::Load<graphics::Texture>(L"player", L"..\\Resources\\Player.bmp");
			Resources::Load<graphics::Texture>(L"SpringFloor", L"..\\Resources\\SpringFloor.bmp");
			Resources::Load<graphics::Texture>(L"HPBAR", L"..\\Resources\\HPBAR.bmp");
			Resources::Load<graphics::Texture>(L"PixelMap", L"..\\Resources\\pixelMap.bmp");
		}
		m.unlock();
		// complete
		mbLoadCompleted = true;

	}
}
