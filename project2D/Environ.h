#pragma once

#include "Actor.h"
#include "StructPos.h"

class CameraOperator;

class Environ :
	public Actor
{
public:
	Environ(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Pos* pReferencePos);
	virtual ~Environ();

	virtual void Update(float deltaTime);

	void SetPos();

private:
	Pos* m_pReferencePos;
};

