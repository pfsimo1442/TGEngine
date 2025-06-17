#pragma once
#include "tgEntity.h"
#include "tgComponent.h"

namespace tg
{
    using namespace math;
    class Transform : public Component
    {
    public:
        Transform();
        ~Transform();

        void Initialize() override;
        void Update()  override;
        void LateUpdate()  override;
        void Render(HDC hdc)  override;

        void SetPosition(Vector2 pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
        Vector2 GetPosition() { return mPosition; }
        void SetScale(Vector2 scale) { mScale.x = scale.x; mScale.y = scale.y; }
        Vector2 GetScale() { return mScale; }
        void SetPositionStyle(Vector2 define) { mPositionStyle.x = define.x; mPositionStyle.y = define.y; }
        Vector2 GetPositionStyle() { return mPositionStyle; }
        void SetRotation(float rotate) { mRotation = rotate; }
        float GetRotation() { return mRotation; }
        
    private:
        Vector2 mPosition;
        Vector2 mScale;
        Vector2 mPositionStyle;
        float mRotation;
    };
}