#include "BaseMain.h"

//Higher
#include "Application2D.h"
#include "Textures.h"

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
//----------------------------------------------------------
BaseMain::BaseMain(Application2D* pApp2D, aie::Font* pFont, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures)
{
	m_pApp2D = pApp2D;
	m_pCamOp = pCamOp;
	m_pResMod = pResMod;
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
	if (m_pPlayer != nullptr)
	{
		m_pPlayer->Update(deltaTime);
	}

	for (int i = 0; i < m_nUIElements; ++i)
	{
		m_apUIElement[i]->Update();
	}

	for (int i = 0; i < EACTOR_TOTAL; ++i)
	{
		for (int j = 0; j < m_nActors[i]; ++i)
		{
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
		for (int j = 0; j < m_nActors[i]; ++i)
		{
			m_apActor[i][j]->Draw();
		}
	}	
}