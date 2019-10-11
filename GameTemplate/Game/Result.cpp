#include "stdafx.h"
#include "Result.h"
#include "Title.h"

Result::Result()
{
}


Result::~Result()
{
	DeleteGO(m_spriteRender);
	DeleteGO(m_fontRender);
	DeleteGO(spriteRender);
}
bool Result::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/taitoru.dds", 1300.0f, 750.0f);
	spriteRender = NewGO<prefab::CSpriteRender>(0);
	spriteRender->Init(L"sprite/gameclear.dds", 770.0f, 100.0f);
	position = { 0.0f,125.0f,0.0f };
	spriteRender->SetPosition(position);
	m_fontRender = NewGO<prefab::CFontRender>(0);
	m_fontRender->SetText(L"スコア　P1");
	m_position={ 300.0f,0.0f };
	m_fontRender->SetPosition(m_position);
	fontRender = NewGO<prefab::CFontRender>(0);
	fontRender->SetText(L"スコア　P2");
	m_2position = { 300.0f,-170.0f };
	fontRender->SetPosition(m_2position);
	m_Score = FindGO<Game>("game");
	m_score = m_Score->m_score;
	m_enescore = m_Score->m_enescore;
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
	/*else if () {
		//2Dが上から落ちてくる処理。
	}*/
	if (m_position.x == 300.0f && Pad(0).IsTrigger(enButtonStart)) {
		NewGO<Title>(1);
		DeleteGO(this);
	}
	m_fontRender->SetPosition(m_position);
	fontRender->SetPosition(m_2position);
	
}
