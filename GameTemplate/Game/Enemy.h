#pragma once
class Enemy : public IGameObject
{
public:
	Enemy();
	~Enemy();
	bool Start();
	void Move();
	void Update();

	prefab::CSkinModelRender* m_skiModelRender = nullptr;	//スキンモデルレンダラー
	CQuaternion m_rotation = CQuaternion::Identity;		//回転
	CVector3 m_position = CVector3::Zero;				//ポジション
	CCharacterController enechara;						//キャラコン
};

