#include "tgCircleCollider2D.h"
#include "tgTransform.h"
#include "tgGameObject.h"
#include "tgRenderer.h"
#include "tgCamera.h"

namespace tg
{
    CircleCollider2D::CircleCollider2D()
        : Collider(eColliderType::Circle2D)
		, mRadius(0.0f)
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

    void CircleCollider2D::Render()
    {
        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector3 pos = tr->GetPosition();
    }
}