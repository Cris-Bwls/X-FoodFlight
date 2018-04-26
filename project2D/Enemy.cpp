#include "Enemy.h"

#include "AnimFSM.h"
#include "Textures.h"

#define ENEMY_SIZE_X 64.0f // X size of texture
#define ENEMY_SIZE_Y 64.0f // Y size of texture
#define ENEMY_RADIUS 45 // Using Pythag 45.25

#define ENEMY_SPEED 2

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Enemy::Enemy(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Player* pPlayer) : Collider(pApp2D, pCamOp, pResMod, pTextures, pPlayer)
{
	m_pTexture = pTextures->GetTexture(ETEXTURE_BIRD);

	m_fFacing = -ENEMY_SIZE_X + 1;
}

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Enemy::~Enemy()
{
}

void Enemy::Update(float deltaTime)
{

}

void Enemy::Draw()
{
	float fResModX = m_pResMod->fX;
	float fResModY = m_pResMod->fY;

	m_pRenderer->setUVRect(ENEMY_SIZE_X * m_fFrame * 0.2f, 0.5f, .2f, .5f);
	m_pRenderer->drawSprite(m_pTexture, m_pCurrentPos->fX * fResModX, m_pCurrentPos->fY * fResModY, m_fFacing * fResModX, ENEMY_SIZE_Y * fResModY, 0.0f, 20.0f);
}

