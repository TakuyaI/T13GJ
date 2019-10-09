#include "stdafx.h"
#include "BackGround.h"


BackGround::BackGround()
{
}


BackGround::~BackGround()
{
}

void BackGround::InitGhostObject()
{
	//ゴーストのワイヤーフレーム表示を有効にする
#if _DEBUG && 1
	PhysicsWorld().SetDebugDrawMode(btIDebugDraw::DBG_DrawWireframe);
#endif
	
}

bool BackGround::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/background.cmo");
	InitGhostObject();
	stateObject.CreateBox(m_position, CQuaternion::Identity, { 12000.0f,500.0f,800.0 });
	return true;
}

void BackGround::Update()
{

}