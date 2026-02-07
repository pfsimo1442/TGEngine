#pragma once
#include "tgComponent.h"

namespace tg
{
	class AudioListener final : public Component
	{
	public:
		AudioListener();
		virtual ~AudioListener();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:
		bool mbIsVel;
	};
}