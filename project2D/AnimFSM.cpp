#include "AnimFSM.h"

#include "AnimIdle.h"
#include "AnimMove.h"

AnimFSM::AnimFSM()
{
	m_pAnimIdle = new AnimIdle();
	m_pAnimMove = new AnimMove();
}


AnimFSM::~AnimFSM()
{
	delete m_pAnimMove;
	delete m_pAnimIdle;
}

//---------------------------------------------------
// returns the UV offset
//---------------------------------------------------
float AnimFSM::Update()
{
	switch (m_eAnimState)
	{
	case EANIMSTATES_IDLE:
		return m_pAnimIdle->Update();
		break;
	case EANIMSTATES_MOVE:
		return m_pAnimMove->Update();
		break;
	case EANIMSTATES_DIVE:
		// return m_pAnimDive->Update();
		break;
	default:
		//ERROR
		return 0;
	}
}

void AnimFSM::ChangeState(EAnimStates eAnimState)
{
	m_eAnimState = eAnimState;
}