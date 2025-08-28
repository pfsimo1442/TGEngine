#include "tgAudioClip.h"
#include "tgAudioSource.h"

static tg::math::Vector2 ConvertWindowCSToFModCS(tg::math::Vector2 winSize, tg::math::Vector2 pos)
{
	return tg::math::Vector2(
		pos.x / winSize.x * 2 - 1
		, pos.y / winSize.y * 2 - 1
	);
};

namespace tg
{
	tg::AudioClip::AudioClip()
		: Resource(enums::eResourceType::AudioClip)
		, mSound(nullptr)
		, mChannel(nullptr)
		, mMinDistance(1.0f)
		, mMaxDistance(1000.0f)
		, mbLoop(false)
	{
	}
	AudioClip::~AudioClip()
	{
		mSound->release();
		mSound = nullptr;
	}

	HRESULT AudioClip::Load(const std::wstring& path)
	{
		std::string cPath(path.begin(), path.end());
		if (!Fmod::CreateSound(cPath, &mSound))
			return S_FALSE;
		
		mSound->set3DMinMaxDistance(mMinDistance, mMaxDistance);

		return S_OK;
	}

	void AudioClip::Play()
	{
		if(mbLoop)
			mSound->setMode(FMOD_LOOP_NORMAL);
		else
			mSound->setMode(FMOD_LOOP_OFF);

		Fmod::SoundPlay(mSound, &mChannel);
	}

	void AudioClip::Stop()
	{
		mChannel->stop();
	}

	void AudioClip::Set2DAttributes(const Vector2 pos, const Vector2 vel)
	{
		Vector2 fcsPos = ConvertWindowCSToFModCS(Vector2(672.0f, 846.0f), pos);

		FMOD_VECTOR fmodPos(fcsPos.x, fcsPos.y, 0.0f);
		FMOD_VECTOR fmodVel(vel.x, vel.y, 0.0f);
		//FMOD_VECTOR fmodPos(0.0f, 0.0f, 0.0f);
		//FMOD_VECTOR fmodVel(0.0f, 0.0f, 0.0f);

		mChannel->set3DAttributes(&fmodPos, &fmodVel);
	}
}
