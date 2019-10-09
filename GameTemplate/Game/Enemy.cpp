#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
	DeleteGO(m_skinModelRender);
}

bool Enemy::Start()
{
	//スキンモデルレンダラーの作成
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/r2.cmo");
	
	/*m_rotation.SetRotationDeg(CVector3::AxisY, 180.0f);

	m_rotation.SetRotationDeg(CVector3::AxisX, 90.0f);
	m_skinModelRender->SetRotation(m_rotation);
*/
	//モデルの大きさ
	CVector3 scale;
	scale.x = 2.0f;
	scale.y = 2.0f;
	scale.z = 2.0f;
	m_skinModelRender->SetScale(scale);


	m_position.x = 500.0f;
	m_position.y = 15.0f;
	m_position.z = 500.0f;
	enechara.Init(
		20.0f,
		70.0f,
		m_position
	);


	return true;
}
void Enemy::Move()
{
	//左右移動
	float pposix= FindGO<Player>("player")->m_position.x;
	if (pposix > m_position.x) {
		m_position.x += 5.0f;
	}
	if (pposix < m_position.x) {
		m_position.x -= 5.0f;
	}
	//奥行方向
	float pposiz = FindGO<Player>("player")->m_position.z;
	if (pposiz > m_position.z-500.0f) {
		m_position.z += 5.0f;
	}
	if (pposiz <= m_position.z-500.0f) {
		m_position.z -= 5.0f;
	}

	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);

}
void Enemy::Attack()
{
	CVector3 diff = FindGO<Player>("player")->m_position - m_position;
	if (diff.Length() < 300.0f) {
		attack = 1;
	}
	float pposix = FindGO<Player>("player")->m_position.x;
	if (attack == 1); {
		attack = 0;
	}
}
void Enemy::Update()
{
	Move();

}