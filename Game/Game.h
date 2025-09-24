#pragma once

//#include "Level3DRender/LevelRender.h"

class Player;
class Stage;
class GameCamera;
class Enemy;
class Game :public IGameObject
{
public:
	Game();
	~Game();
	
private:
	
	Player* player;
	Stage* stage;
	GameCamera* gameCamera;
	Enemy* enemy;
	//Vector3 m_pos;
};

