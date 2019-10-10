#pragma once
class Enemy : public IGameObject
{
public:
	Enemy();
	~Enemy();
	bool Start();
	void Move();
	void Attack();
	void Update();


	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//�X�L�����f�������_���[
	CQuaternion m_rotation = CQuaternion::Identity;		//��]
	CVector3 m_position = CVector3::Zero;				//�|�W�V����
	CCharacterController enechara;						//�L�����R��
	int attack = 0;			//�U��
	int m_timer = 0;		//�^�C�}�[
	int m_enemybullet = 50;
	int hani = 0;
};

