#include "stdafx.h"
#include "Result.h"
#include "Title.h"

Result::Result()
{
}


Result::~Result()
{
	DeleteGO(m_spriteRender);//リザルト画面の削除
	DeleteGO(m_fontRender);//P1描画の削除
	DeleteGO(fontRender);//P2描画の削除
	DeleteGO(spriteRender);//ゲームクリアの削除
	DeleteGO(n_priteRender);//ゲームオーバーの削除
	DeleteGO(s_spriteRender);//ナイス
}
bool Result::Start()
{
	//リザルト画面の作成
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/taitoru.dds", 1300.0f, 750.0f);
	//ゲームクリアの作成
	spriteRender = NewGO<prefab::CSpriteRender>(0);
	spriteRender->Init(L"sprite/gameclear.dds", 770.0f, 100.0f);
	position = { 0.0f,450.0f,0.0f };//座標
	spriteRender->SetPosition(position);//与える。
	//ゲームオーバーの作成
	n_priteRender = NewGO<prefab::CSpriteRender>(0);
	n_priteRender->Init(L"sprite/gameover.dds", 770.0f, 100.0f);
	n_position = { 0.0f,450.0f,0.0f };//座標
	n_priteRender->SetPosition(n_position);//与える
	//ナイス
	s_spriteRender = NewGO<prefab::CSpriteRender>(0);
	s_spriteRender->Init(L"sprite/nice.dds", 770.0f, 400.0f);
	s_position = { -300.0f,-550.0f,0.0f };//座標
	s_spriteRender->SetPosition(s_position);//与える

	m_fontRender = NewGO<prefab::CFontRender>(0);
	m_fontRender->SetText(L"スコア　P1");
	m_position={ 300.0f,0.0f };
	m_fontRender->SetPosition(m_position);

	fontRender = NewGO<prefab::CFontRender>(0);
	fontRender->SetText(L"スコア　P2");
	m_2position = { 300.0f,-170.0f };
	fontRender->SetPosition(m_2position);

	m_Score = FindGO<Game>("game");//ゲーム.cppからスコアを探す
	m_score = m_Score->m_score;//操作する方のスコア
	m_enescore = m_Score->m_enescore;//敵のスコア
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
				spriteRender->SetPosition(position);//クリア
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
			n_priteRender->SetPosition(n_position);//オーバー
		}
	}
	if (m_position.x == 300.0f && Pad(0).IsTrigger(enButtonStart)) {
		NewGO<Title>(1);//タイトル作成
		DeleteGO(this);//リザルトで表示しているやつ全削除
	}
	m_fontRender->SetPosition(m_position);//P1に座標を与える。
	fontRender->SetPosition(m_2position);//P2に座標を与える。
}
