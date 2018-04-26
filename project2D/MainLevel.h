#pragma once
#include "BaseMain.h"

#include "LinkedList.h"
#include "StructPos.h"
#include "EnumActor.h"

#include "Input.h"
#include "Font.h"

class Application2D;
class UIElement;
class Actor;
class Player;
class ColliderController;

class MainLevel :
	public BaseMain
{
public:
	MainLevel(Application2D* pApp2D, aie::Font* pFont, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures);
	virtual ~MainLevel();

private:
	ColliderController * m_pColliderController;
};

