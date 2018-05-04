#include "Waves.h"

#include "Debug.h"

#include "Application2D.h"
#include "CameraOperator.h"
#include "Textures.h"

#define WAVE_HEIGHT 256
#define WAVE_WIDTH 128

//----------------------------------------------------------
// Constructor
//
//			pApp2D (Application2D*):
//				pointer to Application2D
//			pCamOp (CameraOperator*):
//				pointer to CameraOperator
//			pResMod (Resolution*):
//				pointer to Resolution
//			pTextures (Textures*):
//				pointer to Textures
//			pReferencePos (Pos*):
//				pointer to Reference Position
//----------------------------------------------------------
Waves::Waves(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Pos* pReferencePos) : Environ(pApp2D, pCamOp, pResMod, pTextures, pReferencePos)
{
#ifdef DEBUG_MODE
	assert(pApp2D);
	assert(pCamOp);
	assert(pResMod);
	assert(pTextures);
	assert(pReferencePos);
#endif // DEBUG_MODE

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
#ifdef DEBUG_MODE
	assert(m_pApp2D);
	assert(m_pCamOp);
	assert(m_pRenderer);
	assert(m_pTexture);
	assert(m_pCurrentPos);
	assert(m_pResMod);
#endif // DEBUG_MODE

	float fTimer;
	m_pApp2D->GetTimer(fTimer);

	float fDevResX = m_pCamOp->GetDevRes()->fX;

	m_pRenderer->setUVRect(fTimer, sin((fTimer)) / 5, 10, 1);
	m_pRenderer->drawSprite(m_pTexture, m_pCurrentPos->fX * m_pResMod->fX, 32 * m_pResMod->fY, fDevResX * 2 * m_pResMod->fX, WAVE_WIDTH * m_pResMod->fY, 0, 51);

	m_pRenderer->setUVRect(fTimer * 0.75f, cos((fTimer / 2)) / 10, 10, 1);
	m_pRenderer->drawSprite(m_pTexture, m_pCurrentPos->fX * m_pResMod->fX, 16 * m_pResMod->fY, fDevResX * 2 * m_pResMod->fX, WAVE_WIDTH * m_pResMod->fY, 0, 50);
}