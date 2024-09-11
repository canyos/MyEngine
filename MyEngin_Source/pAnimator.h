#pragma once
#include "pComponent.h"
#include "pAnimation.h"
#include "pTexture.h"

namespace p {
	class Animator : public Component
	{
	public:
		
		struct Event {
			void operator = (std::function<void()> func) {
				mEvent = func;
			}
			void operator()() {
				if (mEvent)
					mEvent;
			}
			std::function<void()> mEvent;
		};
		struct Events {
			Event mStartEvent;
			Event mCompleteEvent;
			Event mEndEvent;
		};
		Animator();
		~Animator();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void CreateAnimation(const std::wstring& name,
			graphics::Texture* spriteSheet, //�̹��� �ؽ���
			Vector2 leftTop, // �̹��� ���� ��ġ
			Vector2 size, //�̹��� �Ѱ��� ũ��
			Vector2 offset, //�߾��� ���� ������ ������
			UINT spriteLength, // �������� ������ �̹��� ����
			float duration); //����� ���ӽð�

		Animation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop = true);
		bool IsComplete() { return mActiveAnimation->IsComplete(); }
	private:
		std::map<std::wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool mbLoop; //������ ������
		std::map<std::wstring, Events*> mEvents;
	};
}


