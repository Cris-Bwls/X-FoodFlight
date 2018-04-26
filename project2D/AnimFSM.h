#pragma once

#include "EnumAnimStates.h"

class AnimIdle;
class AnimMove;

class AnimFSM
{
public:
	AnimFSM();
	~AnimFSM();

	float Update();

	void ChangeState(EAnimStates eAnimState);

private:
	EAnimStates m_eAnimState = EANIMSTATES_IDLE;

	AnimIdle* m_pAnimIdle;
	AnimMove* m_pAnimMove;
};



