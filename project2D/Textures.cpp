#include "Textures.h"

#include <iostream>

Textures::Textures()
{
	m_apTexture = new aie::Texture*[ETEXTURE_TOTAL];

	for (int i = 0; i < ETEXTURE_TOTAL; ++i)
	{
		switch (i)
		{
		case ETEXTURE_BIRD:
			m_apTexture[ETEXTURE_BIRD] = new aie::Texture("./textures/birds_64x64.png");
			break;
		case ETEXTURE_FISH:
			m_apTexture[ETEXTURE_FISH] = new aie::Texture("./textures/OrangeFish_37x24.png");
			break;
		case ETEXTURE_WAVE:
			m_apTexture[ETEXTURE_WAVE] = new aie::Texture("./textures/wave2_256x128.png");
			break;
		case ETEXTURE_CLOUD1:
			m_apTexture[ETEXTURE_CLOUD1] = new aie::Texture("./textures/cloud1_204x512.png");
			break;
		case ETEXTURE_CLOUD2:
			m_apTexture[ETEXTURE_CLOUD2] = new aie::Texture("./textures/cloud2_274x512.png");
			break;
		case ETEXTURE_CLOUD3:
			m_apTexture[ETEXTURE_CLOUD3] = new aie::Texture("./textures/cloud3_220x512.png");
			break;
		case ETEXTURE_CLOUD4:
			m_apTexture[ETEXTURE_CLOUD4] = new aie::Texture("./textures/cloud4_360x512.png");
			break;
		case ETEXTURE_CLIFF:
			m_apTexture[ETEXTURE_CLIFF] = new aie::Texture("./textures/CliffFace1_720x300.png");
			break;
		case ETEXTURE_HEART:
			m_apTexture[ETEXTURE_HEART] = new aie::Texture("./textures/heart_pixel_art_64x64.png");
			break;
		default:
			//ERROR
			printf("ERROR\n");
			printf("Textures::Constructor, Invalid Texture\n");
		}

	}
}


Textures::~Textures()
{
	for (int i = 0; i < ETEXTURE_TOTAL; ++i)
	{
		delete m_apTexture[i];
	}
	delete[] m_apTexture;
}


aie::Texture* Textures::GetTexture(ETexture eTexture)
{
	if (eTexture < ETEXTURE_TOTAL)
	{
		return m_apTexture[eTexture];
	}
	else
	{
		//ERROR
		printf("ERROR\n");
		printf("Textures::GetTexture, Invalid Texture\n");
	}
}