#include "pGameObject.h"
namespace p {
	GameObject::GameObject() {

	}
	GameObject::~GameObject() {

	}
	void GameObject::Update() {
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			mX -= 0.01f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			mX += 0.01f;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			mY -= 0.01f;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			mY += 0.01f;
		}
	}
	void GameObject::LateUpdate() {

	}
	void GameObject::Render(HDC hdc) {
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));//���� ĥ�� �귯��

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));// ���� ����, dc, ����, ����
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);//dc�� ����� brush�� ����ϵ��� ��

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);//�����츶�� dc�� �ְ� �������ϼ� �����Ƿ� dc��Ȯ�ϰ� �־������

		SelectObject(hdc, oldBrush); //���� ��� ����� �޸� �����ϰ� �ǹǷ� ���ο� �귯�� ����ϰ� �ٽ� ������� �ٲ���
		SelectObject(hdc, oldPen);
		DeleteObject(brush);//�Ķ��� �귯�� ������Ʈ �޸� ����
		DeleteObject(redPen);


		//�⺻���� ���ֻ�� �Ǵ� GDI������Ʈ�� �̸� DC�ȿ� ������ -> stockObject
		//HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH); //stockObject����� �귯�� ����
		//HBRUSH oldBrush2 = (HBRUSH)SelectObject(mHdc, grayBrush);
		//Rectangle(mHdc, 400, 400, 500, 500);
		//SelectObject(mHdc, oldBrush2); //default�� �����α�, delete�� ���ʿ����
		//Rectangle(mHdc, 500, 500, 600, 600);
	}

}