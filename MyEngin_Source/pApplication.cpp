#include "pApplication.h"
#include "pInput.h"
#include "pTime.h"

namespace p {
	Application::Application() :mHwnd(nullptr), mHdc(nullptr), mHeight(0), mWidth(0), mBackHdc(NULL), mBackBitmap(NULL)
	{
	}
	Application::~Application()
	{
	}
	void p::Application::Initialize(HWND hwnd,UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0,0,width,height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);//윈도우 설정해줌

		mWidth = rect.right - rect.left, mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);//윈도우 위치, 크기 설정
		ShowWindow(mHwnd, true);

		//윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);
		
		//백버퍼를 가르킬 dc생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);


		mPlayer.SetPosition(0, 0);
		Input::Initialize();
		Time::Initialize();
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
		
		Time::Update();
	}

	void p::Application::LateUpdate()
	{
	}

	void p::Application::Render() //처음만 그리는게 아니라 매번 새로 그림
	{
		//Rectangle(mHdc, 0, 0, 1600, 900);//매번 배경 새로 그려 잔상 지움-> 깜빡거림(flickering) 문제
		//window의 크기가 1600,900 이므로 실제 그릴 수 있는 영역은 더 작음
		//더블 버퍼링으로 해결
		//dc를 두개 그려 번갈아가면서 화면에 출력
		Rectangle(mBackHdc, 0, 0, 1600, 900);


		mPlayer.Render(mBackHdc);
		Time::Render(mBackHdc);

		//backbuffer를 원본 버퍼로 복사
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}

