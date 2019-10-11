#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet()
{
}


Bullet::~Bullet()
{
	DeleteGO(m_skinModelRender);
}

bool Bullet::Start()
{
	m_gun = FindGO<Gun>("gun");
	m_player = FindGO<Player>("player");
	m_enemy = FindGO<Enemy>("enemy");
	m_game = FindGO<Game>("game",false);
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/tama.cmo");
	m_position = m_gun->m_position;
	m_skinModelRender->SetPosition(m_position);
	return true;
}
void Bullet::Update()
{
	m_position += m_moveSpeed;
	m_skinModelRender->SetPosition(m_position);

	m_timer++;
	if (m_timer == 60) {
		DeleteGO(this);
	}

	CVector3 v1 = m_position - m_player->m_position;
	if (v1.Length() < 70.0f) {
		DeleteGO(this);
	}
	CVector3 v2 = m_position - m_enemy->m_position;
	if (v2.Length() < 70.0f) {
		m_game->m_score++;
		DeleteGO(this);
	}
}