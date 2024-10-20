#include "pScene.h"
#include "pCollisionManager.h"
#include "pSceneManager.h"

namespace p {
	Scene::Scene() :mLayers{}
	{
		mLayers.resize((UINT)enums::eLayerType::Max);
		for (int i = 0; i < (UINT)enums::eLayerType::Max; i++) {
			mLayers[i] = new Layer();
		}
	}
	Scene::~Scene()
	{
		for (Layer*layer : mLayers) {
			delete layer;
			layer = nullptr;
		}
	}
	void Scene::Initialize()
	{
		const std::wstring& sceneName = GetName();
		SceneManager::SetActiveScene(sceneName);
	}
	void Scene::Update()
	{
		for (Layer* layer : mLayers) {
			if (layer == nullptr) continue;
			layer->Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (Layer* layer : mLayers) {
			if (layer == nullptr) continue;
			layer->LateUpdate();
		}
	}
	void Scene::Render()
	{
		for (Layer* layer : mLayers) {
			if (layer == nullptr) continue;
			layer->Render();
		}
	}

	void Scene::Destroy()
	{
		for (Layer* layer : mLayers) {
			if (layer == nullptr) continue;
			layer->Destroy();
		}
	}

	void Scene::OnEnter() {

	}
	void Scene::OnExit() {
		CollisionManager::Clear();
	}
	void Scene::AddGameObject(GameObject * gameObject,  enums::eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObject);
	}
	void Scene::EraseGameObject(GameObject* gameObj)
	{
		eLayerType layerType = gameObj->GetLayerType();
		mLayers[(UINT)layerType]->EraseGameObjects(gameObj);

	}
}

