#include "Collider.h"

#include "Player.h"


//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Collider::Collider(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Player* pPlayer) : Actor(pApp2D, pCamOp, pResMod)
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

		if ((m_fX < fPlayerX) || (m_fY < fPlayerY))
		{	// Collision
			return true;
		}
	}
	// No Collision
	return false;
}

//----------------------------------------------------------
// Collision
//----------------------------------------------------------
void Collider::Draw()
{
}