#pragma once
#include "..//TGEngine_CORE//tgGameObject.h"

namespace tg
{
	class ProjectTile : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(const Matrix& view, const Matrix& projection) override;
	};
}