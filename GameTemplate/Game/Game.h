#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
class Gun;
class EnemyGun;
class Player;
class Enemy;
class BackGround;
class GameCamera;
class Bullet;
class EnemyBullet;
class Result;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void PostRender(CRenderContext& rc)override;

	Gun* m_gun;
	EnemyGun* m_eg;
	Player* m_player;
	Enemy* m_enemy;
	BackGround* m_bg;
	GameCamera* m_gc;
	Bullet* m_bullet;
	EnemyBullet* m_enemybullet;
	Result* m_result;

	CFont m_font;
	int m_timer = 0;
	int m_fontTiner = 30;
	int m_score = 0;
	int m_enescore = 0;
	int m_playerBullet = 50;
	int m_flag = 0;
};

