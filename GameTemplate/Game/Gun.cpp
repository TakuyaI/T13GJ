#include "stdafx.h"
#include "Gun.h"


Gun::Gun()
{
}


Gun::~Gun()
{
}

bool Gun::Start()
{
	m_player = FindGO<Player>("player");
	m_skinmodelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinmodelRender->Init(L"modelData/raiful.cmo");

	/*m_position = { 0.0f, 50.0f, 50.0f };
	m_skinmodelRender->SetPosition(m_position);*/
	return true;
}

void Gun::Update()
{
	m_position = m_player->m_position;
	m_position.y += 70.0f;
	m_position.z += 100.0f;
	m_skinmodelRender->SetPosition(m_position);
}