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

    void BoxCollider2D::Render()
    {
        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector3 pos = tr->GetPosition();
    }
}