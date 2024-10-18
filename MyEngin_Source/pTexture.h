#pragma once
#include <DirectXTex.h>
#include <DirectXTex.inl>

#include"pResource.h"
#include "pGraphicDevice.h"

namespace p {
	namespace graphics {
		class Texture:public Resource
		{
		public:
			enum class eTextureType {
				Bmp,
				Png,
				None,
			};
			static Texture* Create(const std::wstring& name,UINT width, UINT height);

			Texture();
			~Texture();

			virtual HRESULT Save(const std::wstring& path) override;
			virtual HRESULT Load(const std::wstring& path) override;
			void Bind(eShaderStage stage, UINT startSlot);

			/*COLORREF GetPixel(int x, int y);

			UINT GetWidth() const { return mWidth; }
			void SetWidth(UINT width) { mWidth = width; }
			UINT GetHeight() const{ return mHeight; }
			void SetHeight(UINT height) { mHeight = height; }
			
			eTextureType GetTextureType() { return mType; }
			//Gdiplus::Image* GetImage() { return mImage; }
			bool IsAlpha() { return mbAlpha; }*/
		private:
			ScratchImage mImage;
			D3D11_TEXTURE2D_DESC mDesc; 
			Microsoft::WRL::ComPtr<ID3D11Texture2D> mTexture;

			Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mSRV;
			Microsoft::WRL::ComPtr<ID3D11RenderTargetView> mRTV;

			/*bool mbAlpha;
			eTextureType mType;
			

			UINT mWidth;
			UINT mHeight;

			//Gdiplus::Image* mImage;
			//HBITMAP mBitmap;
			//HDC mHdc;*/
		};
	}
}


