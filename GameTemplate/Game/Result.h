#pragma once
class Result : public IGameObject
{
public:
	Result();
	~Result();
	bool Start();
	void Update();
	prefab::CSpriteRender* m_spriteRender = nullptr;
	prefab::CFontRender* m_fontRender = nullptr;
	CVector2 m_position = CVector2::Zero;
	int m_score = 0;
};

