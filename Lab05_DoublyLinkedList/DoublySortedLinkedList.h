#ifndef _DOUBLYSORTEDLINKED_LIST_H
#define _DOUBLYSORTEDLINKED_LIST_H

#include "MusicType.h"
#include "DoublyIterator.h"

//#define min MusicType(INT_MIN)
//#define max MusicType(INT_MAX)


template<typename T>
class DoublyIterator;

/**
*	연결리스트에서 쓰이는 NodeType의 구조체
*/
template <typename T>
struct DoublyNodeType
{
	T data; ///< 각 노드의 데이터.
	DoublyNodeType* prev;   ///< 이전 노드의 포인터
	DoublyNodeType* next;	///< 다음 노드의 포인터
};


/**
*	정렬된 더블연결리스트 클래스
*/
template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>;  ///< DoublyIterator와 친구 클래스.
public:
	/**
	*	디폴트 생성자.
	*/
	DoublySortedLinkedList();

	/**
	*	소멸자.
	*/
	~DoublySortedLinkedList();

	/**
	*	@brief	리스트가 비었는지 아닌지 검사한다.
	*	@pre	m_nLength가 값을 가지고 있어야 한다.
	*	@post	비었는지 아닌지를 알려준다.
	*	@return	비어있으면 true, 아니면 false를 반환.
	*/
	bool IsEmpty();

	/**
	*	@brief	리스트가 가득 찼는지 아닌지 검사한다.
	*	@pre	m_nLength가 값을 가지고 있어야 한다.
	*	@post	가득 찼는지 아닌지를 알려준다.
	*	@return	가득 차있으면 true, 아니면 false를 반환.
	*/
	bool IsFull();

	/**
	*	@brief	리스트를 비운다.
	*	@pre	없음.
	*	@post	m_pFirst와 m_pLast를 제외한 모든 데이터를 지운다.
	*/
	void MakeEmpty();

	/**
	*	@brief	리스트의 길이를 반환한다.
	*	@pre	없음.
	*	@post	리스트의 길이를 반환.
	*	@return	m_nLength 리스트의 길이 반환.
	*/
	int GetLength() const;

	/**
	*	@brief	새로운 아이템을 리스트에 추가한다.
	*	@pre	item을 입력받는다.
	*	@post	아이템을 리스트에 추가한다.
	*	@return	같은 아이템이 있으면 0을 반환하고, 입력에 성공하면 1을 반환.
	*/
	int Add(T &item);

	/**
	*	@brief	입력받은 아이템을 리스트에서 삭제한다.
	*	@pre	item을 입력받는다.
	*	@post	입력받은 아이템을 리스트에서 찾아 삭제한다.
	*/
	void Delete(T &item);

	/**
	*	@brief	입력받은 아이템으로 정보를 바꾼다.
	*	@pre	item을 입력받는다.
	*	@post	새로운 정보로 교체된다.
	*/
	void Replace(T &item);

	/**
	*	@brief	입력받은 아이템의 정보와 비교하여 같은 리스트의 아이템을 가져온다.
	*	@pre	item을 입력받는다.
	*	@post	검색된 데이터를 아이템에 넣는다.
	*	@return	일치하는 데이터를 찾으면 1, 그렇지 않으면 0을 반환.
	*/
	T* Get(T& item);

	/**
	*	@brief	입력받은 아이템의 정보와 비교하여 같은 리스트의 아이템을 가져온다.
	*	@pre	item을 입력받는다.
	*	@post	검색된 데이터를 아이템에 넣는다.
	*	@return	일치하는 데이터를 찾으면 1, 그렇지 않으면 0을 반환.
	*/
	T* GetPoint(T& item);

	DoublySortedLinkedList<T>& operator= (const DoublySortedLinkedList<T> &obj)
	{
		int length = obj.GetLength();
		DoublyIterator<T> itor(obj);

		for (int i = 0; i < length; i++)
			Add(itor.GetNextNode()->data);

		return *this;
	}
private:
	DoublyNodeType<T>* m_pFirst;	///< Pointer for pointing a first node.
	DoublyNodeType<T>* m_pLast;
	int m_nLength;	///< Number of node in the list.
};

// 리스트의 맨 처음과 끝이 서로를 가리키게 설정하고 리스트의 길이를 0으로 초기화시켜놓는다.
template <typename T>
DoublySortedLinkedList<T>::DoublySortedLinkedList()
{
	m_pFirst = new DoublyNodeType<T>;
	m_pLast = new DoublyNodeType<T>;

	m_pFirst->next = m_pLast; // 끝과 처음이 서로를 가리키게 초기화.
	m_pFirst->prev = NULL; // 처음.

	m_pLast->next = NULL; // 끝.
	m_pLast->prev = m_pFirst; // 끝과 처음이 서로를 가리키게 초기화.

	m_nLength = 0; // 길이는 0.
}


// Class destructor
template <typename T>
DoublySortedLinkedList<T>::~DoublySortedLinkedList()
{
	delete m_pFirst;
	delete m_pLast;
}


// 리스트가 비었는지 검사한다.
template <typename T>
bool DoublySortedLinkedList<T>::IsEmpty()
{
	if (m_nLength == 0)
		return true;
	else
		return false;
}

