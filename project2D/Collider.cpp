#include "Collider.h"

#include "Debug.h"

#include "Player.h"
#include "CameraOperator.h"

#define OFFSET 150.0f

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
//			pPlayer (Player*):
//				pointer to Player
//----------------------------------------------------------
Collider::Collider(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Player* pPlayer) : Actor(pApp2D, pCamOp, pResMod, pTextures)
{
#ifdef DEBUG_MODE
	assert(pApp2D);
	assert(pCamOp);
	assert(pResMod);
	assert(pTextures);
#endif // DEBUG_MODE

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
//		Checks for Collision with player
//
//			return (bool):
//				true: there is a collision
//----------------------------------------------------------
bool Collider::Collision()
{
#ifdef DEBUG_MODE
	assert(m_pCurrentPos);
#endif // DEBUG_MODE

	// IF can Collide
	if (m_bCanCollide)
	{
		float fPlayerX;
		float fPlayerY;
		float fPlayerRadius;
		m_pPlayer->GetPos(fPlayerX, fPlayerY, fPlayerRadius);

		float fPlayerLoX = fPlayerX - ((fPlayerRadius + m_fRadius) / 2);
		float fPlayerHiX = fPlayerX + ((fPlayerRadius + m_fRadius) / 2);
									  								  
		float fPlayerLoY = fPlayerY - ((fPlayerRadius + m_fRadius) / 2);
		float fPlayerHiY = fPlayerY + ((fPlayerRadius + m_fRadius) / 2);

		// IF Collides on X Axis
		if ((m_pCurrentPos->fX > fPlayerLoX) && (m_pCurrentPos->fX < fPlayerHiX))
		{
			// IF Collides on Y Axis
			if ((m_pCurrentPos->fY > fPlayerLoY) && (m_pCurrentPos->fY < fPlayerHiY))
			{
				// Collision
				printf("Collision!\n");
				return true;
			}
		}

	}
	// No Collision
	return false;
}

//----------------------------------------------------------
// CheckVisible
//		Checks if Visible
//----------------------------------------------------------
void Collider::CheckVisible()
{
#ifdef DEBUG_MODE
	assert(m_pCamOp);
	assert(m_pCurrentPos);
#endif // DEBUG_MODE

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
//		Sets Enabled to chosen state
//
//			bIsEnabled (bool)
//				true: is enabled
//----------------------------------------------------------
void Collider::SetIsEnabled(bool bIsEnabled)
{
	m_bIsEnabled = bIsEnabled;
}

//----------------------------------------------------------
// GetIsEnabled
//		Gets IsEnabled
//			
//			return (bool)
//				bIsEnabled
//----------------------------------------------------------
bool Collider::GetIsEnabled()
{
	return m_bIsEnabled;
}