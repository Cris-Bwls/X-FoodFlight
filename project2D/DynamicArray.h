#pragma once

#include <memory.h>

template<typename T>
class DynamicArray
{
public:
	//--------------------------------------------------
	// Constructor
	//
	//			initSize (int):
	//				determines inital size of array
	//--------------------------------------------------
	DynamicArray(int initSize = 1)
	{
		m_pData = new T[initSize];
		m_nCapacity = initSize;
		m_nUsed = 0;
	}

	//--------------------------------------------------
	// Destructor
	//--------------------------------------------------
	~DynamicArray()
	{
		delete m_pData;
	}

	//--------------------------------------------------
	// PushBack
	//		Adds data to end of array
	//		
	//			data (T):
	//				data to be added
	//--------------------------------------------------
	void PushBack(T data)
	{
		if (m_nUsed >= m_nCapacity - 1)
		{
			Resize();
		}
		m_pData[m_nUsed] = data;
		++m_nUsed;
	}

	//--------------------------------------------------
	// PushFront
	//		Adds data to end of array
	//		
	//			data (T):
	//				data to be added
	//--------------------------------------------------
	void PushFront(T data)
	{
		PushPoint(data, 0);
	}

	//--------------------------------------------------
	// PushPoint
	//		Adds data at point in array
	//			data (T):
	//				data to be added
	//			point (int):
	//				point to add data
	//--------------------------------------------------
	void PushPoint(T data, int point)
	{
		if (m_nUsed >= m_nCapacity - 1)
		{
			Resize();
		}
		memcpy(&m_pData[point + 1], &m_pData[point], sizeof(T) * (m_nUsed - point));
		m_pData[point] = data;
		++m_nUsed;
	}

	//--------------------------------------------------
	// PopBack
	//		Deletes data at end of array
	//--------------------------------------------------
	T PopBack()
	{
		T data = m_pData[m_nUsed];
		m_nUsed--;
		return data;
	}

	//--------------------------------------------------
	// PopPoint
	//		Deletes data at point in array
	//
	//			point (int):
	//				point in array
	//			isOrdered (bool):
	//				Determines if array should keep its order
	//--------------------------------------------------
	T PopPoint(int point, bool isOrdered = false)
	{
		T data = m_pData[point];
		if (!isOrdered)
		{
			m_pData[point] = m_pData[m_nUsed - 1];
			m_nUsed--;
		}
		else
		{
			memcpy(&m_pData[point], &m_pData[point + 1], sizeof(T) * (m_nUsed - (point + 1)));
			m_nUsed--;
		}
		return data;
	}

	//--------------------------------------------------
	// Size
	//
	//		return (int):
	//			Size of Array	
	//--------------------------------------------------
	int Size()
	{
		return m_nUsed;
	}

	//--------------------------------------------------
	// [] Operator Overload
	//
	//		index (int):
	//			position in array
	//--------------------------------------------------
	T& operator[] (int index)
	{
		return m_pData[index];
	}

private:
	//--------------------------------------------------
	// Resize
	//		Private Resize function
	//		Grows array
	//--------------------------------------------------
	void Resize()
	{
		m_nCapacity = (m_nCapacity * 1.5) + 1;
		T* pTemp = new T[m_nCapacity];
		memcpy(pTemp, m_pData, sizeof(T)*m_nUsed);
		delete[] m_pData;
		m_pData = pTemp;
	}

	//--------------------------------------------------
	// Variables
	//--------------------------------------------------
	T* m_pData;
	int m_nCapacity;
	int m_nUsed;
};