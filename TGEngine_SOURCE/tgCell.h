#pragma once
#include "tgResource.h"
#include "tgTexture.h"

namespace tg
{
	class Cell : public Resource
	{
	public:
		static Cell* Create(const std::wstring& name, UINT size);

		Cell();
		~Cell();

		virtual HRESULT Load(const std::wstring& path) override;

		UINT GetSize() { return mSize; }
		void SetSize(UINT size) { mSize = size; mTextures.resize(size); }
		graphics::Texture* GetTexture(UINT n) { return mTextures[n]; }
		void SetTexture(graphics::Texture* texture, UINT n) { mTextures[n] = texture; }

	private:
		UINT mSize;
		std::vector<graphics::Texture*> mTextures;
	};
}