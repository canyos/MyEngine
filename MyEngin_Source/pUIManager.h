#pragma once
#include "CommonInclude.h"
#include "pUIBase.h"

namespace p {
	using namespace enums;
	class UIManager
	{
	public:
		static void Initialize();
		static void OnLoad(eUIType type);
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void OnComplete(UIBase* addUI);
		static void OnFail();
		static void Release();

		static void Push(eUIType type);
		static void Pop(eUIType type);

	private:
		static std::unordered_map<eUIType, UIBase*> mUIs;//UI type�� ���� UIBase��
		static std::stack<UIBase*> mUIBases; //UI�� ����������
		static std::queue<eUIType> mRequestUiQueue; //�޼��� ť
		static UIBase* mActiveUI; 
	};
}


