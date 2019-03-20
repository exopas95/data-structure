#ifndef _APPLICATION_H
#define _APPLICATION_H

#include "MusicType.h"
#include "CHeapBase.h"
#include "CMaxHeap.h"
#include "CMinHeap.h"

#include <iostream>
#include <string>
using namespace std;

/**
*	�������� ������ ���� application Ŭ����.
*	@author	������
*	@date	2018.12.03
*/
class Application
{
public:
	/**
	*	������.
	*/
	Application()
	{
		m_nCurCommand = 0;
	}

	/**
	*	�Ҹ���.
	*/
	~Application()
	{
	}
	
	/**
	*	@brief	���α׷� ����.
	*	@pre	���α׷� ����.
	*	@post	���α׷� ����.
	*/
	void Run();

	/**
	*	@brief	MaxHeap�� MinHeap �� �� �ϳ��� �����ϴ� �Լ�.
	*	@pre	none.
	*	@post	none.
	*/
	void WhatHeap();

	/**
	*	@brief	ȭ�鿡 �޴��� �߰� Ű����� �Է��ϴ� �Լ�.
	*	@pre	none.
	*	@post	none.
	*	@return	�޴��� ��ȯ�Ѵ�.
	*/
	int GetCommand();

	/**
	*	@brief	Heap�� �� ���������� �߰��ϱ� ���� �Լ�.
	*	@pre	Heap�� �ʱ�ȭ�Ǿ���Ѵ�.
	*	@post	Heap�� �� ���������� �߰��Ѵ�.
	*	@return	�� �۵��ϸ� 1�� ��ȯ�ϰ� �ƴϸ� 0�� ��ȯ�Ѵ�.
	*/
	int AddItem();

	/**
	*	@brief	Heap���� ���������� �����ϱ� ���� �Լ�.
	*	@pre	Heap�� ��������� �ȵȴ�.
	*	@post	Heap���� ���������� �����Ѵ�.
	*	@return	�� �۵��ϸ� 1�� ��ȯ�ϰ� �ƴϸ� 0�� ��ȯ�Ѵ�.
	*/
	int DeleteItem();

	/**
	*	@brief	Heap���� ���������� �����ϱ� ���� �Լ�.
	*	@pre	Heap�� ��������� �ȵȴ�.
	*	@post	Heap���� ���������� �����Ѵ�.
	*	@return	�� �۵��ϸ� 1�� ��ȯ�ϰ� �ƴϸ� 0�� ��ȯ�Ѵ�.
	*/
	int ReplaceItem();

	/**
	*	@brief	Heap���� ù��° ���������� �����ϱ� ���� �Լ�.
	*	@pre	Heap�� ��������� �ȵȴ�.
	*	@post	Heap���� ù��° ���������� �����Ѵ�.
	*	@return	�� �۵��ϸ� 1�� ��ȯ�ϰ� �ƴϸ� 0�� ��ȯ�Ѵ�.
	*/
	int DequeueItem();

	/**
	*	@brief	Heap�� �ִ� ���������� ����ϱ� ���� �Լ�.
	*	@pre	none.
	*	@post	Heap�� �ִ� ���������� ��µȴ�.
	*/
	void DisplayItem();

	/**
	*	@brief	Heap���� ���������� �˻��ϱ� ���� �Լ�.
	*	@pre	Heap�� ��������� �ȵȴ�.
	*	@post	Heap���� ���������� �˻��Ѵ�.
	*	@return	�� �۵��ϸ� 1�� ��ȯ�ϰ� �ƴϸ� 0�� ��ȯ�Ѵ�.
	*/
	int SearchItem();

private:
	CHeapBase<MusicType> *m_List;	///< Heap for MusicType.
	int m_nCurCommand;	///< ���� ������ �޴� ��ȣ
};

#endif	// _APPLICATION_H