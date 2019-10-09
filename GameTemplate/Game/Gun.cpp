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
	m_skinmodelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinmodelRender->Init(L"modelData/raiful.cmo");

	m_position = { 0.0f, 50.0f, 0.0f };
	m_skinmodelRender->SetPosition(m_position);
	return true;
}

void Gun::Update()
{

}