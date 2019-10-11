#include "stdafx.h"
#include "Result.h"
#include "Title.h"

Result::Result()
{
}


Result::~Result()
{
	DeleteGO(m_spriteRender);//���U���g��ʂ̍폜
	DeleteGO(m_fontRender);//P1�`��̍폜
	DeleteGO(fontRender);//P2�`��̍폜
	DeleteGO(spriteRender);//�Q�[���N���A�̍폜
	DeleteGO(n_priteRender);//�Q�[���I�[�o�[�̍폜
	DeleteGO(s_spriteRender);//�i�C�X
}
bool Result::Start()
{
	//���U���g��ʂ̍쐬
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/taitoru.dds", 1300.0f, 750.0f);
	//�Q�[���N���A�̍쐬
	spriteRender = NewGO<prefab::CSpriteRender>(0);
	spriteRender->Init(L"sprite/gameclear.dds", 770.0f, 100.0f);
	position = { 0.0f,450.0f,0.0f };//���W
	spriteRender->SetPosition(position);//�^����B
	//�Q�[���I�[�o�[�̍쐬
	n_priteRender = NewGO<prefab::CSpriteRender>(0);
	n_priteRender->Init(L"sprite/gameover.dds", 770.0f, 100.0f);
	n_position = { 0.0f,450.0f,0.0f };//���W
	n_priteRender->SetPosition(n_position);//�^����
	//�i�C�X
	s_spriteRender = NewGO<prefab::CSpriteRender>(0);
	s_spriteRender->Init(L"sprite/nice.dds", 770.0f, 400.0f);
	s_position = { -300.0f,-550.0f,0.0f };//���W
	s_spriteRender->SetPosition(s_position);//�^����

	m_fontRender = NewGO<prefab::CFontRender>(0);
	m_fontRender->SetText(L"�X�R�A�@P1");
	m_position={ 300.0f,0.0f };
	m_fontRender->SetPosition(m_position);

	fontRender = NewGO<prefab::CFontRender>(0);
	fontRender->SetText(L"�X�R�A�@P2");
	m_2position = { 300.0f,-170.0f };
	fontRender->SetPosition(m_2position);

	m_Score = FindGO<Game>("game");//�Q�[��.cpp����X�R�A��T��
	m_score = m_Score->m_score;//���삷����̃X�R�A
	m_enescore = m_Score->m_enescore;//�G�̃X�R�A
	return true;

}

void Result::PostRender(CRenderContext& rc)
{
	wchar_t text[256];
	swprintf_s(text, L"%d", m_score);
	m_font.Begin(rc);
	m_font.Draw(
		text,
		heikou,
		{ 0.0f, 0.0f, 0.0f, 1.0f },
		0.0f,
		1.8f,
		{ 0.0f, 1.0f }
	);

	swprintf_s(text, L"%d", m_enescore);
	m_font.Draw(
		text,
		tousoku,
		{ 0.0f, 0.0f, 0.0f, 1.0f },
		0.0f,
		1.8f,
		{ 0.0f, 1.0f }
	);
	m_font.End(rc);
}

void Result::Update()
{
	if (heikou.x <= 800.0f){
		heikou.x -= 10.0f;
	}
	if (heikou.x <= 360.0f) {
		heikou.x = 360.0f;
	}
	if (tousoku.x <= 800.0f) {
		tousoku.x -= 10.0f;
	}
	if (tousoku.x <= 360.0f) {
		tousoku.x = 360.0f;
	}
	if (heikou.x== 360.0f && tousoku.x == 360.0f && m_score > m_enescore) {
			if (position.y<= 500.0f){
				position.y -= 10.0f;
			}
			if (position.y <= 125.0f) {
				position.y = 125.0f;
				spriteRender->SetPosition(position);//�N���A
				if (position.y == 125.0f) {
					if (s_position.y <= -550.0f) {
						s_position.y += 10.0f;
					}
					if (s_position.y <= 150.0f) {
						s_position.y = -150.0f;
						s_spriteRender->SetPosition(s_position);
					}
				}
			}
	}
	else if (heikou.x == 360.0f && tousoku.x == 360.0f && m_enescore > m_score) {
		if (n_position.y <= 500.0f) {
			n_position.y -= 10.0f;
		}
		if (n_position.y <= 125.0f) {
			n_position.y = 125.0f;
			n_priteRender->SetPosition(n_position);//�I�[�o�[
		}
	}
	if (m_position.x == 300.0f && Pad(0).IsTrigger(enButtonStart)) {
		NewGO<Title>(1);//�^�C�g���쐬
		DeleteGO(this);//���U���g�ŕ\�����Ă����S�폜
	}
	m_fontRender->SetPosition(m_position);//P1�ɍ��W��^����B
	fontRender->SetPosition(m_2position);//P2�ɍ��W��^����B
}
