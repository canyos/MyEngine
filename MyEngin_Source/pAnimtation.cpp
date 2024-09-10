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
		float rot = tr->GetRoation();
		Vector2 scale = tr->GetScale();

		if (renderer::mainCamera) {
			pos = renderer::mainCamera->CalculatePosition(pos);
		}

		Sprite sprite = mAnimationSheet[mIndex];
		graphics::Texture::eTextureType type = mTexture->GetTextureType();

		
		if (type == graphics::Texture::eTextureType::Bmp) {
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			func.SourceConstantAlpha = 255; //(0투명~255불투명)

			HDC imgHdc = mTexture->GetHdc();

			AlphaBlend(hdc, 
				pos.x - (sprite.size.x/2.0f), 
				pos.y - (sprite.size.y / 2.0f),
				sprite.size.x*scale.x, 
				sprite.size.y*scale.y,
				imgHdc, sprite.leftTop.x, sprite.leftTop.y,
				sprite.size.x, sprite.size.y, func);
		}

		if (type == graphics::Texture::eTextureType::Png) {
			//내가 원하는 픽셀을 투명화 시킬 때
			Gdiplus::ImageAttributes imgAtt = {};

			//투명화 시킬 픽셀의 색 범위
			imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));
			Gdiplus::Graphics graphics(hdc);
			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);
			//왼쪽 위 기준으로 회전시킴, 중앙을 기준으로 회전시키고 싶음

			graphics.DrawImage(mTexture->GetImage(),
				Gdiplus::Rect(
					pos.x - (sprite.size.x / 2.0f),
					pos.y - (sprite.size.y / 2.0f),
					sprite.size.x*scale.x,
					sprite.size.y*scale.y
				),
				sprite.leftTop.x, sprite.leftTop.y,
				sprite.size.x, 
				sprite.size.y,
				Gdiplus::UnitPixel,
				&imgAtt
				//nullptr
			);
		}

		
	}
	
	void Animation::Reset()
	{
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}
}