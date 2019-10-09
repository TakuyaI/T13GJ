#pragma once
#include "Gun.h"
#include "Player.h"
#include "Enemy.h"
#include "Game.h"
class Gun;
class Player;
class Enemy;
class Game;
class Bullet : public IGameObject
{
public:
	Bullet();
	~Bullet();

	bool Start();
	void Update();

	Gun* m_gun;
	Player* m_player;
	Enemy* m_enemy;
	Game* m_game;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_moveSpeed = CVector3::Zero;

	int m_timer = 0;
};

