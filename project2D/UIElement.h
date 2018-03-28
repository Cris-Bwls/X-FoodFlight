#pragma once


#include "EnumColour.h"
#include "Input.h"
#include "Font.h"

class Application2D;


class UIElement
{
public:
	UIElement(Application2D* pApp2D, EColour eColour, aie::Font* pFont, const char* sText, float fWidth, float fHeight, float fPosX, float fPosY, float fDepth = 0.0f);
	~UIElement();

	void ChangePos(float fPosX, float fPosY, float fOffsetX = 0.0f, float fOffsetY = 0.0f);
	bool Update(aie::Input* input);
	void Draw();

private:
	Application2D*	m_pApp2D; 
	EColour			m_eColour;
	aie::Font*		m_pFont;
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

