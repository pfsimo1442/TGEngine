#include "tgTransform.h"

namespace tg
{
    Transform::Transform()
        : Component(enums::eComponentType::Transform)
        , mPositionStyle(Vector2(0.5f, 0.5f))
        , mScale(Vector2::One)
        , mRotation(0.0f)
    {
    }
    Transform::~Transform()
    {
    }
    void Transform::Initialize()
    {
    }
    void Transform::Update()
    {
    }
    void Transform::LateUpdate()
    {
    }
    void Transform::Render(HDC hdc)
    {
    }
}