#include "Waves.h"

#include "Application2D.h"
#include "CameraOperator.h"
#include "Textures.h"

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

	// Begin Render
	m_pApp2D->GetRenderer()->begin();

	// Camera Based Pos

	/*m_pApp2D->GetRenderer()->setUVRect(fTimer, sin((fTimer)) / 5, 10, 1);
	m_pApp2D->GetRenderer()->drawSprite(m_pTexture, m_pCamOp->GetDevCamPos()->fX, 32, m_pCamOp->GetDevRes()->fX * 2, 0, 0, 51);

	m_pApp2D->GetRenderer()->setUVRect(fTimer * 0.75f, cos((fTimer / 2)) / 10, 10, 1);
	m_pApp2D->GetRenderer()->drawSprite(m_pTexture, m_pCamOp->GetDevCamPos()->fX, 16, m_pCamOp->GetDevRes()->fX * 2, 0, 0, 50);*/


	// Player Based Pos

	m_pApp2D->GetRenderer()->setUVRect(fTimer, sin((fTimer)) / 5, 10, 1);
	m_pApp2D->GetRenderer()->drawSprite(m_pTexture, m_pCurrentPos->fX, 32, m_pCamOp->GetDevRes()->fX * 2, 0, 0, 51);

	m_pApp2D->GetRenderer()->setUVRect(fTimer * 0.75f, cos((fTimer / 2)) / 10, 10, 1);
	m_pApp2D->GetRenderer()->drawSprite(m_pTexture, m_pCurrentPos->fX, 16, m_pCamOp->GetDevRes()->fX * 2, 0, 0, 50);

	// End Render
	m_pApp2D->GetRenderer()->end();
}