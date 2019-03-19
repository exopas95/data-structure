#include "ArrayList.h"


// Make list empty.
void ArrayList::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
int ArrayList::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
bool ArrayList::IsFull()
{
	if(m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}

// Check if the list is empty.
int ArrayList::IsEmpty()
{
	if (m_Length == 0)
		return 1;
	else
		return -1;
}

// add a new data into list.
int ArrayList::Add(ItemType inData)
{
	if(!IsFull())
	{
		m_Array[m_Length] = inData;
		m_Length++;
	}
	else
		return 0;

	return 1;
}


// Initialize list iterator.
void ArrayList::ResetList()
{
	m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
int ArrayList::GetNextItem(ItemType& data)
{
	m_CurPointer++;	// list pointer increase
	if(m_CurPointer == MAXSIZE)	// end of list, return -1.
		return -1;
	data = m_Array[m_CurPointer];	// copy record from the list pointer

	return m_CurPointer;
}

// Primary key를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
int ArrayList::Get(ItemType& data)
{
	int location = 0;

	if (IsEmpty() == -1)
	{
		while (data.CompareByID(m_Array[location]) != EQUAL)
		{
			if (location > MAXSIZE)
				return -1;
			location++;
		}
		data = m_Array[location];
	}
	else // if list is empty, return -1
		return -1;
	
	return location;
}

// Delete remaining record.
int ArrayList::Delete(ItemType inData)
{
	if (IsEmpty() == -1)
	{
		int location = Get(inData);

			while (location < (MAXSIZE - 1))
			{
				m_Array[location] = m_Array[location + 1];
				location++;
			}
			m_Length--;
	}
	else // if  list is empty return 0.
		return 0;

	return 1;
}

// Replace record.
int ArrayList::Replace(ItemType data)
{
	ItemType item = data;
	if (IsEmpty() == -1)
	{
		m_Array[Get(item)] = data;
	}
	else
		return 0;
	return 1;
}
