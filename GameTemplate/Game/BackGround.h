#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();

	void InitGhostObject();
	bool Start();
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CPhysicsGhostObject m_ghostObject;
	CVector3 m_position = CVector3::Zero;
	CPhysicsStaticObject stateObject;
};

