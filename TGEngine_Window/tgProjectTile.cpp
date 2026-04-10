#include "tgProjectTile.h"

namespace tg
{
	void ProjectTile::Initialize()
	{
		GameObject::Initialize();
	}

	void ProjectTile::Update()
	{
		GameObject::Update();
	}

	void ProjectTile::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void ProjectTile::Render(const Matrix& view, const Matrix& projection)
	{
		GameObject::Render(view, projection);
	}
}