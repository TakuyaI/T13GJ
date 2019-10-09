#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

bool Enemy::Start()
{
	m_skiModelRender = NewGO<prefab::CSkinModelRender>(0);
	return true;
}
void Enemy::Update()
{

}