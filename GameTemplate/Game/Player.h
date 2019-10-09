#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();

	bool Start();
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。

};

