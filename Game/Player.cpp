#include "stdafx.h"
#include "Player.h"
#include"Enemy.h"
#include"Game.h"

Player::Player()
{
	//�A�j���[�V�����N���b�v�����[�h����B
	animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	//���j�e�B�����̃��f����ǂݍ��ށB
	modelRender.Init("Assets/modelData/unityChan.tkm", animationClips, enAnimationClip_Num, enModelUpAxisY);

	//�L�����R��������������B
	characterController.Init(25.0f, 75.0f, position);
}

Player::~Player()
{

}

//�X�V�����B
void Player::Update()
{
	//�ړ������B
	Move();

	//��]�����B
	Rotation();

	//�X�e�[�g�Ǘ��B
	ManageState();

	//�A�j���[�V�����̍Đ��B
	PlayAnimation();

	//�G�`������̍X�V�����B
	modelRender.Update();
}

void Player::Move()
{
	//xz�̈ړ����x��0.0f�ɂ���B
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;

	//���X�e�B�b�N�̓��͗ʂ��擾�B
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	//�J�����̑O�����ƉE�����̃x�N�g���������Ă���B
	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();
	//y�����ɂ͈ړ������Ȃ��B
	forward.y = 0.0f;
	right.y = 0.0f;

	//���X�e�B�b�N�̓��͗ʂ�120.0f����Z�B
	right *= stickL.x * 120.0f;
	forward *= stickL.y * 120.0f;

	//�ړ����x�ɃX�e�B�b�N�̓��͗ʂ����Z����B
	moveSpeed += right + forward;

	//�n�ʂɕt���Ă�����B
	if (characterController.IsOnGround())
	{
		//�d�͂𖳂����B
		moveSpeed.y = 0.0f;
		//A�{�^���������ꂽ��B
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			//�W�����v������B
			moveSpeed.y = 120.0f;
		}
	}
	//�n�ʂɕt���Ă��Ȃ�������B
	else
	{
		//�d�͂𔭐�������B
		moveSpeed.y -= 2.5f;
	}

	//�L�����N�^�[�R���g���[���[���g���č��W���ړ�������B
	position = characterController.Execute(moveSpeed, 1.0f / 60.0f);

	//�G�`������ɍ��W��������B
	modelRender.SetPosition(position);
}

void Player::Rotation()
{
	//x��z�̈ړ����x����������(�X�e�B�b�N�̓��͂���������)�B
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
		//�L�����N�^�[�̕�����ς���B
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
		//�G�`������ɉ�]��������B
		modelRender.SetRotation(rotation);
	}
}

//�X�e�[�g�Ǘ��B
void Player::ManageState()
{
	//�n�ʂɕt���Ă��Ȃ�������B
	if (characterController.IsOnGround() == false)
	{
		//�X�e�[�g��1(�W�����v��)�ɂ���B
		playerState = 1;
		//������ManageState�̏������I��点��B
		return;
	}

	//�n�ʂɕt���Ă�����B
	//x��z�̈ړ����x����������(�X�e�B�b�N�̓��͂���������)�B
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
		//�X�e�[�g��2(����)�ɂ���B
		playerState = 2;
	}
	//x��z�̈ړ����x������������(�X�e�B�b�N�̓��͂�����������)�B
	else
	{
		//�X�e�[�g��0(�ҋ@)�ɂ���B
		playerState = 0;
	}
}

//�A�j���[�V�����̍Đ��B
void Player::PlayAnimation()
{
	//switch���B
	switch (playerState) {
		//�v���C���[�X�e�[�g��0(�ҋ@)��������B
	case 0:
		//�ҋ@�A�j���[�V�������Đ�����B
		modelRender.PlayAnimation(enAnimationClip_Idle);
		break;
		//�v���C���[�X�e�[�g��1(�W�����v��)��������B
	case 1:
		//�W�����v�A�j���[�V�������Đ�����B
		modelRender.PlayAnimation(enAnimationClip_Jump);
		break;
		//�v���C���[�X�e�[�g��2(����)��������B
	case 2:
		//�����A�j���[�V�������Đ�����B
		modelRender.PlayAnimation(enAnimationClip_Walk);
		break;
	}
}

//�`�揈���B
void Player::Render(RenderContext& rc)
{
	//���j�e�B������`�悷��B
	modelRender.Draw(rc);
}

void Enemy::Update()
{
	// �v���C���[��T��
	auto player = FindGO<Player>("Player");
	if (player != nullptr) {
		Vector3 playerPos = player->GetPosition();

		// �v���C���[�̓��̍����ɒ����i��: Y���W��+1.5f�j
		playerPos.y += 1.5f;

		// �G�̌��݈ʒu����v���C���[�ʒu�ւ̕������v�Z
		Vector3 dir = playerPos - m_position;
		dir.Normalize();

		// �ړ����x��ݒ�
		float speed = 0.05f;  // ���������珬��������
		m_position += dir * speed;
	}

	// �s����X�V
	m_worldMatrix.MakeTranslation(m_position);

	// ���f���X�V
	m_modelRender.Update();
}
