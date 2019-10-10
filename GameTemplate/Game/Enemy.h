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


	prefab::CSkinModelRender* m_skinModelRender = nullptr;	//スキンモデルレンダラー
	CQuaternion m_rotation = CQuaternion::Identity;		//回転
	CVector3 m_position = CVector3::Zero;				//ポジション
	CCharacterController enechara;						//キャラコン
	int attack = 0;			//攻撃
	int m_timer = 0;		//タイマー
	int m_enemybullet = 50;
	int hani = 0;
};

