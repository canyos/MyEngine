#pragma once
#include "pScene.h"

namespace p {
	class DontDestroyOnLoad : public Scene {
	public:
		DontDestroyOnLoad();
		~DontDestroyOnLoad();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;
		
		void OnEnter()override;//Scene�� ���ų� 
		void OnExit()override;//������ �ʿ���°� ó��


	private:
	};
}


