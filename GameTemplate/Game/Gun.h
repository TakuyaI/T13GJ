#pragma once
#include "Player.h"
class Gun : public IGameObject
{
public:
	Gun();
	~Gun();

	bool Start();
	void Update();

	Player* m_player;
	prefab::CSkinModelRender* m_skinmodelRender = nullptr;
	CVector3 m_position = CVector3::Zero;

};

