#include "Player.h"

//DEBUG
#include<iostream>

#include "Application2D.h"
#include "Textures.h"
#include "Score.h"
#include "Health.h"
#include "CameraOperator.h"

#define PLAYER_SIZE 64.0f;	// Size of texture
#define PLAYER_RADIUS 45.25f // Using Pythag 45.25

#define PLAYER_HORIZ_SPEED 2.0f	// Arbitrary
#define PLAYER_VERT_SPEED 2.0f	// Arbitrary
#define FISH_WEIGHT 100	//	

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Player::Player(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Score* pScore, Health* pHealth) : Actor(pApp2D, pCamOp, pResMod, pTextures)
{
	// Pointers Gathered
	m_pTexture = pTextures->GetTexture(ETEXTURE_BIRD);
	m_pScore = pScore;
	m_pHealth = pHealth;

	// Player starts facing right
	m_fFacing = -PLAYER_SIZE + 1;

	//DEBUG
	m_pCurrentPos->fX = 300.0f;
	m_pCurrentPos->fY = 300.0f;
	SetBoundaries(150, 2000);
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
	float fResModX = m_pResMod->fX;
	float fResModY = m_pResMod->fY;

	m_pRenderer->setUVRect(64, 0, .2f, .5f);
	m_pRenderer->drawSprite(m_pTexture, m_pCurrentPos->fX * fResModX, m_pCurrentPos->fY * fResModY, m_fFacing * fResModX, 64.0f * fResModY, 0.0f, 20.0f);

	//DEBUG
	system("cls");
	printf("CAMPOS: X = %f, Y= %f\n", m_pCamOp->GetDevCamPos()->fX, m_pCamOp->GetDevCamPos()->fY);
	printf("PLAYERPOS: X = %f, Y= %f\n", m_pCurrentPos->fX, m_pCurrentPos->fY);
}

//----------------------------------------------------------
// Move
//----------------------------------------------------------
void Player::Move(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	if (input->isKeyDown(aie::INPUT_KEY_UP) && m_pCurrentPos->fY < m_fYmax)
	{
		// Player moves up
		m_pCurrentPos->fY += PLAYER_VERT_SPEED * 100.0f * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_DOWN) && m_pCurrentPos->fY > m_fYmin)
	{
		// Player moves down
		m_pCurrentPos->fY -= PLAYER_VERT_SPEED * 100.0f * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_LEFT) && m_pCurrentPos->fX > m_fXmin)
	{
		// sprite faces left
		m_fFacing = PLAYER_SIZE;
		// Player moves left
		m_pCurrentPos->fX -= PLAYER_HORIZ_SPEED * 100.0f * deltaTime;

		// Camera changes pos
		float fBarrierRight = m_pCamOp->GetBarrier()->fRight;
		
		m_pCamOp->GetDevCamPos()->fX = m_pCurrentPos->fX - fBarrierRight;
	}
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT) && m_pCurrentPos->fX < m_fXmax)
	{
		// sprite faces right
		m_fFacing = -PLAYER_SIZE + 1;
		// Player moves right
		m_pCurrentPos->fX += PLAYER_HORIZ_SPEED * 100.0f * deltaTime;

		// Camera changes pos
		float fBarrierLeft = m_pCamOp->GetBarrier()->fLeft;

		m_pCamOp->GetDevCamPos()->fX = m_pCurrentPos->fX - fBarrierLeft;
	}

	// Camera Position is checked
	m_pCamOp->CheckCamPos();

	//DEBUG
	printf("DELTATIME: %f\n", deltaTime);
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