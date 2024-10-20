#include "pTexture.h"
#include "pApplication.h"
#include "pResources.h"
//해당 전역변수를 알림
extern p::Application application;

namespace p {
	namespace graphics {
		/*Texture* Texture::Create(const std::wstring& name,UINT width, UINT height)
		{
			Texture* image = Resources::Find<Texture>(name);
			if (image)
				return image;

			image = new Texture();
			image->SetName(name);
			image->SetWidth(width);
			image->SetHeight(height);

			/*
			 = application.Get();
			HWND hwnd = application.GetHwnd();

			image->mBitmap = CreateCompatibleBitmap(, width, height);
			image->m = CreateCompatibleDC();

			HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
			HBRUSH oldBrush = (HBRUSH)SelectObject(, transparentBrush);

			::Rectangle(image->m,-1,-1,image->GetWidth()+1, image->GetHeight() + 1);
			SelectObject(, oldBrush);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(image->m, image->mBitmap);
			DeleteObject(oldBitmap);
			
			Resources::Insert(name + L"Image", image);
			
			return image;
		}*/
		Texture::Texture() : Resource(enums::eResourceType::Texture), mDesc{} {

		}
		Texture::~Texture() {

		}
		HRESULT Texture::Save(const std::wstring& path)
		{
			return E_NOTIMPL;
		}
		HRESULT Texture::Load(const std::wstring & path)
		{	
			std::wstring ext
				= path.substr(path.find_last_of(L".") + 1);
			/*
			//bmp 일때
			if (ext == L"bmp")
			{
				mType = eTextureType::Bmp;
				mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP
					, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

				if (mBitmap == nullptr)
					return S_FALSE;

				BITMAP info = {};
				GetObject(mBitmap, sizeof(BITMAP), &info);

				mWidth = info.bmWidth;
				mHeight = info.bmHeight;

				if (info.bmBitsPixel == 32) {
					mbAlpha = true;
				}
				else if (info.bmBitsPixel == 24) {
					mbAlpha = false;
				}

				 mainDC = application.Get();
				m = CreateCompatibleDC(mainDC);

				HBITMAP oldBitmap = (HBITMAP)SelectObject(m, mBitmap);
				DeleteObject(oldBitmap);

			}
			else if (ext == L"png")
			{
				mType = eTextureType::Png;
				mImage = Gdiplus::Image::FromFile(path.c_str());

				if (mImage == nullptr)
					return S_FALSE;

				mWidth = mImage->GetWidth();
				mHeight = mImage->GetHeight();
			}
			*/

			if (ext == L".dds" || ext == L".DDS")
			{
				if (FAILED(LoadFromDDSFile(path.c_str(), DDS_FLAGS::DDS_FLAGS_NONE, nullptr, mImage)))
					return S_FALSE;
			}
			else if (ext == L".tga" || ext == L".TGA")
			{
				if (FAILED(LoadFromTGAFile(path.c_str(), nullptr, mImage)))
					return S_FALSE;
			}
			else // WIC (png, jpg, jpeg, bmp )
			{
				if (FAILED(LoadFromWICFile(path.c_str(), WIC_FLAGS::WIC_FLAGS_NONE, nullptr, mImage)))
					return S_FALSE;
			}

			HRESULT hr = CreateShaderResourceView
			(
				graphics::GetDevice()->GetID3D11Device().Get()
				, mImage.GetImages()
				, mImage.GetImageCount()
				, mImage.GetMetadata()
				, mSRV.GetAddressOf()
			);
			if (hr == S_FALSE)
				assert(false/*"Textrue load fail!!"*/);
			mSRV->GetResource((ID3D11Resource**)mTexture.GetAddressOf());
			return S_OK;
		}

		/*COLORREF Texture::GetPixel(int x, int y)
		{
			return ::GetPixel(m, x, y);
		}*/

		void Texture::Bind(eShaderStage stage, UINT startSlot)
		{
			graphics::GetDevice()->SetShaderResource(stage, startSlot, mSRV.GetAddressOf());
		}
	}
}