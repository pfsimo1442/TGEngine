#include "tgPlayer.h"
#include "tgInput.h"
#include "tgTransform.h"
#include "tgTime.h"

namespace tg 
{
    void Player::Initialize()
    {
        GameObject::Initialize();
    }

    void Player::Update()
    {
        GameObject::Update();
    }

    void Player::LateUpdate()
    {
        GameObject::LateUpdate();
    }

    void Player::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
}