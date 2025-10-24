#pragma once
#include "..\\TGEngine_SOURCE\\tgGameObject.h"

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
        void Render() override;

    private:

    };
}