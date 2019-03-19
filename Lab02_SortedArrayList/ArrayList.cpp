#include "ArrayList.h"


// 리스트를 비운다.
void ArrayList::MakeEmpty()
{
	m_Length = 0;
}


// 리스트의 길이를 반환한다.
int ArrayList::GetLength()
{
	return m_Length;
}


// 리스트가 가득 찼는지 확인한다.
bool ArrayList::IsFull()
{
	if(m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


// 리스트에 새로운 데이터를 추가한다.
int ArrayList::Add(MusicType inData)
{
	if (!IsFull())
	{
		MusicType CurItem;
		ResetList();
		GetNextItem(CurItem);

		while (m_CurPointer <= m_Length) //처음부터 끝까지
		{
			if (CurItem.CompareByName(inData) == GREATER || m_CurPointer == m_Length)	//만약 CurItem>inData일경우 혹은 배열의 마지막이라서 비교대상이 없는경우
			{
				for (int i = m_Length; i > m_CurPointer; i--)	//맨뒤에서 부터 하나씩 땡긴다.
					m_Array[i] = m_Array[i - 1];	//배열 밀기
				m_Array[m_CurPointer] = inData;	//배열 밀은 후 현재 포인터에 아이템 넣는다.
				m_Length++;	//개수 증가
				break;
			}
			GetNextItem(CurItem);	//다음아이템으로
		}
		
	}
	else
	{
		ReSize();
		MusicType CurItem;
		ResetList();
		GetNextItem(CurItem);

		while (m_CurPointer <= m_Length) //처음부터 끝까지
		{
			if (CurItem.CompareByName(inData) == GREATER || m_CurPointer == m_Length)	//만약 CurItem>inData일경우 혹은 배열의 마지막이라서 비교대상이 없는경우
			{
				for (int i = m_Length; i > m_CurPointer; i--)	//맨뒤에서 부터 하나씩 땡긴다.
					m_Array[i] = m_Array[i - 1];	//배열 밀기
				m_Array[m_CurPointer] = inData;	//배열 밀은 후 현재 포인터에 아이템 넣는다.
				m_Length++;	//개수 증가
				break;
			}
			GetNextItem(CurItem);	//다음아이템으로
		}
	}
	return 1;
}


// Initialize list iterator.
void ArrayList::ResetList()
{
	m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
int ArrayList::GetNextItem(MusicType& data)
{
	m_CurPointer++;	// list pointer 증가
	if(m_CurPointer == MAXSIZE)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}

//곡명과 일치하는 item을 찾아서 반환함
int ArrayList::Get(MusicType& data)
{
	MusicType CurItem;
	
	ResetList();	//iterator 초기화
	GetNextItem(CurItem);	//첫아이템 가져옴
	while(m_CurPointer<m_Length)	//처음부터 끝까지
	{
		switch(CurItem.CompareByName(data))	//입력 아이템과 현재 아이템을 비교
		{
		case EQUAL:	//일치하면
			data=CurItem;	//data에 현재 아이템을 반환
			return 1;	//성공(1)을 리턴
			break;
		case GREATER:	//현재 아이템의 곡명이 더 크면(정렬되있으므로 나머지에 찾는게 없다)
			return 0;	//실패(0)을 리턴
			break;
		default:	//현재 아이템의 곡명이 더 작으면
			GetNextItem(CurItem);	//다음 아이템을 가져온다.(계속 탐색)
			break;
		}
	}
	return 0; //실패시0
}

//곡명과 일치하는 item을 찾아서 제거함
int ArrayList::Delete(MusicType data)
{
	if(Get(data))	//곡명이 일치하는 item을 발견한다면(1)
	{
		for(int i=m_CurPointer;i<m_Length;i++)	//현재 포인터부터 입력된 배열 끝까지 반복
			m_Array[i]=m_Array[i+1];	//배열 뒤에걸 앞으로 하나씩 땡김
		m_Length--;	//아이템 개수를 하나 줄임
		return 1;	//성공(1)을 리턴
	}
	return 0;	//곡명과 일치하는 item을 찾지 못한다면 실패(0)을 리턴
}

//곡명이 일치하는 item의 내용을 교체시킴
int ArrayList::Replace(MusicType data)
{
	MusicType tmp(data);	//입력받은 item을 백업

	if(Get(data))	//일치하는 아이템을 찾은 경우
	{
		m_Array[m_CurPointer]=tmp;	//배열에서 현재포인터가 가르키는 것을 백업했던 아이템으로 교체시킴
		return 1;	//성공(1)을 리턴
	}
	return 0;	//곡명과 일치하는 item을 찾지 못한다면 실패(0)을 리턴
}

//곡명이 일치하는 item을 이진탐색으로 검색해서 반환한다.
int ArrayList::GetBinarySearch(MusicType& data )
{
	if(m_Length==0)	//만약 배열이 비었다면
		return 0;	//실패(0)을 리턴
	int currentPos=m_Length/2;	//배열의 중간부터 시작
	MusicType const item = data;
	while (1)
	{
		switch (m_Array[currentPos].BinaryCompareByName(item))
		{
		case EQUAL:	//현재 아이템과 입력 아이템의 곡명의 일치한다면
			data = m_Array[currentPos];	//data에 발견한 값을 리턴
			cout << "<============I FOUND ITEM !==========>" << endl;
			data.DisplayRecordOnScreen(); 	//일치하는 ata의 내용을 출력한다.
			cout << "<====================================>" << endl;
			/* BinarySearch 에서 일치하는 문자열 여러개를 도출하려고 썼던 코드
			for (int i = currentPos - 1; i >= 0; i--) // 현재 아이템 좌측의 아이템을 확인
			{
			if (m_Array[i].BinaryCompareByName(item) == EQUAL)
			{
			m_Array[i].DisplayRecordOnScreen();
			}
			else if (LESS || GREATER)
			break;
			}
			for (int i = currentPos + 1;; i++) //현재 아이템 우측의 아이템을 확인
			{

			if (m_Array[i].BinaryCompareByName(item) == EQUAL)
			{
			m_Array[i].DisplayRecordOnScreen();
			}
			else
			break;
			}
			*/
			return 1;
			break;
		case GREATER:	//현재 아이템의 곡명이 입력 아이템의 곡명보다 크다면
			if (currentPos == 0)	//처음 배열의 값보다 작은경우
				return 0;	//실패(0)을 리턴
			currentPos /= 2;	//더 작은쪽 인덱스의 절반로 이동
			break;
		case LESS:	//현재 아이템의 곡명이 입력 아이템의 곡명보다 작다면
			if (currentPos == m_Length - 1)	//마지막 배열의 값보다 큰경우
				return 0;	//실패(0)을 리턴
			currentPos = (currentPos + m_Length) / 2;	//더 큰쪽 인덱스의 절반으로 이동
			break;
		}
	}
	return 0;	//호출될 일 없는 리턴(WARNING 방지용)
}
