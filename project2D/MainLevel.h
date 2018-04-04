#pragma once
#include "BaseMain.h"

#include "LinkedList.h"
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
	MainLevel(Application2D* pApp2D, aie::Font* pFont, CameraOperator* pCapOp, Resolution* pResMod);
	virtual ~MainLevel();

private:
	LinkedList<Fish>*	m_pListFish;
	LinkedList<Enemy>*	m_pListEnemy;
};

