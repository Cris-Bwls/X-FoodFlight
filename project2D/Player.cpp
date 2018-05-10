#include "Player.h"

#include "Debug.h"

#include "Application2D.h"
#include "Textures.h"
#include "Score.h"
#include "Health.h"
#include "CameraOperator.h"
#include "AnimFSM.h"

#define PLAYER_SIZE_X 64.0f	// X size of texture
#define PLAYER_SIZE_Y 64.0f	// Y size of texture
#define PLAYER_RADIUS 45.25f // Using Pythag 45.25

#define PLAYER_HORIZ_SPEED 20.0f //2.0f	// Arbitrary
#define PLAYER_VERT_SPEED 2.0f	// Arbitrary

#define FISH_WEIGHT 100	//

//----------------------------------------------------------
// Constructor
//
//			pApp2D (Application2D*):
//				pointer to Application2D
//			pCamOp (CameraOperator*):
//				pointer to CameraOperator
//			pResMod (Resolution*):
//				pointer to Resolution
//			pTextures (Textures*):
//				pointer to Textures
//			pScore (Score*):
//				pointer to Score
//			pHealth (Health*):
//				pointer to Health
//----------------------------------------------------------
Player::Player(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Score* pScore, Health* pHealth) : Actor(pApp2D, pCamOp, pResMod, pTextures)
{
#ifdef DEBUG_MODE
	assert(pApp2D);
	assert(pCamOp);
	assert(pResMod);
	assert(pTextures);
	//assert(pScore);
	//assert(pHealth);
#endif // DEBUG_MODE

	// Pointers Gathered
	m_pTexture = pTextures->GetTexture(ETEXTURE_BIRD);
	m_pScore = pScore;
	m_pHealth = pHealth;

	m_pAnimFSM = new AnimFSM;
	m_fRadius = PLAYER_RADIUS;

	// Player starts facing right
	m_fFacing = -PLAYER_SIZE_X + 1;

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
	delete m_pAnimFSM;
}

//----------------------------------------------------------
// Update
//----------------------------------------------------------
void Player::Update(float deltaTime)
{
#ifdef DEBUG_MODE
	assert(m_pAnimFSM);
#endif // DEBUG_MODE

	// Checks Fish
	CheckFish();
	// Moves Player
	Move(deltaTime);

	// Sets Animation Frame (UV X transform)
	m_fFrame = m_pAnimFSM->Update();
}

//----------------------------------------------------------
// Draw
//----------------------------------------------------------
void Player::Draw()
{
#ifdef DEBUG_MODE
	assert(m_pResMod);
	assert(m_pRenderer);
	assert(m_pTexture);
	assert(m_pCurrentPos);
#endif // DEBUG_MODE

	float fResModX = m_pResMod->fX;
	float fResModY = m_pResMod->fY;

	// Sets UV rect
	m_pRenderer->setUVRect(PLAYER_SIZE_X * m_fFrame * 0.2f, 0, .2f, .5f);
	// Draw Player
	m_pRenderer->drawSprite(m_pTexture, m_pCurrentPos->fX * fResModX, m_pCurrentPos->fY * fResModY, m_fFacing * fResModX, PLAYER_SIZE_Y * fResModY, 0.0f, 20.0f);

	//DEBUG
	system("cls");
	printf("CAMPOS: X = %f, Y= %f\n", m_pCamOp->GetDevCamPos()->fX, m_pCamOp->GetDevCamPos()->fY);
	printf("PLAYERPOS: X = %f, Y= %f\n", m_pCurrentPos->fX, m_pCurrentPos->fY);
	printf("Frame = %f\n", m_fFrame);
	printf("Fish = %i\n", m_nFish);
}

