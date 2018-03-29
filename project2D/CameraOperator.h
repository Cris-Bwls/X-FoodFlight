#pragma once

#include"StructResolution.h"

class Application2D;

class CameraOperator
{
public:
	CameraOperator(Application2D* pApp2D, Resolution* pResMod);
	~CameraOperator();

	void SetBarrier();

private:
	Application2D* m_pApp2D;
	Resolution* m_pResMod;

	float m_fCameraX;
	float m_fCameraY;

	float m_fResX;
	float m_fResY;

	float m_fBarrierLeft;
	float m_fBarrierRight;

	float m_fBarrierXMax;
	float m_fBarrierXMin;
};

