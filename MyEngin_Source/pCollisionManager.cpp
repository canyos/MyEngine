#include "pCollisionManager.h"
#include "pScene.h"
#include "pSceneManager.h"
#include "pGameObject.h"
#include "pCollider.h"
#include "pTransform.h"
#include "pGameObject.h"

namespace p {
	std::bitset<(UINT)eLayerType::Max> CollisionManager::mCollisionLayerMatrix[(UINT)eLayerType::Max] = {};
	std::unordered_map<UINT64, bool> CollisionManager::mCollisionMap = {};
	
	void CollisionManager::Initialize()
	{
	}
	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::GetActiveScene();
		for (UINT row = 0; row < (UINT)eLayerType::Max; row++) {
			for (UINT col = 0; col < (UINT)eLayerType::Max; col++) {
				if (mCollisionLayerMatrix[row][col]) {
					LayerCollision(scene, (eLayerType)row, (eLayerType)col);
				}
			}
		}
	}
	void CollisionManager::LateUpdate()
	{
	}
	void CollisionManager::Render(HDC hdc)
	{
	}
	void CollisionManager::CollisionLayerCheck(eLayerType left, eLayerType right, bool enable)
	{
		int row=0, col=0;
		if (left <= right) {
			row = (UINT)left;
			col = (UINT)right;
		}
		else {
			row = (UINT)right;
			col = (UINT)left;
		}
		mCollisionLayerMatrix[row][col] = enable;
	}

	void CollisionManager::LayerCollision(Scene * scene, eLayerType left, eLayerType right)
	{
		const std::vector<GameObject*>& lefts = scene->GetLayer(left)->GetGameObjects();
		const std::vector<GameObject*>& rights = scene->GetLayer(right)->GetGameObjects();

		for (GameObject* left : lefts) {
			if (left->IsActive() == false) {
				continue;
			}
			Collider* leftCol = left->GetComponent<Collider>();
			if (leftCol == NULL) {
				continue;
			}

			for (GameObject* right : rights) {
				if (right->IsActive() == false) {
					continue;
				}
				Collider* rightCol = right->GetComponent<Collider>();
				if (rightCol == NULL) {
					continue;
				}
				if (left == right)
					continue;

				ColliderCollision(leftCol, rightCol);
			}
		}
	}
	void CollisionManager::ColliderCollision(Collider * left, Collider * right)
	{
		//�浹üũ ���� 
		//�� �浹ü ��ȣ�� ������ ID�� Ȯ���� CollisionId���� ����
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();

		auto iter = mCollisionMap.find(id.id);
		if (iter == mCollisionMap.end()) {
			mCollisionMap.insert({ id.id,false });
			iter = mCollisionMap.find(id.id);
		}
		//�浹 üũ
		if(Intersect(left, right)) {
			if (iter->second == false) {
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
				iter->second = true;
			}
			else {
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else {
			if (iter->second == true) {
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);
				iter->second = false;
			}
		}

	}
	bool CollisionManager::Intersect(Collider * left, Collider * right)
	{
		Transform* leftTr = left->GetOwner()->GetComponent<Transform>();
		Transform* rightTr = right->GetOwner()->GetComponent<Transform>();

		Vector2 leftPos = leftTr->GetPosition() + left->GetOffset();
		Vector2 rightPos = rightTr->GetPosition() + right->GetOffset();

		Vector2 leftSize = left->GetSize() *100.0f;
		Vector2 rightSize = right->GetSize() *100.0f;

		enums::eColliderType leftType = left->GetColliderType();
		enums::eColliderType rightType = right->GetColliderType();

		if (leftType == enums::eColliderType::Rect2D &&
			rightType == enums::eColliderType::Rect2D) {
			//rect-rect
			if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f) &&
				fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f)) {
				return true;
			}
		}
		
		if (leftType == enums::eColliderType::Circle2D &&
			rightType == enums::eColliderType::Circle2D) {
			//circle-circle
			Vector2 leftCirclePos = leftPos + (leftSize / 2.0f);
			Vector2 rightCirclePos = rightPos + (rightSize / 2.0f);

			float distance = (leftCirclePos - rightCirclePos).length();
			if (distance <= (leftSize.x / 2.0f) + (rightSize.x / 2.0f)) {
				return true;
			}
		}
		
		if (leftType == enums::eColliderType::Rect2D &&
			rightType == enums::eColliderType::Circle2D) {
			//rect-circle
			//�� ������ ��ŭ �簢�� �����ڸ� Ȯ���� 
			//�� ������ �������� �Ÿ��� r���� ������
			return checkCollideCircleRect(right, left);
			
		}
		if (leftType == enums::eColliderType::Circle2D &&
			rightType == enums::eColliderType::Rect2D) {
			//circle-rect
			return checkCollideCircleRect(left, right);
		}
		return false;
	}
	bool CollisionManager::checkCollideCircleRect(Collider * circle, Collider * rect)
	{
		bool result = false;
		Transform* circleTr = circle->GetOwner()->GetComponent<Transform>();
		Transform* rectTr = rect->GetOwner()->GetComponent<Transform>();

		Vector2 circlePos = circleTr->GetPosition() + circle->GetOffset();
		Vector2 rectPos = rectTr->GetPosition() + rect->GetOffset();

		Vector2 circleSize = circle->GetSize() *100.0f;
		Vector2 rectSize = rect->GetSize() *100.0f;


		float r = circleSize.x / 2.0f;//������

		Vector2 rectLeftTop = Vector2(rectPos.x - rectSize.x / 2.0f, rectPos.y - rectSize.y / 2.0f);
		Vector2 rectRightTop = Vector2(rectPos.x + rectSize.x / 2.0f, rectPos.y - rectSize.y / 2.0f);
		Vector2 rectLeftBottom = Vector2(rectPos.x - rectSize.x / 2.0f, rectPos.y + rectSize.y / 2.0f);
		Vector2 rectRightBottom = Vector2(rectPos.x + rectSize.x / 2.0f, rectPos.y + rectSize.y / 2.0f);
		
		float dist1 = (rectLeftTop - circlePos).length();
		float dist2 = (rectRightTop - circlePos).length();
		float dist3 = (rectLeftBottom - circlePos).length();
		float dist4 = (rectRightBottom - circlePos).length();

		if (dist1 <= r ||
			dist2 <= r ||
			dist3 <= r ||
			dist4 <= r) {
			result = true;
		}

		return result;
	}
}