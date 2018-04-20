#include "ColliderController.h"

#include "Collider.h"
#include "CameraOperator.h"
#include "Player.h"

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
ColliderController::ColliderController(Collider** apCollider, CameraOperator* pCamOp, Player* pPlayer)
{
	m_apCollider = apCollider;
	m_fDevResX = pCamOp->GetDevRes()->fX;
	m_pPlayerPos = pPlayer->GetCurrentPos();

	m_bHasFirst = false;
	m_bHasLast = false;
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
ColliderController::~ColliderController()
{
}

//----------------------------------------------------------
// Update
//----------------------------------------------------------
void ColliderController::Update()
{

}

//----------------------------------------------------------
// CheckEnds
//		Checks to see if ends are in range
//			if too far beyond POP
//			if in range PUSH next
//----------------------------------------------------------
void ColliderController::CheckEnds()
{
	// WHILE !hasFirst
	while (!m_bHasFirst)
	{
		// IF prev NOT start sentinel && pos of DeQue first in window
		if ( (m_dqListPos.ReadFront()->m_pPrev != m_llPos.GetStart() ) && ( m_dqListPos.ReadFront()->m_data->fX > (m_pPlayerPos->fX - m_fDevResX) ) )
		{
			// pushFront prev pointer to DeQue

		}
		// ELSE IF pos of DeQue first outside window && pos of next outside window
			// PopFront DeQue
		// ELSE
			// hasFirst
	}
	// END WHILE

	// WHILE !hasLast
		// IF next NOT end sentinel && pos of DeQue last in window
			// pushBack next pointer to DeQue
		// ELSE IF pos of DeQue last outside window && pos of prev outside window
			// popBack DeQue
		// ELSE
			// hasLast
	// END WHILE
}

void ColliderController::AddPos(Pos* pos)
{
	m_llPos.PushBack(pos);
}
