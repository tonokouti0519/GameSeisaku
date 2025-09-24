#pragma once
class BackGround : public IGameObject
{
public:
    BackGround();
    ~BackGround();

    void Update() override;
    void Render(RenderContext& rc) override;

private:
    ModelRender modelRender;
    PhysicsStaticObject physicsStaticObject; // Å©Ç±Ç±ÅI
};