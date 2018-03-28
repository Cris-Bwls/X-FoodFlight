#pragma once

#include "Texture.h"
#include "EnumTexture.h"

class Textures
{
public:
	Textures();
	~Textures();
	
	aie::Texture* GetTexture(ETexture eTexture);

private:
	aie::Texture** m_apTexture;
};

