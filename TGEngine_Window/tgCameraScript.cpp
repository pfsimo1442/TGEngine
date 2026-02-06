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
		Vector3 pos = tr->GetPosition();
		Vector3 dir = Vector3::Zero;
		float spd = 500.0f;

		if (Input::GetKey(eKeyCode::A))
			dir += -tr->Right();
		if (Input::GetKey(eKeyCode::W))
			dir += tr->Foward();
		if (Input::GetKey(eKeyCode::D))
			dir += tr->Right();
		if (Input::GetKey(eKeyCode::S))
			dir += -tr->Foward();
		if (Input::GetKey(eKeyCode::E))
			dir += tr->Up();
		if (Input::GetKey(eKeyCode::Q))
			dir += -tr->Up();

		dir.Normalize();
		pos += dir * spd * Time::DeltaTime();
		tr->SetPosition(pos);
	}

	void CameraScript::LateUpdate()
	{
		
	}

	void CameraScript::Render()
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