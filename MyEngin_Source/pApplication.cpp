#include "pApplication.h"
#include "pInput.h"
#include "pTime.h"
#include "pSceneManager.h"
#include "pResources.h"
#include "pCollisionManager.h"
#include "pUIManager.h"
#include "pFmod.h"
#include "pRenderer.h"

namespace p {
	Application::Application() 
		:mHwnd(nullptr)
		, mHdc(nullptr)
		, mHeight(0)
		, mWidth(0)
		, mBackHdc(NULL)
		, mBackBitmap(NULL)
		, mbLoaded(false)
	{
	}
	Application::~Application()
	{
	}
	void Application::Initialize(HWND hwnd,UINT width, UINT height)
	{
		AdjustWindowRect(hwnd, width, height);
		InitializeEtc();

		mGraphicDevice = std::make_unique<graphics::GraphicDevice>();
		renderer::Initialize();
		mGraphicDevice->Initialize();

		Fmod::Initialize();
		CollisionManager::Initialize();
		UIManager::Initialize();
		SceneManager::Initialize();
		
	}
	void Application::AdjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0,0, (LONG)width, (LONG)height };
		::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);//������ ��������

		mWidth = rect.right - rect.left, mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);//������ ��ġ, ũ�� ����
		ShowWindow(mHwnd, true);
	}

	void Application::InitializeEtc()
	{
		Input::Initialize();
		Time::Initialize();
	}


	void Application::Run()
	{
		if (mbLoaded == false)
			mbLoaded = true;

		Update();
		LateUpdate();
		Render();

		Destroy();
	}

	void Application::Update()
	{
		//Ű�����Է¹���
		//������ x+ ���� x-
		Input::Update();
		Time::Update();

		CollisionManager::Update();
		UIManager::Update();
		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		CollisionManager::LateUpdate();
		UIManager::LateUpdate();
		SceneManager::LateUpdate();
	}

	void Application::Render() //ó���� �׸��°� �ƴ϶� �Ź� ���� �׸�
	{
		//Rectangle(m, 0, 0, 1600, 900);//�Ź� ��� ���� �׷� �ܻ� ����-> �����Ÿ�(flickering) ����
		//window�� ũ�Ⱑ 1600,900 �̹Ƿ� ���� �׸� �� �ִ� ������ �� ����
		//���� ���۸����� �ذ�
		//dc�� �ΰ� �׷� �����ư��鼭 ȭ�鿡 ���
		
		Time::Render();
		CollisionManager::Render();
		UIManager::Render();
		SceneManager::Render();

	}
	void Application::Destroy()
	{
		SceneManager::Destroy();
	}
	void Application::Release() {
		SceneManager::Release();
		UIManager::Release();
		Resources::Release();
		renderer::Release();
	}
}

