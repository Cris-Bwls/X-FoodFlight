#include "BaseMain.h"

//Higher
#include "Application2D.h"

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
BaseMain::BaseMain(Application2D* pApp2D, aie::Font* pFont, CameraOperator* pCamOp)
{
	m_pApp2D = pApp2D;
	m_pCamOp = pCamOp;
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
void BaseMain::Update(aie::Input* input, float deltaTime)
{
	if (m_pPlayer != nullptr)
	{
		m_pPlayer->Update(input, deltaTime);
	}

	for (int i = 0; i < m_nUIElements; ++i)
	{
		m_apUIElement[i]->Update(input);
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