#include "pScene.h"

namespace p {
	Scene::Scene()
	{
	}
	Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{
	}
	void Scene::Update()
	{
		for (GameObject* gameObj : mGameObjects)
			gameObj->Update();
	}
	void Scene::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects)
			gameObj->LateUpdate();
	}
	void Scene::Render(HDC hdc)
	{
		for (GameObject* gameObj : mGameObjects)
			gameObj->Render(hdc);
	}
	void Scene::AddGameObject(GameObject * gameObject)
	{
		mGameObjects.push_back(gameObject);
	}
}

