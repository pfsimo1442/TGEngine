#pragma once
#include "..//TGEngine_CORE//tgGameObject.h"

namespace tg
{

    class
        Platform : public GameObject
    {
    public:
        Platform();
        ~Platform();

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(const Matrix& view, const Matrix& projection) override;

    private:

    };
}