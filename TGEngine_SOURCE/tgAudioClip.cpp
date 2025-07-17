#include "tgAudioClip.h"

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
	}

	HRESULT AudioClip::Load(const std::wstring& path)
	{
		std::string cPath(path.begin(), path.end());
		if (!Fmod::CreateSound(cPath, mSound))
			return S_FALSE;

		return E_NOTIMPL;
	}

	void AudioClip::Play()
	{

	}

	void AudioClip::Stop()
	{

	}

	void AudioClip::Set3DAttributes(const Vector2 pos)
	{

	}
}
