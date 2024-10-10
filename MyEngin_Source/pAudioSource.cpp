#include "pAudioSource.h"
#include "pTransform.h"
#include "pGameObject.h"
#include "pFmod.h"

namespace p {
	AudioSource::AudioSource()
		: Component(eComponentType::AudioSource)
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
		mAudioClip->Set3DAttributes(pos);
	}
	void AudioSource::Render(HDC hdc)
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
