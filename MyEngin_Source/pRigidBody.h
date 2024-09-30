#pragma once
#include "pComponent.h"

namespace p {
	class RigidBody : public Component
	{
	public:
		RigidBody();
		~RigidBody();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetMass(float mass) { mMass = mass; }
		void AddForce(Vector2 force) { mForce = force; }
		void SetGround(bool ground) { mbGround = ground; }
		bool GetGround() { return mbGround; }
		void SetVelocity(Vector2 velocity) { mVelocity = velocity; }
		Vector2 GetVelocity() { return mVelocity; }
	private:
		bool mbGround;//���� ��ҳ�
		float mMass;
		float mFriction;//������
		Vector2 mForce;//��
		Vector2 mAcceleration;
		Vector2 mVelocity;//�ӵ�
		Vector2 mLimitedVelocity;//�ӵ�
		Vector2 mGravity;//�߷�
	};
}
