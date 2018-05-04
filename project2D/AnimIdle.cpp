#include "AnimIdle.h"

#include "Debug.h"

#define FRAME_SPEED 15 //number of frames before transition (lower is faster)

#define TOTAL_FRAMES 3 //number of different frames in animation sequence

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
AnimIdle::AnimIdle()
{
}

//----------------------------------------------------------
// Destructor
//----------------------------------------------------------
AnimIdle::~AnimIdle()
{
}

//----------------------------------------------------------
// Update
//		Updates Frame for sprite
//
//			return (float):
//				UV X transform for sprite 
//				(current animation frame)
//----------------------------------------------------------
float AnimIdle::Update()
{
	// IF Frame iterator >= number of frames before transition
	if (m_nFrameIterator >= FRAME_SPEED)
	{
		// Set frame iterator to 0
		m_nFrameIterator = 0;		
	}
	
	// IF Frame Iterator == 0
	if (m_nFrameIterator == 0)
	{
		// increment animation Iterator
		++m_nAnimIterator;

		// IF animation Iterator == number of Frames in animation Sequence
		if (m_nAnimIterator == TOTAL_FRAMES)
		{
			// Set Animation Iterator to 0
			m_nAnimIterator = 0;
		}
	}

	// Choose frame according to Animation Iterator
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
		// Error
		printf("ERROR\n");
		printf("AnimMove::Update, AnimIterator outside bounds\n");
		// Defaults to Frame 0
		m_fFrame = 0;
		break;
	}

	// increment Frame Iterator
	++m_nFrameIterator;

	// Returns chosen Frame
	return m_fFrame;
}