#pragma once
#include "CommonInclude.h"

namespace p {
	enum class eKeyState {
		Down, //누름
		Pressed, //계속 누름
		Up, //누르다가 뗌
		None //아무것도안함
	};
	enum class eKeyCode {
		Q,W,E,R,T,Y,U,I,O,P,
		A,S,D,F,G,H,J,K,L,
		Z,X,C,V,B,N,M, 
		Left,Right,Down,Up,
		END,
	};
	class Input
	{
	public:
		struct Key {
			eKeyCode keyCode; //무슨 키인지
			eKeyState state; //상태
			bool bPressed; // 눌렸는지
		};
		static void Initialize();
		static void Update();

		static bool GetKeyDown(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Up; }
		static bool GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Pressed; }
	private:
		//eKeyState mState[] = eKeyState::Up;
		static std::vector<Key> mKeys; //모든 키를 관리하는 vector, input전체가 공유가능하게 static으로 선언

	};
}


