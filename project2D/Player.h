#pragma once
#include "Actor.h"

#include "Input.h"


class Player :
	public Actor
{
public:
	Player(Application2D* pApp2D, CameraOperator* pCamOp);
	~Player();

	void Update(aie::Input* input, float deltaTime);

private:
};

