#pragma once
class Title : public IGameObject
{
public:
	Title();
	~Title();

	bool Start();
	void Update();

	prefab::CSpriteRender* m_spriteModelRender = nullptr;
};

