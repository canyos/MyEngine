#include "pSpriteRenderer.h"
#include "pGameObject.h"
#include "pTransform.h"
#include "pTexture.h"
#include "pRenderer.h"
namespace p
{
	SpriteRenderer::SpriteRenderer(): Component(enums::eComponentType::SpriteRenderer), mTexture(nullptr), mSize(math::Vector2::One)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr)//텍스처 세팅 안됨
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos = renderer::mainCamera->CalculatePosition(pos);
		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp) {
			TransparentBlt(hdc, pos.x, pos.y, 
				mTexture->GetWidth()*mSize.x, mTexture->GetHeight()*mSize.y, 
				mTexture->GetHdc(), 0, 0, 
				mTexture->GetWidth(), mTexture->GetHeight(), RGB(255, 0, 255));
		}
		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png) {
			Gdiplus::Graphics graphcis(hdc);
			graphcis.DrawImage(mTexture->GetImage(), Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth()*mSize.x, mTexture->GetHeight()*mSize.y));
		}

	}

}