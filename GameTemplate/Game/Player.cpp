#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
	DeleteGO(m_skinModelRender);
}

//ゴーストの初期化。
void Player::InitGhostObject()
{
	//ゴーストのワイヤーフレーム表示を有効にする
#if _DEBUG && 0
	PhysicsWorld().SetDebugDrawMode(btIDebugDraw::DBG_DrawWireframe);
#endif
	//ボックス形状のゴーストを作成する
	m_ghostObject.CreateBox(
		m_bg->m_position,                 //第一引数は座標
		CQuaternion::Identity,      //第二引数は回転クォータニオン
		{ 12000.0f,500.0f,800.0 }     //第三引数はボックスのサイズ
	);
}

bool Player::Start()
{
	m_bg = FindGO<BackGround>("background");
	m_game = FindGO<Game>("game");

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");

	m_position.z = -800.0f;
	m_skinModelRender->SetPosition(m_position);
	m_charaCon.Init(50.0f, 100.0f, m_position);

	//ゴーストの初期化。
	InitGhostObject();

	return true;
}

void Player::Update()
{
	if (m_flag == 0) {
		m_moveSpeed.x = Pad(0).GetLStickXF() * 400.0f;
		m_moveSpeed.z = Pad(0).GetLStickYF() * 400.0f;

		if (m_game->m_playerBullet > 0) {
			m_timer++;
			if (Pad(0).IsPress(enButtonB) && m_timer >= 10) {
				m_bullet = NewGO<Bullet>(0, "bullet");
				m_bullet->m_moveSpeed.z = 50.0f;
				m_game->m_playerBullet--;
				m_timer = 0;
			}
		}
	}
	m_position = m_charaCon.Execute(m_moveSpeed);

	m_skinModelRender->SetPosition(m_position);


	PhysicsWorld().ContactTest(m_charaCon, [&](const btCollisionObject & contactObject) {
		if (m_ghostObject.IsSelf(contactObject) == true) {
			//m_ghostObjectとぶつかった
			if (Pad(0).IsPress(enButtonA)) {
				if (m_game->m_playerBullet < 50) {
					m_flag = 1;
					m_bulletTimer++;
					if (m_bulletTimer == 120) {
						m_game->m_playerBullet = 50;
						m_bulletTimer = 0;
						m_flag = 0;
					}
				}
			}
		}
	});


	//if (m_game->m_playerBullet < 50) {
	//	PhysicsWorld().ContactTest(m_charaCon, [&](const btCollisionObject & contactObject) {
	//		if (m_ghostObject.IsSelf(contactObject) == true) {
	//			//m_ghostObjectとぶつかった
	//			if (Pad(0).IsPress(enButtonA)) {
	//				m_flag = 1;
	//				m_bulletTimer++;
	//				if (m_bulletTimer == 120) {
	//					m_game->m_playerBullet = 50;
	//					m_bulletTimer = 0;
	//				}
	//				m_flag = 0;
	//			}
	//		}
	//		m_bulletTimer = 0;
	//	});
	//}
}