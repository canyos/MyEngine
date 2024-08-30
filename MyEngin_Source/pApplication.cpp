#include "pApplication.h"
#include "pInput.h"
namespace p {
	Application::Application():mHwnd(nullptr), mHdc(nullptr)
	{
	}
	Application::~Application()
	{
	}
	void p::Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
		mPlayer.SetPosition(0, 0);
		Input::Initialize();
	}

	void p::Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void p::Application::Update()
	{
		//Ű�����Է¹���
		//������ x+ ���� x-
		Input::Update();
		mPlayer.Update();

	}

	void p::Application::LateUpdate()
	{
	}

	void p::Application::Render() //ó���� �׸��°� �ƴ϶� �Ź� ���� �׸�
	{
		mPlayer.Render(mHdc);
		
	}
}

