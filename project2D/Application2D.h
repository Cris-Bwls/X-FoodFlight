#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "gl_core_4_4.h"

#include "StructResolution.h"
#include "StructPos.h"

class GameManager;

class Application2D : public aie::Application 
{
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	void SetRes();
	void SetCameraPos(float fX, float fY);
	void SetCameraPos(Pos* pCamPos);

	aie::Renderer2D* GetRenderer();
	void GetRes(float &fX, float &fY, bool &bIsFullscreen);
	void GetCameraPos(float &fx, float &fY);
	Pos* GetCameraPos();
	void GetTimer(float &fTimer);

protected:
	Resolution*			m_pRes;

	Pos*				m_pCamPos;
	aie::Renderer2D*	m_pRenderer2D;
	GameManager*		m_pGame;

	float m_timer;
};