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
	SetUVRect();
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
StaticSprite::~StaticSprite()
{
}

//----------------------------------------------------------
// Update
//----------------------------------------------------------
void StaticSprite::Update()
{
	CheckIsVisible();
}

//----------------------------------------------------------
// Draw
//----------------------------------------------------------
void StaticSprite::Draw()
{
	if (m_bIsVisible)
	{
		//Set UVRect
		m_pApp2D->GetRenderer()->setUVRect(m_fUvX, m_fUvY, m_fUvW, m_fUVH);
		//Draw sprite
		m_pApp2D->GetRenderer()->drawSprite(m_pTexture, m_pPos->fX, m_pPos->fY, m_fWidth, m_fHeight, m_fRotation, m_fDepth);
	}
}

//----------------------------------------------------------
// CheckIsVisible
//----------------------------------------------------------
void StaticSprite::CheckIsVisible()
{
	float fOffset = 100.0f;
	float fPosX = m_pCamOp->GetDevCamPos()->fX;
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
// ChangeSize
//		Change Size of sprite
//
//			fHeight (float):
//				float of new height
//			fWidth (float):
//				float of new Width
//			fHeightOffset (float):
//				float of offset height
//			fWidthOffset (float):
//				float of offset Width
//----------------------------------------------------------
void StaticSprite::ChangeSize(float fHeight, float fWidth, float fHeightOffset, float fWidthOffset)
{
	if (fHeight != 0.0f)
	{
		m_fHeight = fHeight + fHeightOffset;

	}
	else
	{
		m_fHeight += fHeightOffset;
	}

	if (fWidth != 0.0f)
	{
		m_fWidth = fWidth + fWidthOffset;

	}
	else
	{
		m_fWidth += fWidthOffset;
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

//----------------------------------------------------------
// SetUVRect
//		Set UVRect elements
//----------------------------------------------------------
void StaticSprite::SetUVRect(float fUvX, float fUvY, float fUvW, float fUvH)
{
	m_fUvX = fUvX;
	m_fUvY = fUvY;
	m_fUvW = fUvW;
	m_fUVH = fUvH;
}