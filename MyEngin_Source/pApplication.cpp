#include "pApplication.h"
#include "pInput.h"
#include "pTime.h"
#include "pSceneManager.h"
#include "pResources.h"
#include "pCollisionManager.h"
#include "pUIManager.h"

namespace p {
	Application::Application() :mHwnd(nullptr), mHdc(nullptr), mHeight(0), mWidth(0), mBackHdc(NULL), mBackBitmap(NULL)
	{
	}
	Application::~Application()
	{
	}
	void Application::Initialize(HWND hwnd,UINT width, UINT height)
	{
		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);
		InitializeEtc();

		CollisionManager::Initialize();
		UIManager::Initialize();
		SceneManager::Initialize();
		
	}
	void Application::InitializeEtc()
	{
		Input::Initialize();
		Time::Initialize();
	}
	void Application::clearRenderTarget() {
		HBRUSH grayBrush = (HBRUSH)CreateSolidBrush(RGB(128,128,128));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHdc, grayBrush);

		Rectangle(mBackHdc, -1, -1, 1601, 901);
		(HBRUSH)SelectObject(mBackHdc, oldBrush);
		DeleteObject(grayBrush);
	}

	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}

	void Application::adjustWindowRect(const HWND &hwnd, const UINT &width, const UINT &height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0,0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);//������ ��������

		mWidth = rect.right - rect.left, mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);//������ ��ġ, ũ�� ����
		ShowWindow(mHwnd, true);
	}

	void Application::createBuffer(const UINT &width, const UINT &height)
	{
		//������ �ػ󵵿� �´� �����(��ȭ��) ����
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		//����۸� ����ų dc����
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}

	void Application::Run()
	{
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
		//Rectangle(mHdc, 0, 0, 1600, 900);//�Ź� ��� ���� �׷� �ܻ� ����-> �����Ÿ�(flickering) ����
		//window�� ũ�Ⱑ 1600,900 �̹Ƿ� ���� �׸� �� �ִ� ������ �� ����
		//���� ���۸����� �ذ�
		//dc�� �ΰ� �׷� �����ư��鼭 ȭ�鿡 ���

		clearRenderTarget();

		
		Time::Render(mBackHdc);
		CollisionManager::Render(mBackHdc);
		UIManager::Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		//backbuffer�� ���� ���۷� ����
		copyRenderTarget(mBackHdc, mHdc);
	}
	void Application::Destroy()
	{
		SceneManager::Destroy();
	}
	void Application::Release() {
		SceneManager::Release();
		UIManager::Release();
		Resources::Release();
	}
}

