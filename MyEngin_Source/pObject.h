#pragma once
#include "pLayer.h"
#include "pGameObject.h"
#include "pSceneManager.h"
#include "pScene.h"
#include "pComponent.h"
#include "pMath.h"
#include "pTransform.h"

namespace p {
	namespace object {
		template<typename T>
		static T* Instantiate(p::enums::eLayerType type) {
			T* gameObject = new T();
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);
			return gameObject;
		}

		template<typename T>
		static T* Instantiate(p::enums::eLayerType type,Vector2 pos ) {
			T* gameObject = new T();
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);

			Transform* tr = gameObject->GetComponent<Transform>();
			tr->SetPosition(pos);
			return gameObject;
		}
	}

}