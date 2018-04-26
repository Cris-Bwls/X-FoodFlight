#include "MainLevel.h"

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
#include "ColliderController.h"


#define UI_MAIN_MENU "MAIN MENU"

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
MainLevel::MainLevel(Application2D* pApp2D, aie::Font* pFont, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, GameManager* pGame) : BaseMain(pApp2D, pFont, pCamOp, pResMod, pTextures, pGame)
{
	// Reset Camera
	pCamOp->ResetCamPos();

	m_nUIElements = 1;

	m_nActors[EACTOR_CLOUDS] = 2; //2;
	m_nActors[EACTOR_WAVES] = 1; //1;
	m_nActors[EACTOR_ENEMY] = 3; //3;
	m_nActors[EACTOR_FISH] = 0; //3;

								// UI Init
	m_apUIElement = new UIElement*[m_nUIElements];

	float fPosX = (pApp2D->getWindowWidth() - 100);
	float fPosY = (pApp2D->getWindowHeight() - 100);

	float fWidth, fHeight;
	pFont->getStringSize(UI_MAIN_MENU, fWidth, fHeight);

	m_apUIElement[0] = new UIElement(pApp2D, pResMod, ECOLOUR_RED, pFont, UI_MAIN_MENU, fWidth * 1.1, fHeight * 1.1, fPosX, fPosY);

	//DEBUG
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
		}
	}

	// Enemy Positions
	for (int i = 0; i < m_nActors[EACTOR_ENEMY]; ++i)
	{
		m_apActor[EACTOR_ENEMY][i]->SetStartPos(300 + (300 * i), 400 + (50 * i));
	}

	// Fish Positions
	for (int i = 0; i < m_nActors[EACTOR_FISH]; ++i)
	{

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
}

//----------------------------------------------------------
// UpdateUI
//----------------------------------------------------------
bool MainLevel::UpdateUI(ELevel &eNewLevel)
{
	// MainMenu
	if (m_apUIElement[0]->Update())
	{
		eNewLevel = (ELEVEL_MAIN_MENU);
		return true;
	}

	return false;
}