#include "ColliderController.h"

#include "Collider.h"
#include "CameraOperator.h"
#include "Player.h"

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
ColliderController::ColliderController(Collider** apCollider, int nNumColliders, CameraOperator* pCamOp, Player* pPlayer)
{
	m_apCollider = apCollider;
	m_fDevResX = pCamOp->GetDevRes()->fX;

	if (pPlayer != nullptr)
	{
		m_pPlayerPos = pPlayer->GetCurrentPos();
	}
	else
	{
		m_pPlayerPos = nullptr;
	}

	m_nNumColliders = nNumColliders;

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
	if (m_pPlayerPos != nullptr)
	{
		CheckEnds();
	}
}

//----------------------------------------------------------
// CheckEnds
//		Checks to see if ends are in range
//			if too far beyond POP
//			if in range PUSH next
//----------------------------------------------------------
void ColliderController::CheckEnds()
{
	m_bHasFirst = false;
	// WHILE !hasFirst
	while (!m_bHasFirst)
	{
		// IF prev NOT start sentinel && pos of DeQue first in window
		if ( (m_dqListPos.ReadFront()->m_pPrev != m_llPos.GetStart() ) && ( m_dqListPos.ReadFront()->m_data->fX > (m_pPlayerPos->fX - m_fDevResX) ) )
		{
			// pushFront prev pointer to DeQue
			m_dqListPos.PushFront(m_dqListPos.ReadFront()->m_pPrev);

			m_bFoundCollider = false;
			m_nIterator = 0;

			// Set Position to a collider
			while (!m_bFoundCollider && (m_nIterator < m_nNumColliders))
			{
				if (!m_apCollider[m_nIterator]->GetIsEnabled())
				{
					m_bFoundCollider = true;
					m_apCollider[m_nIterator]->SetIsEnabled(true);
					m_apCollider[m_nIterator]->SetStartPos(m_dqListPos.ReadFront()->m_data);
				}
				++m_nIterator;
			}
		}
		// ELSE IF pos of DeQue first outside window && pos of next outside window
		else if ((m_dqListPos.ReadFront()->m_data->fX < (m_pPlayerPos->fX - m_fDevResX)) && (m_dqListPos.ReadFront()->m_pNext->m_data->fX < (m_pPlayerPos->fX - m_fDevResX)))
		{
			m_bFoundCollider = false;
			m_nIterator = 0;

			// Disable collider
			while (!m_bFoundCollider && (m_nIterator < m_nNumColliders))
			{
				if (m_apCollider[m_nIterator]->GetStartPos() == m_dqListPos.ReadFront()->m_data)
				{
					m_bFoundCollider = true;
					m_apCollider[m_nIterator]->SetIsEnabled(false);
					m_apCollider[m_nIterator]->SetStartPos(nullptr);
				}
				++m_nIterator;
			}

			// PopFront DeQue
			m_dqListPos.PopFront();
		}
		// ELSE
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
		if ((m_dqListPos.ReadBack()->m_pNext != m_llPos.GetEnd()) && (m_dqListPos.ReadBack()->m_data->fX < (m_pPlayerPos->fX + m_fDevResX)))
		{
			// pushBack next pointer to DeQue
			m_dqListPos.PushBack(m_dqListPos.ReadBack()->m_pNext);

			m_bFoundCollider = false;
			m_nIterator = 0;

			// Set Position to a collider
			while (!m_bFoundCollider && (m_nIterator < m_nNumColliders))
			{
				if (!m_apCollider[m_nIterator]->GetIsEnabled())
				{
					m_bFoundCollider = true;
					m_apCollider[m_nIterator]->SetIsEnabled(true);
					m_apCollider[m_nIterator]->SetStartPos(m_dqListPos.ReadBack()->m_data);
				}
				++m_nIterator;
			}
		}
		// ELSE IF pos of DeQue last outside window && pos of prev outside window
		else if ((m_dqListPos.ReadBack()->m_data->fX > (m_pPlayerPos->fX + m_fDevResX)) && (m_dqListPos.ReadBack()->m_pPrev->m_data->fX > (m_pPlayerPos->fX + m_fDevResX)))
		{
			m_bFoundCollider = false;
			m_nIterator = 0;

			// Disable collider
			while (!m_bFoundCollider && (m_nIterator < m_nNumColliders))
			{
				if (m_apCollider[m_nIterator]->GetStartPos() == m_dqListPos.ReadBack()->m_data)
				{
					m_bFoundCollider = true;
					m_apCollider[m_nIterator]->SetIsEnabled(false);
					m_apCollider[m_nIterator]->SetStartPos(nullptr);
				}
				++m_nIterator;
			}

			// PopBack DeQue
			m_dqListPos.PopBack();
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

LinkedList<Pos*>* ColliderController::GetPosList()
{
	return &m_llPos;
}
