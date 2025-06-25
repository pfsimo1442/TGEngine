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

        void SetPosition(Vector2 pos) { mPosition = pos; }
        Vector2 GetPosition() { return mPosition; }
        void SetScale(Vector2 scale) { mScale = scale; }
        Vector2 GetScale() { return mScale; }
        void SetPositionStyle(Vector2 define) { mPositionStyle = define; }
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