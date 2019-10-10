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
}
bool Result::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/reslut.dds", 1300.0f, 750.0f);
	m_fontRender = NewGO<prefab::CFontRender>(0);
	m_fontRender->SetText(L"スコア　P1");
	m_position={ 700.0f,0.0f };
	m_fontRender->SetPosition(m_position);
	m_Score = FindGO<Game>("game");
	m_score = m_Score->m_score;
	return true;

}

void Result::PostRender(CRenderContext& rc)
{
	wchar_t text[256];
	swprintf_s(text, L"%d", m_score);
	m_font.Begin(rc);
	m_font.Draw(
		text,
		{ 350.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f, 1.0f },
		0.0f,
		1.8f,
		{ 0.0f, 1.0f }
	);
	m_font.End(rc);
}

void Result::Update()
{
	if (m_position.x <= 800.0f){
		m_position.x -= 10.0f;
	}
	if (m_position.x <= 300.0f) {
		m_position.x = 300.0f;
	}
	/*else if () {
		//2Dが上から落ちてくる処理。
	}*/
	if (m_position.x == 300.0f && Pad(0).IsTrigger(enButtonStart)) {
		NewGO<Title>(1);
		DeleteGO(this);
	}
	m_fontRender->SetPosition(m_position);
	
}
