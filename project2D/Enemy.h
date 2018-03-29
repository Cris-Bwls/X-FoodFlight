#pragma once
#include "Collider.h"
class Enemy :
	public Collider
{
public:
	Enemy(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Player* pPlayer = nullptr);
	~Enemy();

	void Update(float deltaTime);
};

