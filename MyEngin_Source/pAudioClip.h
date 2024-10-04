#pragma once
#include "pFmod.h"
#include "pResource.h"

namespace p {
	class AudioClip : public Resource
	{
	public:
		AudioClip();
		virtual ~AudioClip();

		virtual HRESULT Load(const std::wstring& path) override;
	private:
		FMOD::Sound* mSound;
		FMOD::Channel* mChannel;
	};

}