#pragma once
#include "tgResource.h"
#include "tgTexture.h"
#include "tgShader.h"

namespace tg
{
	class Material : public Resource
	{
	public:
		struct Data
		{
			std::wstring albedo;
		};

		Material();
		virtual ~Material();

		virtual HRESULT Save(const std::wstring& path) override;
		virtual HRESULT Load(const std::wstring& path) override;

		void Bind();

		void SetShader(graphics::Shader* shader) { mShader = shader; }

	private:
		graphics::eRenderingMode mMode;
		Material::Data mData;

		graphics::Shader* mShader;
	};
}