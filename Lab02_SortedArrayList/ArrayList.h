#ifndef _SORTEDLIST_H
#define _SORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "MusicType.h"

/**
*	array based simple sorted list.
*/
class ArrayList
{
public:
	/**
	*	default constructor.
	*/
	ArrayList()
	{
		MAXSIZE = 5;
		m_Array = new MusicType[MAXSIZE];
		m_Length = 0;
		ResetList();
	}

	/**
	*	destructor.
	*/
	~ArrayList()	
	{
		delete[] m_Array;
	}

	/**
	*	@brief	리스트의 공간을 두 배 재할당한다.
	*	@pre	리스트 크기 = MAXSIZE
	*	@post	리스트 크기 = MAXSIZE * 2
	*/
	void ReSize() 
	{
		MusicType *copyArray = new MusicType[MAXSIZE * 2];
		memcpy(copyArray, m_Array, MAXSIZE * sizeof(MusicType));
		MAXSIZE = MAXSIZE * 2;
		m_Array = copyArray;
	}

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(MusicType data);

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized. 
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(MusicType& data);

	/**
	*	@brief	item을 찾아서 해당 item을 반환한다.
	*	@pre	인수 data에 있는 곡명이 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에서 찾은 item이 data에 입력된다.
	*	@param	data	찾고자 하는 곡명이 입력된 Musicype값. 발견한 item이 리턴된다.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int Get(MusicType& data);

	/**
	*	@brief	곡명이 일치하는 item을 찾아서 해당 item을 제거한다.
	*	@pre	인수 data에 있는 곡명이 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에 해당 item이 제거된다.
	*	@param	data	제거하고자 하는 곡명이 입력된 MusicType값. 
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Delete(MusicType data);

	/**
	*	@brief	곡명이 일치하는 list내 item을 찾아서 변경한다.
	*	@pre	인수 data에 있는 곡명이 list 내에 존재하는 값이어야 한다.
	*	@post	배열 내에 넘겨받은 item과 곡명과 일치하는 값이 넘겨받은 item의 내용으로 변경된다.
	*	@param	data	교체하고자 하는 곡명와 레코드를 가진 MusicType값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Replace(MusicType data);

	/**
	*	@brief	이진탐색을 통해 곡명과 일치하는 list내 item을 찾아서 반환한다.
	*	@pre	없음.
	*	@post	배열 내에 넘겨받은 item과 곡명과 일치하는 값을 찾아서 data로 반환된다.
	*	@param	data	찾고자 하는 곡명이 입력된 MusicType값.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int GetBinarySearch(MusicType& data);
private:
	int MAXSIZE;
	MusicType* m_Array;			///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};

#endif	// _UNSORTEDLIST_H