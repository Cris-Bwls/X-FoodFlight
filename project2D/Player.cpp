#include "Player.h"

//DEBUG
#include<iostream>

#include "Application2D.h"
#include "Textures.h"
#include "Score.h"
#include "Health.h"
#include "CameraOperator.h"

#define PLAYER_RADIUS 45.25f // Using Pythag 45.25

#define PLAYER_SPEED 2.0f	// Arbitrary
#define FISH_WEIGHT 100	//	

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Player::Player(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Score* pScore, Health* pHealth) : Actor(pApp2D, pCamOp, pResMod, pTextures)
{
	m_pTexture = pTextures->GetTexture(ETEXTURE_BIRD);
	m_pScore = pScore;
	m_pHealth = pHealth;

	//DEBUG
	m_pCurrentPos->fX = 300.0f;
	m_pCurrentPos->fY = 300.0f;
	SetBoundaries(150.0f, 2000.0f);
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
Player::~Player()
{
}

//----------------------------------------------------------
// Update
//----------------------------------------------------------
void Player::Update(float deltaTime)
{
	CheckFish();
	Move(deltaTime);
}

//----------------------------------------------------------
// Draw
//----------------------------------------------------------
void Player::Draw()
{
	m_pApp2D->GetRenderer()->begin();
	//DEBUG
	system("cls");
	printf("CAMPOS: X = %f, Y= %f\n", m_pCamOp->GetCamPos()->fX, m_pCamOp->GetCamPos()->fY);
	printf("PLAYERPOS: X = %f, Y= %f\n", m_pCurrentPos->fX, m_pCurrentPos->fY);
	m_pApp2D->GetRenderer()->setUVRect(64, 0, .2f, .5f);
	m_pApp2D->GetRenderer()->drawSprite(m_pTexture, m_pCurrentPos->fX, m_pCurrentPos->fY, -63.0f, 64.0f, 0.0f, 20.0f);
	m_pApp2D->GetRenderer()->end();
}

//----------------------------------------------------------
// Move
//----------------------------------------------------------
void Player::Move(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	if (input->isKeyDown(aie::INPUT_KEY_UP) && m_pCurrentPos->fY < m_fYmax)
	{
		m_pCurrentPos->fY += PLAYER_SPEED * 100.0f * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_DOWN) && m_pCurrentPos->fY > m_fYmin)
	{
		m_pCurrentPos->fY -= PLAYER_SPEED * 100.0f * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_LEFT) && m_pCurrentPos->fX > m_fXmin)
	{
		float fCamPosX = m_pCamOp->GetCamPos()->fX;
		float fPlayerPosX = m_pCurrentPos->fX - fCamPosX;
		float fMiddle = m_pCamOp->GetDevRes()->fX / 2;
		float fBarrierLeft = m_pCamOp->GetBarrier()->fLeft;
		
		// MATH
		double dRatio = fMiddle + fBarrierLeft - fPlayerPosX;
		dRatio /= (fMiddle + fBarrierLeft);
		printf("fRatio = %f\n", dRatio);

		// Move
		m_pCurrentPos->fX -= PLAYER_SPEED * 100.0f * deltaTime;
		if (dRatio > 0)
		{
			fCamPosX -= PLAYER_SPEED * 100.0f * deltaTime * dRatio;
		}
		m_pApp2D->SetCameraPos(fCamPosX, 0.0f);
	}
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT) && m_pCurrentPos->fX < m_fXmax)
	{
		float fCamPosX = m_pCamOp->GetCamPos()->fX;
		float fPlayerPosX = m_pCurrentPos->fX - fCamPosX;
		float fMiddle = m_pCamOp->GetDevRes()->fX / 2;
		float fBarrierRight = m_pCamOp->GetBarrier()->fRight;

		// MATH
		double dRatio = fPlayerPosX - (fBarrierRight - fMiddle);
		dRatio /= (fBarrierRight - fMiddle);
		printf("fRatio = %f\n", dRatio);

		// Move
		m_pCurrentPos->fX += PLAYER_SPEED * 100.0f * deltaTime;
		if (dRatio > 0)
		{
			fCamPosX += PLAYER_SPEED * 100.0f * deltaTime * dRatio;
		}
		m_pApp2D->SetCameraPos(fCamPosX, 0.0f);
	}
}

//----------------------------------------------------------
// SetBoundaries
//		Boundaries of level
//----------------------------------------------------------
void Player::SetBoundaries(float fXmin, float fXmax, float fYmin, float fYmax)
{
	m_fXmin = fXmin;
	m_fXmax = fXmax;
	m_fYmin = fYmin;
	m_fYmax = fYmax;

}

//----------------------------------------------------------
// GetPos
//----------------------------------------------------------
Pos* Player::GetPos(float &fRadius)
{
	fRadius = m_fRadius;
	return m_pCurrentPos;
}


//----------------------------------------------------------
// GetPos
//----------------------------------------------------------
void Player::GetPos(float &fPosX, float &fPosY, float &fRadius)
{
	fPosX	= m_pCurrentPos->fX;
	fPosY	= m_pCurrentPos->fY;
	fRadius = m_fRadius;
}

//----------------------------------------------------------
// AddFish
//----------------------------------------------------------
void Player::AddFish()
{
	++m_nFish;
}

//----------------------------------------------------------
// TakeFish
//----------------------------------------------------------
void Player::TakeFish(bool bTookHit)
{
	m_nFish = 0;

	if (bTookHit)
	{
		// Call Score and Health
	}
}

//----------------------------------------------------------
// CheckFish
//----------------------------------------------------------
void Player::CheckFish()
{
	m_fYmax -= (float)(FISH_WEIGHT * m_nFish);
}