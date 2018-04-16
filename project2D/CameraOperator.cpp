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
	m_pRealCamPos = pApp2D->GetCameraPos();
	
	m_pDevCamPos = new Pos;
	m_pDevCamPos->fX = 0;
	m_pDevCamPos->fY = 0;
	
	m_pBarrier = new Barrier;
	ChangeBarrier();
	//DEBUG
	SetDevCamPosBounds(0, 2150);
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
//----------------------------------------------------------
void CameraOperator::SetDevCamPosBounds(float fXmin, float fXmax)
{
	m_fXmin = fXmin;
	m_fXmax = fXmax - m_pBarrier->fLeft;
}

//----------------------------------------------------------
// CheckCamPos
//----------------------------------------------------------
void CameraOperator::CheckCamPos()
{
	if (m_pDevCamPos->fX < m_fXmin)
	{
		m_pDevCamPos->fX = m_fXmin;
	}
	else if (m_pDevCamPos->fX > m_fXmax)
	{
		m_pDevCamPos->fX = m_fXmax;
	}

	ChangeRealCamPos();
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
// GetDevCamPos
//----------------------------------------------------------
Pos* CameraOperator::GetDevCamPos()
{
	return m_pDevCamPos;
}

//----------------------------------------------------------
// ChangeRealCamPos
//----------------------------------------------------------
void CameraOperator::ChangeRealCamPos()
{
	m_pRealCamPos->fX = m_pDevCamPos->fX * m_pResMod->fX;
	m_pRealCamPos->fY = m_pDevCamPos->fY * m_pResMod->fY;
}

//----------------------------------------------------------
// ChangeBarrier
//----------------------------------------------------------
void CameraOperator::ChangeBarrier()
{
	float fHalfResX = m_pDevRes->fX / 2;
	m_pBarrier->fLeft = m_pDevCamPos->fX + fHalfResX - BARRIER_OFFSET;
	m_pBarrier->fRight = m_pDevCamPos->fX + fHalfResX + BARRIER_OFFSET;
}