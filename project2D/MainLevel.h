#pragma once
#include "BaseMain.h"

#include "LinkedList.h"
#include "StructPos.h"
#include "EnumActor.h"
#include "EnumLevel.h"

#include "Input.h"
#include "Font.h"

class Application2D;
class UIElement;
class Actor;
class Player;
class ColliderPosController;

class MainLevel :
	public BaseMain
{
public:
	MainLevel(Application2D* pApp2D, aie::Font* pFont, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, GameManager* pGame);
	virtual ~MainLevel();

	bool UpdateUI(ELevel &eNewLevel);

protected:
	ColliderPosController*	m_pEnemyPositions;
	ColliderPosController*	m_pFishPositions;
};

