#pragma once
#include "CommonInclude.h"
#include "pGameObject.h"
#include "pSceneManager.h"

namespace p {
	class Application {
	public:
		Application();
		~Application();
		void Initialize(HWND hwnd, UINT width, UINT height);
		//�ʱ�ȭ
		void Run();

		void Update();
		void LateUpdate();
		void Render();//�ٲ���ġ�� �ٽ� �׷���
	private:
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
		void adjustWindowRect(const HWND &hwnd, const UINT &width, const UINT &height);
		void createBuffer(const UINT &width, const UINT &height);
		void InitializeEtc();
	private:
		HWND mHwnd;
		HDC mHdc;

		//dc�� �׸� �� �ִ� ��ȭ��
		//������ dc�Ѱ��� ���۸� �ΰ� ����� �Դٰ��� �ؾ���-> �츮�� dc�� �ϳ� �� �������
		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		//scene�� �ְ� scene�ȿ� object
		std::vector<Scene*> mScenes;
	};
}