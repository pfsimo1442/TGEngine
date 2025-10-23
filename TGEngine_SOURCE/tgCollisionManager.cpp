#include "tgCollisionManager.h"
#include "tgScene.h"
#include "tgSceneManager.h"
#include "tgGameObject.h"
#include "tgCollider.h"
#include "tgTransform.h"
#include "tgGameObject.h"

namespace tg
{
	std::bitset<(UINT)eLayerType::Max> CollisionManager::mCollisionLayerMatrix[(UINT)eLayerType::Max] = {};
	std::unordered_map<UINT64, bool> CollisionManager::mCollisionMap = {};

	void CollisionManager::Initialize()
	{

	}

	void CollisionManager::Update()
	{
		for (UINT row = 0; row < (UINT)eLayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)eLayerType::Max; col++)
			{
				if (mCollisionLayerMatrix[row][col] == true)
				{
					LayerCollision((eLayerType)row, (eLayerType)col);
				}
			}
		}
	}

	void CollisionManager::LateUpdate()
	{

	}

	void CollisionManager::Render()
	{
		
	}

	void CollisionManager::Clear()
	{
		mCollisionMap.clear();
		mCollisionLayerMatrix->reset();
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

		mCollisionLayerMatrix[row][col] = enable;
	}

	void CollisionManager::LayerCollision(eLayerType left, eLayerType right)
	{
		const std::vector<GameObject*>& leftObjs = SceneManager::GetGameObjects(left);
		const std::vector<GameObject*>& rightObjs = SceneManager::GetGameObjects(right);
		
		for (GameObject* leftObj : leftObjs)
		{
			if (leftObj->IsActive() == false)
				continue;
			Collider* leftCol = leftObj->GetComponent<Collider>();
			if (leftCol == nullptr)
				continue;

			for (GameObject* rightObj : rightObjs)
			{
				if (rightObj->IsActive() == false)
					continue;
				Collider* rightCol = rightObj->GetComponent<Collider>();
				if (rightCol == nullptr)
					continue;
				if (leftObj == rightObj)
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
				float cir2cirDistance = (leftPos - rightPos).Length();
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

						Vector2 diff = leftPos - rightPos;
						diff.Abs();

						float cap2capDistance = (diff - Vector2(0, leftSize.y / 2 + rightSize.y / 2 - (leftSize.x / 2 + rightSize.x / 2)
							)).Length();
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
				// box to circle
				Vector2 boxSize;
				float circleRadius;
				Vector2 boxPos;
				Vector2 circlePos;

				if (leftColliderType == eColliderType::Box2D)
				{
					boxSize = leftSize;
					circleRadius = rightSize.x / 2;
					boxPos = leftPos;
					circlePos = rightPos;
				}
				else
				{
					boxSize = rightSize;
					circleRadius = leftSize.x / 2;
					boxPos = rightPos;
					circlePos = leftPos;
				}

				if (boxPos.x - boxSize.x / 2 - circleRadius <= circlePos.x
					&& circlePos.x <= boxPos.x + boxSize.x / 2 + circleRadius 
					&& boxPos.y - boxSize.y / 2 - circleRadius <= circlePos.y
					&& circlePos.y <= boxPos.y + boxSize.y / 2 + circleRadius)
				{
					Vector2 diff = circlePos - boxPos;
					diff.Abs();

					if ((boxPos.x - boxSize.x / 2 <= circlePos.x
						&& circlePos.x <= boxPos.x + boxSize.x / 2)
						|| (boxPos.y - boxSize.y / 2 <= circlePos.y
						&& circlePos.y <= boxPos.y + boxSize.y / 2))
					{
						return true;
					}
					else if ((diff - Vector2(boxSize.x / 2, boxSize.y / 2)
						).Length() 
						<= circleRadius)
					{
						return true;
					}
				}
			}
			else if ((leftColliderType == eColliderType::Circle2D && rightColliderType == eColliderType::Capsule2D)
				|| (leftColliderType == eColliderType::Capsule2D && rightColliderType == eColliderType::Circle2D))
			{
				// circle to capsule
				Vector2 capsuleSize;
				float circleRadius;
				Vector2 capsulePos;
				Vector2 circlePos;

				if (leftColliderType == eColliderType::Capsule2D)
				{
					capsuleSize = leftSize;
					circleRadius = rightSize.x / 2;
					capsulePos = leftPos;
					circlePos = rightPos;
				}
				else
				{
					capsuleSize = rightSize;
					circleRadius = leftSize.x / 2;
					capsulePos = rightPos;
					circlePos = leftPos;
				}

				if (capsulePos.x - capsuleSize.x / 2 - circleRadius <= circlePos.x
					&& circlePos.x <= capsulePos.x + capsuleSize.x / 2 + circleRadius
					&& capsulePos.y - capsuleSize.y / 2 - circleRadius <= circlePos.y
					&& circlePos.y <= capsulePos.y + capsuleSize.y / 2 + circleRadius)
				{
					Vector2 diff = capsulePos - circlePos;
					diff.Abs();

					if (capsulePos.y - capsuleSize.y / 2 + capsuleSize.x / 2<= circlePos.y
						&& circlePos.y <= capsulePos.y + capsuleSize.y / 2 - capsuleSize.x / 2)
					{
						return true;
					}
					else if ((diff - Vector2(0, capsuleSize.y / 2 - capsuleSize.x / 2)
						).Length()
						<= capsuleSize.x / 2 + circleRadius)
					{
						return true;
					}
				}
			}
			else if ((leftColliderType == eColliderType::Capsule2D && rightColliderType == eColliderType::Box2D)
				|| (leftColliderType == eColliderType::Box2D && rightColliderType == eColliderType::Capsule2D))
			{
				// capsule to box
				Vector2 boxSize;
				Vector2 capsuleSize;
				Vector2 boxPos;
				Vector2 capsulePos;

				if (leftColliderType == eColliderType::Box2D)
				{
					boxSize = leftSize;
					capsuleSize = rightSize;
					boxPos = leftPos;
					capsulePos = rightPos;
				}
				else
				{
					boxSize = rightSize;
					capsuleSize = leftSize;
					boxPos = rightPos;
					capsulePos = leftPos;
				}

				if (boxPos.x - boxSize.x / 2 - capsuleSize.x / 2 <= capsulePos.x
					&& capsulePos.x <= boxPos.x + boxSize.x / 2 + capsuleSize.x / 2
					&& boxPos.y - boxSize.y / 2 - capsuleSize.y / 2 <= capsulePos.y
					&& capsulePos.y <= boxPos.y + boxSize.y / 2 + capsuleSize.y / 2)
				{
					Vector2 diff = capsulePos - boxPos;
					diff.Abs();	

					if ((boxPos.x - boxSize.x / 2 <= capsulePos.x
						&& capsulePos.x <= boxPos.x + boxSize.x / 2)
						|| (boxPos.y - boxSize.y / 2 - (capsuleSize.y / 2 - capsuleSize.x / 2) <= capsulePos.y
						&& capsulePos.y <= boxPos.y + boxSize.y / 2 + (capsuleSize.y / 2 - capsuleSize.x / 2)))
					{
						return true;
					}
					else if ((diff - Vector2(boxSize.x / 2, boxSize.y / 2 + capsuleSize.y / 2 - capsuleSize.x / 2)
						).Length()
						<= capsuleSize.x / 2)
					{
						return true;
					}
				}
			}
		}

		return false;
	}
}