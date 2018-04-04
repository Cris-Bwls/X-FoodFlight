#include "Actor.h"

// Higher
#include "Textures.h"
#include "Application2D.h"
#include "CameraOperator.h"

// Lower


//----------------------------------------------------------
//----------------------------------------------------------
Actor::Actor(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod)
{
	m_pApp2D = pApp2D;
	m_pCamOp = pCamOp;
	m_pResMod = pResMod;
}

//----------------------------------------------------------
//----------------------------------------------------------
Actor::~Actor()
{
}

//----------------------------------------------------------
//----------------------------------------------------------
void Actor::SetIsVisible(bool isVisible)
{
	m_bIsVisible = isVisible;
}

//----------------------------------------------------------
//----------------------------------------------------------
void Actor::SetIsDead(bool isDead)
{
	m_bIsDead = isDead;
}

//----------------------------------------------------------
//----------------------------------------------------------
void Actor::Move(float deltaTime)
{
	m_pCurrentPos->fX += m_fSpeed * deltaTime;
	m_pCurrentPos->fY += m_fSpeed * deltaTime;
}

//----------------------------------------------------------
//----------------------------------------------------------
void Actor::Update(float deltaTime)
{
	Move(deltaTime);
}

//----------------------------------------------------------
//----------------------------------------------------------
void Actor::SetStartPos(Pos* pPos)
{
	*m_pStartPos = *pPos;
}

//----------------------------------------------------------
//----------------------------------------------------------
void Actor::SetStartPos(float fX, float fY)
{
	m_pStartPos->fX = fX;
	m_pStartPos->fY = fY;
}

//----------------------------------------------------------
//----------------------------------------------------------
Pos* Actor::GetStartPos()
{
	return m_pStartPos;
}

//----------------------------------------------------------
//----------------------------------------------------------
void Actor::GetStartPos(float &fX, float &fY)
{
	fX = m_pStartPos->fX;
	fY = m_pStartPos->fY;
}

//----------------------------------------------------------
//----------------------------------------------------------
Pos* Actor::GetCurrentPos()
{
	return m_pCurrentPos;
}

//----------------------------------------------------------
//----------------------------------------------------------
void Actor::GetCurrentPos(float &fX, float &fY)
{
	fX = m_pCurrentPos->fX;
	fY = m_pCurrentPos->fY;
}