#pragma once
class Gameclear :public IGameObject
{
public:
	 Gameclear();
	 ~Gameclear();
	void Update() override;
	void Render(RenderContext& rc) override;
private:
	SpriteRender spriteRender;
};


