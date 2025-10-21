#include "tgAnimation.h"
#include "tgTime.h"
#include "tgTransform.h"
#include "tgGameObject.h"
#include "tgAnimator.h"
#include "tgRenderer.h"
#include "tgCamera.h"

namespace tg
{
	Animation::Animation()
		: Resource(enums::eResourceType::Animation)
		, mAnimator(nullptr)
		, mTexture(nullptr)
		, mAnimationSheet{}
		, mIndex(-1)
		, mTime(0.0f)
		, mbComplete(false)
	{
	}
	Animation::~Animation()
	{
	}
	
	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	void Animation::Update()
	{
		if (mbComplete)
			return;

		mTime += Time::DeltaTime();

		if (mAnimationSheet[mIndex].duration < mTime)
		{
			mTime = 0.0f;
			if (mIndex < mAnimationSheet.size() - 1)
				mIndex++;
			else
				mbComplete = true;
		}
	}

	void Animation::Render(HDC hdc)
	{
		if (mTexture == nullptr)
			return;

		GameObject* gameObj = mAnimator->GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Vector2 posStyle = tr->GetPositionStyle();
		float rot = tr->GetRotation();
		Vector2 scale = tr->GetScale();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePosition(pos);

		Sprite sprite = mAnimationSheet[mIndex];

		graphics::Texture::eTextureType type = mTexture->GetTextureType();
		if (type == graphics::Texture::eTextureType::Bmp)
		{
			HDC imgHdc = mTexture->GetHdc();

			if (mTexture->IsAlpha())
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; // 0(transparent) ~ 255(Opaque)

				AlphaBlend(hdc
					, (int)(pos.x - (sprite.size.x * posStyle.x * scale.x) + sprite.offset.x), (int)(pos.y - (sprite.size.y * posStyle.y * scale.y) + sprite.offset.y)
					, (int)(sprite.size.x * scale.x), (int)(sprite.size.y * scale.y)
					, imgHdc
					, (int)sprite.leftTop.x, (int)sprite.leftTop.y
					, (int)sprite.size.x, (int)sprite.size.y
					, func);
			}
			else
			{
				TransparentBlt(hdc
					, (int)(pos.x - (sprite.size.x * posStyle.x * scale.x) + sprite.offset.x), (int)(pos.y - (sprite.size.y * posStyle.y * scale.y) + sprite.offset.y)
					, (int)(sprite.size.x * scale.x), (int)(sprite.size.y * scale.y)
					, imgHdc
					, (int)sprite.leftTop.x, (int)sprite.leftTop.y
					, (int)sprite.size.x, (int)sprite.size.y
					, RGB(255, 0, 255));
			}

			/*Rectangle(hdc
				, pos.x, pos.y
				, pos.x + 100, pos.y + 100);*/
		}
		else if (type == graphics::Texture::eTextureType::Png)
		{
			Gdiplus::ImageAttributes imgAtt = {};

			imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect
				(
					(INT)(pos.x - (sprite.size.x * posStyle.x * scale.x)), (INT)(pos.y - (sprite.size.y * posStyle.y * scale.y))
					, (INT)(sprite.size.x * scale.x), (INT)(sprite.size.y * scale.y)
				)
				, (INT)sprite.leftTop.x, (INT)sprite.leftTop.y
				, (INT)sprite.size.x, (INT)sprite.size.y
				, Gdiplus::UnitPixel
				, nullptr/*&imgAtt*/
			);
		}
	}
	
	void Animation::CreateAnimation(const std::wstring& name, graphics::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
	{
		mTexture = spriteSheet;
		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite sprite = { };
			sprite.leftTop.x = leftTop.x + (size.x * i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mAnimationSheet.push_back(sprite);
		}
	}

	void Animation::Reset()
	{
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}
}