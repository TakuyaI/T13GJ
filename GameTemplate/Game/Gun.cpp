#include "stdafx.h"
#include "Gun.h"
#include "Bullet.h"

Gun::Gun()
{
}


Gun::~Gun()
{
	DeleteGO(m_skinmodelRender);
}

bool Gun::Start()
{
	m_player = FindGO<Player>("player");
	m_skinmodelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinmodelRender->Init(L"modelData/raiful.cmo");

	
	return true;
}

void Gun::Update()
{
	m_position = m_player->m_position;
	m_position.y += 70.0f;
	m_position.z += 100.0f;
	m_skinmodelRender->SetPosition(m_position);

}