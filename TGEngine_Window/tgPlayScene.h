#pragma once
#include "..\\TGEngine_SOURCE\\tgScene.h"

namespace tg
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;
		
		void OnEnter() override;
		void OnExit() override;

	private:
		class Player* mPlayer;
		class Camera* mMainCamera;
	};
}