#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "Bullet.h"
#include "BackGround.h"
#include "Game.h"

class Bullet;
class BackGround;
class Player : public IGameObject
{
public:
	Player();
	~Player();

	void InitGhostObject();
	bool Start();
	void Update();

	Bullet* m_bullet;
	BackGround* m_bg;
	Game* m_game;

	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//�X�L�����f�������_���[�B
	CVector3 m_position = CVector3::Zero;//���W�B
	CVector3 m_moveSpeed = CVector3::Zero;//���x�B
	CPhysicsGhostObject m_ghostObject;//�S�[�X�g�B
	CCharacterController m_charaCon;//�L�����R���B
	int m_timer = 0;//�^�C�}�[�B
	int m_bulletTimer = 0;//�e�̃C���^�[�o���B
	int m_flag = 0;//�t���O�B
};

