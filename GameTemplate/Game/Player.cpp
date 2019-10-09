#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

bool Player::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");

	m_charaCon.Init(50.0f, 100.0f, m_position);

	return true;
}

void Player::Update()
{

	m_moveSpeed.x = Pad(0).GetLStickXF() * 400.0f;
	m_moveSpeed.z = Pad(0).GetLStickYF() * 400.0f;

	m_position = m_charaCon.Execute(m_moveSpeed);

	m_skinModelRender->SetPosition(m_position);


}