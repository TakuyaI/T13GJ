#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet()
{
}


Bullet::~Bullet()
{
	DeleteGO(m_skinModelRender);
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
	m_position += m_moveSpeed;
	m_skinModelRender->SetPosition(m_position);

	m_timer++;
	if (m_timer == 60) {
		DeleteGO(this);
	}
}