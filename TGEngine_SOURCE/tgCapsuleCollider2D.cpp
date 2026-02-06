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

    void CapsuleCollider2D::Render()
    {
        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector3 pos = tr->GetPosition();
    }
}