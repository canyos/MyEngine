#pragma once
#include "CommonInclude.h"

namespace p {
	enum class eKeyState {
		Down, //����
		Pressed, //��� ����
		Up, //�����ٰ� ��
		None //�ƹ��͵�����
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
			eKeyCode keyCode; //���� Ű����
			eKeyState state; //����
			bool bPressed; // ���ȴ���
		};
		static void Initialize();
		static void Update();

		static bool GetKeyDown(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Up; }
		static bool GetKey(eKeyCode code) { return mKeys[(UINT)code].state == eKeyState::Pressed; }
	private:
		//eKeyState mState[] = eKeyState::Up;
		static std::vector<Key> mKeys; //��� Ű�� �����ϴ� vector, input��ü�� ���������ϰ� static���� ����

	};
}


