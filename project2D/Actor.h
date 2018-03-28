#pragma once

#include "Texture.h"
#include "EnumTexture.h"

class Application2D;
class CameraOperator;

class Actor
{
public:
	Actor(Application2D* pApp2D, CameraOperator* pCamOp);
	virtual ~Actor();

	void SetIsVisible(bool isVisible);
	void SetIsDead(bool isDead);

	virtual void Move(float deltaTime);

	virtual void Update(float deltaTime);
	virtual void Draw();
	void GetPos(float &fX, float &fY);
	
protected:
	Application2D* m_pApp2D = nullptr;
	CameraOperator* m_pCamOp = nullptr;
	aie::Texture* m_pTexture = nullptr;
	

	float m_fX = 0.0f;
	float m_fY = 0.0f;
	float m_fRot = 0.0f;

	float m_fSpeed = 0.0f;
	float m_fRadius = 0.0f;

	bool m_bIsVisible = false;
	bool m_bIsDead = false;
};

