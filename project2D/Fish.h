#pragma once
#include "Actor.h"
class Fish :
	public Actor
{
public:
	Fish(Application2D* pApp2D, CameraOperator* pCamOp);
	Fish(const char* filename);
	~Fish();
};

