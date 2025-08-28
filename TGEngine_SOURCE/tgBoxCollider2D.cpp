#include "tgBoxCollider2D.h"
#include "tgTransform.h"
#include "tgGameObject.h"
#include "tgRenderer.h"
#include "tgCamera.h"

namespace tg
{
    BoxCollider2D::BoxCollider2D()
        : Collider(eColliderType::Box2D)
    {
    }
    BoxCollider2D::~BoxCollider2D()
    {
    }

    void BoxCollider2D::Initialize()
    {

    }

    void BoxCollider2D::Update()
    {

    }

    void BoxCollider2D::LateUpdate()
    {

    }

    void BoxCollider2D::Render(HDC hdc)
    {
        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();
        if (renderer::mainCamera)
            pos = renderer::mainCamera->CalculatePosition(pos);
        Vector2 offset = GetOffset();

        Vector2 size = GetSize();

        HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);
        HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
        HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

        ::Rectangle(hdc
            , pos.x + offset.x - (size.x / 2), pos.y + offset.y - (size.y / 2)
            , pos.x + offset.x + (size.x / 2), pos.y + offset.y + (size.y / 2));
        
        SelectObject(hdc, oldBrush);
        SelectObject(hdc, oldPen);
        DeleteObject(greenPen);
    }
}