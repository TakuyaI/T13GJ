#pragma once
#include "Bullet.h"
class Bullet;
class Player : public IGameObject
{
public:
	Player();
	~Player();

	bool Start();
	void Update();

	Bullet* m_bullet;

	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero;
	CVector3 m_moveSpeed = CVector3::Zero;
	CCharacterController m_charaCon;
	int m_timer = 0;
};

