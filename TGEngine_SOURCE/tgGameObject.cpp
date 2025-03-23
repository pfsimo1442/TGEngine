#include "tgGameObject.h"
#include "tgInput.h"

namespace tg
{
	GameObject::GameObject()
		: mX(0.0f)
		, mY(0.0f)
	{
	}
	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		if (Input::GetKey(eKeyCode::A)) { mX -= 0.01f; }
		if (Input::GetKey(eKeyCode::D)) { mX += 0.01f; }
		if (Input::GetKey(eKeyCode::W)) { mY -= 0.01f; }
		if (Input::GetKey(eKeyCode::S)) { mY += 0.01f; }
	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Rectangle(hdc, 100 + (int)mX, 100 + (int)mY, 200 + (int)mX, 200 + (int)mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}