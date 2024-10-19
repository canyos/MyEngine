#pragma once
#include "pResource.h"
#include "pTexture.h"
#include "pShader.h"

namespace p {
	class Material : public Resource
	{
	public:
		struct Data
		{
			std::wstring albedo; //diffuse
		};

		Material();
		virtual ~Material();
		virtual HRESULT Save(const std::wstring& path) override;
		virtual HRESULT Load(const std::wstring& path) override;
		void Bind();
		void SetShader(graphics::Shader* shader) { mShader = shader; }
		void SetAlbedoTexture(graphics::Texture* texture) { mAlbedoTexture = texture; mData.albedo = texture->GetName(); }
	private:
		graphics::eRenderingMode mMode;
		Material::Data mData;

		//Texture* mTexture;
		graphics::Texture* mAlbedoTexture;
		graphics::Shader* mShader;
	};
}


