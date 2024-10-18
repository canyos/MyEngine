#pragma once
#include "pCollider.h"

namespace p {
	class BoxCollider2D : public Collider
	{
	public:
		BoxCollider2D();
		~BoxCollider2D();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();


	private:
		Vector2 mSize;

	};
}

