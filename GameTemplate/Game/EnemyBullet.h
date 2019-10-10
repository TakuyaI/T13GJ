#pragma once
#include "EnemyGun.h"
#include "Player.h"
#include "Game.h"
class EnemyGun;
class Player;
class Enemy;
class Game;
class EnemyBullet :public IGameObject
{
public:
	EnemyBullet();
	~EnemyBullet();

	bool Start();
	void Update();

	EnemyGun* m_enegun;
	Player* m_player;
	Enemy* m_enemy;
	Game* m_game;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_moveSpeed = CVector3::Zero;

	int m_timer = 0;

};