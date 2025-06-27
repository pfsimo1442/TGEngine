#pragma once
#include "..\\TGEngine_SOURCE\\tgScript.h"

namespace tg
{
	class PlatformScript : public Script
	{
	public:
		PlatformScript();
		~PlatformScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

	private:

	};
}

