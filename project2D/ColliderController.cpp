#include "ColliderController.h"

#include "Collider.h"
#include "CameraOperator.h"
#include "Player.h"

ColliderController::ColliderController(Collider** apCollider, CameraOperator* pCamOp, Player* pPlayer)
{
	m_apCollider = apCollider;
	m_pCamOp = pCamOp;
	m_pPlayer = pPlayer;
}


ColliderController::~ColliderController()
{
}
