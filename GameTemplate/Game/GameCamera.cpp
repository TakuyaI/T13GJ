#include "stdafx.h"
#include "GameCamera.h"


GameCamera::GameCamera()
{
}


GameCamera::~GameCamera()
{
}

bool GameCamera::Start()
{
	//ƒJƒƒ‰‚ğİ’èB
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	m_toCameraPos = { 0.0f, 50.0f, 10.0f };
	m_toTargetPos = { 0.0f, 0.0f, 1000.0f };
	m_player = FindGO<Player>("player");
	return true;
}

void GameCamera::Update()
{
	m_target = m_player->m_position;
	m_target.y += 50.0f;

	m_position = m_target + m_toCameraPos;

	MainCamera().SetTarget(m_target + m_toTargetPos);
	MainCamera().SetPosition(m_position);
	MainCamera().Update();
}