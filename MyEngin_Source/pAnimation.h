#pragma once
#include "pResource.h"
#include "pTexture.h"
namespace p {
	class Animation : public Resource
	{
	public:
		struct Sprite {
			Vector2 leftTop; // �̹��� ���� ��ġ
			Vector2 size; //�̹��� �Ѱ��� ũ��
			Vector2 offset; //�߾��� ���� ������ ������
			float duration;
			Sprite()
				:leftTop(Vector2::Zero),
				size(Vector2::Zero),
				offset(Vector2::Zero),
				duration(0.0f)
			{

			}
		};
		Animation();
		~Animation();
		HRESULT Load(const std::wstring& path) override;
		void CreateAnimation(const std::wstring& name,
			graphics::Texture* spriteSheet, //�̹��� �ؽ���
			Vector2 leftTop, // �̹��� ���� ��ġ
			Vector2 size, //�̹��� �Ѱ��� ũ��
			Vector2 offset, //�߾��� ���� ������ ������
			UINT spriteLength, // �������� ������ �̹��� ����
			float duration); //����� ���ӽð�

		void Update();
		void Render(HDC hdc);
		void Reset();

		bool IsComplete() {	return mbComplete;	}
		void SetAnimator(class Animator* animator) { mAnimator = animator; }

	private:
		class Animator* mAnimator;
		graphics::Texture* mTexture;
		std::vector<Sprite> mAnimationSheet;
		int mIndex;// ����ε��� �������� 
		float mTime; //���ʴ����� �ѱ����
		bool mbComplete; //�ٽ� ���ư��� üũ
	};
}


