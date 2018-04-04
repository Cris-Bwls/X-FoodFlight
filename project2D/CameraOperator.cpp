#include "CameraOperator.h"

#include "Application2D.h"

#define BARRIER_OFFSET 150.0f

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
CameraOperator::CameraOperator(Application2D* pApp2D, Resolution* pDevRes, Resolution* pResMod)
{
	m_pApp2D = pApp2D;
	m_pDevRes = pDevRes;
	m_pResMod = pResMod;
	m_pCamPos = pApp2D->GetCameraPos();
	
	m_pBarrier = new Barrier;
	m_pBarrier->fXMin = BARRIER_OFFSET;
	m_pBarrier->fXMax = m_pDevRes->fX - BARRIER_OFFSET;

	UpdateBarrier();
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
CameraOperator::~CameraOperator()
{
	delete m_pBarrier;
}



//----------------------------------------------------------
// UpdateBarrier
//----------------------------------------------------------
void CameraOperator::UpdateBarrier()
{

	// IF (left barrier < min allowed)
	if (m_pBarrier->fLeft < m_pBarrier->fXMin)
	{ 
		// set camera pos to min allowed
		m_pCamPos->fX = m_pBarrier->fXMin - BARRIER_OFFSET;
	}
	// ELSE IF (right barrier > max allowed)
	else if (m_pBarrier->fRight > m_pBarrier->fXMax)
	{
		// set camera pos to max allowed
		m_pCamPos->fX = m_pBarrier->fXMax - (m_pDevRes->fX - BARRIER_OFFSET);
	}

	// Left and right barriers are then set
	m_pBarrier->fLeft = (m_pCamPos->fX + BARRIER_OFFSET);
	m_pBarrier->fRight = (m_pCamPos->fX + m_pDevRes->fX - BARRIER_OFFSET);
}

//----------------------------------------------------------
// GetBarrier
//----------------------------------------------------------
Barrier* CameraOperator::GetBarrier()
{
	return m_pBarrier;
}

//----------------------------------------------------------
// GetDevRes
//----------------------------------------------------------
Resolution* CameraOperator::GetDevRes()
{
	return m_pDevRes;
}

//----------------------------------------------------------
// GetCamPos
//----------------------------------------------------------
Pos* CameraOperator::GetCamPos()
{
	return m_pCamPos;
}