#include "stdafx.h"
#include "BackGround.h"


BackGround::BackGround()
{
    // モデルの初期化（背景モデル）
    modelRender.Init("Assets/modelData/ground.tkm");

    // 静的オブジェクトとして当たり判定を付ける
    physicsStaticObject.CreateFromModel(
        modelRender.GetModel(),
        modelRender.GetModel().GetWorldMatrix()
    );
}

BackGround::~BackGround()
{
}

void BackGround::Update()
{
    // 背景は動かないので基本は空でもOK
    modelRender.Update();
}

void BackGround::Render(RenderContext& rc)
{
    modelRender.Draw(rc);
}

