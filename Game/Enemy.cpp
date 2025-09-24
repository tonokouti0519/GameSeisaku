#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"
#include "Game.h"

Enemy::Enemy() {}
Enemy::~Enemy() {}

bool Enemy::Start()
{
    // モデルを読み込む
    m_modelRender.Init("Assets/modelData/yari.tkm");
   

    // 初期位置に配置
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
    // プレイヤーを探す
    auto player = FindGO<Player>("Player");
    if (player != nullptr) {
        Vector3 playerPos = player->GetPosition();

        // プレイヤーの頭の高さに調整（例: Y座標に+1.5f）
        playerPos.y += 1.5f;

        // 敵の現在位置からプレイヤー位置への方向を計算
        Vector3 dir = playerPos - m_position;
        dir.Normalize();

        // 移動速度を設定
        float speed = 0.05f;  // 速すぎたら小さくする
        m_position += dir * speed;
    }

    // 行列を更新
    m_worldMatrix.MakeTranslation(m_position);

    // モデル更新
    m_modelRender.Update();
}
