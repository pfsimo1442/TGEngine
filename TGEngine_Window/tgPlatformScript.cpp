#include "tgPlatformScript.h"
#include "tgTransform.h"
#include "tgGameObject.h"
#include "tgRigidbody.h"
#include "tgAudioSource.h"

namespace tg
{
	PlatformScript::PlatformScript()
	{
	}
	PlatformScript::~PlatformScript()
	{
	}

	void PlatformScript::Initialize()
	{

	}

	void PlatformScript::Update()
	{
		
	}

	void PlatformScript::LateUpdate()
	{

	}

	void PlatformScript::Render(HDC hdc)
	{

	}

	void PlatformScript::OnCollisionEnter(Collider* other)
	{
		//only y (gravity) - todo: add x value
		Rigidbody* otherRb = other->GetOwner()->GetComponent<Rigidbody>();
		Transform* otherTr = other->GetOwner()->GetComponent<Transform>();
		Collider* otherCol = other;

		Rigidbody* platformRb = this->GetOwner()->GetComponent<Rigidbody>();
		Transform* platformTr = this->GetOwner()->GetComponent<Transform>();
		Collider* platformCol = this->GetOwner()->GetComponent<Collider>();

		Vector2 otherPos = otherTr->GetPosition();
		Vector2 otherSize = otherCol->GetSize();
		Vector2 otherOffset = otherCol->GetOffset();
		Vector2 otherColPos = otherPos + otherOffset;

		Vector2 platformPos = platformTr->GetPosition();
		Vector2 platformSize = platformCol->GetSize();
		Vector2 platformOffset = platformCol->GetOffset();
		Vector2 platformColPos = platformPos + platformOffset;

		if (platformColPos.x - platformSize.x / 2 < otherColPos.x
			&& otherColPos.x < platformColPos.x + platformSize.x / 2)
		{
			float otherPosY = platformPos.y - (otherSize.y + platformSize.y) / 2;
			otherTr->SetPosition(Vector2(otherPos.x, otherPosY));
		}
		else
		{
			if (otherCol->GetColliderType() == eColliderType::Box2D)
			{
				float otherPosY = platformPos.y - (otherSize.y + platformSize.y) / 2;
				otherTr->SetPosition(Vector2(otherPos.x, otherPosY));
			}
			else if (otherCol->GetColliderType() == eColliderType::Capsule2D)
			{
				float otherPosY = platformPos.y
					- platformSize.y / 2
					- sqrtf((otherSize.x / 2)
						* (otherSize.x / 2)
						- (fabs(platformColPos.x - otherColPos.x) - platformSize.x / 2)
						* (fabs(platformColPos.x - otherColPos.x) - platformSize.x / 2))
					- (otherSize.y - otherSize.x) / 2;
				otherTr->SetPosition(Vector2(otherPos.x, otherPosY));
			}
			else if (otherCol->GetColliderType() == eColliderType::Circle2D)
			{
				float otherPosY = platformPos.y
					- platformSize.y / 2
					- sqrtf((otherSize.x / 2)
						* (otherSize.x / 2)
						- (fabs(platformColPos.x - otherColPos.x) - platformSize.x / 2)
						* (fabs(platformColPos.x - otherColPos.x) - platformSize.x / 2)
					);
				otherTr->SetPosition(Vector2(otherPos.x, otherPosY));
			}
		}
		
		//float len = fabs(otherTr->GetPosition().y - platformTr->GetPosition().y);

		otherRb->SetIsOnGround(true);

		AudioSource* platformAS = this->GetOwner()->GetComponent<AudioSource>();
		platformAS->Play();
	}

	void PlatformScript::OnCollisionStay(Collider* other)
	{
		Rigidbody* otherRb = other->GetOwner()->GetComponent<Rigidbody>();
		Transform* otherTr = other->GetOwner()->GetComponent<Transform>();
		Collider* otherCol = other;

		Rigidbody* platformRb = this->GetOwner()->GetComponent<Rigidbody>();
		Transform* platformTr = this->GetOwner()->GetComponent<Transform>();
		Collider* platformCol = this->GetOwner()->GetComponent<Collider>();

		Vector2 otherPos = otherTr->GetPosition();
		Vector2 otherSize = otherCol->GetSize();
		Vector2 otherOffset = otherCol->GetOffset();
		Vector2 otherColPos = otherPos + otherOffset;

		Vector2 platformPos = platformTr->GetPosition();
		Vector2 platformSize = platformCol->GetSize();
		Vector2 platformOffset = platformCol->GetOffset();
		Vector2 platformColPos = platformPos + platformOffset;

		if (platformColPos.x - platformSize.x / 2 < otherColPos.x
			&& otherColPos.x < platformColPos.x + platformSize.x / 2)
		{
			float otherPosY = platformPos.y - (otherSize.y + platformSize.y) / 2;
			otherTr->SetPosition(Vector2(otherPos.x, otherPosY));
		}
		else
		{
			if (otherCol->GetColliderType() == eColliderType::Box2D)
			{
				float otherPosY = platformPos.y - (otherSize.y + platformSize.y) / 2;
				otherTr->SetPosition(Vector2(otherPos.x, otherPosY));
			}
			else if (otherCol->GetColliderType() == eColliderType::Capsule2D)
			{
				float otherPosY = platformPos.y
					- platformSize.y / 2
					- sqrtf((otherSize.x / 2)
						* (otherSize.x / 2)
						- (fabs(platformColPos.x - otherColPos.x) - platformSize.x / 2)
						* (fabs(platformColPos.x - otherColPos.x) - platformSize.x / 2))
					- (otherSize.y - otherSize.x) / 2;
				otherTr->SetPosition(Vector2(otherPos.x, otherPosY));
			}
			else if (otherCol->GetColliderType() == eColliderType::Circle2D)
			{
				float otherPosY = platformPos.y
					- platformSize.y / 2
					- sqrtf((otherSize.x / 2)
						* (otherSize.x / 2)
						- (fabs(platformColPos.x - otherColPos.x) - platformSize.x / 2)
						* (fabs(platformColPos.x - otherColPos.x) - platformSize.x / 2)
					);
				otherTr->SetPosition(Vector2(otherPos.x, otherPosY));
			}
		}
	}

	void PlatformScript::OnCollisionExit(Collider* other)
	{
		Rigidbody* rb = other->GetOwner()->GetComponent<Rigidbody>();

		rb->SetIsOnGround(false);

		AudioSource* platformAS = this->GetOwner()->GetComponent<AudioSource>();
		platformAS->Stop();
	}
}