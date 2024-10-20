#pragma once
#include "pScene.h"
#include "pDontDestroyOnLoad.h"
namespace p {
	class SceneManager{
	public:
		template <typename T>
		static Scene* CreateScene(std::wstring name) {
			T* scene = new T();
			mScene.insert(std::make_pair(name, scene));
			scene->SetName(name);
			scene->Initialize();
			mScene.insert({ name, scene });
			
			return scene;
		}

		static bool SetActiveScene(const std::wstring& name);
		static Scene* LoadScene(const std::wstring& name);

		static Scene* GetActiveScene() { return mActiveScene; }
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render();

		static void Destroy();
		static void Release();

		static Scene* GetDontDestroyOnLoad() { return mDontDestroyOnLoad; }
		static std::vector<GameObject*> GetGameObjects(eLayerType layer);

	private:
		//static std::vector<Scene*> mScene;
		static std::map<const std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
		static Scene* mDontDestroyOnLoad;
	};
}


