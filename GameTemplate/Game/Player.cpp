#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
	DeleteGO(m_skinModelRender);
}

//�S�[�X�g�̏������B
void Player::InitGhostObject()
{
	//�S�[�X�g�̃��C���[�t���[���\����L���ɂ���
#if _DEBUG && 0
	PhysicsWorld().SetDebugDrawMode(btIDebugDraw::DBG_DrawWireframe);
#endif
	//�{�b�N�X�`��̃S�[�X�g���쐬����
	m_ghostObject.CreateBox(
		m_bg->m_position,                 //�������͍��W
		CQuaternion::Identity,      //�������͉�]�N�H�[�^�j�I��
		{ 12000.0f,500.0f,800.0 }     //��O�����̓{�b�N�X�̃T�C�Y
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

	//�S�[�X�g�̏������B
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
			//m_ghostObject�ƂԂ�����
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
	//			//m_ghostObject�ƂԂ�����
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