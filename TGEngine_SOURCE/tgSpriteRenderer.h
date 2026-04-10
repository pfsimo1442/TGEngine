#pragma once
#include "tgComponent.h"
#include "tgTexture.h"
#include "tgMaterial.h"
#include "tgMesh.h"
#include "tgBaseRenderer.h"

namespace tg
{
	class SpriteRenderer : public BaseRenderer
	{
	public:
		SpriteRenderer();
		virtual ~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(const Matrix& view, const Matrix& projection) override;

		void SetSprite(graphics::Texture* sprite) { mSprite = sprite; }

	private:
		graphics::Texture* mSprite;
	};
}