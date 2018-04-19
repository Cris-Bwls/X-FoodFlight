#pragma once
#include "Actor.h"

#include "Input.h"

#define PLAYER_DEFAULT_YMIN 50.0f
#define PLAYER_DEFAULT_YMAX 620.0f //720 - 100

class Score;
class Health;

class Player :
	public Actor
{
public:
	Player(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Score* pScore = nullptr, Health* pHealth = nullptr);
	~Player();

	void Update(float deltaTime);
	void Draw();

	void Move(float deltaTime);

	void SetBoundaries(float fXmin, float fXmax, float Ymin = PLAYER_DEFAULT_YMIN, float yMax = PLAYER_DEFAULT_YMAX);

	void GetPos(float &fPosX, float &fPosY, float &fRadius);
	Pos* GetPos(float &fRadius);

	void AddFish();
	void TakeFish(bool bTookHit = false);
	void CheckFish();

private:
	Score*	m_pScore;
	Health* m_pHealth;

	float m_fXmin;
	float m_fXmax;
	float m_fYmin;
	float m_fYmax;

	float m_fFacing;

	int m_nFish = 0;
};

