#pragma once
#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
class Gun;
class Player;
class Enemy;
class BackGround;
class GameCamera;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void PostRender(CRenderContext& rc)override;

	Gun* m_gun[2] = { nullptr };
	Player* m_player;
	Enemy* m_enemy;
	BackGround* m_bg;
	GameCamera* m_gc;

	CFont m_font;
	int m_timer = 0;
	int m_fontTiner = 10;
	
};

