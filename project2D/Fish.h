#pragma once
#include "Collider.h"
class Fish :
	public Collider
{
public:
	Fish(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Player* pPlayer = nullptr);
	~Fish();

	void Update(float deltaTime);
	void Draw();
};

