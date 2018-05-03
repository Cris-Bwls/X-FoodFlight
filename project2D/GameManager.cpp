#include "GameManager.h"
#include <iostream>

// Higher
#include "Application2D.h"

// Lower
#include "Textures.h"

#include "CameraOperator.h"

#include "BaseMain.h"
#include "MainMenu.h"

#include "MainLevel.h"
#include "Level01.h"

// Developed Resolution
#define DEV_RES_X 1280.0f
#define DEV_RES_Y 720.0f

// Font
#define FONT_FILE "./font/origa___.ttf"
#define FONT_SIZE 32

//----------------------------------------------------------
// Constructor
//		
//			pApp2D (Application2D*):
//				pointer to Application2D
//----------------------------------------------------------
GameManager::GameManager(Application2D* pApp2D)
{
	m_pApp2D = pApp2D;

	m_pDevRes = new Resolution;
	m_pDevRes->fX = DEV_RES_X;
	m_pDevRes->fY = DEV_RES_Y;

	m_pResMod = new Resolution;
	SetResMod();


	m_pCamOp = new CameraOperator(m_pApp2D, m_pDevRes, m_pResMod);

	m_pTextures = new Textures;

	m_pFont = new aie::Font(FONT_FILE, FONT_SIZE * m_pResMod->fY);
	m_pLevel = new MainMenu(m_pApp2D, m_pFont, m_pCamOp, m_pResMod, m_pTextures, this);
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
GameManager::~GameManager()
{
	delete m_pLevel;
	delete m_pFont;
	delete m_pTextures;
	delete m_pCamOp;
	delete m_pResMod;
	delete m_pDevRes;
}

//----------------------------------------------------------
// SetResMod
//		Sets the Resolution ratio modifier
//		
//		ResMod = (Play window resolution) / (developed resolution)
//
//----------------------------------------------------------
void GameManager::SetResMod()
{
	// Set Var
	m_pResMod->fX = ((float)m_pApp2D->getWindowWidth() / DEV_RES_X);
	m_pResMod->fY = ((float)m_pApp2D->getWindowHeight() / DEV_RES_Y);
}

//----------------------------------------------------------
// CheckResMod
//		Check Resolution Mod
//----------------------------------------------------------
void GameManager::CheckResMod()
{
	// Setup Var
	float fX = m_pResMod->fX;
	float fY = m_pResMod->fY;

	// Reset ResMod incase window size has changed
	SetResMod();

	// IF ResMod has changed
	if (fX != m_pResMod->fX || fY != m_pResMod->fY)
	{
		// Recreate font with new size
		delete m_pFont;
		m_pFont = new aie::Font(FONT_FILE, FONT_SIZE * m_pResMod->fY);
	}
}

//----------------------------------------------------------
// ChangeLevel
//		Change current Level
//----------------------------------------------------------
void GameManager::ChangeLevel()
{
	switch (m_eLevel)
	{
	case ELEVEL_MAIN_MENU:
		delete m_pLevel;
		m_pLevel = new MainMenu(m_pApp2D, m_pFont, m_pCamOp, m_pResMod, m_pTextures, this);
		break;
	case ELEVEL_LEVEL_01:
		delete m_pLevel;	
		m_pLevel = new Level01(m_pApp2D, m_pFont, m_pCamOp, m_pResMod, m_pTextures, this);
		break;
	case ELEVEL_LEVEL_02:
		delete m_pLevel;
		m_pLevel = new MainMenu(m_pApp2D, m_pFont, m_pCamOp, m_pResMod, m_pTextures, this); //CB:DEBUG
		break;
	case ELEVEL_LEVEL_ENDLESS:
		delete m_pLevel;
		m_pLevel = new MainMenu(m_pApp2D, m_pFont, m_pCamOp, m_pResMod, m_pTextures, this); //CB:DEBUG
		break;
	default:
		//ERROR
		printf("ERROR\n");
		printf("GameManager::ChangeLevel, Invalid Level\n");
	}
}

//----------------------------------------------------------
// Update
//
//			deltaTime (float):
//				change in time between update calls
//----------------------------------------------------------
void GameManager::Update(float deltaTime)
{
	// Check the Resolution Modifier
	CheckResMod();

	// Update the level
	m_pLevel->Update(deltaTime);
	
	// If the UI is clicked to change the level
	if (m_pLevel->UpdateUI(m_eLevel))
	{
		// Change the level
		ChangeLevel();
		// Perform Update again
		Update(deltaTime);
	}
}

//----------------------------------------------------------
// Draw
//----------------------------------------------------------
void GameManager::Draw()
{
	// Call Levels Draw Func
	m_pLevel->Draw();
}