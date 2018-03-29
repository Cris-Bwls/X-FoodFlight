#include "Player.h"

#include "Score.h"
#include "Health.h"

#define PLAYER_RADIUS 45 // Using Pythag 45.25
#define PLAYER_SPEED 2

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Player::Player(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod) : Actor(pApp2D, pCamOp, pResMod)
{
}

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Player::~Player()
{
}

//----------------------------------------------------------
// Update
//----------------------------------------------------------
void Player::Update(aie::Input* input, float deltaTime)
{

}

//----------------------------------------------------------
// GetPos
//----------------------------------------------------------
void Player::GetPos(float &fPosX, float &fPosY, float &fRadius)
{
	fPosX	= m_fX;
	fPosY	= m_fY;
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