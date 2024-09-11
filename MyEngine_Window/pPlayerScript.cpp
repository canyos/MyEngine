#include "pPlayerScript.h"
#include "pInput.h"
#include "pTime.h"
#include "pTransform.h"
#include "pGameObject.h"
#include "pAnimator.h"
namespace p {
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Idle)
		, mAnimator(nullptr)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{


	}
	void PlayerScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case p::PlayerScript::eState::Idle:
			idle();
			break;
		case p::PlayerScript::eState::Walk:
			move();
			break;

		case p::PlayerScript::eState::Sleep:
			break;
		case p::PlayerScript::eState::Attack:
			break;
		case p::PlayerScript::eState::GiveWater:
			giveWater();
			break;
		default:
			break;
		}

	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}

	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::LButton)) {
			mState = PlayerScript::eState::GiveWater;
			mAnimator->PlayAnimation(L"FrontGiveWater",false);
			Vector2 mousePos = Input::GetMousePosition();


		}

		if (Input::GetKey(eKeyCode::D))
		{
			mState = PlayerScript::eState::Walk;
			//mAnimator->PlayAnimation(L"RightWalk");
		}
		if (Input::GetKey(eKeyCode::A)) {
			mState = PlayerScript::eState::Walk;
			//mAnimator->PlayAnimation(L"LeftWalk");
		}
			
		if (Input::GetKey(eKeyCode::W)) {
			mState = PlayerScript::eState::Walk;
			//mAnimator->PlayAnimation(L"UpWalk");
		}
			
		if (Input::GetKey(eKeyCode::S)) {
			mState = PlayerScript::eState::Walk;
			//mAnimator->PlayAnimation(L"DownWalk");
		}
			
	}

	void PlayerScript::move()
	{

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::W))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			pos.y += 100.0f * Time::DeltaTime();
		}

		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::D) || Input::GetKeyUp(eKeyCode::A)
			|| Input::GetKeyUp(eKeyCode::W) || Input::GetKeyUp(eKeyCode::S))
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"SitDown", false);
		}
	}
	void PlayerScript::giveWater()
	{
		if (mAnimator->IsComplete()) {
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
	}
}

