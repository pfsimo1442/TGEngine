#pragma once
#include "tgEntity.h"
#include "tgComponent.h"
#include "tgTexture.h"
#include "tgMaterial.h"
#include "tgMesh.h"

namespace tg
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		virtual ~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void SetSprite(graphics::Texture* sprite) { mSprite = sprite; }
		void SetMaterial(Material* material) { mMaterial = material; }

	private:
		graphics::Texture* mSprite;
		Material* mMaterial;
		Mesh* mMesh;
	};
}