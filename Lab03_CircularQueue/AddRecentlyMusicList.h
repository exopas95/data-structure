#pragma once

#include "SortedList.h"
#include "SimpleMusicType.h"

template <typename T>
class AddRecentlyMusicList: public SortedList<T>
{
	
public:
	void EnQueue(T& item);
	void DeQueue();
	void ResetQueue();
	void S_GetNextItem();
};



// Adds newItem to the top of the AddRecentlyMusicList.
template <typename T>
void AddRecentlyMusicList<T>::EnQueue(T& newItem)
{
	Add(newItem);
}


// Removes top item from the AddRecentlyMusicList.
template <typename T>
void AddRecentlyMusicList<T>::DeQueue()
{
	return m_Array[m_nLength - 1];
}

template <typename T>
void AddRecentlyMusicList<T>::ResetQueue()
{
	ResetList();
}

template <typename T>
void AddRecentlyMusicList<T>::S_GetNextItem()
{
	GetNextItem();
}