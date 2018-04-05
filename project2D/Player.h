#pragma once
#include "Actor.h"

#include "Input.h"

class Score;
class Health;

class Player :
	public Actor
{
public:
	Player(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Score* pScore, Health* pHealth);
	~Player();

	void Update(aie::Input* input, float deltaTime);

	void Move(aie::Input* input, float deltaTime);

	void GetPos(float &fPosX, float &fPosY, float &fRadius);
	Pos* GetPos(float &fRadius);

	void AddFish();

	void TakeFish(bool bTookHit = false);
private:
	Score*	m_pScore;
	Health* m_pHealth;

	int m_nFish = 0;
};

