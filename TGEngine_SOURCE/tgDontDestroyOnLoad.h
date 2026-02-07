#pragma once
#include "tgScene.h"

namespace tg
{
	class DontDestroyOnLoad : public Scene
	{
	public:
		DontDestroyOnLoad();
		virtual ~DontDestroyOnLoad();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnEnter() override;
		void OnExit() override;
	};
}