#pragma once
#include"Game.h"

class Player;
//�Q�[�����̃J�����𐧌䂷��B
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start() override;
	void Update() override;
private:
	/////////////////////////////////////
	//�����o�ϐ�
	/////////////////////////////////////
	Player* m_player = nullptr;	//�v���C���[�B
	Vector3 m_toCameraPos;	//�����_���王�_�Ɍ������x�N�g���B
};


