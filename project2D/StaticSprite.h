#pragma once

#include "Texture.h"
#include "EnumTexture.h"

#include"StructPos.h"
#include"StructResolution.h"

class Application2D;
class CameraOperator;
class Textures;

class StaticSprite
{
public:
	StaticSprite(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, ETexture eTexture, float fDepth = 0.0f);
	~StaticSprite();

	void Update();
	void Draw();

	void CheckIsVisible();
	void ChangeSize(float fHeight, float fWidth); //CB:HERENOW
	void ChangePos(Pos* pPos, float fRotation = 0.0f);
	void ChangePos(float fX, float fY, float fRotation = 0.0f);

private:
	aie::Texture*	m_pTexture;
	Application2D*	m_pApp2D;
	CameraOperator* m_pCamOp;
	Resolution*		m_pResMod;
	Pos*			m_pPos;

	float m_fRotation;

	bool m_bIsVisible;
	bool m_bIsDead;

};

