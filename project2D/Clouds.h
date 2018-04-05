#pragma once
#include "Environ.h"

class Clouds :
	public Environ
{
public:
	Clouds(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures);
	~Clouds();
};

