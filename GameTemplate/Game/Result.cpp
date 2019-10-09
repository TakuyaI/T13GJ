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
		//文字がスライドインしてくる処理
	}
	else if () {
		//2Dが上から落ちてくる処理。
	}*/
}
