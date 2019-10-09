#pragma once
class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();

	bool Start();
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
};

