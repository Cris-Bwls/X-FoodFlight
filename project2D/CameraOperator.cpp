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
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
CameraOperator::~CameraOperator()
{
	delete m_pBarrier;
}

//----------------------------------------------------------
// SetCamPosBounds
//----------------------------------------------------------
void CameraOperator::SetCamPosBounds(float fXmin, float fXmax)
{
	m_fXmin = fXmin;
	m_fXmax = fXmax;
}

//----------------------------------------------------------
// CheckCamPos
//----------------------------------------------------------
void CameraOperator::CheckCamPos()
{
	if (m_pCamPos->fX < m_fXmin)
	{
		m_pCamPos->fX = m_fXmin;
	}
	else if (m_pCamPos->fX> m_fXmax - m_pDevRes->fX)
	{
		m_pCamPos->fX = m_fXmax - m_pDevRes->fX;
	}
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