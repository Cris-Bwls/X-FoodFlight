#pragma once

#include "DeQue.h"
#include "LinkedList.h"
#include "StructPos.h"

class Collider;
class CameraOperator;
class Player;

class ColliderController
{
public:
	ColliderController(Collider** apCollider, CameraOperator* pCamOp, Player* pPlayer = nullptr);
	~ColliderController();

private:
	Collider**		m_apCollider;
	CameraOperator* m_pCamOp;
	Player*			m_pPlayer;

	LinkedList<Pos*> m_llPos;
	DeQue<double> m_dqListPos;
};

