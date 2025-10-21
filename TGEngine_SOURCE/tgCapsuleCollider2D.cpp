#include "tgCapsuleCollider2D.h"
#include "tgTransform.h"
#include "tgGameObject.h"
#include "tgRenderer.h"
#include "tgCamera.h"

namespace tg
{
    CapsuleCollider2D::CapsuleCollider2D()
        : Collider(eColliderType::Capsule2D)
    {
    }
    CapsuleCollider2D::~CapsuleCollider2D()
    {
    }

    void CapsuleCollider2D::Initialize()
    {

    }

    void CapsuleCollider2D::Update()
    {

    }

    void CapsuleCollider2D::LateUpdate()
    {

    }

    void CapsuleCollider2D::Render(HDC hdc)
    {
        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();
        if (renderer::mainCamera)
            pos = renderer::mainCamera->CalculatePosition(pos);
        Vector2 offset = GetOffset();

        float height = GetSize().y;
        float radius = GetSize().x / 2;

        HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

        HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
        HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

        Arc(hdc
            , (int)(pos.x + offset.x - radius), (int)(pos.y + offset.y - (height / 2))
            , (int)(pos.x + offset.x + radius), (int)(pos.y + offset.y - (height / 2) + 2 * radius)
            , (int)(pos.x + offset.x + radius), (int)(pos.y + offset.y - (height / 2 - radius))
            , (int)(pos.x + offset.x - radius), (int)(pos.y + offset.y - (height / 2 - radius)));
        ::Rectangle(hdc
            , (int)(pos.x + offset.x - radius), (int)(pos.y + offset.y - (height / 2 - radius))
            , (int)(pos.x + offset.x + radius), (int)(pos.y + offset.y + (height / 2 - radius)));
        Arc(hdc
            , (int)(pos.x + offset.x - radius), (int)(pos.y + offset.y + (height / 2) - 2 * radius)
            , (int)(pos.x + offset.x + radius), (int)(pos.y + offset.y + (height / 2))
            , (int)(pos.x + offset.x - radius), (int)(pos.y + offset.y + (height / 2 - radius))
            , (int)(pos.x + offset.x + radius), (int)(pos.y + offset.y + (height / 2 - radius)));

        SelectObject(hdc, oldBrush);
        SelectObject(hdc, oldPen);
        DeleteObject(greenPen);
    }
}