//----------------------------------------------------------
// Move
//		Checks for Input and moves player accordingly
//----------------------------------------------------------
void Player::Move(float deltaTime)
{
#ifdef DEBUG_MODE
	assert(aie::Input::getInstance());
	assert(m_pCurrentPos);
	assert(m_pCamOp);
	assert(m_pAnimFSM);
#endif // DEBUG_MODE

	aie::Input* input = aie::Input::getInstance();
	bool bPlayerMoved = false;

	// IF Up is Pressed && player is below max height
	if (input->isKeyDown(aie::INPUT_KEY_UP) && m_pCurrentPos->fY < m_fYmax)
	{
		bPlayerMoved = true;

		// Player moves up
		m_pCurrentPos->fY += PLAYER_VERT_SPEED * 100.0f * deltaTime;
	}
	// IF Down is Pressed && player is above min height
	if (input->isKeyDown(aie::INPUT_KEY_DOWN) && m_pCurrentPos->fY > m_fYmin)
	{
		bPlayerMoved = true;

		// Player moves down
		m_pCurrentPos->fY -= PLAYER_VERT_SPEED * 100.0f * deltaTime;
	}
	// IF Left is Pressed && player X Pos > min X Pos
	if (input->isKeyDown(aie::INPUT_KEY_LEFT) && m_pCurrentPos->fX > m_fXmin)
	{
		bPlayerMoved = true;

		// sprite faces left
		m_fFacing = PLAYER_SIZE_X;
		// Player moves left
		m_pCurrentPos->fX -= PLAYER_HORIZ_SPEED * 100.0f * deltaTime;

		// Camera changes pos
		float fBarrierRight = m_pCamOp->GetBarrier()->fRight;		
		m_pCamOp->GetDevCamPos()->fX = m_pCurrentPos->fX - fBarrierRight;
	}
	// IF Right is Pressed && player X Pos < max X Pos
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT) && m_pCurrentPos->fX < m_fXmax)
	{
		bPlayerMoved = true;

		// sprite faces right
		m_fFacing = -PLAYER_SIZE_X + 1;
		// Player moves right
		m_pCurrentPos->fX += PLAYER_HORIZ_SPEED * 100.0f * deltaTime;

		// Camera changes pos
		float fBarrierLeft = m_pCamOp->GetBarrier()->fLeft;
		m_pCamOp->GetDevCamPos()->fX = m_pCurrentPos->fX - fBarrierLeft;
	}

	// IF Player Moved
	if (bPlayerMoved)
	{
		// Change animation state to MOVE
		m_pAnimFSM->ChangeState(EANIMSTATES_MOVE);
	}
	else
	{
		// Change animation state to IDLE
		m_pAnimFSM->ChangeState(EANIMSTATES_IDLE);
	}
	// Camera Position is checked
	m_pCamOp->CheckCamPos();

	//DEBUG
	printf("DELTATIME: %f\n", deltaTime);
}

//----------------------------------------------------------
// SetBoundaries
//		Boundaries of level
//
//			fXmin (float):
//				Min X position for Player in Level
//			fXmax (float):
//				Max X position for Player in Level
//			fYmin (float):
//				Min Y position for Player in Level
//			fYmax (float):
//				Max Y position for Player in Level
//----------------------------------------------------------
void Player::SetBoundaries(float fXmin, float fXmax, float fYmin, float fYmax)
{
	m_fXmin = fXmin;
	m_fXmax = fXmax;
	m_fYmin = fYmin;
	m_fYmax = fYmax;
	m_fYmaxInit = m_fYmax;

}

//----------------------------------------------------------
// GetPos
//		Gets Player Position
//
//			&fRadius (float): (out)
//				reference to player radius
//
//			return (Pos*)
//				pointer to Current player Position
//----------------------------------------------------------
Pos* Player::GetPos(float &fRadius)
{
#ifdef DEBUG_MODE
	assert(m_pCurrentPos);
#endif // DEBUG_MODE

	fRadius = m_fRadius;
	return m_pCurrentPos;
}


//----------------------------------------------------------
// GetPos
//		Gets Player Position
//
//			&fPosX (float): (out)
//				reference to players current X pos
//			&fPosY (float): (out)
//				reference to players current Y pos
//			&fRadius (float): (out)
//				reference to player radius
//----------------------------------------------------------
void Player::GetPos(float &fPosX, float &fPosY, float &fRadius)
{
#ifdef DEBUG_MODE
	assert(m_pCurrentPos);
#endif // DEBUG_MODE

	fPosX	= m_pCurrentPos->fX;
	fPosY	= m_pCurrentPos->fY;
	fRadius = m_fRadius;
}

//----------------------------------------------------------
// AddFish
//		Adds a fish to players fish count
//----------------------------------------------------------
void Player::AddFish()
{
	++m_nFish;
}

//----------------------------------------------------------
// TakeFish
//		Removes all fish from players fish count
//
//		bTookHit (bool):
//			If the player is dropping fish because they got hit
//----------------------------------------------------------
void Player::TakeFish(bool bTookHit)
{
	m_nFish = 0;

	// IF the player took a hit
	if (bTookHit)
	{
		// Call Score and Health
	}
	else
	{
		// Add to Score
	}
}

//----------------------------------------------------------
// CheckFish
//		Checks how many fish the player has and updates how
//		high they can fly
//----------------------------------------------------------
void Player::CheckFish()
{
	m_fYmax = m_fYmaxInit - (float)(FISH_WEIGHT * m_nFish);
}