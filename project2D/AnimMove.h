#pragma once
class AnimMove
{
public:
	AnimMove();
	~AnimMove();

	float Update();

private:
	int m_nFrameIterator = 0;
	int m_nAnimIterator = 0;

	float m_fFrame;
};

