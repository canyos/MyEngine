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
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);//������ ��������

		mWidth = rect.right - rect.left, mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);//������ ��ġ, ũ�� ����
		ShowWindow(mHwnd, true);

		//������ �ػ󵵿� �´� �����(��ȭ��) ����
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);
		
		//����۸� ����ų dc����
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
		//Ű�����Է¹���
		//������ x+ ���� x-
		Input::Update();
		mPlayer.Update();
		
		Time::Update();
	}

	void p::Application::LateUpdate()
	{
	}

	void p::Application::Render() //ó���� �׸��°� �ƴ϶� �Ź� ���� �׸�
	{
		//Rectangle(mHdc, 0, 0, 1600, 900);//�Ź� ��� ���� �׷� �ܻ� ����-> �����Ÿ�(flickering) ����
		//window�� ũ�Ⱑ 1600,900 �̹Ƿ� ���� �׸� �� �ִ� ������ �� ����
		//���� ���۸����� �ذ�
		//dc�� �ΰ� �׷� �����ư��鼭 ȭ�鿡 ���
		Rectangle(mBackHdc, 0, 0, 1600, 900);


		mPlayer.Render(mBackHdc);
		Time::Render(mBackHdc);

		//backbuffer�� ���� ���۷� ����
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}

