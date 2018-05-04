#include "Actor.h"

#include "Debug.h"

// Higher
#include "Application2D.h"
#include "CameraOperator.h"
#include "Textures.h"

// Lower


//----------------------------------------------------------
// Constructor
//
//			pApp2D (Application2D*):
//				pointer to Application2D
//			pCamOp (CameraOperator*):
//				pointer to CameraOperator
//			pResMod (Resolution*):
//				pointer to Resolution
//			pTextures (Textures*):
//				pointer to Textures
//----------------------------------------------------------
Actor::Actor(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures)
{
#ifdef DEBUG_MODE
	assert(pApp2D);
	assert(pCamOp);
	assert(pResMod);
	assert(pTextures);
#endif // DEBUG_MODE

	m_pApp2D = pApp2D;
	m_pRenderer = m_pApp2D->GetRenderer();
	m_pCamOp = pCamOp;
	m_pResMod = pResMod;

	m_pStartPos = new Pos;
	m_pCurrentPos = new Pos;
}

//----------------------------------------------------------
//----------------------------------------------------------
Actor::~Actor()
{
	delete m_pCurrentPos;
	delete m_pStartPos;
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
#ifdef DEBUG_MODE
	assert(m_pCurrentPos);
#endif // DEBUG_MODE

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
#ifdef DEBUG_MODE
	assert(m_pStartPos);
	assert(m_pCurrentPos);
#endif // DEBUG_MODE

	*m_pStartPos = *pPos;

	// Sets CurrentPos to StartPos
	*m_pCurrentPos = *m_pStartPos;
}

//----------------------------------------------------------
//----------------------------------------------------------
void Actor::SetStartPos(float fX, float fY)
{
#ifdef DEBUG_MODE
	assert(m_pStartPos);
	assert(m_pCurrentPos);
#endif // DEBUG_MODE

	m_pStartPos->fX = fX;
	m_pStartPos->fY = fY;

	// Sets CurrentPos to StartPos
	*m_pCurrentPos = *m_pStartPos;
}

//----------------------------------------------------------
//----------------------------------------------------------
Pos* Actor::GetStartPos()
{
#ifdef DEBUG_MODE
	assert(m_pStartPos);
#endif // DEBUG_MODE

	return m_pStartPos;
}

//----------------------------------------------------------
//----------------------------------------------------------
void Actor::GetStartPos(float &fX, float &fY)
{
#ifdef DEBUG_MODE
	assert(m_pStartPos);
#endif // DEBUG_MODE

	fX = m_pStartPos->fX;
	fY = m_pStartPos->fY;
}

//----------------------------------------------------------
//----------------------------------------------------------
Pos* Actor::GetCurrentPos()
{
#ifdef DEBUG_MODE
	assert(m_pCurrentPos);
#endif // DEBUG_MODE

	return m_pCurrentPos;
}

//----------------------------------------------------------
//----------------------------------------------------------
void Actor::GetCurrentPos(float &fX, float &fY)
{
#ifdef DEBUG_MODE
	assert(m_pCurrentPos);
#endif // DEBUG_MODE

	fX = m_pCurrentPos->fX;
	fY = m_pCurrentPos->fY;
}