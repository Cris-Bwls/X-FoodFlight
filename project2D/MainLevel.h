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

class MainLevel :
	public BaseMain
{
public:
	MainLevel(Application2D* pApp2D, aie::Font* pFont, CameraOperator* pCapOp, Resolution* pResMod, Textures* pTextures);
	virtual ~MainLevel();

private:
	LinkedList<Pos*>*	m_pListFish;
	LinkedList<Pos*>*	m_pListEnemy;
};

