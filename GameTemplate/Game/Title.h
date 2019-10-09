#pragma once
class Title : public IGameObject
{
public:
	Title();
	~Title();

	bool Start();
	void Update();
	void PostRender(CRenderContext& rc)override;

	prefab::CSpriteRender* m_spriteModelRender = nullptr;
	CFont m_fontTest;
};

