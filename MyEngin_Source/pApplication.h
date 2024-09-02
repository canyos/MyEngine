#pragma once
#include "CommonInclude.h"
#include "pGameObject.h"

namespace p {
	class Application {
	public:
		Application();
		~Application();
		void Initialize(HWND hwnd, UINT width, UINT height);//초기화
		void Run();

		void Update();
		void LateUpdate();
		void Render();//바뀐위치로 다시 그려줌
	private:
		HWND mHwnd;
		HDC mHdc;

		//dc가 그릴 수 있는 도화지
		//원래는 dc한개에 버퍼를 두개 만들어 왔다갔다 해야함-> 우리는 dc를 하나 더 만들것임
		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		GameObject mPlayer;
	};
}


