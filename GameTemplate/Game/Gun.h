#pragma once
class Gun : public IGameObject
{
public:
	Gun();
	~Gun();

	bool Start();
	void Update();

	prefab::CSkinModelRender* m_skinmodelRender = nullptr;
	CVector3 m_position = CVector3::Zero;

};

