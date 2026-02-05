#include "tgSpriteRenderer.h"
#include "tgGameObject.h"
#include "tgTransform.h"
#include "tgRenderer.h"

#include "tgResources.h"

namespace tg
{
	SpriteRenderer::SpriteRenderer()
		: Component(eComponentType::SpriteRenderer)
		, mSprite(nullptr)
		, mMaterial(nullptr)
		, mMesh(nullptr)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Initialize()
	{
		mMesh = Resources::Find<Mesh>(L"RectMesh");

		mMaterial = Resources::Find<Material>(L"Sprite-Default-Material");
	}

	void SpriteRenderer::Update()
	{
		
	}
	
	void SpriteRenderer::LateUpdate()
	{
	
	}

	void SpriteRenderer::Render()
	{
		if (mMesh)
			mMesh->Bind();

		if (mMaterial)
			mMaterial->BindShader();

		if (mSprite)
			mSprite->Bind(eShaderStage::PS, (UINT)eTextureType::Albedo);

		if (mMesh)
			graphics::GetDevice()->DrawIndexed(mMesh->GetIndexCount(), 0, 0);
	}
}