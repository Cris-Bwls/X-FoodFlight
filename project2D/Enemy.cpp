#include "Enemy.h"

#include "Debug.h"

#include "AnimFSM.h"
#include "Textures.h"

#define ENEMY_SIZE_X 64.0f // X size of texture
#define ENEMY_SIZE_Y 64.0f // Y size of texture
#define ENEMY_RADIUS 45 // Using Pythag 45.25

#define ENEMY_SPEED 2

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
//			pPlayer (Player*):
//				pointer to Player
//----------------------------------------------------------
Enemy::Enemy(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Player* pPlayer) : Collider(pApp2D, pCamOp, pResMod, pTextures, pPlayer)
{
#ifdef DEBUG_MODE
	assert(pApp2D);
	assert(pCamOp);
	assert(pResMod);
	assert(pTextures);
#endif // DEBUG_MODE

	m_pTexture = pTextures->GetTexture(ETEXTURE_BIRD);

	m_fRadius = ENEMY_RADIUS;

	m_fFacing = -ENEMY_SIZE_X + 1;
}

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Enemy::~Enemy()
{
}

//----------------------------------------------------------
// Update
//----------------------------------------------------------
void Enemy::Update(float deltaTime)
{
	Collision();
}

//----------------------------------------------------------
// Draw
//----------------------------------------------------------
void Enemy::Draw()
{
#ifdef DEBUG_MODE
	assert(m_pResMod);
	assert(m_pTexture);
	assert(m_pCurrentPos);
#endif // DEBUG_MODE

	float fResModX = m_pResMod->fX;
	float fResModY = m_pResMod->fY;

	// Sets UV rect
	m_pRenderer->setUVRect(ENEMY_SIZE_X * m_fFrame * 0.2f, 0.5f, .2f, .5f);
	// Draws Enemy
	m_pRenderer->drawSprite(m_pTexture, m_pCurrentPos->fX * fResModX, m_pCurrentPos->fY * fResModY, m_fFacing * fResModX, ENEMY_SIZE_Y * fResModY, 0.0f, 20.0f);
}

