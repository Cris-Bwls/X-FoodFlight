#include "MainMenu.h"

//Higher
#include <iostream>
#include "Application2D.h"

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
//----------------------------------------------------------
MainMenu::MainMenu(Application2D* pApp2D, aie::Font* pFont, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures) : BaseMain(pApp2D, pFont, pCamOp, pResMod, pTextures)
{
	m_nUIElements = 2;

	m_nActors[EACTOR_CLOUDS]	= 2; //2;
	m_nActors[EACTOR_WAVES]		= 1; //1;
	m_nActors[EACTOR_ENEMY]		= 0; //3;
	m_nActors[EACTOR_FISH]		= 0; //3;

	// UI Init
	m_apUIElement = new UIElement*[m_nUIElements];

	float fPosX = (pApp2D->getWindowWidth() / 2);
	float fPosY = (pApp2D->getWindowHeight() / 2);

	float fWidth, fHeight;
	pFont->getStringSize(UI_PLAY, fWidth, fHeight);

	m_apUIElement[0] = new UIElement(pApp2D, pResMod, ECOLOUR_GREEN, pFont, UI_PLAY, fWidth * 1.1, fHeight * 1.1, fPosX, fPosY);

	pFont->getStringSize(UI_QUIT, fWidth, fHeight);
	m_apUIElement[1] = new UIElement(pApp2D, pResMod, ECOLOUR_RED, pFont, UI_QUIT, fWidth * 1.1, fHeight * 1.1, fPosX, fPosY - 100);

	//DEBUG
	m_pPlayer = new Player(pApp2D, pCamOp, pResMod, pTextures);

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
				m_apActor[i][j] = new Clouds(m_pApp2D, m_pCamOp, pResMod, pTextures, m_pPlayer->GetCurrentPos(), 1.0f - ((float)j/2), -150.0f * (float)j, 1.0f - (0.5f * (float)j), j);
			}
			break;
		case EACTOR_WAVES:
			m_apActor[i] = new Actor*[m_nActors[i]];
			for (int j = 0; j < m_nActors[i]; ++j)
			{
				m_apActor[i][j] = new Waves(m_pApp2D, m_pCamOp, pResMod, pTextures, m_pPlayer->GetCurrentPos());
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

	delete m_pPlayer;
}

//----------------------------------------------------------
// Draw
//----------------------------------------------------------
void MainMenu::Draw()
{
	//DEBUG
	if (m_pPlayer != nullptr)
	{
		m_pPlayer->Draw();
	}

	for (int i = 0; i < m_nUIElements; ++i)
	{
		m_apUIElement[i]->Draw();
	}

	for (int i = 0; i < EACTOR_TOTAL; ++i)
	{
		for (int j = 0; j < m_nActors[i]; ++j)
		{
			m_apActor[i][j]->Draw();
		}
	}
}

//----------------------------------------------------------
// UpdateUI
//----------------------------------------------------------
void MainMenu::UpdateUI(float deltaTime)
{
	// Play
	m_apUIElement[0]->Update();

	// Quit
	if (m_apUIElement[1]->Update())
	{
		m_pApp2D->quit();
	}
}