#include "CameraOperator.h"

#include "Debug.h"

#include "Application2D.h"

#define BARRIER_OFFSET 150.0f

//----------------------------------------------------------
// Constructor
//
//			pApp2D (Application2D*)
//				pointer to App2D
//			pDevRes (Resolution*)
//				pointer to Developed Resolution
//			pResMod (Resolution*)
//				pointer to Resolution Modifier
//----------------------------------------------------------
CameraOperator::CameraOperator(Application2D* pApp2D, Resolution* pDevRes, Resolution* pResMod)
{
#ifdef DEBUG_MODE
	assert(pApp2D);
	assert(pDevRes);
	assert(pResMod);
#endif // DEBUG_MODE

	m_pApp2D = pApp2D;
	m_pDevRes = pDevRes;
	m_pResMod = pResMod;

	// 'Real' Cam Pos is adjusted for playing resolution 
	m_pRealCamPos = pApp2D->GetCameraPos();
	
	// Create and Init Camera Pos
	m_pDevCamPos = new Pos;
	m_pDevCamPos->fX = 0;
	m_pDevCamPos->fY = 0;
	
	// Create and Init Barrier
	m_pBarrier = new Barrier;
	ChangeBarrier();
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
CameraOperator::~CameraOperator()
{
	delete m_pBarrier;
	delete m_pDevCamPos;
}

//----------------------------------------------------------
// SetCamBarrierBounds
//		Sets Bounds of Camera
//
//			fXmin (float)
//				Min camera X pos
//			fXmax (float)
//				Max camera X pos
//----------------------------------------------------------
void CameraOperator::SetDevCamPosBounds(float fXmin, float fXmax)
{
#ifdef DEBUG_MODE
	assert(m_pBarrier);
#endif // DEBUG_MODE

	m_fXmin = fXmin;
	m_fXmax = fXmax - m_pBarrier->fLeft;
}

//----------------------------------------------------------
// CheckCamPos
//		Checks Camera Posistion
//----------------------------------------------------------
void CameraOperator::CheckCamPos()
{
#ifdef DEBUG_MODE
	assert(m_pDevCamPos);
#endif // DEBUG_MODE

	// IF Camera X pos < Min Camera X pos
	if (m_pDevCamPos->fX < m_fXmin)
	{
		// Set Camera X pos to the Min x pos
		m_pDevCamPos->fX = m_fXmin;
	}
	// ELSE IF Camera X pos > MAX Camera X pos
	else if (m_pDevCamPos->fX > m_fXmax)
	{
		// Set Camera X pos to the Max x pos
		m_pDevCamPos->fX = m_fXmax;
	}

	// Change the 'real' camera position
	ChangeRealCamPos();
}

//----------------------------------------------------------
// GetBarrier
//		Gets Barrier
//
//			return (Barrier*):
//				Camera Barrier
//----------------------------------------------------------
Barrier* CameraOperator::GetBarrier()
{
#ifdef DEBUG_MODE
	assert(m_pBarrier);
#endif // DEBUG_MODE

	return m_pBarrier;
}

//----------------------------------------------------------
// GetDevRes
//		Gets Developed Resolution
//
//			return (Resolution*)
//				Developed Resolution
//----------------------------------------------------------
Resolution* CameraOperator::GetDevRes()
{
#ifdef DEBUG_MODE
	assert(m_pDevRes);
#endif // DEBUG_MODE

	return m_pDevRes;
}

//----------------------------------------------------------
// GetDevCamPos
//		Gets Camera Posistion for developed resolution
//
//			return (Pos*)
//				Position of Camera for developed resolution
//----------------------------------------------------------
Pos* CameraOperator::GetDevCamPos()
{
#ifdef DEBUG_MODE
	assert(m_pDevCamPos);
#endif // DEBUG_MODE

	return m_pDevCamPos;
}

//----------------------------------------------------------
// ChangeRealCamPos
//		Changes the 'real' camera position according to the
//		'developed' camera position and the difference in
//		resolution between the two
//----------------------------------------------------------
void CameraOperator::ChangeRealCamPos()
{
#ifdef DEBUG_MODE
	assert(m_pRealCamPos);
	assert(m_pDevCamPos);
	assert(m_pResMod);
#endif // DEBUG_MODE

	m_pRealCamPos->fX = m_pDevCamPos->fX * m_pResMod->fX;
	m_pRealCamPos->fY = m_pDevCamPos->fY * m_pResMod->fY;
}

//----------------------------------------------------------
// ChangeBarrier
//		Changes the barrier positions according to the
//		'Developed' Camera Pos
//----------------------------------------------------------
void CameraOperator::ChangeBarrier()
{
#ifdef DEBUG_MODE
	assert(m_pBarrier);
	assert(m_pDevCamPos);
#endif // DEBUG_MODE

	float fHalfResX = m_pDevRes->fX / 2;
	m_pBarrier->fLeft = m_pDevCamPos->fX + fHalfResX - BARRIER_OFFSET;
	m_pBarrier->fRight = m_pDevCamPos->fX + fHalfResX + BARRIER_OFFSET;
}

//----------------------------------------------------------
// ResetCamPos
//		Resets the 'developed' and 'real' camera positions to '0'
//----------------------------------------------------------
void CameraOperator::ResetCamPos()
{
#ifdef DEBUG_MODE
	assert(m_pDevCamPos);
#endif // DEBUG_MODE

	m_pDevCamPos->fX = 0.0f;
	m_pDevCamPos->fY = 0.0f;

	ChangeRealCamPos();
}