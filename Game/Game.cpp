#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "Stage.h"
#include "GameCamera.h"
#include"Enemy.h"
Game::Game()
{
	//�v���C���[�̃I�u�W�F�N�g�������B
	player = NewGO<Player>(0,"player");

	//
	stage = NewGO<Stage>(0, "stage");

	gameCamera = NewGO<GameCamera>(0, "gamecamera");

	enemy = NewGO<Enemy>(0, "enemy");
}

Game::~Game()
{

}