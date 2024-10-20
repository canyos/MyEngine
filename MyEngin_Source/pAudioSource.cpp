#include "pAudioSource.h"
#include "pTransform.h"
#include "pGameObject.h"
#include "pFmod.h"

namespace p {
	AudioSource::AudioSource()
		: Component(eComponentType::AudioSource),
		  mAudioClip(nullptr)
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
		//mAudioClip->Set3DAttributes(pos);
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
