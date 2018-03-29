#pragma once
#include "Actor.h"

#include "Input.h"


class Player :
	public Actor
{
public:
	Player(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod);
	~Player();

	void Update(aie::Input* input, float deltaTime);

	void GetPos(float &fPosX, float &fPosY, float &fRadius);

	void AddFish();

	void TakeFish(bool bTookHit = false);
private:
	int m_nFish = 0;
};

