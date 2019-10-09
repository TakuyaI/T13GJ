#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "tkEngine/light/tkDirectionLight.h"

Game::Game()
{
	NewGO<Player>(0, "player");
	NewGO<BackGround>(0, "background");
}


Game::~Game()
{
}
bool Game::Start()
{
	//ƒJƒƒ‰‚ğİ’èB
	MainCamera().SetTarget({ 0.0f, 70.0f, 0.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 70.0f, 200.0f });
	MainCamera().Update();
	
	
	return true;
}

void Game::Update()
{

}