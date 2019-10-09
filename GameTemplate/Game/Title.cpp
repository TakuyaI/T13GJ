#include "stdafx.h"
#include "Title.h"
#include "Game.h"

Title::Title()
{
}


Title::~Title()
{
	DeleteGO(m_spriteModelRender);
}

bool Title::Start() 
{
	m_spriteModelRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteModelRender->Init(L"sprite/Title.dds",1300.0f, 1000.0f);
	
	return true;
}

void Title::Update()
{
	if (Pad(0).IsPress(enButtonA))
	{
		NewGO<Game>(0);
		
		prefab::CSoundSource* sound = NewGO<prefab::CSoundSource>(0);
		sound->Init( L"sound/saezuri.wav");
		sound->Play(false);
		DeleteGO(this);
	}

}

void Title::PostRender(CRenderContext& rc)
{
	wchar_t text[256];
	swprintf_s(text, L"スタート");
	m_fontTest.Begin(rc);
	m_fontTest.Draw(
		text,
		{ 465.0f, 340.0f },
		{ 1.0f, 0.0f, 0.0f, 1.0f },
		0.0f,
		0.8f,
		{ 0.0f, 1.0f }
	);
	m_fontTest.End(rc);
}