#include "AnimMove.h"

#define FRAME_SPEED 15 //number of frames before transition (lower is faster)

#define TOTAL_FRAMES 5 //number of different frames in animation sequence

AnimMove::AnimMove()
{
}


AnimMove::~AnimMove()
{
}

float AnimMove::Update()
{
	if (m_nFrameIterator >= FRAME_SPEED)
	{
		m_nFrameIterator = 0;
	}

	if (m_nFrameIterator == 0)
	{
		++m_nAnimIterator;

		if (m_nAnimIterator == TOTAL_FRAMES)
		{
			m_nAnimIterator = 0;
		}
	}

	switch (m_nAnimIterator)
	{
	case 0:
		m_fFrame = 0;
		break;
	case 1:
		m_fFrame = 1;
		break;
	case 2:
		m_fFrame = 2;
		break;
	case 3:
		m_fFrame = 3;
		break;
	case 4:
		m_fFrame = 4;
		break;
	default:
		//ERROR
		m_fFrame = 1;
		break;
	}

	++m_nFrameIterator;

	return m_fFrame;
}