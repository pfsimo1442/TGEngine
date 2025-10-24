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
        void Render()  override;

        void SetPosition(Vector2 pos) { mPosition = pos; }
        void SetScale(Vector2 scale) { mScale = scale; }
        void SetPositionStyle(Vector2 define) { mPositionStyle = define; }
        void SetRotation(float rotate) { mRotation = rotate; }
        
        Vector2 GetPosition() const { return mPosition; }
        Vector2 GetScale() const { return mScale; }
        Vector2 GetPositionStyle() const { return mPositionStyle; }
        float GetRotation() const { return mRotation; }
        
    private:
        Vector2 mPosition;
        Vector2 mScale;
        Vector2 mPositionStyle;
        float mRotation;
    };
}