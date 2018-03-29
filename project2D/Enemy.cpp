#include "Enemy.h"

#define ENEMY_RADIUS 45 // Using Pythag 45.25
#define ENEMY_SPEED 2

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Enemy::Enemy(Application2D* pApp2D, CameraOperator* pCamOp, Resolution* pResMod, Player* pPlayer) : Collider(pApp2D, pCamOp, pResMod, pPlayer)
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
