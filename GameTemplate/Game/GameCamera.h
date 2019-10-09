#pragma once
#include "Player.h"
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();

	bool Start();
	void Update();

	Player* m_player;

	CVector3 m_position = CVector3::Zero;
	CVector3 m_target = CVector3::Zero;
	CVector3 m_toCameraPos = CVector3::Zero;
	CVector3 m_toTargetPos = CVector3::Zero;
};

