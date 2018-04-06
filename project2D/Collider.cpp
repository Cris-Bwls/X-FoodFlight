#include "Collider.h"

#include "Player.h"


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