#pragma once

#include "EnumTexture.h"
#include "EnumLevel.h"
#include "StructResolution.h"

#include "Input.h"
#include "Font.h"

class Application2D;
class Textures;
class CameraOperator;
class BaseMain;


class GameManager
{
public:
	GameManager(Application2D* pApp2D);
	~GameManager();

	void SetResMod();
	void CheckResMod();
	void ChangeLevel();
	void Update(float deltaTime);
	void Draw();

private:
	Application2D*	m_pApp2D;
	Resolution*		m_pDevRes;
	Resolution*		m_pResMod;
	Textures*		m_pTextures;
	CameraOperator* m_pCamOp;
	aie::Font*		m_pFont;
	BaseMain*		m_pLevel;

	ELevel eLevel;
};

