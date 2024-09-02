#pragma once
#include "pEntity.h"
#include "pGameObject.h"

namespace p {
	class Scene : public Entity {
	public:
		Scene();
		~Scene();
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		
		void AddGameObject(GameObject* gameObject);
	private:
		std::vector<GameObject*> mGameObjects;
	};
}


