#include "pRigidBody.h"
#include "pTime.h"
#include "pTransform.h"
#include "pGameObject.h"
namespace p {
	RigidBody::RigidBody()
		:Component(enums::eComponentType::RigidBody),
		mMass(1.0f), 
		mbGround(false),
		mFriction(10.0f),
		mVelocity(Vector2::Zero),
		mForce(Vector2::Zero),
		mLimitedVelocity(Vector2(200.0f,1000.0f)),
		mGravity(Vector2(0.0f,800.0f)),
		mAcceleration(Vector2::Zero)
	{
	}
	RigidBody::~RigidBody()
	{
	}
	void RigidBody::Initialize()
	{
	}
	void RigidBody::Update()
	{
		//f = ma
		mAcceleration = mForce / mMass;
		//�ӵ��� ���ӵ� ����
		mVelocity += mAcceleration * Time::DeltaTime();
		if (mbGround) {
			//����������
			Vector2 gravity = mGravity;
			gravity.Normalize();

			float dot = mVelocity.Dot(gravity);//�߷°� ������ ������ �̵��� ����
			mVelocity -= gravity * dot;
		}
		else {
			//���߿�����
			mVelocity += mGravity * Time::DeltaTime();
		}

		//�ִ� �ӵ� ����
		Vector2 gravity = mGravity;
		gravity.Normalize();
		float dot = mVelocity.Dot(gravity);
		gravity = gravity * dot;

		Vector2 sideVelocity = mVelocity - gravity;
		if (mLimitedVelocity.y < gravity.Length()) {
			gravity.Normalize();
			gravity *= mLimitedVelocity.y;
		}
		if (mLimitedVelocity.x < sideVelocity.Length()) {
			sideVelocity.Normalize();
			sideVelocity *= mLimitedVelocity.x;
		}
		
		mVelocity = gravity + sideVelocity;

		if (!(mVelocity == Vector2::Zero)) {
			Vector2 friction = -mVelocity;
			friction.Normalize();
			friction = friction*mFriction*mMass*Time::DeltaTime();
			//���������� ���� �ӵ� ���ҷ��� ����ӵ����� ũ�� �ȿ�����
			if (mVelocity.Length() <= friction.Length()) {
				mVelocity = Vector2::Zero;
			}
			else {
				mVelocity += friction;
			}
		}
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		pos = pos + mVelocity * Time::DeltaTime();
		tr->SetPosition(pos);

		mForce= Vector2::One;
	}
	void RigidBody::LateUpdate()
	{
	}
	void RigidBody::Render(HDC hdc)
	{
	}
}

