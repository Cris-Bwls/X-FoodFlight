#include "AnimFSM.h"

#include "Debug.h"

#include "AnimIdle.h"
#include "AnimMove.h"

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
AnimFSM::AnimFSM()
{
	m_pAnimIdle = new AnimIdle();
	m_pAnimMove = new AnimMove();
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
AnimFSM::~AnimFSM()
{
	delete m_pAnimMove;
	delete m_pAnimIdle;
}

//--------------------------------------------------------
// Update
//		Updates idle state chosen
//
//			return (float):
//				UV offset returned from chosen State 
//				Update function
//---------------------------------------------------------
float AnimFSM::Update()
{
#ifdef DEBUG_MODE
	assert(m_pAnimIdle);
	assert(m_pAnimMove);
	//assert(m_pAnimDive); //CB::DEBUG
#endif // DEBUG_MODE

	switch (m_eAnimState)
	{
	case EANIMSTATES_IDLE:
		return m_pAnimIdle->Update();
		break;
	case EANIMSTATES_MOVE:
		return m_pAnimMove->Update();
		break;
	case EANIMSTATES_DIVE:
		//return m_pAnimDive->Update(); //CB::DEBUG
		break;
	default:
		//ERROR
		return 0;
	}
}

//--------------------------------------------------------
// ChangeState
//		Changes the state
//
//			eAnimState (EAnimState):
//				Animation State Chosen
//---------------------------------------------------------
void AnimFSM::ChangeState(EAnimStates eAnimState)
{
	m_eAnimState = eAnimState;
}