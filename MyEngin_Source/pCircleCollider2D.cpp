#include "pCircleCollider2D.h"
#include "pTransform.h"
#include "pGameObject.h"
#include "pRenderer.h"
#include "pCamera.h"

namespace p {
	CircleCollider2D::CircleCollider2D()
		: Collider(enums::eColliderType::Circle2D)
	{
	}
	CircleCollider2D::~CircleCollider2D()
	{
	}
	void CircleCollider2D::Initialize()
	{
	}
	void CircleCollider2D::Update()
	{
	}
	void CircleCollider2D::LateUpdate()
	{
	}
	/*
	void CircleCollider2D::Render()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePosition(pos);
		Vector2 offset = GetOffset();
		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(, transparentBrush);
		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(, greenPen);

		Vector2 rightBottom;
		rightBottom.x = pos.x + offset.x + 100 * GetSize().x;
		rightBottom.y = pos.y + offset.y + 100 * GetSize().y;
		Ellipse(, pos.x + offset.x
			, pos.y + offset.y
			, rightBottom.x
			, rightBottom.y);
		SelectObject(, oldBrush);
		SelectObject(, oldPen);
		DeleteObject(greenPen);
	}
	*/
	void CircleCollider2D::Render() {
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
	}
}
