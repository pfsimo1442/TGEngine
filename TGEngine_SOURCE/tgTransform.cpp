#include "tgTransform.h"

namespace tg
{
    Transform::Transform()
        : Component(eComponentType::Transform)
        , mPositionStyle(Vector2(0.0f, 0.0f))
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
    void Transform::Render()
    {
    }
}