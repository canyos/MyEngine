#include "pCatScript.h"
#include "pInput.h"
#include "pTime.h"
#include "pTransform.h"
#include "pGameObject.h"
#include "pAnimator.h"
namespace p {
	CatScript::CatScript()
		: mState(CatScript::eState::SitDown)
		, mAnimator(nullptr)
		, mTime(0.0f)
	{
	}
	CatScript::~CatScript()
	{
	}
	void CatScript::Initialize()
	{


	}
	void CatScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case p::CatScript::eState::SitDown:
			idle();
			break;
		case p::CatScript::eState::Walk:
			move();
			break;
		case p::CatScript::eState::LayDown:
			layDown();
			break;
		case p::CatScript::eState::Sleep:
			break;
		case p::CatScript::eState::Attack:
			break;
		default:
			break;
		}

	}
	void CatScript::LateUpdate()
	{
	}
	void CatScript::Render(HDC hdc)
	{
	}

	void CatScript::idle()
	{
		mTime += Time::DeltaTime();
		if (mTime > 3.0f) {
			mState = CatScript::eState::Walk;
			int direction = (rand()%4);
			mDirection = (eDirection)direction;
			PlayWalkAnimationByDirection(mDirection);
			mTime = 0.0f;
		}
		
	}

	void CatScript::move()
	{
		mTime += Time::DeltaTime();
		if (mTime > 2.0f) {
			int isLayDown = rand() % 2;
			if (isLayDown) {
				mState = eState::LayDown;
				mAnimator->PlayAnimation(L"LayDown", false);
			}
			else {
				mState = eState::SitDown;
				mAnimator->PlayAnimation(L"SitDown", false);
			}
			
		}
		Transform* tr = GetOwner()->GetComponent<Transform>();
		translate(tr);
	}
	void CatScript::PlayWalkAnimationByDirection(eDirection direction)
	{
		switch (direction) {
		case p::CatScript::eDirection::Left:
			mAnimator->PlayAnimation(L"LeftWalk", true);
			break;
		case p::CatScript::eDirection::Right:
			mAnimator->PlayAnimation(L"RightWalk", true);
			break;
		case p::CatScript::eDirection::Up:
			mAnimator->PlayAnimation(L"UpWalk", true);
			break;
		case p::CatScript::eDirection::Down:
			mAnimator->PlayAnimation(L"DownWalk", true);
			break;

		default:
			assert(false);
			break;
		}
	}
	void CatScript::translate(Transform* tr)
	{
		Vector2 pos = tr->GetPosition();
		switch(mDirection) {
		case p::CatScript::eDirection::Left:
			pos.x -= 100.0f * Time::DeltaTime();
			break;
		case p::CatScript::eDirection::Right:
			pos.x += 100.0f * Time::DeltaTime();
			break;
		case p::CatScript::eDirection::Up:
			pos.y -= 100.0f * Time::DeltaTime();
			break;
		case p::CatScript::eDirection::Down:
			pos.y += 100.0f * Time::DeltaTime();
			break;
		default:
			assert(false);
			break;
		}
		tr->SetPosition(pos);
	}
	void CatScript::layDown()
	{
	}
}

