#pragma once
#include "Enemy.h"
class Enemy;
class EnemyGun : public IGameObject
{
public:
	EnemyGun();
	~EnemyGun();

	bool Start();
	void Update();

	Enemy* m_enemy;
	prefab::CSkinModelRender* m_skinmodelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
};

