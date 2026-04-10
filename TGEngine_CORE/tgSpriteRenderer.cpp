#include "tgSpriteRenderer.h"
#include "tgGameObject.h"
#include "tgTexture.h"
#include "tgRenderer.h"
#include "tgResources.h"

namespace tg
{
	SpriteRenderer::SpriteRenderer()
		: BaseRenderer(eComponentType::SpriteRenderer)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Initialize()
	{
		BaseRenderer::Initialize();

		Mesh* mesh = Resources::Find<Mesh>(L"RectMesh");
		Material* material = Resources::Find<Material>(L"SpriteDefaultMaterial");

		SetMesh(mesh);
		SetMaterial(material);
	}

	void SpriteRenderer::Update()
	{
		BaseRenderer::Update();
	}
	
	void SpriteRenderer::LateUpdate()
	{
		BaseRenderer::LateUpdate();
	}

	void SpriteRenderer::Render(const Matrix& view, const Matrix& projection)
	{
		BaseRenderer::Render(view, projection);

		if (mSprite)
			mSprite->Bind(eShaderStage::PS, (UINT)eTextureType::Sprite);

		BaseRenderer::Draw();
	}
}