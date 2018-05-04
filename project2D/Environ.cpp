#include "Environ.h"

#include "Debug.h"

#include "CameraOperator.h"

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
Environ::Environ(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Pos* pReferencePos) : Actor(pApp2D, pCamOp, pResMod, pTextures)
{
#ifdef DEBUG_MODE
	assert(pApp2D);
	assert(pCamOp);
	assert(pResMod);
	assert(pTextures);
	assert(pReferencePos);
#endif // DEBUG_MODE

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
//		Sets Current Position to Reference Position
//----------------------------------------------------------
void Environ::SetPos()
{
#ifdef DEBUG_MODE
	assert(m_pCurrentPos);
	assert(m_pReferencePos);
#endif // DEBUG_MODE

	m_pCurrentPos->fX = m_pReferencePos->fX;
}
