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

        if (Input::GetKey(eKeyCode::Arrow_Right))
        {
            Transform* tr = GetComponent<Transform>();
            Vector2 pos = tr->GetPosition();
            pos.x += 100.0f * Time::DeltaTime();
            tr->SetPosition(pos);
        }
    }

    void Player::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
}