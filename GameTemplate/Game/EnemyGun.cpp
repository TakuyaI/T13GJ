#include "stdafx.h"
#include "EnemyGun.h"


EnemyGun::EnemyGun()
{
}


EnemyGun::~EnemyGun()
{
	DeleteGO(m_skinmodelRender);
}

bool EnemyGun::Start()
{
	m_enemy = FindGO<Enemy>("enemy");
	m_skinmodelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinmodelRender->Init(L"modelData/raiful.cmo");
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 180.0f);
	m_skinmodelRender->SetRotation(qRot);

	return true;
}

void EnemyGun::Update()
{
	m_position = m_enemy->m_position;
	m_position.y += 70.0f;
	m_position.z -= 100.0f;
	m_skinmodelRender->SetPosition(m_position);

}