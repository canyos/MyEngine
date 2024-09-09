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
			Player,
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
			SpriteRenderer,
			Animator,
			Script,
			Camera,
			End,
		};
	}
	

}