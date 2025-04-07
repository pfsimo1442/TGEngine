#pragma once

namespace tg::enums
{
	enum class eComponentType
	{
		Transform, 
		SpriteRenderer, 
		Script, 
		Camera,
		End,
	};

	enum class eLayerType
	{
		None,
		BackGround,
		// Monster,
		Player,
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		// Mash, 
		// Shader, 
		AudioClip,
		Prefab, 
		End,
	};
}