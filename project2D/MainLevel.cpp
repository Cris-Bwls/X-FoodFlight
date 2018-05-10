#include "MainLevel.h"

#include "Debug.h"

//Higher
#include "Application2D.h"
#include "GameManager.h"

//Lower
#include "CameraOperator.h"
#include "UIElement.h"
#include "Actor.h"
#include "Clouds.h"
#include "Waves.h"
#include "Enemy.h"
#include "Fish.h"
#include "Player.h"
#include "ColliderPosController.h"


#define UI_MAIN_MENU "MAIN MENU"

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
MainLevel::MainLevel(Application2D* pApp2D, aie::Font* pFont, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, GameManager* pGame) : BaseMain(pApp2D, pFont, pCamOp, pResMod, pTextures, pGame)
{
#ifdef DEBUG_MODE
	assert(pApp2D);
	assert(pFont);
	assert(pCamOp);
	assert(pResMod);
	assert(pTextures);
	assert(pGame);
#endif // DEBUG_MODE

	m_nUIElements = 1;

	m_nActors[EACTOR_CLOUDS] = 2; //2;
	m_nActors[EACTOR_WAVES] = 1; //1;
	m_nActors[EACTOR_ENEMY] = 12; //12;
	m_nActors[EACTOR_FISH] = 12; //12;

	// UI Init
	m_apUIElement = new UIElement*[m_nUIElements];

	float fPosX = (pApp2D->getWindowWidth() - 100);
	float fPosY = (pApp2D->getWindowHeight() - 100);

	float fWidth, fHeight;
	pFont->getStringSize(UI_MAIN_MENU, fWidth, fHeight);

	m_apUIElement[0] = new UIElement(pApp2D, pResMod, ECOLOUR_RED, pFont, UI_MAIN_MENU, fWidth * 1.1, fHeight * 1.1, fPosX, fPosY);

	m_pPlayer = new Player(pApp2D, pCamOp, pResMod, pTextures);

	// Actor Init
	m_apActor = new Actor**[EACTOR_TOTAL];
	float buffer;

	for (int i = 0; i < EACTOR_TOTAL; ++i)
	{
		switch (i)
		{
		case EACTOR_CLOUDS:
			m_apActor[i] = new Actor*[m_nActors[i]];
			for (int j = 0; j < m_nActors[i]; ++j)
			{
				m_apActor[i][j] = new Clouds(m_pApp2D, m_pCamOp, pResMod, pTextures, m_pPlayer->GetPos(buffer), 1.0f - ((float)j / 2), -150.0f * (float)j, 1.0f - (0.5f * (float)j), j);
			}
			break;
		case EACTOR_WAVES:
			m_apActor[i] = new Actor*[m_nActors[i]];
			for (int j = 0; j < m_nActors[i]; ++j)
			{
				m_apActor[i][j] = new Waves(m_pApp2D, m_pCamOp, pResMod, pTextures, m_pPlayer->GetPos(buffer));
			}
			break;
		case EACTOR_ENEMY:
			m_apActor[i] = new Actor*[m_nActors[i]];
			for (int j = 0; j < m_nActors[i]; ++j)
			{
				m_apActor[i][j] = new Enemy(m_pApp2D, m_pCamOp, pResMod, pTextures, m_pPlayer);
			}
			break;
		case EACTOR_FISH:
			m_apActor[i] = new Actor*[m_nActors[i]];
			for (int j = 0; j < m_nActors[i]; ++j)
			{
				m_apActor[i][j] = new Fish(m_pApp2D, m_pCamOp, pResMod, pTextures, m_pPlayer);
			}
			break;
		default:
			//ERROR
			printf("ERROR\n");
			printf("Mainlevel::Constructor, invalid Actor count\n");
			std::getchar();
		}
	}

	// Enemy Position Init
	m_pEnemyPositions = new ColliderPosController(pCamOp, m_pPlayer, (Collider**)m_apActor[EACTOR_ENEMY], m_nActors[EACTOR_ENEMY]);
	{
		Pos* tempPos = new Pos();
		tempPos->fX = 300.0f;
		tempPos->fY = 400.0f;

		m_pEnemyPositions->GetPosList()->PushBack(tempPos);
		m_pEnemyPositions->StartDeQue();
	}
	// Fish Position Init
	m_pFishPositions = new ColliderPosController(pCamOp, m_pPlayer, (Collider**)m_apActor[EACTOR_FISH], m_nActors[EACTOR_FISH]);
	{
		Pos* tempPos = new Pos();
		tempPos->fX = 300.0f;
		tempPos->fY = 50.0f;

		m_pFishPositions->GetPosList()->PushBack(tempPos);
		m_pFishPositions->StartDeQue();
	}
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
MainLevel::~MainLevel()
{
	for (int i = 0; i < m_nUIElements; ++i)
	{
		delete m_apUIElement[i];
	}

	for (int i = 0; i < EACTOR_TOTAL; ++i)
	{
		for (int j = 0; j < m_nActors[i]; ++j)
		{
			delete m_apActor[i][j];
		}

		delete[] m_apActor[i];
	}

	delete[] m_apUIElement;
	delete[] m_apActor;

	delete m_pPlayer;

	auto tempPosList = m_pEnemyPositions->GetPosList();
	while (tempPosList->GetStart()->m_pNext != tempPosList->GetEnd())
	{
		delete tempPosList->GetData(0);
		tempPosList->PopPoint(tempPosList->GetStart()->m_pNext);
	}
	delete m_pEnemyPositions;

	tempPosList = m_pFishPositions->GetPosList();
	while (tempPosList->GetStart()->m_pNext != tempPosList->GetEnd())
	{
		delete tempPosList->GetData(0);
		tempPosList->PopPoint(tempPosList->GetStart()->m_pNext);
	}
	delete m_pFishPositions;
}

//----------------------------------------------------------
// Update
//----------------------------------------------------------
void MainLevel::Update(float deltaTime)
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
	// Add new positions if needed
	AddPositions();

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

//----------------------------------------------------------
// UpdateUI
//		Updates UI Elements
//		
//			&eNewLevel (ELevel): (out)
//				reference to the new level
//
//			return (bool):
//				true if level has changed
//----------------------------------------------------------
bool MainLevel::UpdateUI(ELevel &eNewLevel)
{
#ifdef DEBUG_MODE
	assert(m_apUIElement);
	assert(m_apUIElement[0]);
#endif // DEBUG_MODE

	// MainMenu
	// IF UI element pressed
	if (m_apUIElement[0]->Update())
	{
		// Set New Level
		eNewLevel = (ELEVEL_MAIN_MENU);
		// Level Changed
		return true;
	}

	// Level NOT changed
	return false;
}