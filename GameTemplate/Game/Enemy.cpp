#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
	DeleteGO(m_skiModelRender);

}

bool Enemy::Start()
{
	//スキンモデルレンダラーの作成
	m_skiModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skiModelRender->Init(L"modelData/r.cmo");

	m_position.x = 0.0f;
	m_position.y = 0.0f;
	m_position.z = 0.0f;
	enechara.Init(
		20.0f,
		70.0f,
		m_position
	);


	return true;
}
void Enemy::Move()
{

}
void Enemy::Update()
{

}