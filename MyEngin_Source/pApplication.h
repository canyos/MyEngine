#pragma once
#include "CommonInclude.h"
#include "pGameObject.h"

namespace p {
	class Application {
	public:
		Application();
		~Application();
		void Initialize(HWND hwnd, UINT width, UINT height);//�ʱ�ȭ
		void Run();

		void Update();
		void LateUpdate();
		void Render();//�ٲ���ġ�� �ٽ� �׷���
	private:
		HWND mHwnd;
		HDC mHdc;

		//dc�� �׸� �� �ִ� ��ȭ��
		//������ dc�Ѱ��� ���۸� �ΰ� ����� �Դٰ��� �ؾ���-> �츮�� dc�� �ϳ� �� �������
		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		GameObject mPlayer;
	};
}


