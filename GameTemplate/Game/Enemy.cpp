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
	m_skiModelRender->Init(L"modelData/r2.cmo");
	m_rotation.SetRotationDeg(CVector3::AxisX, 90.0f);
	//モデルの大きさ
	CVector3 scale;


	m_position.x = 50.0f;
	m_position.y = 100.0f;
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
	m_skiModelRender->SetPosition(m_position);
	m_skiModelRender->SetRotation(m_rotation);

}
void Enemy::Update()
{
	Move();
}