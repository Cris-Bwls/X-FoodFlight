#pragma once
#include "Actor.h"
class Environ :
	public Actor
{
public:
	Environ(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod);
	virtual ~Environ();
};

