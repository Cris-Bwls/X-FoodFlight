#pragma once
#include "Collider.h"
class Enemy :
	public Collider
{
public:
	Enemy(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Player* pPlayer = nullptr);
	~Enemy();

	void Update(float deltaTime);
	void Draw();
};

