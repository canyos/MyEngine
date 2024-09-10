#include "pInput.h"
#include "pApplication.h"

namespace p {
	std::vector<Input::Key> Input::Keys = {};
	int ASCII[(UINT)eKeyCode::END] = {
		'Q','W','E','R','S','T','U','I','O','P',
		'A','S','D','F','G','H','J','K','L',
		'Z','X','C','V','B','N','M',
		VK_LEFT,VK_RIGHT,VK_DOWN,VK_UP,
		
	};
	
	void Input::Initialize()
	{
		createKeys();
	}

	void Input::Update()
	{
		updateKeys();
	}
	void Input::createKeys() {
		for (size_t i = 0; i < (UINT)eKeyCode::END; i++) {
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;
			Keys.push_back(key);
		}
	}
	void Input::updateKeys() {
		for (Input::Key& key : Keys)
			updateKey(key);
	}
	void Input::updateKey(Input::Key& key) {
		if (isKeyDown(key.keyCode)) {
			updateKeyDown(key);
		}
		else {
			updateKeyUp(key);
		}
	}
	bool Input::isKeyDown(eKeyCode code) {
		return GetAsyncKeyState(ASCII[static_cast<UINT>(code)]) & 0x8000;
	}
	void Input::updateKeyDown(Input::Key& key) {//키가 눌렸다.
		if (key.bPressed == true)//이전 프레임에도 눌려있음
			key.state = eKeyState::Pressed;
		else//지금 누른거임
			key.state = eKeyState::Down;
		key.bPressed = true;
	}
	void Input::updateKeyUp(Input::Key& key) {//키가 안눌림
		if (key.bPressed == true)//이전 프레임에는 눌려있음
			key.state = eKeyState::Up;
		else
			key.state = eKeyState::None;
		key.bPressed = false;
	}
}