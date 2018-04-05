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
	void ChangeSize(float fHeight = 0.0f, float fWidth = 0.0f, float fHeightOffset = 0.0f, float fWidthOffset = 0.0f);
	void ChangePos(Pos* pPos, float fRotation = 0.0f);
	void ChangePos(float fX, float fY, float fRotation = 0.0f);
	void SetUVRect(float fUvX = 0.0f, float fUvY = 0.0f, float fUvW = 0.0f, float fUvH = 0.0f);

private:
	aie::Texture*	m_pTexture;
	Application2D*	m_pApp2D;
	CameraOperator* m_pCamOp;
	Resolution*		m_pResMod;
	Pos*			m_pPos;

	float m_fRotation;
	float m_fHeight;
	float m_fWidth;
	float m_fDepth;

	float m_fUvX;
	float m_fUvY;
	float m_fUvW;
	float m_fUVH;

	bool m_bIsVisible;
	bool m_bIsDead;

};

