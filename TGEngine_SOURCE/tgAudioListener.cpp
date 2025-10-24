#include "tgAudioListener.h"
#include "tgTransform.h"
#include "tgRigidbody.h"
#include "tgGameObject.h"
#include "tgFmod.h"

namespace tg
{
	AudioListener::AudioListener()
		: Component(enums::eComponentType::AudioListener)
		, mbIsVel(false)
	{
	}
	AudioListener::~AudioListener()
	{
	}

	void AudioListener::Initialize()
	{

	}

	void AudioListener::Update()
	{

	}

	void AudioListener::LateUpdate()
	{
		Transform* tr = nullptr;
		tr = GetOwner()->GetComponent<Transform>();
		//Rigidbody* rg = GetOwner()->GetComponent<Rigidbody>();
		//Vector2 vel = Vector2(0.0f, 0.0f);
		//if (mbIsVel == true)
		//	vel = rg->GetVelocity();
			
		Vector3 pos;
		Vector3 vel;
		Fmod::Set3DListenerAttributes(pos, vel);
	}

	void AudioListener::Render()
	{

	}
}