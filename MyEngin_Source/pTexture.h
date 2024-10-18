#pragma once
#include"pResource.h"
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
			//COLORREF GetPixel(int x, int y);

			UINT GetWidth() const { return mWidth; }
			void SetWidth(UINT width) { mWidth = width; }
			UINT GetHeight() const{ return mHeight; }
			void SetHeight(UINT height) { mHeight = height; }
			
			eTextureType GetTextureType() { return mType; }
			//Gdiplus::Image* GetImage() { return mImage; }
			bool IsAlpha() { return mbAlpha; }
		private:
			bool mbAlpha;
			eTextureType mType;
			//Gdiplus::Image* mImage;
			//HBITMAP mBitmap;
			// m;

			UINT mWidth;
			UINT mHeight;
		};
	}
}


