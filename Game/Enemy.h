#pragma once

class Enemy :public IGameObject
{
public:
	Enemy();
	~Enemy();

	//初期化処理
	bool Start();

	//更新処理
	void Update();
	//描画処理
	void Render(RenderContext& rc);

private:
	ModelRender m_modelRender;   // 敵のモデル
	Matrix m_worldMatrix;        // 位置・回転・拡縮を管理
	Vector3 m_position = { 0.0f, 0.0f, 3.0f }; // 出現位置

	
};