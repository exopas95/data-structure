#include "Application.h"


// 프로그램 구동.
void Application::Run()
{
	WhatHeap();

	while(1)
	{
		m_nCurCommand = GetCommand();

		switch(m_nCurCommand)
		{
		case 1:		// 추가
			AddItem();
			break;
		case 2:		// 삭제
			DeleteItem();
			break;
		case 3:		// 삭제
			ReplaceItem();
			break;
		case 4:		// 삭제
			DequeueItem();
			break;
		case 5:		// 출력
			DisplayItem();
			break;
		case 6:		// 검색
			SearchItem();
			break;
		case 0:		// 종료
			return;
		default:	// 그 외
			cout << "\tIllegal sellection...\n";
			break;
		}
	}	
}


// MaxHeap와 MinHeap 둘 중 하나를 선택하는 함수.
void Application::WhatHeap()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Max Heap" << endl;
	cout << "\t   2 : Min Heap" << endl;
	cout << "\t   0 : Quit " << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	switch(command)
		{
		case 1:		// Max Heap
			m_List = new CMaxHeap<MusicType>(10);
			break;
		case 2:		// Min Heap
			m_List = new CMinHeap<MusicType>(10);
			break;
		case 0:		// 종료
			return;
		default:	// 그 외
			cout << "\tIllegal sellection...\n";
			break;
		}

}


// 화면에 메뉴가 뜨고 키보드로 입력하는 함수.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Delete item" << endl;
	cout << "\t   3 : Replace item" << endl;
	cout << "\t   4 : Dequeue item" << endl;
	cout << "\t   5 : Display item" << endl;
	cout << "\t   6 : Search item" << endl;
	cout << "\t   0 : Quit " << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

// Heap에 새 음악정보를 추가하기 위한 함수.
int Application::AddItem()
{
	MusicType item;

	item.SetRecordFromKB(); // 음악정보 입력

	if(!m_List->IsFull()) // Heap가 Full인지 아닌지 검사
	{
		m_List->Add(item); // 음악정보 추가
		return 1;
	}
	else
		cout << "\tFull!!!" << endl;

	return 1;
}


// Heap에서 음악정보를 삭제하기 위한 함수.
int Application::DeleteItem()
{	
	MusicType item;
	
	if(!m_List->IsEmpty()) // Heap가 Empty인지 아닌지 검사
	{
		item.SetIDFromKB(); // 삭제할 음악ID 입력

		if(!m_List->Delete(item)) // 음악정보 삭제
			cout << "\n\tNo Data" << endl; 
	}
	else
		cout << "\tEmpty!!!" << endl;

	return 1;
}

// Heap에 새 음악정보를 추가하기 위한 함수.
int Application::ReplaceItem()
{
	MusicType item;
	bool found = false;

	if (!m_List->IsEmpty()) // Heap가 Empty인지 아닌지 검사
	{
		cout << "\n\t변경하고 싶은 곡 이름을 입력하세요 : " << endl;
		item.SetNameFromKB(); // 변경할 곡 명을 입력
		m_List->RetrieveItem(item, found); // 음악정보 검색

		if (found) // 음악정보 변경
		{	
			cout << "\n\t수정할 내용을 입력하세요 : " << endl;
			item.SetArtistFromKB();
			item.SetAlbumFromKB();
			item.SetGenreFromKB();
			item.SetLyricsFromKB();
			m_List->ReplaceItem(item, found);
			cout << "\n\tReplace Complete" << endl;
		}
		else
		{
			cout << "\n\t해당 음악이 없습니다!";
		}
	}
	else
		cout << "\tEmpty!!!" << endl;

	return 1;
}


// Heap에서 첫번째 음악정보를 삭제하기 위한 함수.
int Application::DequeueItem()
{		
	if(!m_List->IsEmpty()) // Heap가 Empty인지 아닌지 검사
	{
		m_List->Dequeue(); // 첫번째 음악정보 삭제
	}
	else
	{
		cout << "\tEmpty!!!" << endl;
	}
	return 1;
}


// Heap에 있는 음악정보를 출력하기 위한 함수.
void Application::DisplayItem()
{
	if(!m_List->IsEmpty()) // Heap가 Empty인지 아닌지 검사
	{
		m_List->PrintHeap(); // 음악정보 출력
	}
	else
		cout << "\tEmpty!!!" << endl;
}


// Heap에서 음악정보를 검색하기 위한 함수.
int Application::SearchItem()
{
	MusicType item;
	bool found = false;
	
	if(!m_List->IsEmpty()) // Heap가 Empty인지 아닌지 검사
	{
		item.SetIDFromKB(); // 검색할 음악ID 입력

		m_List->RetrieveItem(item, found); // 음악정보 검색

		// Heap에서 음악을 찾았는지 못찾았는지 판단
		if(found)
		{
			cout << "\n\tFound!!" << endl;
			item.DisplayRecordOnScreen(); // 검색한 음악정보 출력
		}
		else
			cout << "\n\tNo Data" << endl;
	}
	else
	{
		cout << "\tEmpty!!!" << endl;
	}

	return 1;
}
