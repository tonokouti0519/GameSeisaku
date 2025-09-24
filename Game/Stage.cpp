#include "stdafx.h"
#include "Stage.h"

Stage::Stage()
{
    m_modelRender.Init("Assets/stage/stage.tkm");
    m_modelRender.Update();
    physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
}

Stage::~Stage()
{

}
//�X�V�����B
void Stage::Update()
{

}

//�`�揈���B
void Stage::Render(RenderContext& rc)
{
    m_modelRender.Draw(rc);
}


