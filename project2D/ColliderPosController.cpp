#include "ColliderPosController.h"

#include "Debug.h"

#include "Collider.h"
#include "CameraOperator.h"
#include "Player.h"

//----------------------------------------------------------
// Constructor
//		
//		pCamOp (CameraOperator*):
//			pointer to Camera Operator
//		pPlayer (Player*):
//			pointer to Player
//		apCollider (Collider**):
//			array of Collider Pointers
//		nNumColliders (int):
//			number of Colliders
//----------------------------------------------------------
ColliderPosController::ColliderPosController(CameraOperator* pCamOp, Player* pPlayer, Collider** apCollider, int nNumColliders)
{
#ifdef DEBUG_MODE
	assert(apCollider);
	assert(pPlayer);
	assert(pCamOp);
#endif // DEBUG_MODE
	m_pLLPos		= new LinkedList<Pos*>;
	m_pDQListPos	= new DeQue<LinkedListNode<Pos*>*>;


	m_apCollider = apCollider;
	m_fDevResX = pCamOp->GetDevRes()->fX;

	m_pPlayerPos = pPlayer->GetCurrentPos();

	m_nNumColliders = nNumColliders;

	m_bHasFirst = false;
	m_bHasLast = false;
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
ColliderPosController::~ColliderPosController()
{
	delete m_pLLPos;
	delete m_pDQListPos;
}

//----------------------------------------------------------
// Update
//----------------------------------------------------------
void ColliderPosController::Update()
{
	CheckEnds();
}

//----------------------------------------------------------
// CheckEnds
//		Checks to see if ends are in range
//			if too far beyond POP
//			if in range PUSH next
//
//		Must have run StartDeQue
//----------------------------------------------------------
void ColliderPosController::CheckEnds()
{
#ifdef DEBUG_MODE
	assert(m_apCollider);
	assert(m_pPlayerPos);
#endif // DEBUG_MODE

	m_bHasFirst = false;
	// WHILE !hasFirst
	while (!m_bHasFirst)
	{
		if (m_pDQListPos->ReadFront()->m_data)
		{
			// IF prev NOT start sentinel && pos of DeQue first in window
			if ((m_pDQListPos->ReadFront()->m_pPrev != m_pLLPos->GetStart()) && (m_pDQListPos->ReadFront()->m_data->fX > (m_pPlayerPos->fX - m_fDevResX)))
			{
				// pushFront prev pointer to DeQue
				m_pDQListPos->PushFront(m_pDQListPos->ReadFront()->m_pPrev);

				m_bFoundCollider = false;
				m_nIterator = 0;

				// Set Position to a collider
				while (!m_bFoundCollider && (m_nIterator < m_nNumColliders))
				{
					if (!m_apCollider[m_nIterator]->GetIsEnabled())
					{
						m_bFoundCollider = true;
						m_apCollider[m_nIterator]->SetIsEnabled(true);
						m_apCollider[m_nIterator]->SetIsDead(false);
						m_apCollider[m_nIterator]->SetStartPos(m_pDQListPos->ReadFront()->m_data);
					}
					++m_nIterator;
				}
			}
			// ELSE IF pos of DeQue first outside window && pos of next outside window
			else if ((m_pDQListPos->ReadFront()->m_data->fX < (m_pPlayerPos->fX - m_fDevResX)) && (m_pDQListPos->ReadFront()->m_pNext->m_data->fX < (m_pPlayerPos->fX - m_fDevResX)))
			{
				m_bFoundCollider = false;
				m_nIterator = 0;

				// Disable collider
				while (!m_bFoundCollider && (m_nIterator < m_nNumColliders))
				{
					if (m_apCollider[m_nIterator]->GetStartPos()->fX == m_pDQListPos->ReadFront()->m_data->fX)
					{
						m_bFoundCollider = true;

						// If Collider Is Dead
						if (m_apCollider[m_nIterator]->GetIsDead())
						{
							// remove position from list
						}

						m_apCollider[m_nIterator]->SetIsEnabled(false);
						//m_apCollider[m_nIterator]->SetStartPos(nullptr);
					}
					++m_nIterator;
				}

				// PopFront DeQue
				m_pDQListPos->PopFront();
			}
			// ELSE
			else
			{
				// hasFirst
				m_bHasFirst = true;
			}
		}
		else
		{
			// hasFirst
			m_bHasFirst = true;
		}
	}
	// END WHILE

	m_bHasLast = false;
	// WHILE !hasLast
	while (!m_bHasLast)
	{
		// IF next NOT end sentinel && pos of DeQue last in window
		if ((m_pDQListPos->ReadBack()->m_pNext != m_pLLPos->GetEnd()) && (m_pDQListPos->ReadBack()->m_data->fX < (m_pPlayerPos->fX + m_fDevResX)))
		{
			// pushBack next pointer to DeQue
			m_pDQListPos->PushBack(m_pDQListPos->ReadBack()->m_pNext);

			m_bFoundCollider = false;
			m_nIterator = 0;

			// Set Position to a collider
			while (!m_bFoundCollider && (m_nIterator < m_nNumColliders))
			{
				if (!m_apCollider[m_nIterator]->GetIsEnabled())
				{
					m_bFoundCollider = true;
					m_apCollider[m_nIterator]->SetIsEnabled(true);
					m_apCollider[m_nIterator]->SetIsDead(false);
					m_apCollider[m_nIterator]->SetStartPos(m_pDQListPos->ReadBack()->m_data);
				}
				++m_nIterator;
			}
		}
		// ELSE IF pos of DeQue last outside window && pos of prev outside window
		else if ((m_pDQListPos->ReadBack()->m_data->fX > (m_pPlayerPos->fX + m_fDevResX)) && (m_pDQListPos->ReadBack()->m_pPrev->m_data->fX > (m_pPlayerPos->fX + m_fDevResX)))
		{
			m_bFoundCollider = false;
			m_nIterator = 0;

			// Disable collider
			while (!m_bFoundCollider && (m_nIterator < m_nNumColliders))
			{
				if (m_apCollider[m_nIterator]->GetStartPos()->fX == m_pDQListPos->ReadBack()->m_data->fX)
				{
					m_bFoundCollider = true;

					// If Collider Is Dead
					if (m_apCollider[m_nIterator]->GetIsDead())
					{
						// remove position from list
					}

					m_apCollider[m_nIterator]->SetIsEnabled(false);
					//m_apCollider[m_nIterator]->SetStartPos(nullptr);
				}
				++m_nIterator;
			}

			// PopBack DeQue
			m_pDQListPos->PopBack();
		}
		// ELSE
		else
		{
			// hasLast
			m_bHasLast = true;
		}
	}
	// END WHILE
}

//----------------------------------------------------------
// StartDeQue
//		Starts DeQue
//----------------------------------------------------------
void ColliderPosController::StartDeQue()
{
	m_pDQListPos->PushBack(m_pLLPos->GetStart()->m_pNext);
	m_apCollider[0]->SetIsEnabled(true);
	m_apCollider[0]->SetStartPos(m_pDQListPos->ReadFront()->m_data);
}


//----------------------------------------------------------
// GetPosList
//		Gets Position List
//		
//			return (LinkedList<Pos*>*)
//				reference to Position List
//----------------------------------------------------------
LinkedList<Pos*>* ColliderPosController::GetPosList()
{
	return m_pLLPos;
}
