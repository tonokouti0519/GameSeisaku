#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"
#include "Game.h"

Enemy::Enemy() {}
Enemy::~Enemy() {}

bool Enemy::Start()
{
    // ���f����ǂݍ���
    m_modelRender.Init("Assets/modelData/yari.tkm");
   

    // �����ʒu�ɔz�u
    m_worldMatrix.MakeTranslation(m_position);

    return true;
}

void Enemy::Update() {
    
    m_modelRender.Update();
    
}

void Enemy::Render(RenderContext&rc) {
    m_modelRender.Draw(rc);

}
Vector3 Player::GetPosition() const
{
    return m_position;
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
