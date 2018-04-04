#include "StaticSprite.h"

#include "Application2D.h"
#include "CameraOperator.h"
#include "Textures.h"

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
StaticSprite::StaticSprite(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, ETexture eTexture, float fDepth)
{
	m_pApp2D = pApp2D;
	m_pCamOp = pCamOp;
	m_pResMod = pResMod;
	m_pTexture = pTextures->GetTexture(eTexture);
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
StaticSprite::~StaticSprite()
{
}

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
void StaticSprite::Update()
{
	CheckIsVisible();
}

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
void StaticSprite::Draw()
{
	if (m_bIsVisible)
	{
	m_pApp2D->GetRenderer()->drawSprite(m_pTexture, m_pPos->fX, m_pPos->fY, 0, 0, m_fRotation,)
	}
}

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
void StaticSprite::CheckIsVisible()
{
	float fOffset = 100.0f;
	float fPosX = m_pCamOp->GetCamPos()->fX;
	float fDevX = m_pCamOp->GetDevRes()->fX;
	//	IF (PosX < RHS of screen + offset || PosX > LHS of screen - offset)
	if (m_pPos->fX < fPosX + fDevX + fOffset || m_pPos->fX > fPosX - fOffset)
	{
		// is visible
		m_bIsVisible = true;
	}
	//	ELSE Outside of screen bounds
	else
	{
		// is NOT visible
		m_bIsVisible = false;
	}
}

//----------------------------------------------------------
// ChangePos
//		Change Position of sprite
//
//			pPos (Pos*):
//				pointer to position struct
//----------------------------------------------------------
void StaticSprite::ChangePos(Pos* pPos, float fRotation)
{
	*m_pPos = *pPos;
	m_fRotation = fRotation;
}

//----------------------------------------------------------
// ChangePos
//		Change Position of sprite
//----------------------------------------------------------
void StaticSprite::ChangePos(float fX, float fY, float fRotation)
{
	m_pPos->fX = fX;
	m_pPos->fY = fY;
	m_fRotation = fRotation;
}