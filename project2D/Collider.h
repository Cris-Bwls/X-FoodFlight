#pragma once
#include "Actor.h"

class Player;

class Collider :
	public Actor
{
public:
	Collider(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Player* pPlayer = nullptr);
	~Collider();

	virtual void Update(float deltaTime) = 0;
	void Draw();

	bool Collision();

protected:
	Player* m_pPlayer;
	
	bool m_bCanCollide = true;
};

