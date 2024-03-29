#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "Bullet.h"
#include "BackGround.h"
#include "Game.h"

class Bullet;
class BackGround;
class Player : public IGameObject
{
public:
	Player();
	~Player();

	void InitGhostObject();
	bool Start();
	void Update();

	Bullet* m_bullet;
	BackGround* m_bg;
	Game* m_game;

	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero;//座標。
	CVector3 m_moveSpeed = CVector3::Zero;//速度。
	CPhysicsGhostObject m_ghostObject;//ゴースト。
	CCharacterController m_charaCon;//キャラコン。
	int m_timer = 0;//タイマー。
	int m_bulletTimer = 0;//弾のインターバル。
	int m_flag = 0;//フラグ。
};

