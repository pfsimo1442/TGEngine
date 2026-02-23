#pragma once
#include "..//TGEngine_SOURCE//tgScript.h"
#include "..//TGEngine_SOURCE//tgTexture.h"

namespace tg
{
	class ProjectTileScript : public Script
	{
	public:
		ProjectTileScript();
		virtual ~ProjectTileScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

	private:

	};
}