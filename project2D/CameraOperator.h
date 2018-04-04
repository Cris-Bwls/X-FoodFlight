#pragma once

#include"StructResolution.h"
#include"StructPos.h"
#include"StructBarrier.h"

class Application2D;

class CameraOperator
{
public:
	CameraOperator(Application2D* pApp2D, Resolution* pDevRes, Resolution* pResMod);
	~CameraOperator();

	void UpdateBarrier();
	
	Barrier* GetBarrier();
	Resolution* GetDevRes();
	Pos* GetCamPos();


private:
	Application2D*	m_pApp2D;
	Resolution*		m_pDevRes;
	Resolution*		m_pResMod;
	Pos*			m_pCamPos;

	Barrier* m_pBarrier;

	
};

