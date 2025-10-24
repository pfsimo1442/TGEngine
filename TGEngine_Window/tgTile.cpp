#include "tgTile.h"
#include "tgTransform.h"
#include "tgTilemapRenderer.h"

namespace tg
{
    void Tile::Initialize()
    {
        GameObject::Initialize();
    }

    void Tile::Update()
    {
        GameObject::Update();
    }

    void Tile::LateUpdate()
    {
        GameObject::LateUpdate();
    }

    void Tile::Render()
    {
        GameObject::Render();
    }

    void Tile::SetTilePosition(Vector2 coord)
    {
        Transform* tr = GetComponent<Transform>();
        Vector2 pos = coord * TilemapRenderer::TileSize;
        tr->SetPosition(pos);
    }
}
