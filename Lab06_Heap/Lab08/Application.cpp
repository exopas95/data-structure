#include "Application.h"


// ���α׷� ����.
void Application::Run()
{
	WhatHeap();

	while(1)
	{
		m_nCurCommand = GetCommand();

		switch(m_nCurCommand)
		{
		case 1:		// �߰�
			AddItem();
			break;
		case 2:		// ����
			DeleteItem();
			break;
		case 3:		// ����
			ReplaceItem();
			break;
		case 4:		// ����
			DequeueItem();
			break;
		case 5:		// ���
			DisplayItem();
			break;
		case 6:		// �˻�
			SearchItem();
			break;
		case 0:		// ����
			return;
		default:	// �� ��
			cout << "\tIllegal sellection...\n";
			break;
		}
	}	
}


// MaxHeap�� MinHeap �� �� �ϳ��� �����ϴ� �Լ�.
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
		case 0:		// ����
			return;
		default:	// �� ��
			cout << "\tIllegal sellection...\n";
			break;
		}

}


// ȭ�鿡 �޴��� �߰� Ű����� �Է��ϴ� �Լ�.
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

// Heap�� �� ���������� �߰��ϱ� ���� �Լ�.
int Application::AddItem()
{
	MusicType item;

	item.SetRecordFromKB(); // �������� �Է�

	if(!m_List->IsFull()) // Heap�� Full���� �ƴ��� �˻�
	{
		m_List->Add(item); // �������� �߰�
		return 1;
	}
	else
		cout << "\tFull!!!" << endl;

	return 1;
}


// Heap���� ���������� �����ϱ� ���� �Լ�.
int Application::DeleteItem()
{	
	MusicType item;
	
	if(!m_List->IsEmpty()) // Heap�� Empty���� �ƴ��� �˻�
	{
		item.SetIDFromKB(); // ������ ����ID �Է�

		if(!m_List->Delete(item)) // �������� ����
			cout << "\n\tNo Data" << endl; 
	}
	else
		cout << "\tEmpty!!!" << endl;

	return 1;
}

// Heap�� �� ���������� �߰��ϱ� ���� �Լ�.
int Application::ReplaceItem()
{
	MusicType item;
	bool found = false;

	if (!m_List->IsEmpty()) // Heap�� Empty���� �ƴ��� �˻�
	{
		cout << "\n\t�����ϰ� ���� �� �̸��� �Է��ϼ��� : " << endl;
		item.SetNameFromKB(); // ������ �� ���� �Է�
		m_List->RetrieveItem(item, found); // �������� �˻�

		if (found) // �������� ����
		{	
			cout << "\n\t������ ������ �Է��ϼ��� : " << endl;
			item.SetArtistFromKB();
			item.SetAlbumFromKB();
			item.SetGenreFromKB();
			item.SetLyricsFromKB();
			m_List->ReplaceItem(item, found);
			cout << "\n\tReplace Complete" << endl;
		}
		else
		{
			cout << "\n\t�ش� ������ �����ϴ�!";
		}
	}
	else
		cout << "\tEmpty!!!" << endl;

	return 1;
}


// Heap���� ù��° ���������� �����ϱ� ���� �Լ�.
int Application::DequeueItem()
{		
	if(!m_List->IsEmpty()) // Heap�� Empty���� �ƴ��� �˻�
	{
		m_List->Dequeue(); // ù��° �������� ����
	}
	else
	{
		cout << "\tEmpty!!!" << endl;
	}
	return 1;
}


// Heap�� �ִ� ���������� ����ϱ� ���� �Լ�.
void Application::DisplayItem()
{
	if(!m_List->IsEmpty()) // Heap�� Empty���� �ƴ��� �˻�
	{
		m_List->PrintHeap(); // �������� ���
	}
	else
		cout << "\tEmpty!!!" << endl;
}


// Heap���� ���������� �˻��ϱ� ���� �Լ�.
int Application::SearchItem()
{
	MusicType item;
	bool found = false;
	
	if(!m_List->IsEmpty()) // Heap�� Empty���� �ƴ��� �˻�
	{
		item.SetIDFromKB(); // �˻��� ����ID �Է�

		m_List->RetrieveItem(item, found); // �������� �˻�

		// Heap���� ������ ã�Ҵ��� ��ã�Ҵ��� �Ǵ�
		if(found)
		{
			cout << "\n\tFound!!" << endl;
			item.DisplayRecordOnScreen(); // �˻��� �������� ���
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
