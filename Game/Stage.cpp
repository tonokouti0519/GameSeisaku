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
//更新処理。
void Stage::Update()
{

}

//描画処理。
void Stage::Render(RenderContext& rc)
{
    m_modelRender.Draw(rc);
}


