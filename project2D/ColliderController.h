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
	ColliderController(Collider** apCollider, int nNumColliders, CameraOperator* pCamOp, Player* pPlayer = nullptr);
	~ColliderController();

	void Update();

	void CheckEnds();

	LinkedList<Pos*>* GetPosList();

private:
	Collider**		m_apCollider;
	Pos*			m_pPlayerPos;

	LinkedList<Pos*> m_llPos;
	DeQue<LinkedListNode<Pos*>*> m_dqListPos;

	float m_fDevResX;

	int m_nNumColliders;
	int m_nIterator;

	bool m_bHasFirst;
	bool m_bHasLast;
	bool m_bFoundCollider;

};

