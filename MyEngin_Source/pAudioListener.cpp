#include "pAudioListener.h"
#include "pTransform.h"
#include "pGameObject.h"
#include "pFmod.h"
namespace p {
	AudioListener::AudioListener()
		: Component(eComponentType::AudioListener)
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

		Vector3 pos;
		Fmod::Set3DListenerAttributes(pos);
	}
	void AudioListener::Render()
	{
	}
}
