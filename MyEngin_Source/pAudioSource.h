#pragma once
#include "pComponent.h"
#include "pAudioClip.h"

namespace p {
	class AudioSource : public Component
	{
	public:
		AudioSource();
		~AudioSource();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void Play();
		void Stop();
		void SetLoop(bool loop);
		void SetClip(AudioClip* clip) { mAudioClip = clip; }
		AudioClip* GetClip() { return mAudioClip; }
	private:
		AudioClip* mAudioClip;
	};

}

