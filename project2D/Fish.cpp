#include "Fish.h"

#include "Debug.h"

#include "Player.h"
#include "Textures.h"

#define FISH_SIZE_X 37.0f // X size of texture
#define FISH_SIZE_Y 24.0f // Y size of texture
#define FISH_RADIUS 22 // Using Pythag 22.05

#define FISH_SPEED 2

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
Fish::Fish(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Player* pPlayer) : Collider(pApp2D, pCamOp, pResMod, pTextures, pPlayer)
{
#ifdef DEBUG_MODE
	assert(pApp2D);
	assert(pCamOp);
	assert(pResMod);
	assert(pTextures);
#endif // DEBUG_MODE

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
	// IF NOT Dead
	if (!m_bIsDead)
	{
		// Check If Visible
		CheckVisible();

		// IF Is Visible
		if (m_bIsVisible)
		{
			// IF Collision
			if (Collision())
			{
				// Add fish to Player
				m_pPlayer->AddFish();
				// Kill Fish
				m_bIsDead = true;
			}
		}
	}
}

//----------------------------------------------------------
// Draw
//----------------------------------------------------------
void Fish::Draw()
{
#ifdef DEBUG_MODE
	assert(m_pResMod);
	assert(m_pTexture);
	assert(m_pCurrentPos);
#endif // DEBUG_MODE

	// IF NOT Dead
	if (!m_bIsDead)
	{
		float fResModX = m_pResMod->fX;
		float fResModY = m_pResMod->fY;

		// Sets UV rect
		m_pRenderer->setUVRect(0, 0, 1, 1);
		// Draws Fish
		m_pRenderer->drawSprite(m_pTexture, m_pCurrentPos->fX * fResModX, m_pCurrentPos->fY * fResModY, FISH_SIZE_X * fResModX, FISH_SIZE_Y * fResModY, 0.0f, 20.0f);
	}
}


