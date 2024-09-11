#pragma once
#include "CommonInclude.h"
#include "pMath.h"
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
		LButton, MButton, RButton,
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

		static bool GetKeyDown(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Up; }
		static bool GetKey(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Pressed; }
		static math::Vector2 GetMousePosition() { return mMousePosition; }
	private:
		//eKeyState mState[] = eKeyState::Up;
		static std::vector<Key> Keys; //��� Ű�� �����ϴ� vector, input��ü�� ���������ϰ� static���� ����
		static math::Vector2 mMousePosition;
	private:
		static void createKeys();
		static void updateKeys();
		static void updateKeyDown(Input::Key & key);
		static void updateKeyUp(Input::Key & key);
		static void updateKey(Input::Key& key);
		static bool isKeyDown(eKeyCode code);
		static void clearKeys();
		static void getMousePositionByWindow();
	};
}


