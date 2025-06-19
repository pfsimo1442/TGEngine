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
		// Monster,
		Pet, 
		Player,
		Particle,
		Max = 16,
	};

//#define (UINT)(eLayerType::Max);
	
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