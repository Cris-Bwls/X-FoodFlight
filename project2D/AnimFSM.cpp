#include "AnimFSM.h"



AnimFSM::AnimFSM(bool bIsEnemy)
{
	m_bIsEnemy = bIsEnemy;
}


AnimFSM::~AnimFSM()
{
}

//---------------------------------------------------
// returns the UV offset
//---------------------------------------------------
int AnimFSM::Update()
{
	switch (m_eAnimState)
	{
	case EANIMSTATES_IDLE:
		// return m_pAnimIdle->Update();
		break;
	case EANIMSTATES_MOVE:
		// return m_pAnimMove->Update();
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