#include "Fish.h"

#include "Textures.h"

#define FISH_SIZE_X 37.0f // X size of texture
#define FISH_SIZE_Y 24.0f // Y size of texture
#define FISH_RADIUS 22 // Using Pythag 22.05

#define FISH_SPEED 2

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Fish::Fish(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Player* pPlayer) : Collider(pApp2D, pCamOp, pResMod, pTextures, pPlayer)
{
	m_pTexture = pTextures->GetTexture(ETEXTURE_FISH);

	m_fRadius = FISH_RADIUS;
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
Fish::~Fish()
{
}


//----------------------------------------------------------
// Update
//----------------------------------------------------------
void Fish::Update(float deltaTime)
{
	Collision();
}

void Fish::Draw()
{
	float fResModX = m_pResMod->fX;
	float fResModY = m_pResMod->fY;

	m_pRenderer->setUVRect(0, 0, 1, 1);
	m_pRenderer->drawSprite(m_pTexture, m_pCurrentPos->fX * fResModX, m_pCurrentPos->fY * fResModY, FISH_SIZE_X * fResModX, FISH_SIZE_Y * fResModY, 0.0f, 20.0f);
}


