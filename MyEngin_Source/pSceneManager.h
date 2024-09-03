#pragma once
#include "pScene.h"

namespace p {
	class SceneManager{
	public:
		template <typename T>
		static Scene* CreateScene(std::wstring name) {
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize();
			mScene.insert({ name, scene });
			return scene;
		}

		static Scene* LoadScene(const std::wstring& name){
			if(mActiveScene)
				mActiveScene->OnExit();
			std::map<const std::wstring, Scene*>::iterator iter = mScene.find(name);
			if (iter == mScene.end())
				return nullptr;
			mActiveScene = iter->second;
			mActiveScene->OnEnter();
			return iter->second;
		} 
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
	private:
		//static std::vector<Scene*> mScene;
		static std::map<const std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
	};
}


