#include "Collider.h"

#include "Player.h"

Collider::Collider(Application2D* pApp2D, CameraOperator* pCamOp, Player* pPlayer) : Actor(pApp2D, pCamOp)
{
	m_pPlayer = pPlayer;

	if (m_pPlayer == nullptr)
	{
		canCollide = false;
	}
}


Collider::~Collider()
{
}


bool Collider::Collision()
{
	if (canCollide)
	{

	}
}