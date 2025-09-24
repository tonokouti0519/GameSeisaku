#pragma once
#include"Game.h"

class Player;
//ゲーム中のカメラを制御する。
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start() override;
	void Update() override;
private:
	/////////////////////////////////////
	//メンバ変数
	/////////////////////////////////////
	Player* m_player = nullptr;	//プレイヤー。
	Vector3 m_toCameraPos;	//注視点から視点に向かうベクトル。
};


