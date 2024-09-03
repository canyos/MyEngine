#pragma once
#include "pEntity.h"
#include "CommonInclude.h"
#include "pGameObject.h"

namespace p {
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);
	private:
		eLayerType mType;
		std::vector<GameObject*> mGameObjects;
	};

}

