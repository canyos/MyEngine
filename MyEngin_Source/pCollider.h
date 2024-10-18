#pragma once
#include "pComponent.h"

namespace p {
	class Collider: public Component
	{
	public:
		Collider(eColliderType type);
		~Collider();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		Vector2 GetOffset() const { return mOffset; }
		void SetOffset(Vector2 offset) { mOffset = offset; }
		UINT32 GetID() const { return mID; }
		Vector2 GetSize() const { return mSize; }
		void SetSize(Vector2 size) { mSize = size; }
		eColliderType GetColliderType() const { return mType; }

	private:
		Vector2 mOffset;
		static UINT32 mCollisionID;
		UINT32 mID;
		Vector2 mSize;
		eColliderType mType;
	};
}

