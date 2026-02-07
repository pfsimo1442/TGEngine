#pragma once
#include "tgFmod.h"
#include "tgResource.h"

namespace tg
{
	class AudioClip : public Resource
	{
	public:
		AudioClip();
		virtual ~AudioClip();

		HRESULT Load(const std::wstring& path) override;

		void Play();
		void Stop();

		void Set2DAttributes(Vector2 pos, Vector2 vel);
		void Set3DAttributes(Vector3 pos, Vector3 vel);

		[[noreturn]] void SetLoop(bool loop) { mbLoop = loop; }

	private:
		FMOD::Sound* mSound;
		FMOD::Channel* mChannel;
		float mMinDistance;
		float mMaxDistance;
		bool mbLoop;
	};
}