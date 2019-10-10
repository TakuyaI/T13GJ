#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"
#include "EnemyGun.h"
#include "EnemyBullet.h"


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
	
	//モデルの大きさ
	CVector3 scale;
	scale.x = 2.0f;
	scale.y = 2.0f;
	scale.z = 2.0f;
	m_skinModelRender->SetScale(scale);

	//初期位置
	m_position.x = 500.0f;
	m_position.y = 25.0f;
	m_position.z = 700.0f;
	//キャラコン
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
	/*if (pposix-100.0f > m_position.x) {
		m_position.x += 5.0f;
	}
	if (pposix+100.0f < m_position.x) {
		m_position.x -= 5.0f;
	}*/
	if (hani ==0 && m_position.x>pposix-200.0f){
		m_position.x -= 5.0f;
	}

	if (m_position.x <= pposix - 200.0f) {
		hani = 1;
	}
	if (hani == 1 && m_position.x < pposix + 200.0f) {
		m_position.x += 5.0f;
	}
	if (m_position.x >= pposix + 200.0f) {
		hani = 0;
	}

	//奥行方向
	float pposiz = FindGO<Player>("player")->m_position.z;
	if (pposiz > m_position.z-500.0f) {
		m_position.z += 5.0f;
	}
	if (pposiz <= m_position.z-500.0f) {
		m_position.z -= 5.0f;
	}
	//川を渡れないようにする。
	if (m_position.z < 450.0f) {
		m_position.z = 450.0f;
	}

	//座標、回転をスキンモデルレンダラーに伝える
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);

}
void Enemy::Attack()
{
	//プレイヤーとの距離が1000以下になったら、
	//弾を打つ
	CVector3 diff = FindGO<Player>("player")->m_position - m_position;
	if (diff.Length() < 1000.0f && m_timer >= 10 && m_enemybullet > 0) {
		EnemyBullet* m_enebullet = NewGO<EnemyBullet>(0, "enemyBullet");
		m_enebullet->m_position = FindGO<EnemyGun>("enemygun")->m_position;
		m_enebullet->m_moveSpeed.z = -50.0f;
		m_timer = 0;
		m_enemybullet--;
	}
	

	/*float posx = FindGO<Player>("player")->m_position.x;
	if (m_position.x - 100.0f < posx < m_position.x + 100.0f &&
		m_timer>= 10) {
		Bullet*m_enebullet = NewGO<Bullet>(0, "EnemyBullet");
		m_enebullet->m_position = m_position;
		m_enebullet->m_moveSpeed.z = 50.0f;
		m_timer = 0;
	}*/
	
}
void Enemy::Update()
{
	m_timer++;
	//移動
	if (m_enemybullet != 0) {
		Move();
	}
	//弾の補充
	if (m_enemybullet == 0&& m_timer >=180) {
		m_enemybullet = 50;
	}
	//攻撃
	Attack();

}