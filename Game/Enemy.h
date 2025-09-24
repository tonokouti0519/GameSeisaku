#pragma once

class Enemy :public IGameObject
{
public:
	Enemy();
	~Enemy();

	//����������
	bool Start();

	//�X�V����
	void Update();
	//�`�揈��
	void Render(RenderContext& rc);

private:
	ModelRender m_modelRender;   // �G�̃��f��
	Matrix m_worldMatrix;        // �ʒu�E��]�E�g�k���Ǘ�
	Vector3 m_position = { 0.0f, 0.0f, 3.0f }; // �o���ʒu

	
};