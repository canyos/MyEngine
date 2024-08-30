#pragma once
#include "CommonInclude.h"
#include "pGameObject.h"

namespace p {
	class Application {
	public:
		Application();
		~Application();
		void Initialize(HWND hwnd);//초기화
		void Run();

		void Update();
		void LateUpdate();
		void Render();//바뀐위치로 다시 그려줌
	private:
		HWND mHwnd;
		HDC mHdc;

		GameObject mPlayer;
	};
}


