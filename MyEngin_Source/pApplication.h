#pragma once
#include "CommonInclude.h"
#include "pGameObject.h"

namespace p {
	class Application {
	public:
		Application();
		~Application();
		void Initialize(HWND hwnd);//�ʱ�ȭ
		void Run();

		void Update();
		void LateUpdate();
		void Render();//�ٲ���ġ�� �ٽ� �׷���
	private:
		HWND mHwnd;
		HDC mHdc;

		GameObject mPlayer;
	};
}


