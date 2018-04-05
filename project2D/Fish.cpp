#include "Fish.h"

#define FISH_RADIUS 22 // Using Pythag 22.05
#define FISH_SPEED 2

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Fish::Fish(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Player* pPlayer) : Collider(pApp2D, pCamOp, pResMod, pTextures, pPlayer)
{
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
Fish::~Fish()
{
}


//----------------------------------------------------------
// Update
//----------------------------------------------------------
void Fish::Update(float deltaTime)
{

}

void Fish::Draw()
{

}


