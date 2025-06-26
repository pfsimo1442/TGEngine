#include "tgCameraScript.h"
#include "tgInput.h"
#include "tgTransform.h"
#include "tgTime.h"
#include "tgGameObject.h"

namespace tg
{
	CameraScript::CameraScript()
	{	
	}
	CameraScript::~CameraScript()
	{	
	}

	void CameraScript::Initialize()
	{
		
	}

	void CameraScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Vector2 direction = Vector2::Zero;
		float speed = 500.0f;

		if (Input::GetKey(eKeyCode::Arrow_Right))
			direction += Vector2::Right;
		if (Input::GetKey(eKeyCode::Arrow_Left))
			direction += Vector2::Left;
		if (Input::GetKey(eKeyCode::Arrow_Up))
			direction += Vector2::Up;
		if (Input::GetKey(eKeyCode::Arrow_Down))
			direction += Vector2::Down;

		pos += (direction.normalize() * speed * Time::DeltaTime());
		tr->SetPosition(pos);
	}

	void CameraScript::LateUpdate()
	{
		
	}

	void CameraScript::Render(HDC hdc)
	{
		
	}

	void CameraScript::OnCollisionEnter(Collider* other)
	{
		
	}

	void CameraScript::OnCollisionStay(Collider* other)
	{
		
	}

	void CameraScript::OnCollisionExit(Collider* other)
	{
		
	}
}