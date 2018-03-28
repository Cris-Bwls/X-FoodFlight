#pragma once
#include "Actor.h"
class Enemy :
	public Actor
{
public:
	Enemy(Application2D* pApp2D, CameraOperator* pCamOp);
	~Enemy();
};

