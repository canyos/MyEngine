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
		//키보드입력받음
		//오른쪽 x+ 왼쪽 x-
		Input::Update();
		mPlayer.Update();

	}

	void p::Application::LateUpdate()
	{
	}

	void p::Application::Render() //처음만 그리는게 아니라 매번 새로 그림
	{
		mPlayer.Render(mHdc);
		
	}
}

