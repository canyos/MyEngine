#include "pInput.h"

namespace p {
	std::vector<Input::Key> Input::mKeys = {};
	int ASCII[(UINT)eKeyCode::END] = {
		'Q','W','E','R','S','T','U','I','O','P',
		'A','S','D','F','G','H','J','K','L',
		'Z','X','C','V','B','N','M',
		VK_LEFT,VK_RIGHT,VK_DOWN,VK_UP,
	};
	void p::Input::Initialize()
	{
		
		for (size_t i = 0; i < (UINT) eKeyCode::END; i++) {
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode) i;
			mKeys.push_back(key);
		}
	}

	void p::Input::Update()
	{
		for (size_t i = 0; i < mKeys.size(); i++) {
			//키가 눌렸다.
			if (GetAsyncKeyState(ASCII[i]) & 0x8000) {
				if (mKeys[i].bPressed) {//이전 프레임에도 눌려있음
					mKeys[i].state = eKeyState::Pressed;
				}
				else {//지금 누른거임
					mKeys[i].state = eKeyState::Down;
				}
				mKeys[i].bPressed = true;
			}
			else {//키가 안눌림
				if (mKeys[i].bPressed) {//이전 프레임에는 눌려있음
					mKeys[i].state = eKeyState::Up;
				}
				else {//지금 누른거임
					mKeys[i].state = eKeyState::None;
				}
				mKeys[i].bPressed = false;
			}
		}
	}
}

