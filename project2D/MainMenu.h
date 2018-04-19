#pragma once
#include "BaseMain.h"

class Application2D;

class MainMenu :
	public BaseMain
{
public:
	MainMenu(Application2D* pApp2D, aie::Font* pFont, CameraOperator* pCapOp, Resolution* pResMod, Textures* pTextures);
	~MainMenu();

	void Draw();

	void UpdateUI(float deltaTime);
};

