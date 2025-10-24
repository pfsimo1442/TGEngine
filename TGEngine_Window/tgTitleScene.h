#pragma once
#include "..\\TGEngine_SOURCE\\tgScene.h"

namespace tg
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class Camera* mMainCamera;
	};
}