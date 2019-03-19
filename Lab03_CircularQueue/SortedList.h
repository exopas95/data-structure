
#ifndef _SORTEDLIST_H
#define _SORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;


/*
*	array based simple sorted list.
*/
template <typename T>
class SortedList
{
public:
	/**
	*	default constructor.
	*/
	SortedList()
	{
		MAXSIZE = 5;
		m_Array = new T[MAXSIZE];
		m_Length = 0;
		ResetList();
	}

	/**
	*	destructor.
	*/
	~SortedList()	
	{
		
		//delete[] m_Array;
	}

	/**
	*	@brief	리스트의 공간을 두 배 재할당한다.
	*	@pre	리스트 크기 = MAXSIZE
	*	@post	리스트 크기 = MAXSIZE * 2
	*/
	void ReSize() 
	{
		T *copyArray = new T[MAXSIZE * 2];
		memcpy(copyArray, m_Array, MAXSIZE * sizeof(T));
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
	int Add(T data);

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
	int GetNextItem(T& data);

	/**
	*	@brief	item을 찾아서 해당 item을 반환한다.
	*	@pre	인수 data에 있는 곡명이 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에서 찾은 item이 data에 입력된다.
	*	@param	data	찾고자 하는 곡명이 입력된 T값. 발견한 item이 리턴된다.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int Get(T& data);



	T* GetPoint(T data);
	

	/**
	*	@brief	곡명이 일치하는 item을 찾아서 해당 item을 제거한다.
	*	@pre	인수 data에 있는 곡명이 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에 해당 item이 제거된다.
	*	@param	data	제거하고자 하는 곡명이 입력된 T값. 
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Delete(T data);

	/**
	*	@brief	곡명이 일치하는 list내 item을 찾아서 변경한다.
	*	@pre	인수 data에 있는 곡명이 list 내에 존재하는 값이어야 한다.
	*	@post	배열 내에 넘겨받은 item과 곡명과 일치하는 값이 넘겨받은 item의 내용으로 변경된다.
	*	@param	data	교체하고자 하는 곡명와 레코드를 가진 T값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Replace(T data);

	/**
	*	@brief	이진탐색을 통해 곡명과 일치하는 list내 item을 찾아서 반환한다.
	*	@pre	없음.
	*	@post	배열 내에 넘겨받은 item과 곡명과 일치하는 값을 찾아서 data로 반환된다.
	*	@param	data	찾고자 하는 곡명이 입력된 T값.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	//int GetBinarySearch(T& data);

protected:
	T* m_Array;			///< MusicList array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;
private:
	int MAXSIZE;
	
};

// 리스트를 비운다.
template<typename T>
void SortedList<T>::MakeEmpty()
{
	m_Length = 0;
}


// 리스트의 길이를 반환한다.
template<typename T>
int SortedList<T>::GetLength()
{
	return m_Length;
}


// 리스트가 가득 찼는지 확인한다.
template<typename T>
bool SortedList<T>::IsFull()
{
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


// 리스트에 새로운 데이터를 추가한다.
template<typename T>
int SortedList<T>::Add(T data)
{
	if (!IsFull())	//꽉 차지 않았으면 항목을 추가한다.
	{
		if (m_Length == 0)	//Array에 아무 항목이 없으면 비교할 필요 없이 추가해준다.
		{
			m_Array[m_Length] = data;
			m_Length++;
			return 1;	//항목을 추가했으므로 1을 리턴해준다.
		}
		else	//Array에 기존 항목이 존재할 때
		{
			for (int i = 0; i < m_Length; i++)
			{
				if (m_Array[i] < data)	//Array에 존재하는 기존 항목의 ID와 사용자가 추가하고자 하는 신규 항목의 ID를 비교한다.
				{
					//기존의 항목이 더 작을때(신규 항목이 더 클때)
					if (i == m_Length - 1)	//Array의 마지막에 도달했는데도 신규 항목이 더 크면 가장 큰 값이므로 마지막에 추가해준다.
					{
						m_Array[m_Length] = data;
						m_Length++;
						return 1;	//성공적으로 추가했으므로 1을 리턴하고 length를 1 늘려준다.
					}
				}
				else if (m_Array[i] > data)
				{
					//기존의 항목이 더 클때(신규 항목이 더 작을때)
					for (int j = m_Length; j > i; j--)	//기존의 항목들을 1칸씩 뒤로 옮긴다.
					{
						m_Array[j] = m_Array[j - 1];
					}
					m_Array[i] = data;	//신규 항목을 Array에 추가해준다.
					m_Length++;
					return 1;	//성공적으로 추가했으므로 1을 리턴하고 length를 1 늘려준다.
				}
				else
				{
					//기존의 항목과 같을 때
					return -1;	//중복되는 값이므로 추가할 수 없다. -1을 리턴해준다.
				}
			}
		}
	}
	else
	{
		ReSize();
		for (int i = 0; i < m_Length; i++)
		{
			if (m_Array[i] < data)	//Array에 존재하는 기존 항목의 ID와 사용자가 추가하고자 하는 신규 항목의 ID를 비교한다.					
			{
				//기존의 항목이 더 작을때(신규 항목이 더 클때)
				if (i == m_Length - 1)	//Array의 마지막에 도달했는데도 신규 항목이 더 크면 가장 큰 값이므로 마지막에 추가해준다.
				{
					m_Array[m_Length] = data;
					m_Length++;
					return 1;	//성공적으로 추가했으므로 1을 리턴하고 length를 1 늘려준다.
				}
			}
			else if (m_Array[i] > data)
			{
				//기존의 항목이 더 클때(신규 항목이 더 작을때)
				for (int j = m_Length; j > i; j--)	//기존의 항목들을 1칸씩 뒤로 옮긴다.
				{
					m_Array[j] = m_Array[j - 1];
				}
				m_Array[i] = data;	//신규 항목을 Array에 추가해준다.
				m_Length++;
				return 1;	//성공적으로 추가했으므로 1을 리턴하고 length를 1 늘려준다.
			}
			else
			{
				//기존의 항목과 같을 때
				return -1;	//중복되는 값이므로 추가할 수 없다. -1을 리턴해준다.
			}

		}
	}

}


// Initialize list iterator.
template<typename T>
void SortedList<T>::ResetList()
{
	m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
template<typename T>
int SortedList<T>::GetNextItem(T& data)
{
	m_CurPointer++;	// list pointer 증가
	if (m_CurPointer == MAXSIZE)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}

//곡명과 일치하는 item을 찾아서 반환함
template<typename T>
int SortedList<T>::Get(T& data)
{
	for (int i = 0; i < m_Length; i++)
	{
		if (m_Array[i] == data)	//data와 'm_Array 중 하나의 항목'의 ID값이 같을 때
		{
			data = m_Array[i];
			return 1;	//data에 복사해준 뒤 1을 리턴한다.
		}
	}
	return 0;	//찾지 못하면 0을 리턴한다.
}

template <typename T>
T* SortedList<T>::GetPoint(T data)
{
	for (int i = 0; i < m_Length; i++)
	{
		if (m_Array[i] == data)	//data와 'm_Array 중 하나의 항목'의 ID값이 같을 때
		{
			//data = m_Array[i];
			return &m_Array[i];	//data에 복사해준 뒤 1을 리턴한다.
		}
	}
	return NULL;	//찾지 못하면 0을 리턴한다.
}


//곡명과 일치하는 item을 찾아서 제거함
template<typename T>
int SortedList<T>::Delete(T data)
{
	for (int i = 0; i < m_Length; i++)
	{
		if (m_Array[i] == data)	//data와 'm_Array 중 하나의 항목'의 ID값이 같을 때
		{
			for (int j = i; j < m_Length - 1; j++)
			{
				m_Array[j] = m_Array[j + 1];
			}
			m_Length--;	//지울 항목의 자리에 다음 항목을 복사하고 이것을 마지막 항목까지 반복한다. m_Length를 1 줄여준다.
			return 1;	//항목을 삭제하는데 성공했으므로 1을 리턴해준다.
		}
	}
	return 0;	//항목을 삭제하는데 실패했으므로 0을 리턴해준다.
}

//곡명이 일치하는 item의 내용을 교체시킴
template<typename T>
int SortedList<T>::Replace(T data)
{
	T tmp(data);	//입력받은 item을 백업

	if (Get(data))	//일치하는 아이템을 찾은 경우
	{
		int curpoint = GetNextItem(data);
		m_Array[curpoint] = tmp;	//배열에서 현재포인터가 가르키는 것을 백업했던 아이템으로 교체시킴
		return 1;	//성공(1)을 리턴
	}
	return 0;	//곡명과 일치하는 item을 찾지 못한다면 실패(0)을 리턴
}

//곡명이 일치하는 item을 이진탐색으로 검색해서 반환한다.
//template<typename T>
//int SortedList<T>::GetBinarySearch(T& data)
//{
//	if (m_Length == 0)	//만약 배열이 비었다면
//		return 0;	//실패(0)을 리턴
//	int currentPos = m_Length / 2;	//배열의 중간부터 시작
//	T const item = data;
//	while (1)
//	{
//		switch (m_Array[currentPos].BinaryCompareByName(item))
//		{
//		case EQUAL:	//현재 아이템과 입력 아이템의 곡명의 일치한다면
//			data = m_Array[currentPos];	//data에 발견한 값을 리턴
//			cout << "<============I FOUND ITEM !==========>" << endl;
//			data.DisplayRecordOnScreen(); 	//일치하는 ata의 내용을 출력한다.
//			cout << "<====================================>" << endl;
//			return 1;
//			break;
//		case GREATER:	//현재 아이템의 곡명이 입력 아이템의 곡명보다 크다면
//			if (currentPos == 0)	//처음 배열의 값보다 작은경우
//				return 0;	//실패(0)을 리턴
//			currentPos /= 2;	//더 작은쪽 인덱스의 절반로 이동
//			break;
//		case LESS:	//현재 아이템의 곡명이 입력 아이템의 곡명보다 작다면
//			if (currentPos == m_Length - 1)	//마지막 배열의 값보다 큰경우
//				return 0;	//실패(0)을 리턴
//			currentPos = (currentPos + m_Length) / 2;	//더 큰쪽 인덱스의 절반으로 이동
//			break;
//		}
//	}
//	return 0;	//호출될 일 없는 리턴(WARNING 방지용)
//}

#endif	// _SORTEDLIST_H