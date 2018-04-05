#include "Player.h"

#include "Textures.h"
#include "Score.h"
#include "Health.h"
#include "CameraOperator.h"

#define PLAYER_RADIUS 45.25f // Using Pythag 45.25
#define PLAYER_SPEED 2.0f	// Arbitrary

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Player::Player(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Score* pScore, Health* pHealth) : Actor(pApp2D, pCamOp, pResMod, pTextures)
{
	m_pTexture = pTextures->GetTexture(ETEXTURE_BIRD);
	m_pScore = pScore;
	m_pHealth = pHealth;
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
void Player::Update(aie::Input* input, float deltaTime)
{
	Move(input, deltaTime);
}

//----------------------------------------------------------
// Move
//----------------------------------------------------------
void Player::Move(aie::Input* input, float deltaTime)
{
	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		m_pCurrentPos->fY += PLAYER_SPEED * 100.0f * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		m_pCurrentPos->fY -= PLAYER_SPEED * 100.0f * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		float fPlayerPosX = m_pCurrentPos->fX;
		float fCamPosX = m_pCamOp->GetCamPos()->fX;
		float fMiddle = m_pCamOp->GetDevRes()->fX / 2;
		float fBarrierLeft = m_pCamOp->GetBarrier()->fLeft;
		
		// MATH
		//CB:HERENOW

		// Move
		fPlayerPosX -= PLAYER_SPEED * 100.0f * deltaTime;
		fCamPosX -= PLAYER_SPEED * 100.0f * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		float fPlayerPosX = m_pCurrentPos->fX;
		float fCamPosX = m_pCamOp->GetCamPos()->fX;
		float fMiddle = m_pCamOp->GetDevRes()->fX / 2;
		float fBarrierRight = m_pCamOp->GetBarrier()->fRight;

		// MATH
		

		// Move
		fPlayerPosX += PLAYER_SPEED * 100.0f * deltaTime;
		fCamPosX += PLAYER_SPEED * 100.0f * deltaTime;
	}
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