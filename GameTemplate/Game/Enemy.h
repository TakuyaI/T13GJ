#pragma once
class Enemy : public IGameObject
{
public:
	Enemy();
	~Enemy();
	bool Start();
	void Move();
	void Update();

	prefab::CSkinModelRender* m_skiModelRender = nullptr;	//�X�L�����f�������_���[
	CQuaternion m_rotation = CQuaternion::Identity;		//��]
	CVector3 m_position = CVector3::Zero;				//�|�W�V����
	CCharacterController enechara;						//�L�����R��
};

