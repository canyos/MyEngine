#include "pGameObject.h"
#include "pInput.h"
#include "pTime.h"

namespace p {
	GameObject::GameObject() {

	}
	GameObject::~GameObject() {

	}
	void GameObject::Update() {
		const int speed = 100.0f;
		if (Input::GetKey(eKeyCode::A)) { //왼쪽
			mX -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::D)) {//오른쪽
			mX += speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::W)) {//위
			mY -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S)) {//아래
			mY += speed * Time::DeltaTime();
		}
	}
	void GameObject::LateUpdate() {

	}
	void GameObject::Render(HDC hdc) {
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));//색을 칠할 브러쉬

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));// 선의 형태, dc, 굵기, 색상
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);//dc가 배경을 brush를 사용하도록 함

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);//윈도우마다 dc가 있고 여러개일수 있으므로 dc정확하게 넣어줘야함

		SelectObject(hdc, oldBrush); //기존 흰색 배경이 메모리 낭비하게 되므로 새로운 브러쉬 사용하고 다시 흰색으로 바꿔줌
		SelectObject(hdc, oldPen);
		DeleteObject(brush);//파랑색 브러쉬 오브젝트 메모리 해제
		DeleteObject(redPen);


		//기본으로 자주사용 되는 GDI오브젝트를 미리 DC안에 만들어둠 -> stockObject
		//HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH); //stockObject사용해 브러쉬 생성
		//HBRUSH oldBrush2 = (HBRUSH)SelectObject(mHdc, grayBrush);
		//Rectangle(mHdc, 400, 400, 500, 500);
		//SelectObject(mHdc, oldBrush2); //default로 돌려두기, delete는 할필요없음
		//Rectangle(mHdc, 500, 500, 600, 600);
	}

}