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
#define DEV_RES_X 1280
#define DEV_RES_Y 720

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
	m_pCamOp = new CameraOperator(m_pApp2D);

	float fX, fY;
	bool bTemp;
	pApp2D->GetRes(fX, fY, bTemp);
	SetResMod(fX, fY);

	m_pTextures = new Textures;
	m_pCamOp = new CameraOperator(m_pApp2D);

	m_pFont = new aie::Font(FONT_FILE, FONT_SIZE * m_pResMod->fY);
	m_pLevel = new MainMenu(m_pApp2D, m_pFont, m_pCamOp);
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
//			pRes (Resolution*):
//				pointer to play window resolution
//----------------------------------------------------------
void GameManager::SetResMod(float fX, float fY)
{
	m_pResMod->fX = (fX / DEV_RES_X);
	m_pResMod->fY = (fY / DEV_RES_Y);
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
		m_pLevel = new MainMenu(m_pApp2D, m_pFont, m_pCamOp);
		break;
	case ELEVEL_LEVEL_01:
		delete m_pLevel;
		m_pLevel = new MainMenu(m_pApp2D, m_pFont, m_pCamOp); //CB:DEBUG
		break;
	case ELEVEL_LEVEL_02:
		delete m_pLevel;
		m_pLevel = new MainMenu(m_pApp2D, m_pFont, m_pCamOp); //CB:DEBUG
		break;
	case ELEVEL_LEVEL_ENDLESS:
		delete m_pLevel;
		m_pLevel = new MainMenu(m_pApp2D, m_pFont, m_pCamOp); //CB:DEBUG
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
	m_pLevel->Update(input, deltaTime);
}

//----------------------------------------------------------
// Draw
//----------------------------------------------------------
void GameManager::Draw()
{
	m_pLevel->Draw();
}