// 리스트가 꽉 차있는지 검사한다.
template <typename T>
bool DoublySortedLinkedList<T>::IsFull()
{
	if(m_nLength == 10)
		return true;
	else
		return false;
}

// 리스트를 비운다.
template <typename T>
void DoublySortedLinkedList<T>::MakeEmpty()
{
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
	DoublyNodeType<T> *pItem;
	DoublyIterator<T> itor(*this);

	itor.GetNextNode();
	while (itor.NextNotNull())
	{
		pItem = itor.m_pCurPointer;
		itor.GetNextNode(); // 현재 포인터를 다음으로 이동.
		delete pItem;
	}

	m_pFirst->next = m_pLast;
	m_pFirst->prev = NULL;
	m_pLast->prev = m_pFirst;
	m_pLast->next = NULL;

	return;
}


// Get number of elements in the list.
template <typename T>
int DoublySortedLinkedList<T>::GetLength() const
{
	return m_nLength;
}


// Add music into this list.
template <typename T>
int DoublySortedLinkedList<T>::Add(T &item)
{
	DoublyIterator<T> itor(*this);
	DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
	itor.GetNextNode(); // 다음으로 이동.

	if (IsEmpty()) // 처음 삽입할 때
	{
		pItem->data = item;
		m_pFirst->next = pItem;
		pItem->prev = m_pFirst;
		pItem->next = m_pLast;
		m_pLast->prev = pItem; // 처음과 끝 사이에 삽입.
		m_nLength++;
		return 1;
	}

	while (1)
	{
		if (item < itor.m_pCurPointer->data) // 맞는 자리를 찾는다.
		{
			pItem->data = item;
			pItem->prev = itor.m_pCurPointer->prev;
			pItem->next = itor.m_pCurPointer;
			itor.m_pCurPointer->prev->next = pItem;
			itor.m_pCurPointer->prev = pItem; // 아이템을 삽입.
			m_nLength++;
			return 1;
		}
		else if (itor.m_pCurPointer->next == NULL)
		{
			pItem->data = item;
			pItem->prev = itor.m_pCurPointer->prev;
			pItem->next = itor.m_pCurPointer;
			itor.m_pCurPointer->prev->next = pItem;
			itor.m_pCurPointer->prev = pItem;
			//pItem->next = NULL;
			//itor.m_pCurPointer->next = pItem;
			//m_pLast = pItem;
			m_nLength++;
			return 1;
		}
		else if (item == itor.m_pCurPointer->data) // 같은 정보의 아이템이 있으면
			return 0; // 0을 반환.
		else
			itor.GetNextNode(); // 다음으로 이동.
	}
}


//원하는 위치의 자료를 삭제하는 메소드, 없는 자료는 0을 출력한다.
template <typename T>
void DoublySortedLinkedList<T>::Delete(T& item)
{
	DoublyIterator<T> itor(*this);
	itor.GetNextNode(); // 다음으로 이동.

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item) // 일치하는 데이터를 찾는다.
		{
			DoublyNodeType<T> *pItem = new DoublyNodeType<T>;
			pItem = itor.m_pCurPointer;
			pItem->prev->next = itor.GetNextNode();// itor.m_pCurPointer;
			itor.m_pCurPointer->prev = pItem->prev; // 삭제하는 노드의 앞과 뒤를 서로 이어준다.
			delete pItem; // 삭제.
			return;
		}
		else
			itor.GetNextNode();
	}
	m_nLength--; // 길이 감소.
	return;
}

//해당하는 노드를 변경해주고 없는 경우 0을 출력
template <typename T>
void DoublySortedLinkedList<T>::Replace(T& item)
{
	DoublyIterator<T> itor(*this);
	itor.GetNextNode(); // 다음으로 이동.

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item)
		{
			itor.m_pCurPointer->data = item; // 정보를 교체.
			return;
		}
		else
			itor.GetNextNode();
	}

	return;
}

// 입력받은 아이템과 일치하는 아이템을 리스트에서 찾아 가져온다.
template <typename T>
T* DoublySortedLinkedList<T>::Get(T& item)
{
	DoublyIterator<T> itor(*this);
	itor.GetNextNode();

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item)
		{
			//item = itor.m_pCurPointer->data;
			return &itor.m_pCurPointer->data; // 일치하면 1을 반환.
		}
		else
			itor.GetNextNode(); // 다음으로 이동.
	}

	return NULL; // 일치하지 않으면 0을 반환.
}

// 입력받은 아이템과 일치하는 아이템의 주소를 리스트에서 찾아 가져온다.
template <typename T>
T* DoublySortedLinkedList<T>::GetPoint(T &item)
{
	DoublyIterator<T> itor(*this);
	itor.GetNextNode();

	while (itor.m_pCurPointer != m_pLast)
	{
		if (itor.m_pCurPointer->data == item)
		{
			item = itor.m_pCurPointer->data;
			return &itor.m_pCurPointer->data; // 일치하면 1을 반환.
		}
		else
			itor.GetNextNode(); // 다음으로 이동.
	}

	return 0; // 일치하지 않으면 0을 반환.
}

#endif	// DOUBLYSORTEDLINKED_LIST