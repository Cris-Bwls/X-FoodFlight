#pragma once
#include "Actor.h"

class Player;

class Collider :
	public Actor
{
public:
	Collider(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Player* pPlayer = nullptr);
	~Collider();

	virtual void Update(float deltaTime) = 0;
	void Draw() = 0;

	bool Collision();

	void CheckVisible();

	void SetIsEnabled(bool bIsEnabled = true);
	bool GetIsEnabled();


protected:
	Player* m_pPlayer;
	
	bool m_bCanCollide = true;
	bool m_bIsEnabled = false;
};

