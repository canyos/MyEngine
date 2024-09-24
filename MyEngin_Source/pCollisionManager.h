#pragma once
#include "CommonInclude.h"
#include "pBoxCollider2D.h"
#include "pCircleCollider2D.h"

namespace p {
	using namespace enums;
	class CollisionManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

		static void CollisionLayerCheck(eLayerType left, eLayerType right, bool enable);
		static void LayerCollision(class Scene* scene, eLayerType row, eLayerType col);
		static void ColliderCollision(Collider* left, Collider* right);
	private:
		static std::bitset <(UINT)eLayerType::Max> mCollisionLayerMatrix[(UINT)eLayerType::Max];

	};
}


