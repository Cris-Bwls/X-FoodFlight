#include "Waves.h"

#include "Application2D.h"
#include "CameraOperator.h"
#include "Textures.h"

#define WAVE_HEIGHT 256
#define WAVE_WIDTH 128

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Waves::Waves(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Pos* pReferencePos) : Environ(pApp2D, pCamOp, pResMod, pTextures, pReferencePos)
{
	m_pTexture = pTextures->GetTexture(ETEXTURE_WAVE);

	SetStartPos(0, 0);
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
Waves::~Waves()
{
}

//----------------------------------------------------------
// Draw
//----------------------------------------------------------
void Waves::Draw()
{
	float fTimer;
	m_pApp2D->GetTimer(fTimer);

	// Camera Based Pos

	/*m_pRenderer->setUVRect(fTimer, sin((fTimer)) / 5, 10, 1);
	m_pRenderer->drawSprite(m_pTexture, m_pCamOp->GetDevCamPos()->fX, 32, m_pCamOp->GetDevRes()->fX * 2, 0, 0, 51);

	m_pRenderer->setUVRect(fTimer * 0.75f, cos((fTimer / 2)) / 10, 10, 1);
	m_pRenderer->drawSprite(m_pTexture, m_pCamOp->GetDevCamPos()->fX, 16, m_pCamOp->GetDevRes()->fX * 2, 0, 0, 50);*/


	// Player Based Pos

	float fDevResX = m_pCamOp->GetDevRes()->fX;

	m_pRenderer->setUVRect(fTimer, sin((fTimer)) / 5, 10, 1);
	m_pRenderer->drawSprite(m_pTexture, m_pCurrentPos->fX * m_pResMod->fX, 32 * m_pResMod->fY, fDevResX * 2 * m_pResMod->fX, WAVE_WIDTH * m_pResMod->fY, 0, 51);

	m_pRenderer->setUVRect(fTimer * 0.75f, cos((fTimer / 2)) / 10, 10, 1);
	m_pRenderer->drawSprite(m_pTexture, m_pCurrentPos->fX * m_pResMod->fX, 16 * m_pResMod->fY, fDevResX * 2 * m_pResMod->fX, WAVE_WIDTH * m_pResMod->fY, 0, 50);
}