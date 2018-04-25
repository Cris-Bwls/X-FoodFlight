#include "Collider.h"

#include "Player.h"
#include "CameraOperator.h"

#define OFFSET 150.0f

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Collider::Collider(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Player* pPlayer) : Actor(pApp2D, pCamOp, pResMod, pTextures)
{
	m_pPlayer = pPlayer;

	if (m_pPlayer == nullptr)
	{
		m_bCanCollide = false;
	}

	m_bIsEnabled = false;
}

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Collider::~Collider()
{
}

//----------------------------------------------------------
// Collision
//----------------------------------------------------------
bool Collider::Collision()
{
	if (m_bCanCollide)
	{
		float fPlayerX;
		float fPlayerY;
		float fPlayerRadius;
		m_pPlayer->GetPos(fPlayerX, fPlayerY, fPlayerY);

		fPlayerX += fPlayerRadius + m_fRadius;
		fPlayerY += fPlayerRadius + m_fRadius;

		if ((m_pCurrentPos->fX < fPlayerX) || (m_pCurrentPos->fX < fPlayerY))
		{	// Collision
			return true;
		}
	}
	// No Collision
	return false;
}

//----------------------------------------------------------
// CheckVisible
//----------------------------------------------------------
void Collider::CheckVisible()
{
	float fCamPosX = m_pCamOp->GetDevCamPos()->fX;
	float fRevResX = m_pCamOp->GetDevRes()->fX;

	// IF current pos between LHS of screen AND RHS of screen
	if ((m_pCurrentPos->fX > (fCamPosX - OFFSET)) && (m_pCurrentPos->fX < fCamPosX + fRevResX + OFFSET))
	{
		// IS visible
		m_bIsVisible = true;
	}
	else
	{
		//	NOT visible
		m_bIsVisible = false;
	}
}

//----------------------------------------------------------
// SetIsEnabled
//----------------------------------------------------------
void Collider::SetIsEnabled(bool bIsEnabled)
{
	m_bIsEnabled = bIsEnabled;
}

//----------------------------------------------------------
// GetIsEnabled
//----------------------------------------------------------
bool Collider::GetIsEnabled()
{
	return m_bIsEnabled;
}