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
	m_spriteModelRender->Init(L"sprite/title.dds",1300.0f, 1000.0f);
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