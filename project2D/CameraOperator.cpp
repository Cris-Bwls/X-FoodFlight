#include "CameraOperator.h"

#include "Application2D.h"

#define BARRIER_OFFSET 150.0f

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
CameraOperator::CameraOperator(Application2D* pApp2D, Resolution* pResMod)
{
	m_pApp2D = pApp2D;
	m_pResMod = pResMod;
	
	SetBarrier();
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
CameraOperator::~CameraOperator()
{
}


//----------------------------------------------------------
// SetBarrier
//----------------------------------------------------------
void CameraOperator::SetBarrier()
{
	m_pApp2D->GetCameraPos(m_fCameraX, m_fCameraY);
	bool bTemp;
	m_pApp2D->GetRes(m_fResX, m_fResY, bTemp);

	m_fBarrierLeft = (m_fCameraX + BARRIER_OFFSET)*m_pResMod->fX;
	m_fBarrierRight = (m_fCameraX + m_fResX - BARRIER_OFFSET)*m_pResMod->fX;
}