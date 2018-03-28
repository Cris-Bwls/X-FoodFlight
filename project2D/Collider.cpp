#include "Collider.h"

#include "Player.h"


//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Collider::Collider(Application2D* pApp2D, CameraOperator* pCamOp, Player* pPlayer) : Actor(pApp2D, pCamOp)
{
	m_pPlayer = pPlayer;

	if (m_pPlayer == nullptr)
	{
		canCollide = false;
	}
}

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Collider::~Collider()
{
}

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
bool Collider::Collision()
{
	if (canCollide)
	{
		
	}
}