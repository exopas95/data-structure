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
	*	@brief	����Ʈ�� ������ �� �� ���Ҵ��Ѵ�.
	*	@pre	����Ʈ ũ�� = MAXSIZE
	*	@post	����Ʈ ũ�� = MAXSIZE * 2
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
	*	@brief	item�� ã�Ƽ� �ش� item�� ��ȯ�Ѵ�.
	*	@pre	�μ� data�� �ִ� ����� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ������ ã�� item�� data�� �Էµȴ�.
	*	@param	data	ã���� �ϴ� ����� �Էµ� Musicype��. �߰��� item�� ���ϵȴ�.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int Get(MusicType& data);

	/**
	*	@brief	����� ��ġ�ϴ� item�� ã�Ƽ� �ش� item�� �����Ѵ�.
	*	@pre	�μ� data�� �ִ� ����� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ���� �ش� item�� ���ŵȴ�.
	*	@param	data	�����ϰ��� �ϴ� ����� �Էµ� MusicType��. 
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Delete(MusicType data);

	/**
	*	@brief	����� ��ġ�ϴ� list�� item�� ã�Ƽ� �����Ѵ�.
	*	@pre	�μ� data�� �ִ� ����� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	�迭 ���� �Ѱܹ��� item�� ���� ��ġ�ϴ� ���� �Ѱܹ��� item�� �������� ����ȴ�.
	*	@param	data	��ü�ϰ��� �ϴ� ���� ���ڵ带 ���� MusicType��.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Replace(MusicType data);

	/**
	*	@brief	����Ž���� ���� ���� ��ġ�ϴ� list�� item�� ã�Ƽ� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	�迭 ���� �Ѱܹ��� item�� ���� ��ġ�ϴ� ���� ã�Ƽ� data�� ��ȯ�ȴ�.
	*	@param	data	ã���� �ϴ� ����� �Էµ� MusicType��.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int GetBinarySearch(MusicType& data);
private:
	int MAXSIZE;
	MusicType* m_Array;			///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};

#endif	// _UNSORTEDLIST_H