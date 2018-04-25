#pragma once

#include "EnumAnimStates.h"

class AnimFSM
{
public:
	AnimFSM(bool bIsEnemy = true);
	~AnimFSM();

	int Update();

	void ChangeState(EAnimStates eAnimState);

private:
	EAnimStates m_eAnimState = EANIMSTATES_IDLE;

	bool m_bIsEnemy;
};



