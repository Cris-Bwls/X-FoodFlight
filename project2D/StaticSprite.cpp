#include "StaticSprite.h"

#include "Textures.h"
#include "CameraOperator.h"

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
StaticSprite::StaticSprite()
{
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

}

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
void StaticSprite::Draw()
{

}

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
void StaticSprite::CheckIsVisible()
{
	if (m_pPos->fX < m_pCamOp->fX)
	{

	}
}

//----------------------------------------------------------
// ChangePos
//		Change Position of sprite
//
//			pPos (Pos*):
//				pointer to position struct
//----------------------------------------------------------
void StaticSprite::ChangePos(Pos* pPos)
{
	*m_pPos = *pPos;
}

//----------------------------------------------------------
// ChangePos
//		Change Position of sprite
//----------------------------------------------------------
void StaticSprite::ChangePos(float fX, float fY)
{
	m_pPos->fX = fX;
	m_pPos->fY = fY;
}