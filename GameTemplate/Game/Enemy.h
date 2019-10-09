#pragma once
class Enemy : public IGameObject
{
public:
	Enemy();
	~Enemy();
	bool Start();
	void Update();

	prefab::CSkinModelRender* m_skiModelRender = nullptr;
	CQuaternion m_rotation = CQuaternion::Identity;
};

