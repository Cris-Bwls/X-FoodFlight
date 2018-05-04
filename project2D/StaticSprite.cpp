#include "StaticSprite.h"

#include "Debug.h"

#include "Application2D.h"
#include "CameraOperator.h"
#include "Textures.h"

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
StaticSprite::StaticSprite(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, ETexture eTexture, Pos* pPos, float fDepth)
{
#ifdef DEBUG_MODE
	assert(pApp2D);
	assert(pCamOp);
	assert(pResMod);
	assert(pTextures);
	assert(pPos);
#endif // DEBUG_MODE

	// Store pointers
	m_pApp2D = pApp2D;
	m_pCamOp = pCamOp;
	m_pResMod = pResMod;
	m_pTexture = pTextures->GetTexture(eTexture);

	// Set position
	ChangePos(pPos);

	// Initializes UvRect and Size
	SetUVRect();
	ChangeSize();
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
	// Checks Visibility
	CheckIsVisible();
}

//----------------------------------------------------------
// Draw
//----------------------------------------------------------
void StaticSprite::Draw()
{
#ifdef DEBUG_MODE
	assert(m_pResMod);
	assert(m_pApp2D);
	assert(m_pTexture);
	assert(m_pPos);
#endif // DEBUG_MODE

	// IF Visible
	if (m_bIsVisible)
	{
		// Setup Var
		float fResModX = m_pResMod->fX;
		float fResModY = m_pResMod->fY;

		//Set UVRect
		m_pApp2D->GetRenderer()->setUVRect(m_fUvX, m_fUvY, m_fUvW, m_fUVH);
		//Draw sprite
		m_pApp2D->GetRenderer()->drawSprite(m_pTexture, m_pPos->fX * fResModX, m_pPos->fY * fResModY, m_fWidth * fResModX, m_fHeight * fResModY, m_fRotation, m_fDepth);
	}
}

//----------------------------------------------------------
// CheckIsVisible
//		Checks Visibility of Object relative to camera Position
//----------------------------------------------------------
void StaticSprite::CheckIsVisible()
{
#ifdef DEBUG_MODE
	assert(m_pCamOp);
	assert(m_pPos);
#endif // DEBUG_MODE

	// Setup Var
	float fOffset = 100.0f;
	float fCamPosX = m_pCamOp->GetDevCamPos()->fX;
	float fDevX = m_pCamOp->GetDevRes()->fX;

	//	IF (PosX < RHS of screen + offset && PosX > LHS of screen - offset)
	if (m_pPos->fX < fCamPosX + fDevX + fOffset && m_pPos->fX > fCamPosX - fOffset)
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

	// Change Height

	// IF new height is not zero
	if (fHeight != 0.0f)
	{
		// current height = new height + offset
		m_fHeight = fHeight + fHeightOffset;

	}
	// ELSE new height is zero
	else
	{
		// add offset to current height
		m_fHeight += fHeightOffset;
	}

	// Change Width

	// IF new width is not zero
	if (fWidth != 0.0f)
	{
		// current width = new width + offset
		m_fWidth = fWidth + fWidthOffset;

	}
	// ELSE new width is zero
	else
	{
		// add offset to current width
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
#ifdef DEBUG_MODE
	assert(pPos);
	assert(m_pPos);
#endif // DEBUG_MODE

	*m_pPos = *pPos;
	m_fRotation = fRotation;
}

//----------------------------------------------------------
// ChangePos
//		Change Position of sprite
//
//			float (fX):
//				X position
//			float (fY):
//				Y position
//			float (fRotation):
//				Rotation
//----------------------------------------------------------
void StaticSprite::ChangePos(float fX, float fY, float fRotation)
{
#ifdef DEBUG_MODE
	assert(m_pPos);
#endif // DEBUG_MODE

	// Store Var
	m_pPos->fX = fX;
	m_pPos->fY = fY;
	m_fRotation = fRotation;
}

//----------------------------------------------------------
// SetUVRect
//		Set UVRect elements
//
//			float (fUvX):
//				UV X position
//			float (fUvY):
//				UV Y position
//			float (fUvW):
//				UV Width
//			float (fUvH):
//				UV Height
//----------------------------------------------------------
void StaticSprite::SetUVRect(float fUvX, float fUvY, float fUvW, float fUvH)
{
	// Store Var
	m_fUvX = fUvX;
	m_fUvY = fUvY;
	m_fUvW = fUvW;
	m_fUVH = fUvH;
}