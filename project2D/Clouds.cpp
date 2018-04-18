#include "Clouds.h"

// Higher
#include "Application2D.h"
#include "Textures.h"
#include "CameraOperator.h"

// Lower

//----------------------------------------------------------
// Constructor
//		Negative heightoffset is closer to the bottom, zero is top of screen
//----------------------------------------------------------
Clouds::Clouds(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Pos* pReferencePos, float fSpeed, float fHeightOffset) : Environ(pApp2D, pCamOp, pResMod, pTextures, pReferencePos)
{
	m_pTexture = pTextures->GetTexture(ETEXTURE_CLOUD1);
	m_pTexture1 = pTextures->GetTexture(ETEXTURE_CLOUD2);
	m_pTexture2 = pTextures->GetTexture(ETEXTURE_CLOUD3);
	m_pTexture3 = pTextures->GetTexture(ETEXTURE_CLOUD4);

	m_fSpeed = fSpeed;
	m_fHeight = pCamOp->GetDevRes()->fY + fHeightOffset;
	SetStartPos(0, m_fHeight);

	m_fPosX[0] = -350.0f;
	m_fPosX[1] = 000.0f;
	m_fPosX[2] = 460.0f;
	m_fPosX[3] = 780.0f;
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
Clouds::~Clouds()
{
}

//----------------------------------------------------------
// Update
//----------------------------------------------------------
void Clouds::Update(float deltaTime)
{
	SetPos();
	m_pCurrentPos->fX - m_pCamOp->GetDevRes()->fX;

}

//----------------------------------------------------------
// Draw
//----------------------------------------------------------
void Clouds::Draw()
{
	// Begin Render
	m_pApp2D->GetRenderer()->begin();

	m_pApp2D->GetRenderer()->setUVRect(0, 0, 1, 1);
	m_pApp2D->GetRenderer()->drawSprite(m_pTexture, m_pCurrentPos->fX + m_fPosX[0], m_fHeight, 0, 0, 0, 50);
	m_pApp2D->GetRenderer()->drawSprite(m_pTexture1, m_pCurrentPos->fX + m_fPosX[1], m_fHeight, 0, 0, 0, 51);
	m_pApp2D->GetRenderer()->drawSprite(m_pTexture2, m_pCurrentPos->fX + m_fPosX[2], m_fHeight, 0, 0, 0, 50);
	m_pApp2D->GetRenderer()->drawSprite(m_pTexture3, m_pCurrentPos->fX + m_fPosX[3], m_fHeight, 0, 0, 0, 51);

	// End Render
	m_pApp2D->GetRenderer()->end();
}
