#include "stdafx.h"
#include "BackGround.h"


BackGround::BackGround()
{
    // ���f���̏������i�w�i���f���j
    modelRender.Init("Assets/modelData/ground.tkm");

    // �ÓI�I�u�W�F�N�g�Ƃ��ē����蔻���t����
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
    // �w�i�͓����Ȃ��̂Ŋ�{�͋�ł�OK
    modelRender.Update();
}

void BackGround::Render(RenderContext& rc)
{
    modelRender.Draw(rc);
}

