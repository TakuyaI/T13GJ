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
	m_fontRender->SetText(L"�X�R�A�@P1");
	m_position={ 700.0f,0.0f };
	m_fontRender->SetPosition(m_position);

	return true;

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
		//2D���ォ�痎���Ă��鏈���B
	}*/
	m_fontRender->SetPosition(m_position);
	
}
