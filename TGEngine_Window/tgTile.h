#pragma once
#include "..\\TGEngine_SOURCE\\tgGameObject.h"

namespace tg
{
	class Tile : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTilePosition(Vector2 coord);

	private:

	};
}