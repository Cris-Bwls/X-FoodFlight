#pragma once


#include "EnumColour.h"
#include "StructResolution.h"
#include "StructPos.h"
#include "Input.h"
#include "Font.h"

class Application2D;


class UIElement
{
public:
	UIElement(Application2D* pApp2D, Resolution* pResMod, EColour eColour, aie::Font* pFont, const char* sText, float fWidth, float fHeight, float fPosX, float fPosY, float fDepth = 0.0f);
	~UIElement();

	void ChangePos(float fPosX, float fPosY, float fOffsetX = 0.0f, float fOffsetY = 0.0f);
	bool Update();
	void Draw();

private:
	void Colourizer(EColour eColour);

	Application2D*	m_pApp2D; 
	Resolution*		m_pResMod;
	EColour			m_eColourBox;
	EColour			m_eColourText;
	aie::Font*		m_pFont;
	Pos*			m_pCamPos;

	const char*		m_sText;
	float			m_fWidth;
	float			m_fHeight;
	float			m_fPosX;
	float			m_fPosY;
	float			m_fRotation;
	float			m_fDepth;

	EColour			m_eColourOriginal;
	float			m_fWidthOriginal;
	float			m_fHeightOriginal;
};

