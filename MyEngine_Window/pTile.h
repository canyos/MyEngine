#pragma once
#include "pGameObject.h"

namespace p {
	class Tile : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void SetIndexPosition(int x, int y);
	private:
	};
}


