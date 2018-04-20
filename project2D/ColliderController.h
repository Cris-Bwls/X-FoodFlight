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

	void Update();

	void CheckEnds();
	void AddPos(Pos* pos);

private:
	Collider**		m_apCollider;
	Pos*			m_pPlayerPos;

	LinkedList<Pos*> m_llPos;
	DeQue<LinkedListNode<Pos*>*> m_dqListPos;

	float m_fDevResX;

	bool m_bHasFirst;
	bool m_bHasLast;
};

