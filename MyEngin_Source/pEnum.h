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
			Prefab,
			End,
		};
		enum class eComponentType {
			Transform,
			SpriteRenderer,
			Script,
			Camera,
			End,
		};
	}
	

}