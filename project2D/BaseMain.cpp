#include "BaseMain.h"

#include "Debug.h"

//Higher
#include "Application2D.h"
#include "Textures.h"
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
BaseMain::BaseMain(Application2D* pApp2D, aie::Font* pFont, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, GameManager* pGame)
{
#ifdef DEBUG_MODE
	assert(pApp2D);
	assert(pFont);
	assert(pCamOp);
	assert(pResMod);
	assert(pTextures);
	assert(pGame);
#endif // DEBUG_MODE

	m_pApp2D = pApp2D;
	m_pCamOp = pCamOp;
	m_pResMod = pResMod;
	m_pGame = pGame;

	// Reset Camera
	pCamOp->ResetCamPos();
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
BaseMain::~BaseMain()
{
}

//----------------------------------------------------------
// Update
//----------------------------------------------------------
void BaseMain::Update(float deltaTime)
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

//----------------------------------------------------------
// Draw
//		Draws everything in level
//----------------------------------------------------------
void BaseMain::Draw()
{
#ifdef DEBUG_MODE
	assert(m_apUIElement);
	assert(m_apActor);
#endif // DEBUG_MODE

	// IF player exists
	if (m_pPlayer != nullptr)
	{
		// Draw Player
		m_pPlayer->Draw();
	}

	// Draw all UI elements
	for (int i = 0; i < m_nUIElements; ++i)
	{
#ifdef DEBUG_MODE
		assert(m_apUIElement[i]);
#endif // DEBUG_MODE

		m_apUIElement[i]->Draw();
	}

	// Draw all Actors
	for (int i = 0; i < EACTOR_TOTAL; ++i)
	{
		for (int j = 0; j < m_nActors[i]; ++j)
		{
#ifdef DEBUG_MODE
			assert(m_apActor[i][j]);
#endif // DEBUG_MODE

			m_apActor[i][j]->Draw();
		}
	}	
}