#pragma once
#include "Actor.h"

class Player;

class Collider :
	public Actor
{
public:
	Collider(Application2D* pApp2D, CameraOperator* pCamOp, Player* pPlayer = nullptr);
	~Collider();

	bool Collision();

protected:
	Player* m_pPlayer;

	bool canCollide = true;
};

