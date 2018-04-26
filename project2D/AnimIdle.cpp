#include "AnimIdle.h"

//DEBUG
#include<iostream>

#define FRAME_SPEED 15 //number of frames before transition (lower is faster)

#define TOTAL_FRAMES 3 //number of different frames in animation sequence

AnimIdle::AnimIdle()
{
}


AnimIdle::~AnimIdle()
{
}

float AnimIdle::Update()
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
		m_fFrame = 4;
		break;
	default:
		m_fFrame = 0;
		break;
	}

	++m_nFrameIterator;

	//DEBUG
	printf("FrameIterator = %i\n", m_nFrameIterator);
	printf("AnimIterator = %i\n", m_nAnimIterator);

	return m_fFrame;
}