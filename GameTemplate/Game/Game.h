#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
class Gun;
class Player;
class Enemy;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	
	Gun* m_gun[2] = { nullptr };
	Player* m_player;
	Enemy* m_enemy;
};

