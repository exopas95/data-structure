#pragma once
#ifndef _DOUBLYITERATOR_H
#define _DOUBLYITERATOR_H

#include "DoublySortedLinkedList.h"

template<typename T>
struct DoublyNodeType;
template<typename T>
class DoublySortedLinkedList;

/**
*	연결리스트에서 쓰이는 Iterator의 클래스.
*/
template <typename T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;
public:
	/**
	*	디폴트 생성자.
	*/
	DoublyIterator(const DoublySortedLinkedList<T> &list) : m_List(list), m_pCurPointer(list.m_pFirst)
	{}; ///< DoublySortedLinkedList와 친구 클래스.

	/**
	*	@brief	현재 포인터가 가리키는 노드가 NULL인지 확인하는 함수
	*	@return	현재 포인터가 가리키는 노드가 NULL이 아니면 true,맞으면 true;
	*/
	bool NotNull();

	/**
	*	@brief	현재 포인터의 다음을 가리키는 포인터가 NULL인지 확인하는 함수
	*	@pre	현재 포인터가 NULL이면 안된다
	*	@return	현재 포인터의 다음을 가리키는 포인터가 NULL이 아니면 true, NULL이면 false
	*/
	bool NextNotNull();

	/**
	*	@brief	첫 node의 item을 리턴해주는 함수
	*	@return	list의 첫 node의 item을 리턴
	*/
	T First();


	bool Next(T& item);

	/**
	*	@brief	다음 node로 이동하고 아이템을 리턴해 주는 함수
	*	@pre	없음
	*	@post	현재 포인터가 다음 node로 이동하고 그 주소값을 반환해줌
	*	@return	다음 node로 이동하고 해당 node의 주소값을 리턴
	*/
	T* Next();

	/**
	*	@brief	다음 Node의 주소값을 반환해 주는 함수
	*	@pre	없음
	*	@post	없음
	*	@return	다음 Node의 주소값을 반환.
	*/
	DoublyNodeType<T>* GetNextNode();

	/**
	*	@brief	현재 Node를 반환해 주는 함수
	*	@pre	없음
	*	@post	없음
	*	@return	현재 Node를 반환.
	*/
	DoublyNodeType<T> GetCurrentNode();

	/**
	*	@brief	iterator비교를 위한 ==연산자 오버로딩
	*	@return	iterator가 같으면 true, 다르면 false를 반환
	*/
	bool operator==(DoublyIterator<T>& itor);

private:
	const DoublySortedLinkedList<T> &m_List;  // 사용할 리스트의 참조 변수
	DoublyNodeType<T>* m_pCurPointer;		  // iterator의 변수
};


//현재 노드의 값이 NULL인지 아닌지 확인하는 함수
template <typename T>
bool DoublyIterator<T> ::NotNull()
{
	if (m_pCurPointer == NULL)
		return false;
	else
		return true;
}

//다음 노드의 값이 NULL인지 아닌지 확인하는 함수
template <typename T>
bool DoublyIterator<T> ::NextNotNull()
{
	if (m_pCurPointer->next == NULL)
		return false;
	else
		return true;
}

//노드의 가장 첫 번째 값을 리턴
template <typename T>
T DoublyIterator<T> ::First()
{
	return m_List.m_pFirst->data;
}

//다음 노드의 아이템을 리턴
template <typename T>
bool DoublyIterator<T> ::Next(T& item)
{
	m_pCurPointer = m_pCurPointer->next;	//다음으로 포인터를 이동
	if (!NextNotNull())
		return false;
	else {
		item = m_pCurPointer->data;
		return true;
	}
}

//다음 노드의 아이템을 리턴
template <typename T>
T* DoublyIterator<T> ::Next()
{
	m_pCurPointer = m_pCurPointer->next;	//다음으로 포인터를 이동
	if (!NextNotNull())
		return NULL;
	else
		return &m_pCurPointer->data;
}


//다음 node로 이동하고 아이템을 리턴해 주는 함수
template<class T>
DoublyNodeType<T>* DoublyIterator<T>::GetNextNode()
{
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer;
}

//현재 노드의 주소값을 반환하는 함수
template <typename T>
DoublyNodeType<T> DoublyIterator<T> ::GetCurrentNode()
{
	return *m_pCurPointer;
}

//비교연산자 오버로딩
template<class T>
inline bool DoublyIterator<T>::operator==(DoublyIterator<T>& itor)
{
	return itor.m_pCurPointer ==m_pCurPointer;
}

#endif _DOUBLYITERATOR_H