#pragma once
#include "tgCollider.h"

namespace tg
{
	class BoxCollider2D : public Collider
	{
	public:
		BoxCollider2D();
		virtual ~BoxCollider2D();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:

	};
}