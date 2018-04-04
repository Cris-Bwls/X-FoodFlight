#pragma once

#include "Texture.h"
#include "EnumTexture.h"

#include"StructPos.h"
#include"StructResolution.h"

class CameraOperator;

class StaticSprite
{
public:
	StaticSprite();
	~StaticSprite();

	void Update();
	void Draw();

	void CheckIsVisible();
	void ChangePos(Pos* pPos);
	void ChangePos(float fX, float fY);

private:
	ETexture eTexture;
	aie::Texture*	m_pTexture;
	CameraOperator* m_pCamOp;
	Resolution*		m_pResMod;
	Pos*			m_pPos;

	float m_fRotation;

	bool m_bIsVisible;
	bool m_bIsDead;

};

