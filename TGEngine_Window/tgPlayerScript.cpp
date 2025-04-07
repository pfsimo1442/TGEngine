#include "tgPlayerScript.h"
#include "tgInput.h"
#include "tgTransform.h"
#include "tgTime.h"
#include "tgGameObject.h"

namespace tg
{
	PlayerScript::PlayerScript()
	{
	}
	PlayerScript::~PlayerScript()
	{
	}

	void PlayerScript::Initialize()
	{
		
	}

	void PlayerScript::Update()
	{
		if (Input::GetKey(eKeyCode::D))
		{
		    Transform* tr = GetOwner()->GetComponent<Transform>();
		    Vector2 pos = tr->GetPosition();
		    pos.x += 100.0f * Time::DeltaTime();
		    tr->SetPosition(pos);
		}
		if (Input::GetKey(eKeyCode::A))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x -= 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		if (Input::GetKey(eKeyCode::W))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.y -= 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		if (Input::GetKey(eKeyCode::S))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.y += 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
	}

	void PlayerScript::LateUpdate()
	{
		
	}

	void PlayerScript::Render(HDC hdc)
	{

	}
}