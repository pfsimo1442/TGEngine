#include "tgAudioSource.h"
#include "tgTransform.h"
#include "tgGameObject.h"
#include "tgFmod.h"

namespace tg
{
	AudioSource::AudioSource()
		: Component(enums::eComponentType::AudioSource)
		, mAudioClip(nullptr)
	{
	}
	AudioSource::~AudioSource()
	{
	}

	void AudioSource::Initialize()
	{

	}

	void AudioSource::Update()
	{

	}

	void AudioSource::LateUpdate()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		Vector3 vel = Vector3::Zero;

		mAudioClip->Set3DAttributes(pos, vel);
	}

	void AudioSource::Render()
	{

	}

	void AudioSource::Play() const
	{
		mAudioClip->Play();
	}

	void AudioSource::Stop() const
	{
		mAudioClip->Stop();
	}

	void AudioSource::SetLoop(bool loop) const
	{
		mAudioClip->SetLoop(loop);
	}
}