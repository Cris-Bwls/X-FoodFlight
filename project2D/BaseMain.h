#pragma once

#include "EnumActor.h"
#include "EnumLevel.h"
#include "StructResolution.h"

#include "Input.h"
#include "Font.h"

class Application2D;
class CameraOperator;
class Textures;
class GameManager;
class UIElement;
class Actor;
class Player;

class BaseMain
{
public:
	BaseMain(Application2D* pApp2D, aie::Font* pFont, CameraOperator* pCapOp, Resolution* pResMod, Textures* pTextures, GameManager* pGame);
	virtual ~BaseMain();

	virtual void Update(float deltaTime);
	virtual void Draw();

	virtual bool UpdateUI(ELevel &eNewLevel) = 0;

protected:
	Application2D*	 m_pApp2D;
	CameraOperator*  m_pCamOp;
	Resolution*		 m_pResMod;
	GameManager*	 m_pGame;

	UIElement**		 m_apUIElement;
	Actor***		 m_apActor;
	Player*			 m_pPlayer = nullptr;


	int m_nUIElements = 1;

	int m_nActors[EACTOR_TOTAL];
};
