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

    void Tile::Render(const Matrix& view, const Matrix& projection)
    {
        GameObject::Render(view, projection);
    }
}
