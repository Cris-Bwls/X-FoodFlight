#pragma once

class AnimIdle
{
public:
	AnimIdle();
	~AnimIdle();

	float Update();

private:
	int m_nFrameIterator = 0;
	int m_nAnimIterator = 0;

	float m_fFrame;
};
