#include "GameManager.h"
#include <iostream>

// Higher
#include "Application2D.h"

// Lower
#include "Textures.h"

#include "CameraOperator.h"

#include "BaseMain.h"
#include "MainMenu.h"

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

	m_pResMod = new Resolution;
	m_pCamOp = new CameraOperator(m_pApp2D, m_pResMod);

	SetResMod();

	m_pTextures = new Textures;

	m_pFont = new aie::Font(FONT_FILE, FONT_SIZE * m_pResMod->fY);
	m_pLevel = new MainMenu(m_pApp2D, m_pFont, m_pCamOp, m_pResMod);
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
GameManager::~GameManager()
{
	delete m_pLevel;
	delete m_pTextures;
	delete m_pResMod;
	delete m_pCamOp;
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
	m_pResMod->fX = ((float)m_pApp2D->getWindowWidth() / DEV_RES_X);
	m_pResMod->fY = ((float)m_pApp2D->getWindowHeight() / DEV_RES_Y);
}

//----------------------------------------------------------
// CheckResMod
//		Check Resolution Mod
//----------------------------------------------------------
void GameManager::CheckResMod()
{
	float fX = m_pResMod->fX;
	float fY = m_pResMod->fY;

	SetResMod();

	if (fX != m_pResMod->fX || fY != m_pResMod->fY)
	{
		delete m_pFont;
		m_pFont = new aie::Font(FONT_FILE, FONT_SIZE * m_pResMod->fY);
	}
}

//----------------------------------------------------------
// ChangeLevel
//----------------------------------------------------------
void GameManager::ChangeLevel()
{
	switch (eLevel)
	{
	case ELEVEL_MAIN_MENU:
		delete m_pLevel;
		m_pLevel = new MainMenu(m_pApp2D, m_pFont, m_pCamOp, m_pResMod);
		break;
	case ELEVEL_LEVEL_01:
		delete m_pLevel;
		m_pLevel = new MainMenu(m_pApp2D, m_pFont, m_pCamOp, m_pResMod); //CB:DEBUG
		break;
	case ELEVEL_LEVEL_02:
		delete m_pLevel;
		m_pLevel = new MainMenu(m_pApp2D, m_pFont, m_pCamOp, m_pResMod); //CB:DEBUG
		break;
	case ELEVEL_LEVEL_ENDLESS:
		delete m_pLevel;
		m_pLevel = new MainMenu(m_pApp2D, m_pFont, m_pCamOp, m_pResMod); //CB:DEBUG
		break;
	default:
		//ERROR
		printf("ERROR\n");
		printf("GameManager::ChangeLevel, Invalid Level\n");
	}
}

//----------------------------------------------------------
// Update
//----------------------------------------------------------
void GameManager::Update(aie::Input* input, float deltaTime)
{
	CheckResMod();
	m_pLevel->Update(input, deltaTime);
}

//----------------------------------------------------------
// Draw
//----------------------------------------------------------
void GameManager::Draw()
{
	m_pLevel->Draw();
}