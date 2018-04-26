#pragma once
#include "MainLevel.h"

#include "EnumActor.h"

#include "Input.h"
#include "Font.h"

class Application2D;
class UIElement;
class Actor;
class Player;

class Level01 :
	public MainLevel
{
public:
	Level01(Application2D* pApp2D, aie::Font* pFont, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures);
	~Level01();
};

