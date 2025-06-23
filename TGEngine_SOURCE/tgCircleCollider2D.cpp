#include "tgCircleCollider2D.h"
#include "tgTransform.h"
#include "tgGameObject.h"
#include "tgRenderer.h"
#include "tgCamera.h"

namespace tg
{
    CircleCollider2D::CircleCollider2D()
        : Collider(eColliderType::Circle2D)
    {
    }
    CircleCollider2D::~CircleCollider2D()
    {
    }

    void CircleCollider2D::Initialize()
    {

    }

    void CircleCollider2D::Update()
    {

    }

    void CircleCollider2D::LateUpdate()
    {

    }

    void CircleCollider2D::Render(HDC hdc)
    {
        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();
        if (renderer::mainCamera)
            pos = renderer::mainCamera->CalculatePosition(pos);
        Vector2 offset = GetOffset();

        float radius = GetSize().x / 2;

        HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

        HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
        HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

        Ellipse(hdc
            , pos.x + offset.x - radius, pos.y + offset.y - radius
            , pos.x + offset.x + radius, pos.y + offset.y + radius);

        SelectObject(hdc, oldBrush);
        SelectObject(hdc, oldPen);
        DeleteObject(greenPen);
    }
}