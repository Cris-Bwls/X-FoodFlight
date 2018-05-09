#include "Level01.h"

#include "Debug.h"

//Higher
#include "Application2D.h"
#include "GameManager.h"
#include "CameraOperator.h"

//Lower
#include "UIElement.h"
#include "Actor.h"
#include "Clouds.h"
#include "Waves.h"
#include "Enemy.h"
#include "Fish.h"
#include "Player.h"
#include "ColliderPosController.h"

//----------------------------------------------------------
// Constructor
//
//			pApp2D (Application2D*):
//				pointer to Application2D
//			pFont (aie::Font*):
//				pointer to Font
//			pCamOp (CameraOperator*):
//				pointer to CameraOperator
//			pResMod (Resolution*):
//				pointer to Resolution
//			pTextures (Textures*):
//				pointer to Textures
//			pGame (GameManager*):
//				pointer to GameManager
//----------------------------------------------------------
Level01::Level01(Application2D* pApp2D, aie::Font* pFont, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, GameManager* pGame) : MainLevel(pApp2D, pFont, pCamOp, pResMod, pTextures, pGame)
{
#ifdef DEBUG_MODE
	assert(pApp2D);
	assert(pFont);
	assert(pCamOp);
	assert(pResMod);
	assert(pTextures);
	assert(pGame);
#endif // DEBUG_MODE

	// Set Camera Bounds
	pCamOp->SetDevCamPosBounds(0, 2150);
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
Level01::~Level01()
{
}

//----------------------------------------------------------
// Update
//----------------------------------------------------------
void Level01::Update(float deltaTime)
{
#ifdef DEBUG_MODE
	assert(m_apActor);
#endif // DEBUG_MODE

	// IF player exists
	if (m_pPlayer != nullptr)
	{
		// Update player
		m_pPlayer->Update(deltaTime);
	}

	// Update Position Controllers
	m_pEnemyPositions->Update();
	m_pFishPositions->Update();

	// Update Actors
	for (int i = 0; i < EACTOR_TOTAL; ++i)
	{
		for (int j = 0; j < m_nActors[i]; ++j)
		{
#ifdef DEBUG_MODE
			assert(m_apActor[i][j]);
#endif // DEBUG_MODE

			m_apActor[i][j]->Update(deltaTime);
		}
	}
}