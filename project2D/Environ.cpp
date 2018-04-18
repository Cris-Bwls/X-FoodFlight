#include "Environ.h"

#include "CameraOperator.h"

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Environ::Environ(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Pos* pReferencePos) : Actor(pApp2D, pCamOp, pResMod, pTextures)
{
	m_pReferencePos = pReferencePos;
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
Environ::~Environ()
{
}

//----------------------------------------------------------
// Update
//----------------------------------------------------------
void Environ::Update(float deltaTime)
{
	SetPos();
}

//----------------------------------------------------------
// SetPos
//----------------------------------------------------------
void Environ::SetPos()
{
	m_pCurrentPos->fX = m_pReferencePos->fX;
}
