#pragma once

#include "Texture.h"
#include "EnumTexture.h"

#include"StructPos.h"
#include"StructResolution.h"

class Application2D;
class CameraOperator;

class Actor
{
public:
	Actor(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod);
	virtual ~Actor();

	void SetIsVisible(bool isVisible);
	void SetIsDead(bool isDead);

	virtual void Move(float deltaTime);

	virtual void Update(float deltaTime);
	virtual void Draw() = 0;

	void SetStartPos(Pos* pPos);
	void SetStartPos(float fX, float fY);

	Pos* GetStartPos();
	void GetStartPos(float &fX, float &fY);

	Pos* GetCurrentPos();
	void GetCurrentPos(float &fX, float &fY);
	
protected:
	Application2D*	m_pApp2D = nullptr;
	CameraOperator* m_pCamOp = nullptr;
	Resolution*		m_pResMod = nullptr;
	aie::Texture*	m_pTexture = nullptr;

	Pos* m_pStartPos = nullptr;
	Pos* m_pCurrentPos = nullptr;

	float m_fRot = 0.0f;

	float m_fSpeed = 0.0f;
	float m_fRadius = 0.0f;

	bool m_bIsVisible = false;
	bool m_bIsDead = false;
};

