#include "tgTilemapRenderer.h"
#include "tgGameObject.h"
#include "tgTransform.h"
#include "tgTexture.h"
#include "tgRenderer.h"
#include "tgCamera.h"

namespace tg
{
	Vector2 TilemapRenderer::TileSize = Vector2::One;
	Vector2 TilemapRenderer::OriginTileSize = Vector2::One;
	Vector2 TilemapRenderer::SelectedCell = Vector2(-1.0f, -1.0f);

	TilemapRenderer::TilemapRenderer()
		: Component(eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mSize(Vector2::One)
		, mCell(Vector2::Zero)
		, mTileSize(Vector2::One)
	{
		TileSize = mTileSize * mSize;
		OriginTileSize = mTileSize;
	}
	TilemapRenderer::~TilemapRenderer()
	{
	}

	void TilemapRenderer::Initialize()
	{

	}

	void TilemapRenderer::Update()
	{

	}

	void TilemapRenderer::LateUpdate()
	{

	}

	void TilemapRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			assert(false);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Vector2 posStyle = tr->GetPositionStyle();
		float rot = tr->GetRotation();

		pos = renderer::mainCamera->CalculatePosition(pos);

		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			if (mTexture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(hdc
					, pos.x - (mTileSize.x * posStyle.x * mSize.x), pos.y - (mTileSize.y * posStyle.y * mSize.y)
					, mTileSize.x * mSize.x, mTileSize.y * mSize.y
					, mTexture->GetHdc()
					, mCell.x * mTileSize.x, mCell.y * mTileSize.y
					, mTileSize.x, mTileSize.y
					, func);
			}
			else
			{
				TransparentBlt(hdc
					, pos.x - (mTileSize.x * posStyle.x * mSize.x), pos.y - (mTileSize.y * posStyle.y * mSize.y)
					, mTileSize.x * mSize.x, mTileSize.y * mSize.y
					, mTexture->GetHdc()
					, mCell.x * OriginTileSize.x, mCell.y * OriginTileSize.y
					, OriginTileSize.x, OriginTileSize.y
					, RGB(255, 0, 255));
			}
		}
	}
}