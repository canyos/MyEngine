#include "pUIManager.h"
#include "pUIHUD.h"
#include "pUIButton.h"

namespace p {
	std::unordered_map<eUIType, UIBase*> UIManager::mUIs = {};
	std::stack<UIBase*> UIManager::mUIBases = {};
	std::queue<eUIType> UIManager::mRequestUiQueue = {};
	UIBase* UIManager::mActiveUI = nullptr;
	void UIManager::Initialize()
	{
		// UI ��ü �������ֱ�
		UIHUD* hud = new UIHUD();
		mUIs.insert(std::make_pair(eUIType::HpBar, hud));
		UIButton* button = new UIButton();
		mUIs.insert(std::make_pair(eUIType::Button, button));
	}
	void UIManager::OnLoad(eUIType type)
	{
		std::unordered_map<eUIType, UIBase*>::iterator iter = mUIs.find(type);
		if (iter == mUIs.end()) {//�ε� ����
			OnFail();
			return;
		}

		OnComplete(iter->second);//�ε� ����

	}
	void UIManager::Update()
	{
		std::stack<UIBase*> uiBases = mUIBases;
		
		while (!uiBases.empty()) { //���� ���� UI������Ʈ�ϱ�
			UIBase* uiBase = uiBases.top();
			uiBase->Update();
			uiBases.pop();
		}

		

		if (mRequestUiQueue.size() > 0) { //��������Ұ������� �ε��ϱ�
			eUIType requestUI = mRequestUiQueue.front();
			mRequestUiQueue.pop();
			OnLoad(requestUI);
		}
	}
	void UIManager::LateUpdate()
	{
		std::stack<UIBase*> uiBases = mUIBases;
		while (!uiBases.empty()) { //���� ���� UI������Ʈ�ϱ�
			UIBase* uiBase = uiBases.top();
			if (uiBase) {
				uiBase->LateUpdate();
				uiBases.pop();
			}
		}
	}
	void UIManager::Render(HDC hdc)
	{
		std::stack<UIBase*> uiBases = mUIBases;
		std::stack<UIBase*> tempStack = {};

		while (!uiBases.empty()) { //���� ���� UI������Ʈ�ϱ�
			UIBase* uiBase = uiBases.top();
			if (uiBase) {
				//uiBase->Render(hdc);
				tempStack.push(uiBase);
				uiBases.pop();
			}
		}
		while (!tempStack.empty()) { //���� ���� UI������Ʈ�ϱ�
			UIBase* uiBase = tempStack.top();
			if (uiBase) {
				uiBase->Render(hdc);
				tempStack.pop();
			}
		}
	}
	void UIManager::OnComplete(UIBase * addUI)
	{
		if (addUI == nullptr)
			return;

		addUI->Initialize();
		addUI->Active();
		addUI->Update();

		//���� ��üȭ�� UI�� �߰��ɰŶ��
		//������ ���� ��Ȱ��ȭ

		if (addUI->IsFullScreen()) {
			std::stack<UIBase*> uiBases = mUIBases;
			while (!uiBases.empty()) { 
				UIBase* uiBase = uiBases.top();
				uiBases.pop();
				if (uiBase) {
					uiBase->InActive();//��Ȱ��ȭ
				}
			}
		}

		mUIBases.push(addUI);
		mActiveUI = addUI;
		int a = 0;
	}
	void UIManager::OnFail()
	{
		mActiveUI = nullptr;
	}
	void UIManager::Release()
	{
		for (auto iter : mUIs)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
	void UIManager::Push(eUIType type)
	{
		mRequestUiQueue.push(type);
	}
	void UIManager::Pop(eUIType type)
	{
		if (mUIBases.size() <= 0)
			return;

		//�ش� ui �Ѱ��� ���ÿ��� ������
		std::stack<UIBase*> tempStack;
		UIBase* uiBase = nullptr;

		while (mUIBases.size() > 0) {
			uiBase = mUIBases.top();
			mUIBases.pop();

			if (uiBase->GetType() != type)//�ٸ��� ������ ����
			{
				tempStack.push(uiBase);
				continue;
			}

			if (uiBase->IsFullScreen()) //��üȭ���̸� �ؿ��� ���� Ȱ��ȭ
			{
				std::stack<UIBase*> uiBases = mUIBases;
				while (!uiBases.empty())
				{
					UIBase* uiBase = uiBases.top();
					uiBases.pop();
					if (uiBase)
					{
						uiBase->Active();
						break;
					}
				}
			}

			uiBase->UIClear();
		}

		while (tempStack.size() > 0)//temp�ٽ� ���� �־���
		{
			uiBase = tempStack.top();
			tempStack.pop();
			mUIBases.push(uiBase);
		}

		if (!mUIBases.empty())
			mActiveUI = nullptr;
		else
			mActiveUI = mUIBases.top();
	}
}
