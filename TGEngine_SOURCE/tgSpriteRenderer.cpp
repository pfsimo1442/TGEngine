#include "tgSpriteRenderer.h"
#include "tgGameObject.h"
#include "tgTransform.h"

namespace tg
{
	SpriteRenderer::SpriteRenderer()
		: mImage(nullptr)
		, mWidth(0)
		, mHeight(0)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}

	void SpriteRenderer::Initialize()
	{
	
	}

	void SpriteRenderer::Update()
	{
		
	}
	
	void SpriteRenderer::LateUpdate()
	{
	
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		//HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		//HBRUSH randBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		//HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN randPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
		//HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		//SelectObject(hdc, oldPen);

		Transform* tr = GetOwner()->GetComponent<Transform>();
		//Rectangle(hdc, tr->GetX(), tr->GetY()
		//	, 100 + tr->GetX(), 100 + tr->GetY());

		//SelectObject(hdc, oldBrush);
		//DeleteObject(blueBrush);
		//DeleteObject(randBrush);
		//DeleteObject(redPen);
		//DeleteObject(randPen);

		Vector2 pos = tr->GetPosition();

		Gdiplus::Graphics graphcis(hdc);
		graphcis.DrawImage(mImage, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
	}

	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		mImage = Gdiplus::Image::FromFile(path.c_str());
		mWidth = mImage->GetWidth();
		mHeight = mImage->GetHeight();
	}
}