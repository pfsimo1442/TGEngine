#pragma once
#include "tgCamera.h"

namespace tg
{
	class SceneCamera : public Camera
	{
	public:
		SceneCamera();
		virtual ~SceneCamera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(const Matrix& view, const Matrix& projection) override;
		void OnEvent(Event& e);

	private:

	};
}