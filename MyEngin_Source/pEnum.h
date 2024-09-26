#pragma once
namespace p
{
	namespace enums {
		enum class eLayerType
		{
			None,
			BackGround,
			//Tree 
			//character
			Tile,
			Animal,
			Player,
			Paricle,
			Max = 16,
		};

		enum class eResourceType {
			Texture,
			//Mesh
			//shader
			Audioclip,
			Animation,
			Prefab,
			End,
		};
		enum class eComponentType {
			Transform,
			Collider,
			Script,
			SpriteRenderer,
			Animator,
			Camera,
			End,
		};
		enum class eColliderType
		{
			Circle2D,
			Rect2D,
			End,
		};
	}
	

}