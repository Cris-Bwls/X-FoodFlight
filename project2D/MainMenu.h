#pragma once
#include "BaseMain.h"

#include "EnumLevel.h"

class Application2D;

class MainMenu :
	public BaseMain
{
public:
	MainMenu(Application2D* pApp2D, aie::Font* pFont, CameraOperator* pCapOp, Resolution* pResMod, Textures* pTextures, GameManager* pGame);
	~MainMenu();

	void Draw();

	bool UpdateUI(ELevel &eNewLevel);
};

