#include "stdafx.h"
#include "EnemyBullet.h"
#include "Player.h"


EnemyBullet::EnemyBullet()
{
}


EnemyBullet::~EnemyBullet()
{
	DeleteGO(m_skinModelRender);
}
bool EnemyBullet::Start()
{
	m_enegun = FindGO<EnemyGun>("enemygun");
	m_player = FindGO<Player>("player");
	m_enemy = FindGO<Enemy>("enemy");
	m_game = FindGO<Game>("game",false);
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/tama.cmo");
	m_position = m_enegun->m_position;
	m_skinModelRender->SetPosition(m_position);
	return true;
}
void EnemyBullet::Update()
{
	m_position += m_moveSpeed;
	m_skinModelRender->SetPosition(m_position);

	m_timer++;
	if (m_timer == 60) {
		DeleteGO(this);
	}

	CVector3 diff = m_player->m_position - m_position;
	if (diff.Length() < 100.0f) {
		m_game->m_enescore++;
		DeleteGO(this);
	}
	/*CVector3 v1 = m_position - m_enemy->m_position;
	if (v1.Length() < 70.0f) {
		DeleteGO(this);
	}
	CVector3 v2 = m_position - m_player->m_position;
	if (v2.Length() < 70.0f) {
		m_game->m_enescore++;
		DeleteGO(this);
	}*/
}