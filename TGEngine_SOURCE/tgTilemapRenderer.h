#pragma once
#include "tgEntity.h"
#include "tgComponent.h"
#include "tgTexture.h"

namespace tg
{
	class TilemapRenderer : public Component
	{
	public:
		TilemapRenderer();
		~TilemapRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void SetTexture(graphics::Texture* texture) { mTexture = texture; }
		void SetSize(Vector2 size) { mSize = size; TileSize = mTileSize * mSize; }
		void SetCellCoordination(Vector2 coord) { mCell = coord; }
		void SetTileSize(Vector2 size) { mTileSize = size; TileSize = mTileSize * mSize; OriginTileSize = mTileSize;}
		
		Vector2 GetCellCoordination() const { return mCell; }

	public:
		static Vector2 TileSize;
		static Vector2 OriginTileSize;
		static Vector2 SelectedCell;

	private:

		graphics::Texture* mTexture;
		Vector2 mSize;

		Vector2 mCell;
		Vector2 mTileSize;
	};
}