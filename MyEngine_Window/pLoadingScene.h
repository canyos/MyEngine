#pragma once
#include "pScene.h"

namespace p {
	class LoadingScene : public Scene
	{
	public:
		LoadingScene();
		~LoadingScene();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void OnEnter() override;
		void OnExit()  override;
	private:
		void resourcesLoad(std::mutex& m);
	private:
		bool mbLoadCompleted;
		std::thread* mResourcesLoadThread;
		std::mutex mMutualExclusion;
	};
}


