#include "pAudioClip.h"

namespace p {
	AudioClip::AudioClip()
		:Resource(enums::eResourceType::Audioclip),
		mSound(nullptr),
		mChannel(nullptr)
	{
	}
	AudioClip::~AudioClip()
	{
	}
	HRESULT AudioClip::Load(const std::wstring& path) {
		std::string cPath(path.begin(), path.end());
		if (!Fmod::CreateSound(cPath, mSound))
			return S_FALSE;
		
		return S_OK;
	}
}
