#include "Enemy.h"

#define ENEMY_SIZE_X 64.0f // X size of texture
#define ENEMY_SIZE_Y 64.0f // Y size of texture
#define ENEMY_RADIUS 45 // Using Pythag 45.25

#define ENEMY_SPEED 2

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Enemy::Enemy(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Textures* pTextures, Player* pPlayer) : Collider(pApp2D, pCamOp, pResMod, pTextures, pPlayer)
{
}

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Enemy::~Enemy()
{
}

void Enemy::Update(float deltaTime)
{

}

void Enemy::Draw()
{

}

