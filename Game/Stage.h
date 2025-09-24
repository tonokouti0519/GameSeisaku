#pragma once

#include "IGameObject.h"          // IGameObject の定義
#include "RenderContext.h"        // RenderContext の定義
#include "PhysicsStaticObject.h"  // PhysicsStaticObject の定義
#include "ModelRender.h"          // ModelRender の定義

class Stage : public IGameObject
{
public:
    Stage();
    ~Stage();
    //更新処理。
    void Update();
    //描画処理。
    void Render(RenderContext& rc);
    PhysicsStaticObject physicsStaticObject;
private:
    ModelRender m_modelRender;


};

