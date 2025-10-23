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
		Vector2 pos = tr->GetPosition();
		Vector2 vel = Vector2(0.0f, 0.0f);

		//mAudioClip->Set2DAttributes(pos, vel);
	}

	void AudioSource::Render()
	{

	}

	void AudioSource::Play()
	{
		mAudioClip->Play();
	}

	void AudioSource::Stop()
	{
		mAudioClip->Stop();
	}

	void AudioSource::SetLoop(bool loop)
	{
		mAudioClip->SetLoop(loop);
	}
}