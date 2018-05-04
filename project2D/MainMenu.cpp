#include "MainMenu.h"

//Higher
#include "Debug.h"

#include "Application2D.h"
#include "GameManager.h"

//Lower
#include "UIElement.h"
#include "Actor.h"
#include "Clouds.h"
#include "Waves.h"
#include "Enemy.h"
#include "Fish.h"
#include "Player.h"

//DEBUG
#include "CameraOperator.h"

// UI names
#define UI_PLAY "PLAY"
#define UI_QUIT "QUIT"


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
MainMenu::MainMenu(Application2D* pApp2D, aie::Font* pFont, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, GameManager* pGame) : BaseMain(pApp2D, pFont, pCamOp, pResMod, pTextures, pGame)
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

	m_nUIElements = 2;

	m_nActors[EACTOR_CLOUDS]	= 2; //2;
	m_nActors[EACTOR_WAVES]		= 1; //1;
	m_nActors[EACTOR_ENEMY]		= 3; //3;
	m_nActors[EACTOR_FISH]		= 3; //3;

	// UI Init
	m_apUIElement = new UIElement*[m_nUIElements];

	float fPosX = (pApp2D->getWindowWidth() / 2);
	float fPosY = (pApp2D->getWindowHeight() / 2);

	float fWidth, fHeight;
	pFont->getStringSize(UI_PLAY, fWidth, fHeight);

	m_apUIElement[0] = new UIElement(pApp2D, pResMod, ECOLOUR_GREEN, pFont, UI_PLAY, fWidth * 1.1, fHeight * 1.1, fPosX, fPosY);

	pFont->getStringSize(UI_QUIT, fWidth, fHeight);
	m_apUIElement[1] = new UIElement(pApp2D, pResMod, ECOLOUR_RED, pFont, UI_QUIT, fWidth * 1.1, fHeight * 1.1, fPosX, fPosY - 100);

	// Actor Init
	m_apActor = new Actor**[EACTOR_TOTAL];

	for (int i = 0; i < EACTOR_TOTAL; ++i)
	{
		switch (i)
		{
		case EACTOR_CLOUDS:
			m_apActor[i] = new Actor*[m_nActors[i]];
			for (int j = 0; j < m_nActors[i]; ++j)
			{
				m_apActor[i][j] = new Clouds(m_pApp2D, m_pCamOp, pResMod, pTextures, m_pCamOp->GetDevCamPos(), 1.0f - ((float)j / 2), -150.0f * (float)j, 1.0f - (0.5f * (float)j), j);
			}
			break;
		case EACTOR_WAVES:
			m_apActor[i] = new Actor*[m_nActors[i]];
			for (int j = 0; j < m_nActors[i]; ++j)
			{
				m_apActor[i][j] = new Waves(m_pApp2D, m_pCamOp, pResMod, pTextures, m_pCamOp->GetDevCamPos());
			}
			break;
		case EACTOR_ENEMY:
			m_apActor[i] = new Actor*[m_nActors[i]];
			for (int j = 0; j < m_nActors[i]; ++j)
			{
				m_apActor[i][j] = new Enemy(m_pApp2D, m_pCamOp, pResMod, pTextures);
			}
			break;
		case EACTOR_FISH:
			m_apActor[i] = new Actor*[m_nActors[i]];
			for (int j = 0; j < m_nActors[i]; ++j)
			{
				m_apActor[i][j] = new Fish(m_pApp2D, m_pCamOp, pResMod, pTextures);
			}
			break;
		default:
			//ERROR
			printf("ERROR\n");
			printf("MainMenu::Constructor, invalid Actor count\n");
			std::getchar();
		}
	}

	// Enemy Positions
	for (int i = 0; i < m_nActors[EACTOR_ENEMY]; ++i)
	{
		m_apActor[EACTOR_ENEMY][i]->SetStartPos(300 + (300 * i), 400 + (50 * i));
		m_apActor[EACTOR_ENEMY][i]->SetIsDead(false);
	}

	// Fish Positions
	for (int i = 0; i < m_nActors[EACTOR_FISH]; ++i)
	{
		m_apActor[EACTOR_FISH][i]->SetStartPos(300 + (300 * i), 50);
		m_apActor[EACTOR_FISH][i]->SetIsDead(false);
	}
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
MainMenu::~MainMenu()
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
}

//----------------------------------------------------------
// Draw
//----------------------------------------------------------
void MainMenu::Draw()
{
#ifdef DEBUG_MODE
	assert(m_apUIElement);
	assert(m_apActor);
#endif // DEBUG_MODE

	// Draw UI Elements
	for (int i = 0; i < m_nUIElements; ++i)
	{
#ifdef DEBUG_MODE
		assert(m_apUIElement[i]);
#endif // DEBUG_MODE

		m_apUIElement[i]->Draw();
	}

	// Draw Actors
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
bool MainMenu::UpdateUI(ELevel &eNewLevel)
{
#ifdef DEBUG_MODE
	assert(m_apUIElement);
	assert(m_apUIElement[0]);
	assert(m_apUIElement[1]);
#endif // DEBUG_MODE

	// Play
	// IF UI element pressed
	if (m_apUIElement[0]->Update())
	{
		// Set New Level
		eNewLevel = (ELEVEL_LEVEL_01);
		// Level changed
		return true;
	}

	// Quit
	// IF UI element pressed
	if (m_apUIElement[1]->Update())
	{
		// Quit
		m_pApp2D->quit();
	}

	// Level NOT changed
	return false;
}