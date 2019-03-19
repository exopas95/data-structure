
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
	*	@brief	����Ʈ�� ������ �� �� ���Ҵ��Ѵ�.
	*	@pre	����Ʈ ũ�� = MAXSIZE
	*	@post	����Ʈ ũ�� = MAXSIZE * 2
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
	*	@brief	item�� ã�Ƽ� �ش� item�� ��ȯ�Ѵ�.
	*	@pre	�μ� data�� �ִ� ����� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ������ ã�� item�� data�� �Էµȴ�.
	*	@param	data	ã���� �ϴ� ����� �Էµ� T��. �߰��� item�� ���ϵȴ�.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int Get(T& data);



	T* GetPoint(T data);
	

	/**
	*	@brief	����� ��ġ�ϴ� item�� ã�Ƽ� �ش� item�� �����Ѵ�.
	*	@pre	�μ� data�� �ִ� ����� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ���� �ش� item�� ���ŵȴ�.
	*	@param	data	�����ϰ��� �ϴ� ����� �Էµ� T��. 
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Delete(T data);

	/**
	*	@brief	����� ��ġ�ϴ� list�� item�� ã�Ƽ� �����Ѵ�.
	*	@pre	�μ� data�� �ִ� ����� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	�迭 ���� �Ѱܹ��� item�� ���� ��ġ�ϴ� ���� �Ѱܹ��� item�� �������� ����ȴ�.
	*	@param	data	��ü�ϰ��� �ϴ� ���� ���ڵ带 ���� T��.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Replace(T data);

	/**
	*	@brief	����Ž���� ���� ���� ��ġ�ϴ� list�� item�� ã�Ƽ� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	�迭 ���� �Ѱܹ��� item�� ���� ��ġ�ϴ� ���� ã�Ƽ� data�� ��ȯ�ȴ�.
	*	@param	data	ã���� �ϴ� ����� �Էµ� T��.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	//int GetBinarySearch(T& data);

protected:
	T* m_Array;			///< MusicList array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;
private:
	int MAXSIZE;
	
};

// ����Ʈ�� ����.
template<typename T>
void SortedList<T>::MakeEmpty()
{
	m_Length = 0;
}


// ����Ʈ�� ���̸� ��ȯ�Ѵ�.
template<typename T>
int SortedList<T>::GetLength()
{
	return m_Length;
}


// ����Ʈ�� ���� á���� Ȯ���Ѵ�.
template<typename T>
bool SortedList<T>::IsFull()
{
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


// ����Ʈ�� ���ο� �����͸� �߰��Ѵ�.
template<typename T>
int SortedList<T>::Add(T data)
{
	if (!IsFull())	//�� ���� �ʾ����� �׸��� �߰��Ѵ�.
	{
		if (m_Length == 0)	//Array�� �ƹ� �׸��� ������ ���� �ʿ� ���� �߰����ش�.
		{
			m_Array[m_Length] = data;
			m_Length++;
			return 1;	//�׸��� �߰������Ƿ� 1�� �������ش�.
		}
		else	//Array�� ���� �׸��� ������ ��
		{
			for (int i = 0; i < m_Length; i++)
			{
				if (m_Array[i] < data)	//Array�� �����ϴ� ���� �׸��� ID�� ����ڰ� �߰��ϰ��� �ϴ� �ű� �׸��� ID�� ���Ѵ�.
				{
					//������ �׸��� �� ������(�ű� �׸��� �� Ŭ��)
					if (i == m_Length - 1)	//Array�� �������� �����ߴµ��� �ű� �׸��� �� ũ�� ���� ū ���̹Ƿ� �������� �߰����ش�.
					{
						m_Array[m_Length] = data;
						m_Length++;
						return 1;	//���������� �߰������Ƿ� 1�� �����ϰ� length�� 1 �÷��ش�.
					}
				}
				else if (m_Array[i] > data)
				{
					//������ �׸��� �� Ŭ��(�ű� �׸��� �� ������)
					for (int j = m_Length; j > i; j--)	//������ �׸���� 1ĭ�� �ڷ� �ű��.
					{
						m_Array[j] = m_Array[j - 1];
					}
					m_Array[i] = data;	//�ű� �׸��� Array�� �߰����ش�.
					m_Length++;
					return 1;	//���������� �߰������Ƿ� 1�� �����ϰ� length�� 1 �÷��ش�.
				}
				else
				{
					//������ �׸�� ���� ��
					return -1;	//�ߺ��Ǵ� ���̹Ƿ� �߰��� �� ����. -1�� �������ش�.
				}
			}
		}
	}
	else
	{
		ReSize();
		for (int i = 0; i < m_Length; i++)
		{
			if (m_Array[i] < data)	//Array�� �����ϴ� ���� �׸��� ID�� ����ڰ� �߰��ϰ��� �ϴ� �ű� �׸��� ID�� ���Ѵ�.					
			{
				//������ �׸��� �� ������(�ű� �׸��� �� Ŭ��)
				if (i == m_Length - 1)	//Array�� �������� �����ߴµ��� �ű� �׸��� �� ũ�� ���� ū ���̹Ƿ� �������� �߰����ش�.
				{
					m_Array[m_Length] = data;
					m_Length++;
					return 1;	//���������� �߰������Ƿ� 1�� �����ϰ� length�� 1 �÷��ش�.
				}
			}
			else if (m_Array[i] > data)
			{
				//������ �׸��� �� Ŭ��(�ű� �׸��� �� ������)
				for (int j = m_Length; j > i; j--)	//������ �׸���� 1ĭ�� �ڷ� �ű��.
				{
					m_Array[j] = m_Array[j - 1];
				}
				m_Array[i] = data;	//�ű� �׸��� Array�� �߰����ش�.
				m_Length++;
				return 1;	//���������� �߰������Ƿ� 1�� �����ϰ� length�� 1 �÷��ش�.
			}
			else
			{
				//������ �׸�� ���� ��
				return -1;	//�ߺ��Ǵ� ���̹Ƿ� �߰��� �� ����. -1�� �������ش�.
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
	m_CurPointer++;	// list pointer ����
	if (m_CurPointer == MAXSIZE)	// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}

//���� ��ġ�ϴ� item�� ã�Ƽ� ��ȯ��
template<typename T>
int SortedList<T>::Get(T& data)
{
	for (int i = 0; i < m_Length; i++)
	{
		if (m_Array[i] == data)	//data�� 'm_Array �� �ϳ��� �׸�'�� ID���� ���� ��
		{
			data = m_Array[i];
			return 1;	//data�� �������� �� 1�� �����Ѵ�.
		}
	}
	return 0;	//ã�� ���ϸ� 0�� �����Ѵ�.
}

template <typename T>
T* SortedList<T>::GetPoint(T data)
{
	for (int i = 0; i < m_Length; i++)
	{
		if (m_Array[i] == data)	//data�� 'm_Array �� �ϳ��� �׸�'�� ID���� ���� ��
		{
			//data = m_Array[i];
			return &m_Array[i];	//data�� �������� �� 1�� �����Ѵ�.
		}
	}
	return NULL;	//ã�� ���ϸ� 0�� �����Ѵ�.
}


//���� ��ġ�ϴ� item�� ã�Ƽ� ������
template<typename T>
int SortedList<T>::Delete(T data)
{
	for (int i = 0; i < m_Length; i++)
	{
		if (m_Array[i] == data)	//data�� 'm_Array �� �ϳ��� �׸�'�� ID���� ���� ��
		{
			for (int j = i; j < m_Length - 1; j++)
			{
				m_Array[j] = m_Array[j + 1];
			}
			m_Length--;	//���� �׸��� �ڸ��� ���� �׸��� �����ϰ� �̰��� ������ �׸���� �ݺ��Ѵ�. m_Length�� 1 �ٿ��ش�.
			return 1;	//�׸��� �����ϴµ� ���������Ƿ� 1�� �������ش�.
		}
	}
	return 0;	//�׸��� �����ϴµ� ���������Ƿ� 0�� �������ش�.
}

//����� ��ġ�ϴ� item�� ������ ��ü��Ŵ
template<typename T>
int SortedList<T>::Replace(T data)
{
	T tmp(data);	//�Է¹��� item�� ���

	if (Get(data))	//��ġ�ϴ� �������� ã�� ���
	{
		int curpoint = GetNextItem(data);
		m_Array[curpoint] = tmp;	//�迭���� ���������Ͱ� ����Ű�� ���� ����ߴ� ���������� ��ü��Ŵ
		return 1;	//����(1)�� ����
	}
	return 0;	//���� ��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}

//����� ��ġ�ϴ� item�� ����Ž������ �˻��ؼ� ��ȯ�Ѵ�.
//template<typename T>
//int SortedList<T>::GetBinarySearch(T& data)
//{
//	if (m_Length == 0)	//���� �迭�� ����ٸ�
//		return 0;	//����(0)�� ����
//	int currentPos = m_Length / 2;	//�迭�� �߰����� ����
//	T const item = data;
//	while (1)
//	{
//		switch (m_Array[currentPos].BinaryCompareByName(item))
//		{
//		case EQUAL:	//���� �����۰� �Է� �������� ����� ��ġ�Ѵٸ�
//			data = m_Array[currentPos];	//data�� �߰��� ���� ����
//			cout << "<============I FOUND ITEM !==========>" << endl;
//			data.DisplayRecordOnScreen(); 	//��ġ�ϴ� ata�� ������ ����Ѵ�.
//			cout << "<====================================>" << endl;
//			return 1;
//			break;
//		case GREATER:	//���� �������� ����� �Է� �������� ����� ũ�ٸ�
//			if (currentPos == 0)	//ó�� �迭�� ������ �������
//				return 0;	//����(0)�� ����
//			currentPos /= 2;	//�� ������ �ε����� ���ݷ� �̵�
//			break;
//		case LESS:	//���� �������� ����� �Է� �������� ����� �۴ٸ�
//			if (currentPos == m_Length - 1)	//������ �迭�� ������ ū���
//				return 0;	//����(0)�� ����
//			currentPos = (currentPos + m_Length) / 2;	//�� ū�� �ε����� �������� �̵�
//			break;
//		}
//	}
//	return 0;	//ȣ��� �� ���� ����(WARNING ������)
//}

#endif	// _SORTEDLIST_H