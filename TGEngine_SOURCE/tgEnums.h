#pragma once

namespace tg::enums
{
	enum class eComponentType
	{
		Transform,
		Collider, 
		Rigidbody,
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
		Platform,
		Tile,
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

	enum class eColliderType
	{
		Circle2D,
		Box2D,
		Capsule2D,
		End,
	};

	enum class eUIType
	{
		Button,
		Image,
		Text,
		InputField,
		Toggle,
		Slider,
		End,
	};
}