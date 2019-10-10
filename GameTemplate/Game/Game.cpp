#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "Enemy.h"
#include "EnemyGun.h"
#include "GameCamera.h"
#include "Gun.h"
#include "Result.h"
#include "Bullet.h"
#include "tkEngine/light/tkDirectionLight.h"

Game::Game()
{
	m_player = NewGO<Player>(0, "player");
	m_bg = NewGO<BackGround>(0, "background");
	m_enemy = NewGO<Enemy>(0, "enemy");
	m_gc = NewGO<GameCamera>(0, "gamecamera");
	m_gun = NewGO<Gun>(0, "gun");
	m_eg = NewGO<EnemyGun>(0, "enemygun");
	
}


Game::~Game()
{
	DeleteGO(m_player);
	DeleteGO(m_bg);
	DeleteGO(m_enemy);
	DeleteGO(m_gc);
	DeleteGO(m_gun);
	DeleteGO(m_eg);
		
}
bool Game::Start()
{
	////カメラを設定。
	//MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	//MainCamera().SetNear(10.0f);
	//MainCamera().SetFar(10000.0f);
	//MainCamera().SetPosition({ 0.0f, 70.0f, 200.0f });
	//MainCamera().Update();
	
	
	return true;
}

void Game::Update()
{
	m_timer++;
	if (m_timer == 60) {
		m_fontTiner--;
		m_timer = 0;
	}
	if (m_fontTiner < 0) {
		NewGO<Result>(1, "result");
			DeleteGO(this);
	}
}

void Game::PostRender(CRenderContext& rc)
{
	
	wchar_t text[256];
	swprintf_s(text, L"%d", m_fontTiner);
	m_font.Begin(rc);
	m_font.Draw(
		text,
		{ 0.0f, 300.0f },
		{0.0f, 0.0f, 0.0f, 1.0f},
		0.0f,
		1.8f,
		{ 0.0f, 1.0f }
	);

	swprintf_s(text, L"スコア%d", m_score);
	m_font.Draw(
		text,
		{ 400.0f, 250.0f },
		{ 0.0f, 0.0f, 0.0f, 1.0f },
		0.0f,
		1.0f,
		{ 0.0f, 1.0f }
	);

	swprintf_s(text, L"弾数%d", m_playerBullet);
	m_font.Draw(
		text,
		{ 400.0f, 200.0f },
		{ 0.0f, 0.0f, 0.0f, 1.0f },
		0.0f,
		1.0f,
		{ 0.0f, 1.0f }
	);
	m_font.End(rc);
}