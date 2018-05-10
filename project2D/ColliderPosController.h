#pragma once

#include "DeQue.h"
#include "LinkedList.h"
#include "StructPos.h"

class Collider;
class CameraOperator;
class Player;

class ColliderPosController
{
public:
	ColliderPosController(CameraOperator* pCamOp, Player* pPlayer, Collider** apCollider, int nNumColliders);
	~ColliderPosController();

	void Update();

	void CheckEnds();
	void StartDeQue();

	LinkedList<Pos*>* GetPosList();

private:
	Collider**		m_apCollider;
	Pos*			m_pPlayerPos;

	LinkedList<Pos*>* m_pLLPos;
	DeQue<LinkedListNode<Pos*>*>* m_pDQListPos;

	float m_fDevResX;

	int m_nNumColliders;
	int m_nIterator;

	bool m_bHasFirst;
	bool m_bHasLast;
	bool m_bFoundCollider;

};

