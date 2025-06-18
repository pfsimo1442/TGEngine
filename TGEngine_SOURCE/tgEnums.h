#pragma once

namespace tg::enums
{
	enum class eComponentType
	{
		Transform,
		Collider, 
		Script, 
		SpriteRenderer,
		Animator, 
		Camera,
		End,
	};

	enum class eLayerType
	{
		None,
		BackGround,
		Player,
		Pet, 
		// Monster,
		Particle,
		Max = 16,
	};
	
	enum class eResourceType
	{
		Texture,
		// Mash, 
		// Shader, 
		AudioClip,
		Animation,
		Prefab, 
		End,
	};
}