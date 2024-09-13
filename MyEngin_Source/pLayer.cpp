#include "pLayer.h"
namespace p {
	Layer::Layer() : mGameObjects {}
	{
	}
	Layer::~Layer()
	{
		for (GameObject* gameobj : mGameObjects) {
			if (gameobj == nullptr)
				continue;
			delete gameobj;
			gameobj = nullptr;
		}
	}
	void Layer::Initialize()
	{
		for (GameObject* gameObj : mGameObjects) {
			if (gameObj == nullptr)
				continue;
			gameObj->Update();
		}
	}
	void Layer::Update()
	{
		for (GameObject* gameObj : mGameObjects) {
			if (gameObj == nullptr)
				continue;
			gameObj->Update();
		}
	}
	void Layer::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects) {
			if (gameObj == nullptr)
				continue;
			gameObj->LateUpdate();
		}
	}
	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameObj : mGameObjects) {
			if (gameObj == nullptr)
				continue;
			gameObj->Render(hdc);
		}
			
	}
	void Layer::AddGameObject(GameObject * gameObject)
	{
		if (gameObject == nullptr)
			return;
		mGameObjects.push_back(gameObject);
	}
}