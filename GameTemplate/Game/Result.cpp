#include "stdafx.h"
#include "Result.h"


Result::Result()
{
}


Result::~Result()
{
}
bool Result::Start()
{
	m_fontRender = NewGO<prefab::CFontRender>(0);
	m_fontRender->SetText(L"Hello");
	m_fontRender->SetPosition({ 500, 0 });
	return true;

}
void Result::Update()
{
	/*if () {
		//�������X���C�h�C�����Ă��鏈��
	}
	else if () {
		//2D���ォ�痎���Ă��鏈���B
	}*/
}
