#include "Clouds.h"

// Higher
#include "Application2D.h"
#include "Textures.h"
#include "CameraOperator.h"

// Defines
#define CLOUD1_HEIGHT	204
#define CLOUD1_WIDTH	512

#define CLOUD2_HEIGHT	274
#define CLOUD2_WIDTH	512

#define CLOUD3_HEIGHT	220
#define CLOUD3_WIDTH	512

#define CLOUD4_HEIGHT	360
#define CLOUD4_WIDTH	512


//----------------------------------------------------------
// Constructor
//		Negative heightoffset is closer to the bottom, zero is top of screen
//----------------------------------------------------------
Clouds::Clouds(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Pos* pReferencePos, float fSpeed, float fHeightOffset, float fScale, float fDepth) : Environ(pApp2D, pCamOp, pResMod, pTextures, pReferencePos)
{
	m_pTexture = pTextures->GetTexture(ETEXTURE_CLOUD1);
	m_pTexture1 = pTextures->GetTexture(ETEXTURE_CLOUD2);
	m_pTexture2 = pTextures->GetTexture(ETEXTURE_CLOUD3);
	m_pTexture3 = pTextures->GetTexture(ETEXTURE_CLOUD4);

	m_fSpeed = fSpeed;
	m_fHeight = pCamOp->GetDevRes()->fY + fHeightOffset;
	m_fScale = fScale;
	m_fDepth = 50 + fDepth;

	*m_pStartPos = *pReferencePos;

	m_fPosX[0] = -300.0f;
	m_fPosX[1] = -100.0f;
	m_fPosX[2] = 70.0f;
	m_fPosX[3] = 280.0f;
	m_fPosX[4] = 410.0f;
	m_fPosX[5] = 660.0f;
	m_fPosX[6] = 830.0f;
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
Clouds::~Clouds()
{
}

//----------------------------------------------------------
// Update
//		Updates Position of Cloud Group
//----------------------------------------------------------
void Clouds::Update(float deltaTime)
{
	if (m_pStartPos->fX > m_pCurrentPos->fX)
	{
		m_pCurrentPos->fX = m_pStartPos->fX + m_pCamOp->GetDevRes()->fX;
	}
	else
	{
		m_pCurrentPos->fX -= (100.0f * m_fSpeed * deltaTime);
	}
}

//----------------------------------------------------------
// Draw
//		Draws the cloud group
//----------------------------------------------------------
void Clouds::Draw()
{
	float fPosX = m_pCurrentPos->fX;
	float fDevX = m_pCamOp->GetDevRes()->fX;
	
	m_pRenderer->setUVRect(0, 0, 1, 1);

	// First Group
	m_pRenderer->drawSprite(m_pTexture3,( fPosX + m_fPosX[0] - fDevX) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD4_WIDTH * m_fScale * m_pResMod->fX, CLOUD4_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture2,( fPosX + m_fPosX[1] - fDevX) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD3_WIDTH * m_fScale * m_pResMod->fX, CLOUD3_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture3,( fPosX + m_fPosX[2] - fDevX) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD4_WIDTH * m_fScale * m_pResMod->fX, CLOUD4_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture1,( fPosX + m_fPosX[3] - fDevX) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD2_WIDTH * m_fScale * m_pResMod->fX, CLOUD2_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture, (fPosX + m_fPosX[4] - fDevX) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD1_WIDTH * m_fScale * m_pResMod->fX, CLOUD1_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture2,( fPosX + m_fPosX[5] - fDevX) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD3_WIDTH * m_fScale * m_pResMod->fX, CLOUD3_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture3,( fPosX + m_fPosX[6] - fDevX) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD4_WIDTH * m_fScale * m_pResMod->fX, CLOUD4_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);

	// Second Group
	m_pRenderer->drawSprite(m_pTexture3,( fPosX + m_fPosX[0]) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD4_WIDTH * m_fScale * m_pResMod->fX, CLOUD4_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture2,( fPosX + m_fPosX[1]) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD3_WIDTH * m_fScale * m_pResMod->fX, CLOUD3_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture3,( fPosX + m_fPosX[2]) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD4_WIDTH * m_fScale * m_pResMod->fX, CLOUD4_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture1,( fPosX + m_fPosX[3]) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD2_WIDTH * m_fScale * m_pResMod->fX, CLOUD2_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture, (fPosX + m_fPosX[4]) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD1_WIDTH * m_fScale * m_pResMod->fX, CLOUD1_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture2,( fPosX + m_fPosX[5]) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD3_WIDTH * m_fScale * m_pResMod->fX, CLOUD3_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture3,( fPosX + m_fPosX[6]) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD4_WIDTH * m_fScale * m_pResMod->fX, CLOUD4_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);

	// Third Group
	m_pRenderer->drawSprite(m_pTexture3,( fPosX + m_fPosX[0] + fDevX) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD4_WIDTH * m_fScale * m_pResMod->fX, CLOUD4_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture2,( fPosX + m_fPosX[1] + fDevX) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD3_WIDTH * m_fScale * m_pResMod->fX, CLOUD3_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture3,( fPosX + m_fPosX[2] + fDevX) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD4_WIDTH * m_fScale * m_pResMod->fX, CLOUD4_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture1,( fPosX + m_fPosX[3] + fDevX) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD2_WIDTH * m_fScale * m_pResMod->fX, CLOUD2_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture, (fPosX + m_fPosX[4] + fDevX) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD1_WIDTH * m_fScale * m_pResMod->fX, CLOUD1_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture2,( fPosX + m_fPosX[5] + fDevX) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD3_WIDTH * m_fScale * m_pResMod->fX, CLOUD3_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture3,( fPosX + m_fPosX[6] + fDevX) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD4_WIDTH * m_fScale * m_pResMod->fX, CLOUD4_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);

	// Fourth Group
	m_pRenderer->drawSprite(m_pTexture3,( fPosX + m_fPosX[0] + (2 * fDevX)) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD4_WIDTH * m_fScale * m_pResMod->fX, CLOUD4_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture2,( fPosX + m_fPosX[1] + (2 * fDevX)) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD3_WIDTH * m_fScale * m_pResMod->fX, CLOUD3_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture3,( fPosX + m_fPosX[2] + (2 * fDevX)) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD4_WIDTH * m_fScale * m_pResMod->fX, CLOUD4_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture1,( fPosX + m_fPosX[3] + (2 * fDevX)) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD2_WIDTH * m_fScale * m_pResMod->fX, CLOUD2_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture, (fPosX + m_fPosX[4] + (2 * fDevX)) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD1_WIDTH * m_fScale * m_pResMod->fX, CLOUD1_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture2,( fPosX + m_fPosX[5] + (2 * fDevX)) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD3_WIDTH * m_fScale * m_pResMod->fX, CLOUD3_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
	m_pRenderer->drawSprite(m_pTexture3,( fPosX + m_fPosX[6] + (2 * fDevX)) * m_pResMod->fX, m_fHeight * m_pResMod->fY, CLOUD4_WIDTH * m_fScale * m_pResMod->fX, CLOUD4_HEIGHT * m_fScale * m_pResMod->fY, 0, m_fDepth);
}
