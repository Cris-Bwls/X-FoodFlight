#pragma once

#include"StructResolution.h"
#include"StructPos.h"

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
	Pos* m_pDevRes;
	Pos* m_pCameraPos;

	float m_fCameraX;
	float m_fCameraY;

	float m_fResX = 1280;
	float m_fResY = 720;

	float m_fBarrierLeft;
	float m_fBarrierRight;

	float m_fBarrierXMax;
	float m_fBarrierXMin;
};

