#pragma once
#include "pAnimation.h"
#include "pTime.h"
#include "pTransform.h"
#include "pGameObject.h"
#include "pAnimator.h"
#include "pRenderer.h"
#include "pCamera.h"

namespace p {
	Animation::Animation()
		:Resource(enums::eResourceType::Animation)
		, mAnimator(nullptr)
		, mTexture(nullptr)
		, mAnimationSheet{}
		, mIndex(-1)
		, mTime(0.0f)
		, mbComplete(false)
	{
	}
	Animation::~Animation() {
	}
	HRESULT Animation::Load(const std::wstring& path) {
		return E_NOTIMPL;
	}
	void Animation::CreateAnimation(const std::wstring & name, graphics::Texture * spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
	{
		mTexture = spriteSheet;
		for (size_t i = 0; i < spriteLength; i++) {
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + size.x*i;
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mAnimationSheet.push_back(sprite);
		}
	}

	void Animation::Update()
	{
		if (mbComplete)
			return;

		mTime += Time::DeltaTime();
		if (mAnimationSheet[mIndex].duration < mTime) { //지속시간이 지나면
			mTime = 0.0f;
			if (mIndex < mAnimationSheet.size()-1) { //끝까지 재생했는지
				mIndex++; //인덱스 추가
			}
			else {
				mbComplete = true; //완료했다고 변경
			}
		}

	}

	void Animation::Render(HDC hdc)
	{
		//알파블렌드 쓸 수 있는 조건 : 알파 채널이 있어야함
		if (mTexture == nullptr)return;

		GameObject* gameObj = mAnimator->GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (renderer::mainCamera) {
			pos = renderer::mainCamera->CalculatePosition(pos);
		}

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 255; //(0투명~255불투명)

		Sprite sprite = mAnimationSheet[mIndex];
		HDC imgHdc = mTexture->GetHdc();
		AlphaBlend(hdc, pos.x, pos.y,
			sprite.size.x, sprite.size.y,
			imgHdc, sprite.leftTop.x, sprite.leftTop.y,
			sprite.size.x, sprite.size.y, func);
	}
	
	void Animation::Reset()
	{
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}
}