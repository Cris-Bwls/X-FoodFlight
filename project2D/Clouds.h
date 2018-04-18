#pragma once

#include "Environ.h"

class Clouds :
	public Environ
{
public:
	Clouds(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Pos* pReferencePos, float fSpeed = 10.0f, float fHeightOffset = 0.0f);
	~Clouds();

	void Update(float deltaTime);
	void Draw();

private:
	aie::Texture* m_pTexture1;
	aie::Texture* m_pTexture2;
	aie::Texture* m_pTexture3;

	float m_fSpeed;
	float m_fHeight;

	float m_fPosX[4];
};

