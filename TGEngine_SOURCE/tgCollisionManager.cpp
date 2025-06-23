#include "tgCollisionManager.h"
#include "tgScene.h"
#include "tgSceneManager.h"
#include "tgGameObject.h"
#include "tgCollider.h"
#include "tgTransform.h"
#include "tgGameObject.h"

namespace tg
{
	std::bitset<(UINT)eLayerType::Max> CollisionManager::mCollisionLayMatrix[(UINT)eLayerType::Max] = {};
	std::unordered_map<UINT64, bool> CollisionManager::mCollisionMap = {};

	void CollisionManager::Initialize()
	{

	}

	void CollisionManager::Update()
	{
		Scene* scene = SceneManager::GetActiveScene();
		for (UINT row = 0; row < (UINT)eLayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)eLayerType::Max; col++)
			{
				if (mCollisionLayMatrix[row][col] == true)
				{
					LayerCollision(scene, (eLayerType)row, (eLayerType)col);
				}
			}
		}
	}

	void CollisionManager::LateUpdate()
	{

	}

	void CollisionManager::Render(HDC hdc)
	{
		
	}
	void CollisionManager::CollisionLayerCheck(eLayerType left, eLayerType right, bool enable)
	{
		int row = 0;
		int col = 0;

		if (left <= right)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right;
			col = (UINT)left;
		}

		mCollisionLayMatrix[row][col] = enable;
	}

	void CollisionManager::LayerCollision(Scene* scene, eLayerType left, eLayerType right)
	{
		const std::vector<GameObject*>& lefts = scene->GetLayer(left)->GetGameObjects();
		const std::vector<GameObject*>& rights = scene->GetLayer(right)->GetGameObjects();
		
		for (GameObject* left : lefts)
		{
			if (left->IsActive() == false)
				continue;
			Collider* leftCol = left->GetComponent<Collider>();
			if (leftCol == nullptr)
				continue;

			for (GameObject* right : rights)
			{
				if (left->IsActive() == false)
					continue;
				Collider* rightCol = right->GetComponent<Collider>();
				if (rightCol == nullptr)
					continue;
				if (left == right)
					continue;

				ColliderCollision(leftCol, rightCol);

			}
		}
	}

	void CollisionManager::ColliderCollision(Collider* left, Collider* right)
	{
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();
		
		auto iter = mCollisionMap.find(id.id);
		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(std::make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
		}

		if (Intersect(left, right))
		{
			if (iter->second == false)
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
				iter->second = true;
			}
			else
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else
		{
			if (iter->second == true)
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);
				iter->second = false;
			}
		}
	}

	bool CollisionManager::Intersect(Collider* left, Collider* right)
	{
		Transform* leftTr = left->GetOwner()->GetComponent<Transform>();
		Transform* rightTr = right->GetOwner()->GetComponent<Transform>();

		Vector2 leftPos = leftTr->GetPosition() + left->GetOffset();
		Vector2 rightPos = rightTr->GetPosition() + right->GetOffset();

		Vector2 leftSize = left->GetSize();
		Vector2 rightSize = right->GetSize();

		eColliderType leftColliderType = left->GetColliderType();
		eColliderType rightColliderType = right->GetColliderType();

		if ((leftColliderType == eColliderType::Box2D
			|| leftColliderType == eColliderType::Circle2D
			|| leftColliderType == eColliderType::Capsule2D)
			&& (rightColliderType == eColliderType::Box2D
			|| rightColliderType == eColliderType::Circle2D
			|| rightColliderType == eColliderType::Capsule2D))
		{
			// 2D
			if (leftColliderType == eColliderType::Box2D && rightColliderType == eColliderType::Box2D)
			{
				// box to box
				if (fabs(leftPos.x - rightPos.x) <= leftSize.x / 2 + rightSize.x / 2
					&& fabs(leftPos.y - rightPos.y) <= leftSize.y / 2 + rightSize.y / 2)
				{
					return true;
				}
			}
			else if(leftColliderType == eColliderType::Circle2D && rightColliderType == eColliderType::Circle2D)
			{
				// circle to circle
				float cir2cirDistance = (leftPos - rightPos).length();
				if (cir2cirDistance <= leftSize.x / 2 + rightSize.x / 2)
				{
					return true;
				}
			}
			else if (leftColliderType == eColliderType::Capsule2D && rightColliderType == eColliderType::Capsule2D)
			{
				// capsule to capsule
				if (fabs(leftPos.y - rightPos.y) <= leftSize.y / 2 + rightSize.y / 2)
				{
					if (fabs(leftPos.y - rightPos.y)
						<= leftSize.y / 2 + rightSize.y / 2 - (leftSize.x / 2 + rightSize.x / 2))
					{
						if (fabs(leftPos.x - rightPos.x) <= leftSize.x / 2 + rightSize.x / 2)
						{
							return true;
						}
					}
					else
					{
						float cap2capDistance = ((leftPos - rightPos).abs()
							- Vector2(0, leftSize.y / 2 + rightSize.y / 2 - (leftSize.x / 2 + rightSize.x / 2)
							)).length();
						if (cap2capDistance <= leftSize.x / 2 + rightSize.x / 2)
						{
							return true;
						}
					}
				}

			}
			else if ((leftColliderType == eColliderType::Box2D && rightColliderType == eColliderType::Circle2D)
				|| (leftColliderType == eColliderType::Circle2D && rightColliderType == eColliderType::Box2D))
			{
				//box to circle

			}
			else if ((leftColliderType == eColliderType::Circle2D && rightColliderType == eColliderType::Capsule2D)
				|| (leftColliderType == eColliderType::Capsule2D && rightColliderType == eColliderType::Circle2D))
			{
				// circle to capsule

			}
			else if ((leftColliderType == eColliderType::Capsule2D && rightColliderType == eColliderType::Box2D)
				|| (leftColliderType == eColliderType::Box2D && rightColliderType == eColliderType::Capsule2D))
			{
				// capsule to box

			}
		}

		return false;
	}
}