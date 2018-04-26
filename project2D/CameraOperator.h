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
	
	void SetDevCamPosBounds(float fXmin, float fXmax);
	void CheckCamPos();
	
	Resolution* GetDevRes();
	Barrier* GetBarrier();
	Pos* GetDevCamPos();

	void ChangeRealCamPos();
	void ChangeBarrier();

	void ResetCamPos();

private:
	Application2D*	m_pApp2D;
	Resolution*		m_pDevRes;
	Resolution*		m_pResMod;
	Pos*			m_pRealCamPos;

	Pos*	 m_pDevCamPos;
	Barrier* m_pBarrier;

	float m_fXmin;
	float m_fXmax;	
};

