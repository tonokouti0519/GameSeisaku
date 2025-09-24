#pragma once

#include "IGameObject.h"          // IGameObject �̒�`
#include "RenderContext.h"        // RenderContext �̒�`
#include "PhysicsStaticObject.h"  // PhysicsStaticObject �̒�`
#include "ModelRender.h"          // ModelRender �̒�`

class Stage : public IGameObject
{
public:
    Stage();
    ~Stage();
    //�X�V�����B
    void Update();
    //�`�揈���B
    void Render(RenderContext& rc);
    PhysicsStaticObject physicsStaticObject;
private:
    ModelRender m_modelRender;


};

