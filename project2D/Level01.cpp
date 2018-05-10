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

#define OFFSET 1000

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
	pCamOp->SetDevCamPosBounds(0, FLT_MAX);
	m_pPlayer->SetBoundaries(150, FLT_MAX);
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
Level01::~Level01()
{
}

//----------------------------------------------------------
// AddPositions
//----------------------------------------------------------
void Level01::AddPositions()
{
	float fPlayerXPos = m_pPlayer->GetCurrentPos()->fX;
	float fTempX;

	// Add to Enemy Positions
	auto end = m_pEnemyPositions->GetPosList()->GetEnd();
	while (fPlayerXPos > end->m_pPrev->m_data->fX - OFFSET)
	{
		fTempX = end->m_pPrev->m_data->fX;
		auto tempPos = new Pos;
		tempPos->fX = fTempX + 300;
		tempPos->fY = 400;

		m_pEnemyPositions->GetPosList()->PushBack(tempPos);
	}

	// Add to Fish Positions
	end = m_pFishPositions->GetPosList()->GetEnd();
	while (fPlayerXPos > end->m_pPrev->m_data->fX - OFFSET)
	{
		fTempX = end->m_pPrev->m_data->fX;
		auto tempPos = new Pos;
		tempPos->fX = fTempX + 300;
		tempPos->fY = 50;

		m_pFishPositions->GetPosList()->PushBack(tempPos);
	}
}