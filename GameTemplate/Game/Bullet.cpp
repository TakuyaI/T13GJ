#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

bool Bullet::Start()
{
	m_gun = FindGO<Gun>("gun");
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/tama.cmo");
	m_position = m_gun->m_position;
	m_skinModelRender->SetPosition(m_position);
	return true;
}
void Bullet::Update()
{
	
}