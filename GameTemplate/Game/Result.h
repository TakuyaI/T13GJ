#pragma once
#include "Game.h"
class Game;
class Result : public IGameObject
{
public:
	Result();
	~Result();
	bool Start();
	void Update();
	void PostRender(CRenderContext& rc)override;
	CFont m_font;
	int Score = 0;
	Game* m_Score;

	prefab::CSpriteRender* m_spriteRender = nullptr;//���U���g���
	prefab::CSpriteRender* spriteRender = nullptr;//�Q�[���N���A�̂��
	CVector3 position = CVector3::Zero;//�Q�[���N���A�̃|�W�V����
	prefab::CSpriteRender* n_priteRender = nullptr;//�Q�[���I�[�o�[
	CVector3 n_position = CVector3::Zero;//�Q�[���I�[�o�[�̃|�W�V����
	prefab::CFontRender* m_fontRender = nullptr;//P1
	prefab::CFontRender* fontRender = nullptr;//P2
	CVector2 m_position = CVector2::Zero;
	CVector2 m_2position = CVector2::Zero;
	int m_score = 0;
	int m_enescore = 0;
	int m_flag = 0;
	CVector2 heikou = { 650.0f, 0.0f };
	CVector2 tousoku = { 650.0f,-180.0f };
};

