#pragma once

class Application2D;

class CameraOperator
{
public:
	CameraOperator(Application2D* pApp2D);
	~CameraOperator();

private:
	Application2D* m_pApp2D;
};

