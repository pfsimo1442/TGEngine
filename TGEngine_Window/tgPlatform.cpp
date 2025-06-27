#include "tgPlatform.h"

namespace tg
{
    Platform::Platform()
    {
    }
    Platform::~Platform()
    {
    }

    void Platform::Initialize()
    {
        GameObject::Initialize();
    }

    void Platform::Update()
    {
        GameObject::Update();
    }

    void Platform::LateUpdate()
    {
        GameObject::LateUpdate();
    }

    void Platform::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
}