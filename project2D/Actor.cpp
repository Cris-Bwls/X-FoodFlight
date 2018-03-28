#include "Actor.h"

// Higher
#include "Application2D.h"
#include "CameraOperator.h"

// Lower


//----------------------------------------------------------
//----------------------------------------------------------
Actor::Actor(Application2D* pApp2D, CameraOperator* pCamOp)
{
	m_pApp2D = pApp2D;
	m_pCamOp = pCamOp;
}

//----------------------------------------------------------
//----------------------------------------------------------
Actor::~Actor()
{
}

//----------------------------------------------------------
//----------------------------------------------------------
void Actor::SetIsVisible(bool isVisible)
{
	m_bIsVisible = isVisible;
}

//----------------------------------------------------------
//----------------------------------------------------------
void Actor::SetIsDead(bool isDead)
{
	m_bIsDead = isDead;
}

//----------------------------------------------------------
//----------------------------------------------------------
void Actor::Move(float deltaTime)
{
	m_fX = m_fSpeed * deltaTime;
	m_fY = m_fSpeed * deltaTime;
}

//----------------------------------------------------------
//----------------------------------------------------------
void Actor::Update(float deltaTime)
{

}

//----------------------------------------------------------
//----------------------------------------------------------
void Actor::Draw()
{

}

//----------------------------------------------------------
//----------------------------------------------------------
void Actor::GetPos(float &x, float &y)
{

}