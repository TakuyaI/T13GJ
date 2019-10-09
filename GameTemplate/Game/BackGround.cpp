#include "stdafx.h"
#include "BackGround.h"


BackGround::BackGround()
{
}


BackGround::~BackGround()
{
}



bool BackGround::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/background.cmo");
	stateObject.CreateBox(m_position, CQuaternion::Identity, { 12000.0f,500.0f,800.0 });
	return true;
}

void BackGround::Update()
{
	
}