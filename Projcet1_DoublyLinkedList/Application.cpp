#include "Application.h"


// Program driver.
void Application::Run()
{
	int select = -1;
	int login = 0;
	while (select != 0)	//0���� �Է¹����� �����Ѵ�.
	{
		loginedUser = NULL;
		cout << endl << endl;
		cout << "\t*-------------------------*" << endl;
		cout << "\t| 1 : ������ �α���       |" << endl;
		cout << "\t| 2 : �α���              |" << endl;
		cout << "\t| 3 : ȸ������            |" << endl;
		cout << "\t| 0 : ����                |" << endl;
		cout << "\t*-------------------------*" << endl;
		cout << endl << "\t --> ";
		cin >> select;
		switch (select)
		{
		case 1:
			userAdminLogin();
			if (loginedUser != NULL)
				login = 1;
			break;
		case 2:
			userLogin();
			if (loginedUser != NULL)
				login = 2;
			break;
		case 3:
			uRegister();	//ȸ������
			SetUserToFile();
			break;
		case 0:
			return;
		default:
			cout << "\t�ٽ� �Է��� �ּ���.";
		}

		int i = 1;
		int j = 1;
		if (login == 1)
		{
			while (i == 1)
			{
				m_Command = GetCommand_Admin();

				switch (m_Command)
				{
				case 1:	// ���� �߰�
					AddMusic();
					break;
				case 2:	// ����Ʈ���� ���� ����
					DeleteMusic();
					break;
				case 3:	// ����Ʈ�� �ִ� ���� ����
					ReplaceMusic();
					break;
				case 4:	// ����Ʈ�� �ִ� ���� �˻�
						// ��, �˻�� ���Ǹ� ���Եȴٸ� ����Ѵ�
						// 	ex) �˻��� : ������� / ��� : �����ѻ��,õ���ǻ��,..
					SearchByID();
					break;
				case 5:	// ����Ʈ�� �ִ� ���� �˻�
						// ��, �˻�� ���Ǹ� ���Եȴٸ� ����Ѵ�
						// 	ex) �˻��� : ������� / ��� : �����ѻ��,õ���ǻ��,..
					SearchByName();
					break;
				case 6:	// ����Ʈ�� �ִ� ���� �˻�
						// ��, �˻�� ������ ���Եȴٸ� ����Ѵ�
					DisplayMusicByArtist();
					break;
				case 7:	// ����Ʈ�� �ִ� �ٹ� �˻�
						// ��, �˻�� �ٹ��� ���Եȴٸ� ����Ѵ�
					SearchByAlbum();
					break;
				case 8:	// ����Ʈ�� �ִ� �帣 �˻�
						// ��, �˻�� �帣�� ���Եȴٸ� ����Ѵ�
					DisplayMusicByGenre();
					break;
				case 9:	// ����Ʈ�� �ִ� ���Ƚ�� �˻�
						// ��, �˻�� ���Ƚ���� ���Եȴٸ� ����Ѵ�
					SearchByRepetition();
					break;
				case 10:	// �ֱ� �߰��� ���� ����Ʈ�� ���
					DisplayNewMusic();
					break;
				case 11:	// �ֱ� �����Ͽ� �߰��� ���� ����Ʈ�� ���
					DisplayPlayNewMusic();
					break;
				case 12:	// ����Ʈ�� �ִ� ��� �������� ���
					DisplayAllMusic();
					break;
				case 13:	// txt ���Ͽ��� ���������� �о�´�
					ReadDataFromFile();
					break;
				case 14:	// txt ���Ͽ� ���������� ����
					WriteDataToFile();
					break;
				case 15:	// ������ �����Ͽ� �߰��Ѵ�.
					AddToPlayMusic();
					break;
				case 16:	// ������ �����Ͽ� �߰��Ѵ�.
					DeletePlayMusic();
					break;
				case 17:	// ������ ����Ѵ�.
					PlayMusic();
					break;
				case 0:
					i = 2;
					break;
				default:
					cout << "\t---------------------------" << endl;
					cout << "\ �ùٸ��� ���� ��ɾ� �Դϴ�...\n";
					cout << "\t---------------------------" << endl;
					select = 0;
					return;
				}
			}
		}

		if (login == 2)
		{
			while (j == 1)
			{
				m_Command = GetCommand_User();

				switch (m_Command)
				{
				case 1:	// ����Ʈ�� �ִ� ���� �˻�
						// ��, �˻�� ���Ǹ� ���Եȴٸ� ����Ѵ�
						// 	ex) �˻��� : ������� / ��� : �����ѻ��,õ���ǻ��,..
					SearchByID();
					break;
				case 2:	// ����Ʈ�� �ִ� ���� �˻�
						// ��, �˻�� ���Ǹ� ���Եȴٸ� ����Ѵ�
						// 	ex) �˻��� : ������� / ��� : �����ѻ��,õ���ǻ��,..
					SearchByName();
					break;
				case 3:	// ����Ʈ�� �ִ� ���� �˻�
						// ��, �˻�� ������ ���Եȴٸ� ����Ѵ�
					DisplayMusicByArtist();
					break;
				case 4:	// ����Ʈ�� �ִ� �ٹ� �˻�
						// ��, �˻�� �ٹ��� ���Եȴٸ� ����Ѵ�
					SearchByAlbum();
					break;
				case 5:	// ����Ʈ�� �ִ� �帣 �˻�
						// ��, �˻�� �帣�� ���Եȴٸ� ����Ѵ�
					DisplayMusicByGenre();
					break;
				case 6:	// ����Ʈ�� �ִ� ���Ƚ�� �˻�
						// ��, �˻�� ���Ƚ���� ���Եȴٸ� ����Ѵ�
					SearchByRepetition();
					break;
				case 7:	// �ֱ� �߰��� ���� ����Ʈ�� ���
					DisplayNewMusic();
					break;
				case 8:	// �ֱ� �����Ͽ� �߰��� ���� ����Ʈ�� ���
					DisplayPlayNewMusic();
					break;
				case 9:	// ����Ʈ�� �ִ� ��� �������� ���
					DisplayAllMusic();
					break;
				case 10:	// txt ���Ͽ��� ���������� �о�´�
					ReadDataFromFile();
					break;
				case 11:	// txt ���Ͽ� ���������� ����
					WriteDataToFile();
					break;
				case 12:	// ������ �����Ͽ� �߰��Ѵ�.
					AddToPlayMusic();
					break;
				case 13:	// ������ �����Ͽ� �߰��Ѵ�.
					DeletePlayMusic();
					break;
				case 14:	// ������ ����Ѵ�.
					PlayMusic();
					break;
				case 0:
					j = 2;
					break;
				default:
					cout << "\t---------------------------" << endl;
					cout << "\ �ùٸ��� ���� ��ɾ� �Դϴ�...\n";
					cout << "\t---------------------------" << endl;
					return;
				}
			}
		}
	}

}


// Display command on screen and get a input from keyboard.
int Application::GetCommand_Admin()
{
	int z = 1;
	int command;
	int number;

	while (z == 1)
	{
		cout << endl << endl;
		cout << "\t---ID -- Command ---------" << endl;
		cout << "\t   1 : ���� �߰�/����" << endl;
		cout << "\t   2 : ������" << endl;
		cout << "\t   3 : �˻�." << endl;
		cout << "\t   4 : ��� ���� ����Ʈ" << endl;
		cout << "\t   5 : ���� ����/�ҷ�����" << endl;
		cout << "\t   0 : �α׾ƿ�" << endl;
		cout << "\t---------------------------" << endl;
		cout << endl << "\t Choose a Command--> ";

		cin >> number;
		switch (number)
		{
		case 1:	// ���� �߰�
			cout << endl << endl;
			cout << "\t---ID -- Command -----------------" << endl;
			cout << "\t   1 : ������ �߰��մϴ�." << endl;
			cout << "\t   2 : ������ �����մϴ�." << endl;
			cout << "\t   3 : ������ ������ �����մϴ�." << endl;
			cout << "\t   0 : �ڷ� ���� ���ϴ�." << endl;
			cout << "\t----------------------------------" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			if (command != 0)
				z = 2;
			break;
		case 2:	// ����Ʈ���� ���� ����
			cout << endl << endl;
			cout << "\t---ID -- Command ----------" << endl;
			cout << "\t   15 : �����Ͽ� �߰�" << endl;
			cout << "\t   16 : �����Ͽ��� ���� " << endl;
			cout << "\t   17 : ���� ��� " << endl;
			cout << "\t   0 : �ڷ� ���� ���ϴ�." << endl;
			cout << "\t----------------------------" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			if (command != 0)
				z = 2;
			break;
		case 3:	// ����Ʈ�� �ִ� ���� ����
			cout << endl << endl;
			cout << "\t---ID -- Command --------------------------------" << endl;
			cout << "\t   4 : ID�� ������ �˻��մϴ�." << endl;
			cout << "\t   5 : �������� ������ �˻��մϴ�." << endl;
			cout << "\t   6 : ���������� ������ �˻��մϴ�." << endl;
			cout << "\t   7 : �ٹ������� ������ �˻��մϴ�." << endl;
			cout << "\t   8 : �帣������ ������ �˻��մϴ�." << endl;
			cout << "\t   9 : ���Ƚ���� �˻��մϴ�" << endl;
			cout << "\t   10 : �ֱ� �߰��� ������ �˻��մϴ�.." << endl;
			cout << "\t   11 : �����Ͽ� �ֱ� �߰��� ������ �˻��մϴ�." << endl;
			cout << "\t   0 : �ڷ� ���� ���ϴ�." << endl;
			cout << "\t-------------------------------------------------" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			if (command != 0)
				z = 2;
			break;
		case 4:	// ����Ʈ�� �ִ� ���� �˻�
				// ��, �˻�� ���Ǹ� ���Եȴٸ� ����Ѵ�
				// 	ex) �˻��� : ������� / ��� : �����ѻ��,õ���ǻ��,..
			command = 12;
			if (command != 0)
				z = 2;
			break;
		case 5:	// ����Ʈ�� �ִ� ���� �˻�
				// ��, �˻�� ���Ǹ� ���Եȴٸ� ����Ѵ�
				// 	ex) �˻��� : ������� / ��� : �����ѻ��,õ���ǻ��,..
			cout << endl << endl;
			cout << "\t---ID -- Command ---------------------" << endl;
			cout << "\t   13 : ���� ����� �ҷ��ɴϴ�." << endl;
			cout << "\t   14 : ��������� ����� �����մϴ�." << endl;
			cout << "\t   0 : �ڷ� ���� ���ϴ�." << endl;
			cout << "\t--------------------------------------" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			if (command != 0)
				z = 2;
			break;
		case 0:
			z = 2;
			command = 0;
			break;
		default:
			cout << endl;
			cout << "\t---------------------------" << endl;
			cout << "\t �ùٸ��� ���� ��ɾ� �Դϴ�...\n";
			cout << "\t---------------------------" << endl;
			break;
		}
	}
	
	cout << endl;

	return command;
}

// Display command on screen and get a input from keyboard.
int Application::GetCommand_User()
{
	int command;
	int number;
	int h = 1;
	while (h == 1)
	{
		cout << endl << endl;
		cout << "\t---ID -- Command ---------" << endl;
		cout << "\t   1 : ������" << endl;
		cout << "\t   2 : �˻�." << endl;
		cout << "\t   3 : ��� ���� ����Ʈ" << endl;
		cout << "\t   4 : ���� ����/�ҷ�����" << endl;
		cout << "\t   0 : �α׾ƿ�" << endl;
		cout << "\t---------------------------" << endl;
		cout << endl << "\t Choose a Command--> ";

		cin >> number;
		switch (number)
		{
		case 1:	// ����Ʈ���� ���� ����
			cout << endl << endl;
			cout << "\t---ID -- Command ----------" << endl;
			cout << "\t   12 : �����Ͽ� �߰�" << endl;
			cout << "\t   13 : �����Ͽ��� ���� " << endl;
			cout << "\t   14 : ���� ��� " << endl;
			cout << "\t   0 : �ڷ� ���� ���ϴ�." << endl;
			cout << "\t----------------------------" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			if(command != 0)
				h = 2;
			break;
		case 2:	// ����Ʈ�� �ִ� ���� ����
			cout << endl << endl;
			cout << "\t---ID -- Command --------------------------------" << endl;
			cout << "\t   1 : ID�� ������ �˻��մϴ�." << endl;
			cout << "\t   2 : �������� ������ �˻��մϴ�." << endl;
			cout << "\t   3 : ���������� ������ �˻��մϴ�." << endl;
			cout << "\t   4 : �ٹ������� ������ �˻��մϴ�." << endl;
			cout << "\t   5 : �帣������ ������ �˻��մϴ�." << endl;
			cout << "\t   6 : ���Ƚ���� �˻��մϴ�" << endl;
			cout << "\t   7 : �ֱ� �߰��� ������ �˻��մϴ�.." << endl;
			cout << "\t   8 : �����Ͽ� �ֱ� �߰��� ������ �˻��մϴ�." << endl;
			cout << "\t   0 : �ڷ� ���� ���ϴ�." << endl;
			cout << "\t-------------------------------------------------" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			if (command != 0)
				h = 2;
			break;
		case 3:	// ����Ʈ�� �ִ� ���� �˻�
				// ��, �˻�� ���Ǹ� ���Եȴٸ� ����Ѵ�
				// 	ex) �˻��� : ������� / ��� : �����ѻ��,õ���ǻ��,..
			command = 9;
			h = 2;
			break;
		case 4:	// ����Ʈ�� �ִ� ���� �˻�
				// ��, �˻�� ���Ǹ� ���Եȴٸ� ����Ѵ�
				// 	ex) �˻��� : ������� / ��� : �����ѻ��,õ���ǻ��,..
			cout << endl << endl;
			cout << "\t---ID -- Command ---------------------" << endl;
			cout << "\t   10 : ���� ����� �ҷ��ɴϴ�." << endl;
			cout << "\t   11 : ��������� ����� �����մϴ�." << endl;
			cout << "\t   0 : �ڷ� ���� ���ϴ�." << endl;
			cout << "\t--------------------------------------" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			if (command != 0)
				h = 2;
			break;
		case 0:
			h = 2;
			command = 0;
			break;
		default:
			cout << endl;
			cout << "\t---------------------------" << endl;
			cout << "\t �ùٸ��� ���� ��ɾ� �Դϴ�...\n";
			cout << "\t---------------------------" << endl;
			break;
		}
	}
	
	cout << endl;

	return command;
}

// Add new record into list.
int Application::AddMusic()
{
	MusicType indata1;
	SimpleMusicType indata2;
	AlbumType indata3;

	indata1.SetRecordFromKB(); // m_List�� ���� ��� ���� ����
	indata2.SetRecord(indata1.GetID(), indata1.GetName());	// g_List�� ���� �Ϻ� ���� ����
	indata3.SetRecord(indata1.GetID(), indata1.GetAlbum(), indata1.GetArtist(), indata1.GetCompany()); //a_List�� ���� ���� ����

	if (m_List.Get(indata1) == 1) // �������� �ߺ��Ǵ��� Ȯ��
	{
		cout << endl;
		cout << "\t<=====������ �̹� �����մϴ�!=====>" << endl;
		return 0;
	}														
	m_List.Add(indata1); // MusicList�� �߰�
	this->DisplayAllMusic();

	// GenreList�� �߰�	
	GenreType temp;	  // �Էµ� ������ ��� �帣�� ���ϴ��� ã�� ���� ����
	GenreType *pData; // g_List�� �ش� �帣�� �����ͷ� ����Ű�� ���� ����

	g_List.ResetList();
	int length = g_List.GetLength();

	bool found = false;

	for (int i = 0; i < length; i++)
	{
		int G_ID = i + 1;
		g_List.GetNextItem(temp);
		if (temp.GetGenreName() == indata1.GetGenre())
		{
			{
				found = true;
				temp.SetGenreInfo(indata1.GetID(), G_ID, indata1.GetGenre());
				pData = g_List.GetPoint(temp); // �Էµ� ���ǰ� ��ġ�ϴ� �帣�� ã�� �����ͷ� ����Ų��
				pData->AddMusicInGenre(indata2); // ����Ʈ �� ����Ʈ�� ���� �߰�

				if (s_List.IsFull())  // �ֱ� ���� ����� ���� á�ٸ�
					s_List.DeQueue(indata2);  //�ֱ� ���� ��Ͽ��� ���� ������ ���� ����
				else
					s_List.EnQueue(indata2);  // �ֱ� ���� ��Ͽ��� �ֽ� ���� �߰�
			}
		}
		G_ID++; // �帣 ��ȣ ����
	}
	if (found == false)
	{
		temp.SetGenreInfo(indata1.GetID(), length + 1, indata1.GetGenre());  // temp�� �帣 ���� ����
		g_List.Add(temp);  // �帣 ����Ʈ�� �帣 ���� �߰�
		pData = g_List.GetPoint(temp); // �Էµ� ���ǰ� ��ġ�ϴ� �帣�� ã�� �����ͷ� ����Ų��
		pData->AddMusicInGenre(indata2); // ����Ʈ �� ����Ʈ�� ���� �߰�

		if (s_List.IsFull())  // �ֱ� ���� ����� ���� á�ٸ�
		{
			s_List.DeQueue(indata2);  // �ֱ� ���� ��Ͽ��� ���� ������ ���� ����
		}
		else
		{
			s_List.EnQueue(indata2);  // �ֱ� ���� ��Ͽ��� �ֽ� ���� �߰�
		}
	}


	// ArtistList�� �߰�	
	ArtistType temp2; // �Էµ� ������ ��� �帣�� ���ϴ��� ã�� ���� ����
	ArtistType *pData2; // a_List�� �ش� �帣�� �����ͷ� ����Ű�� ���� ����

	a_List.ResetList();
	int length2 = a_List.GetLength();

	bool found2 = false;

	for (int i = 0; i < length2; i++)
	{
		int A_ID = i + 1;
		a_List.GetNextItem(temp2);
		if (temp2.GetArtistName() == indata1.GetArtist())
		{
			{
				found2 = true;
				temp2.SetArtistInfo(indata1.GetID(), A_ID, indata1.GetArtist());
				pData2 = a_List.GetPoint(temp2); // �Էµ� ���ǰ� ��ġ�ϴ� �帣�� ã�� �����ͷ� ����Ų��
				pData2->AddAlbumInArtist(indata3); // ����Ʈ �� ����Ʈ�� ���� �߰�
			}
		}
		A_ID++; // ���� ��ȣ ����
	}
	if (found2 == false)
	{
		temp2.SetArtistInfo(indata1.GetID(), length + 1, indata1.GetArtist());  // temp�� ���� ���� ����
		a_List.Add(temp2);  // ���� ����Ʈ�� �帣 ���� �߰�
		pData2 = a_List.GetPoint(temp2); // �Էµ� ���ǰ� ��ġ�ϴ� ������ ã�� �����ͷ� ����Ų��
		pData2->AddAlbumInArtist(indata3); // ����Ʈ �� ����Ʈ�� ���� �߰�
	}
	return 1;
}

// ���Ǹ����� �������� ã�� ����Ѵ�.
int Application::SearchByID()
{
	MusicType item;
	item.SetIDFromKB(); //Name�Է¹޴´�.
	SearchListByMusicID(item);
	return 0;	//����(0)�� ����
}

// ���Ǹ����� �������� ã�� ����Ѵ�.
int Application::SearchByName()
{
	MusicType item;
	item.SetNameFromKB(); //Name�Է¹޴´�.
	SearchListByMusicName(item);
	return 0;	//����(0)�� ����
}


// �ٹ������� �������� ã�� ����Ѵ�.
void Application::SearchByAlbum()
{
	MusicType temp;
	temp.SetAlbumFromKB();	//SearchListByMusicAlbum�Լ��� �Ѱ��� temp�� name�� ����ڿ��� �Է¹޴´�.
	SearchListByMusicAlbum(temp);	//���������� ã�� ������ �ϴ� SearchListByMusicAlbum�Լ��� ȣ���ϰ� temp���� �Ѱ��ش�.
}


// ���Ƚ���� �������� ã�� ����Ѵ�.
void Application::SearchByRepetition()
{
	MusicType temp;
	temp.SetNumberFromKB();	//SearchListByMusicGenre�Լ��� �Ѱ��� temp�� name�� ����ڿ��� �Է¹޴´�.
	SearchListByMusicRepetition(temp);	//���������� ã�� ������ �ϴ� SearchListByMusicGenre�Լ��� ȣ���ϰ� temp���� �Ѱ��ش�.
}

// ���� ��ȣ�� �������� ã�� ����Ѵ�.
void Application::SearchListByMusicID(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� ItemType.
	m_List.ResetList();
	int count = 0;
	for (int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(temp);
		if (temp.GetID() == (inData.GetID()))	//find�Լ������� ��ġ�ϴ� �׸��� �������� ������ -1�� �����ϹǷ� -1�� �ƴϸ� ��ġ�ϴ� ���ڿ��� �ִ°��̴�.
		{
			cout << "<=======I �������� ã�ҽ��ϴ� !======>" << endl;
			temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
			cout << "<====================================>" << endl;
			count++;	//ã�� ������ 1 �÷��ش�.
		}
	}
	if (count == 0)
		cout << "<=====I �������� ã�� �� �����ϴ� !=====>" << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}

// ���Ǹ����� �������� ã�� ����Ѵ�.
void Application::SearchListByMusicName(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� ItemType.
	m_List.ResetList();
	int count = 0;
	for (int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(temp);
		if (temp.GetName().find(inData.GetName()) != -1)	//find�Լ������� ��ġ�ϴ� �׸��� �������� ������ -1�� �����ϹǷ� -1�� �ƴϸ� ��ġ�ϴ� ���ڿ��� �ִ°��̴�.
		{
			cout << "<=======I �������� ã�ҽ��ϴ� !======>" << endl;
			temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
			cout << "<====================================>" << endl;
			count++;	//ã�� ������ 1 �÷��ش�.
		}
	}
	if (count == 0)
		cout << "<=====I �������� ã�� �� �����ϴ� !=====>" << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}

// �ٹ������� �������� ã�� ����Ѵ�.
void Application::SearchListByMusicAlbum(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� ItemType.
	m_List.ResetList();
	int count = 0;
	for (int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(temp);
		if (temp.GetAlbum().find(inData.GetAlbum()) != -1)	//find�Լ������� ��ġ�ϴ� �׸��� �������� ������ -1�� �����ϹǷ� -1�� �ƴϸ� ��ġ�ϴ� ���ڿ��� �ִ°��̴�.
		{
			cout << "<=======I �������� ã�ҽ��ϴ� !======>" << endl;
			temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
			cout << "<====================================>" << endl;
			count++;	//ã�� ������ 1 �÷��ش�.
		}
	}
	if (count == 0)
		cout << "<=====I �������� ã�� �� �����ϴ� !=====>" << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}

// ���Ƚ���� �������� ã�� ����Ѵ�.
void  Application::SearchListByMusicRepetition(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� ItemType.
	m_List.ResetList();
	int count = 0;
	for (int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(temp);
		if (temp.GetNumber() == inData.GetNumber())	//find�Լ������� ��ġ�ϴ� �׸��� �������� ������ -1�� �����ϹǷ� -1�� �ƴϸ� ��ġ�ϴ� ���ڿ��� �ִ°��̴�.
		{
			cout << "<=======I �������� ã�ҽ��ϴ� !======>" << endl;
			temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
			cout << "<====================================>" << endl;
			count++;	//ã�� ������ 1 �÷��ش�.
		}
	}
	if (count == 0)
		cout << "<=====I �������� ã�� �� �����ϴ� !=====>" << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}


//���ǹ�ȣ�� ������ ã�Ƽ� �����Ѵ�.
int Application::DeleteMusic()
{
	int pre = m_List.GetLength();//���� item������ �޾ƿ´�.
	int length = g_List.GetLength();
	int alength = a_List.GetLength();

	MusicType item;
	SimpleMusicType simpleitem;
	AlbumType albumitem;

	GenreType temp; // �Էµ� ������ ��� �帣�� ���ϴ��� ã�� ���� ����
	GenreType *pData; // g_List�� �ش� �帣�� �����ͷ� ����Ű�� ���� ����

	ArtistType atemp; // �Էµ� ������ ��� ������Ͽ� ���ϴ��� ã�� ���� ����
	ArtistType *apData; // a_List�� �ش� �帣�� �����ͷ� ����Ű�� ���� ����

	int num;
	cout << "\tID : ";
	cin >> num;

	item.SetID(num);
	simpleitem.SetID(num);
	albumitem.SetID(num);
	

	//����Ʈ�� �ִ� ������ �����Ѵ�.
	m_List.Delete(item);

	////////////////////////////////////////SIMPLEMUSICLIST ����//////////////////////////////////////////

	g_List.ResetList();

	for (int i = 0; i < length; i++)
	{
		g_List.GetNextItem(temp);
		if (temp.GetID() == item.GetID())
		{
			pData = g_List.GetPoint(temp); // �Էµ� ���ǰ� ��ġ�ϴ� �帣�� ã�� �����ͷ� ����Ų��
			pData->DeleteMusicInGenre(simpleitem); // ����Ʈ �� ����Ʈ�� �ִ� ���� ����
		}
	}

	//////////////////////////////////////�����Ͽ� �ִ� ���� ����///////////////////////////////////////

	p_List.ResetList();
	int pre2 = p_List.GetLength();//���� item������ �޾ƿ´�.
	PlayType item2;

	item2.SetPlayID(num);

	//����Ʈ�� �ִ� ������ �����Ѵ�.
	p_List.Delete(item2);

	if (pre2 > p_List.GetLength()) //���� item�������� ���� item������ �������� ���ż���
	{
		cout << "\n\t! ��� ��Ͽ� �ִ� �뷡�� ���� �Ǿ����ϴ� !" << endl;
	}

	//////////////////////////////////////�ٹ���Ͽ� �ִ� ���� ����////////////////////////////////////////

	a_List.ResetList();

	for (int i = 0; i < alength; i++)
	{
		a_List.GetNextItem(atemp);
		if (atemp.GetID() == item.GetID())
		{
			apData = a_List.GetPoint(atemp); // �Էµ� ���ǰ� ��ġ�ϴ� �帣�� ã�� �����ͷ� ����Ų��
			apData->DeleteAlbumInArtist(albumitem); // ����Ʈ �� ����Ʈ�� �ִ� ���� ����
		}
	}

	/////////////////////////////////���� ��� ���////////////////////////////////////////////////////////

	if (pre> m_List.GetLength()) //���� item�������� ���� item������ �������� ���ż���
	{
		cout << endl;
		cout << "<========! ���� ���� !===========>" << endl;
		this->DisplayAllMusic(); //��� item�� ����Ѵ�.
		return 1;
	}

	cout << "<=========! ���� ���� !==========>" << endl;
	this->DisplayAllMusic();//��� item�� ����Ѵ�.
}

//�ش� ���Ǹ��� ������ �����Ѵ�.
int Application::ReplaceMusic()
{
	MusicType item;
	item.SetIDFromKB();
	item.SetNameFromKB();
	item.SetArtistFromKB();
	item.SetCompanyFromKB();
	item.SetAlbumFromKB();
	item.SetGenreFromKB();
	item.SetMadeFromKB();
	item.SetLongFromKB();
	item.SetNoteFromKB();
	item.SetLyricsFromKB(); //Ű����κ��� ������ �Է¹���

	m_List.Replace(item); //�ش� item�� ���Ǹ� ��ġ�ϴ� ���� ã�� �ٲ۴�.

	cout << "\n\t���� ���� ���� �Ϸ�!!!";
	this->DisplayAllMusic();
	return 0;
}

// �ֱ� ���� ����� ����Ѵ�(30�� ����)
void Application::DisplayNewMusic()
{
	s_List.Print();
}

// �ֱ� ����� ����� ����Ѵ�(30�� ����)
void Application::DisplayPlayNewMusic()
{

	PlayType data;

	cout << "\n\t�ֱ� ����� ��� - ����ð� �� : " << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	rp_List.ResetList();

	for (int i = 0; i < rp_List.GetLength(); i++)
	{
		rp_List.GetNextItem(data);
		data.DisplayPlayOnScreen();
		cout << endl;
	}
}


// ����Ʈ�� ����� ��� �����͸� ����Ѵ�.
void Application::DisplayAllMusic()
{
	MusicType data;

	cout << "\n\t���� ��� : " << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	m_List.ResetList();

	for (int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(data);
		data.DisplayRecordOnScreen();
		cout << endl;
	}
}

// ���� ����Ʈ�� �帣���� ����Ѵ�.
int Application::DisplayMusicByGenre()
{
	GenreType data;

	cout << "\n\t���� ���" << endl;

	// genre list�� ��� �����͸� ȭ�鿡 ���
	g_List.ResetList();
	int length = g_List.GetLength();
	for (int i = 0; i < length; i++)
	{
		g_List.GetNextItem(data);
		data.DisplayGenreOnScreen();
	}

	// Ư�� �帣�� ���� ������ ���� ���� ��
	int id;
	GenreType *pData;

	cout << "\n\tã���� �ϴ� �帣�� ��ȣ�� �Է��ϼ��� : ";
	while (true)
	{
		cin >> id;
		g_List.ResetList();
		for (int i = 0; i < length; i++)
		{
			g_List.GetNextItem(data);
			if (data.GetGenreId() == id)
			{
				data.SetGenreInfo(-1, id, "");
				pData = g_List.GetPoint(data);
				pData->DisplayMusicDetailInGenre(&m_List); // �ش� �帣 ���� ���
				return 1;
			}
		}
		cout << "\n\t!!!! ��ȣ�� �������� �ʽ��ϴ� !!!!";
		cout << "\n\t �帣�� �տ� �ִ� ��ȣ�� �Է��� �ּ���: ";
	}
	return 0;
}

// ���� ����Ʈ�� �������� ����Ѵ�.
int Application::DisplayMusicByArtist()
{
	ArtistType data;

	cout << "\n\t���� ���" << endl;

	// artist list�� ��� �����͸� ȭ�鿡 ���
	a_List.ResetList();
	int length = a_List.GetLength();
	for (int i = 0; i < length; i++)
	{
		a_List.GetNextItem(data);
		data.DisplayArtistOnScreen();
	}

	// Ư�� ������ �ٹ� ������ ���� ���� ��
	int id;
	ArtistType *pData;

	cout << "\n\tã���� �ϴ� ������ ��ȣ�� �Է��� �ּ��� : ";
	while (true)
	{
		cin >> id;
		a_List.ResetList();
		for (int i = 0; i < length; i++)
		{
			a_List.GetNextItem(data);
			if (data.GetArtistId() == id)
			{
				data.SetArtistInfo(-1, id, "");
				pData = a_List.GetPoint(data);
				pData->DisplayAlbumDetailInArtist(&m_List); // �ش� �帣 ���� ���
				return 1;
			}
		}
		cout << "\n\t!!!! ��ȣ�� �������� �ʽ��ϴ� !!!!";
		cout << "\n\t ������ �տ� �ִ� ��ȣ�� �Է��� �ּ���: ";
	}
	return 0;
}

// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.
	
	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	MusicType data;	// �б�� �ӽ� ����
	SimpleMusicType data2;
	AlbumType data3;
	
	char filename[FILENAMESIZE] = "�뷡���.txt";
	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(filename))
	{
		cout << "\n\t������ �������� �ʽ��ϴ�!";
		return 0;
	}

	// ��� ����Ʈ �ʱ�ȭ
	m_List.MakeEmpty();
	g_List.MakeEmpty();
	a_List.MakeEmpty();
	// ������ ��� ������ �о� list�� �߰�
	while(!m_InFile.eof())
	{
		// �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);

		data2.SetRecord(data.GetID(), data.GetName());	// g_List�� ���� �Ϻ� ���� ����
		data3.SetRecord(data.GetID(), data.GetAlbum(), data.GetArtist(), data.GetCompany()); //a_List�� ���� ���� ����
		

		// GenreList�� �߰�	
		GenreType temp;	  // �Էµ� ������ ��� �帣�� ���ϴ��� ã�� ���� ����
		GenreType *pData; // g_List�� �ش� �帣�� �����ͷ� ����Ű�� ���� ����

		g_List.ResetList();
		int length = g_List.GetLength();

		bool found = false;

		for (int i = 0; i < length; i++)
		{
			int G_ID = i + 1;
			g_List.GetNextItem(temp);
			if (temp.GetGenreName() == data.GetGenre())
			{
				{
					found = true;
					temp.SetGenreInfo(data.GetID(), G_ID, data.GetGenre());
					pData = g_List.GetPoint(temp); // �Էµ� ���ǰ� ��ġ�ϴ� �帣�� ã�� �����ͷ� ����Ų��
					pData->AddMusicInGenre(data2); // ����Ʈ �� ����Ʈ�� ���� �߰�

					if (s_List.IsFull())  // �ֱ� ���� ����� ���� á�ٸ�
						s_List.DeQueue(data2);  //�ֱ� ���� ��Ͽ��� ���� ������ ���� ����
					else
						s_List.EnQueue(data2);  // �ֱ� ���� ��Ͽ��� �ֽ� ���� �߰�
				}
			}
			G_ID++; // �帣 ��ȣ ����
		}
		if (found == false)
		{
			temp.SetGenreInfo(data.GetID(), length + 1, data.GetGenre());  // temp�� �帣 ���� ����
			g_List.Add(temp);  // �帣 ����Ʈ�� �帣 ���� �߰�
			pData = g_List.GetPoint(temp); // �Էµ� ���ǰ� ��ġ�ϴ� �帣�� ã�� �����ͷ� ����Ų��
			pData->AddMusicInGenre(data2); // ����Ʈ �� ����Ʈ�� ���� �߰�

			if (s_List.IsFull())  // �ֱ� ���� ����� ���� á�ٸ�
			{
				s_List.DeQueue(data2);  // �ֱ� ���� ��Ͽ��� ���� ������ ���� ����
			}
			else
			{
				s_List.EnQueue(data2);  // �ֱ� ���� ��Ͽ��� �ֽ� ���� �߰�
			}
		}


		// ArtistList�� �߰�	
		ArtistType temp2; // �Էµ� ������ ��� �帣�� ���ϴ��� ã�� ���� ����
		ArtistType *pData2; // a_List�� �ش� �帣�� �����ͷ� ����Ű�� ���� ����

		a_List.ResetList();
		int length2 = a_List.GetLength();

		bool found2 = false;

		for (int i = 0; i < length2; i++)
		{
			int A_ID = i + 1;
			a_List.GetNextItem(temp2);
			if (temp2.GetArtistName() == data.GetArtist())
			{
				{
					found2 = true;
					temp2.SetArtistInfo(data.GetID(), A_ID, data.GetArtist());
					pData2 = a_List.GetPoint(temp2); // �Էµ� ���ǰ� ��ġ�ϴ� �帣�� ã�� �����ͷ� ����Ų��
					pData2->AddAlbumInArtist(data3); // ����Ʈ �� ����Ʈ�� ���� �߰�
				}
			}
			A_ID++; // ���� ��ȣ ����
		}
		if (found2 == false)
		{
			temp2.SetArtistInfo(data.GetID(), length + 1, data.GetArtist());  // temp�� ���� ���� ����
			a_List.Add(temp2);  // ���� ����Ʈ�� �帣 ���� �߰�
			pData2 = a_List.GetPoint(temp2); // �Էµ� ���ǰ� ��ġ�ϴ� ������ ã�� �����ͷ� ����Ų��
			pData2->AddAlbumInArtist(data3); // ����Ʈ �� ����Ʈ�� ���� �߰�
		}
	}

	m_InFile.close();	// file close

	// ���� list ���
	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	MusicType data;	// ����� �ӽ� ����
	char filename[FILENAMESIZE] = "�뷡���.txt";
	//cout << "\n\t������ ���ϸ��� ������ �ּ��� : ";
	//cin >> filename;


	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenOutFile(filename))
	{
		cout << "\n\t������ �������� �ʽ��ϴ�!";
		return 0;
	}
		
	// list �����͸� �ʱ�ȭ
	m_List.ResetList();

	// list�� ���̸� ���Ϲ޾� ����
	int length = m_List.GetLength();

	// iteration�� �̿��Ͽ� ��� item ���
	for (int i = 0; i<length; i++)
	{
		m_List.GetNextItem(data);
		data.WriteDataToFile(m_OutFile);
	}

	cout << "\n\t���忡 �����߽��ϴ�!";
	m_OutFile.close();	// file close

	return 1;
}


// �����Ͽ� ���� �߰�
int Application::AddToPlayMusic()
{
	MusicType copy;
	PlayType temp; // �Էµ� ������ ��� �帣�� ���ϴ��� ã�� ���� ����
	PlayType *pData; // p_List�� �ش� �帣�� �����ͷ� ����Ű�� ���� ����

	temp.SetPlayRecordFromKB();

	m_List.ResetList();
	p_List.ResetList();
	int length = p_List.GetLength();
	int m_length = m_List.GetLength();

	bool found = false;

	for (int i = 0; i < m_length; i++)
	{
		m_List.GetNextItem(copy);
		for (int i = 0; i <= length; i++)
		{
			if (temp.GetPlayName() == copy.GetName())
			{
				if (temp.GetPlayArtist() == copy.GetArtist())
				{
					found = true;
					temp.SetPlayInfo(copy.GetID(), copy.GetNumber(), copy.GetLong(), copy.GetName(), copy.GetArtist());
					p_List.Add(temp);
					cout << "\n\t������ �߰��Ǿ����ϴ�!";
					return 0;
				}
			}
		}
	}
	if (found == false)
	{
		cout << "\n\t������ �������� �ʽ��ϴ�!";
		return 1;
	}
}

// �����Ͽ� �ִ� ���� ����
int Application::DeletePlayMusic()
{
	p_List.ResetList();
	int pre = p_List.GetLength();//���� item������ �޾ƿ´�.
	PlayType item;

	item.SetPlayIDFromKB();

	p_List.Delete(item);

	if (pre> p_List.GetLength()) //���� item�������� ���� item������ �������� ���ż���
	{
		cout << endl;
		cout << "<===========! ���� ���� !===========>" << endl;
		

		// list�� ��� �����͸� ȭ�鿡 ���
		p_List.ResetList();

		for (int i = 0; i < p_List.GetLength(); i++)
		{
			p_List.GetNextItem(item);
			item.DisplayPlayOnScreen();
			cout << endl;
		}
		return 1;
	}

	cout << "<===========! ���� ���� !===========>" << endl;
	cout << endl;
	cout << "\n\t���� ���" << endl;
	p_List.ResetList();

	for (int i = 0; i < p_List.GetLength(); i++)
	{
		p_List.GetNextItem(item);
		item.DisplayPlayOnScreen();
		cout << endl;
	}
	return 0;
}

// ������ ������ �����Ͽ� �߰��Ѵ�.
void Application::PlayMusic()
{
	PlayType item;
	PlayType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� ItemType.
	item.SetPlayRecordFromKB();
	p_List.ResetList();

	int count = 0;
	for (int i = 0; i < p_List.GetLength(); i++)
	{
		p_List.GetNextItem(temp);
		if (temp.GetPlayName() == (item.GetPlayName()))	//find�Լ������� ��ġ�ϴ� �׸��� �������� ������ -1�� �����ϹǷ� -1�� �ƴϸ� ��ġ�ϴ� ���ڿ��� �ִ°��̴�.
		{
			if (temp.GetPlayArtist() == (item.GetPlayArtist()))
			{
				cout << "<==============I ����� !============>" << endl;
				temp.DisplayPlayOnScreen();
				cout << "<====================================>" << endl;
				count++;	
				int repetition = temp.GetPlayTime();
				repetition++; //����� Ƚ���� 1 �÷��ش�.
				temp.SetPlayTime(repetition);
				item.SetPlayTime(repetition);
				//p_List.Replace(temp);


				if (!rp_List.Get(temp))
				{
					rp_List.Add(temp);
					break;
				}
				else
				{
					if (temp.GetPlayArtist() == (item.GetPlayArtist()))
						break;
				}
			}
		}
	}
	if (count == 0)
		cout << "<======I �������� ã�� �� �����ϴ� !=======>" << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}

//ȸ�� ����
void Application::uRegister()
{
	string id;
	string password, name;
	User user;
	cout << "\t\tȸ�������� �����մϴ�.\n\tID : ";
	cin >> id;	//����ڿ��Լ� ID�� �Է¹޴´�.
	users.ResetList();
	for (int i = 0; i < users.GetLength(); i++)
	{
		users.GetNextItem(user);
		if (user.getId() == id)
		{
			cout << "\t\t�ߺ��� id�� �ֽ��ϴ�. ���� �޴��� ���ư��ϴ�." << endl;
			return;
		}
	}	//�ߺ� �˻縦 �Ѵ�.
	cout << "\t�н����� : ";
	cin >> password;
	cout << "\t�̸� : ";
	cin >> name;	//��й�ȣ�� �̸��� �Է¹޴´�.

	User user2;
	user2.setUser(id, password, name);	//�ش� ������ �����Ѵ�.
	users.Add(user2);	//ȸ�� ����Ʈ�� �߰��Ѵ�.
	cout << "\n\tȸ�������� ���������� �Ϸ�Ǿ����ϴ�. �ٽ� �α����ϼ���." << endl;
}


//ȸ�� �α���
void Application::userLogin()
{
	while (true)
	{
		string id;
		string pw;
		User dummy;
		cout << "\tID : ";
		cin >> id;
		cout << "\tPassword : ";
		cin >> pw;	//����ڿ��Լ� ID�� ��й�ȣ�� �Է¹޴´�.
		users.ResetList();
		for (int i = 0; i < users.GetLength(); i++)
		{
			users.GetNextItem(dummy);
			loginedUser = users.GetPoint(dummy);
			if (dummy.getId() == id && dummy.getPW() == pw)
			{
				cout << "\t�α��ο� �����߽��ϴ�!!";
				return;
			}
			loginedUser = NULL;
		}	//�ش� ȸ���� ������ ������ �����ϰ�, ã�� �� ������ NULL�� �����Ѵ�.
		int usr;
		cout << "\t�α��ο� �����߽��ϴ�.\n\t�ٽ� �õ��Ͻðڽ��ϱ�?\n\t 1.��\t2.�ƴϿ�\n";
		cout << endl << "\t --> ";
		cin >> usr;
		if (usr == 2)
			return;
		else if (usr == 1)
			continue;
		else
			cout << "\t�߸� �Է��ϼ̽��ϴ�." << endl;
	}
	return;
}

//ȸ�� �α���
void Application::userAdminLogin()
{
	while (true)
	{
		string id;
		string pw;
		int adminpw;
		User dummy;
		cout << "\tID : ";
		cin >> id;
		cout << "\tPassword : ";
		cin >> pw;	//����ڿ��Լ� ID�� ��й�ȣ�� �Է¹޴´�.
		cout << "\tAdmin Code : ";
		cin >> adminpw;


		if (dummy.getId() == id && dummy.getPW() == pw && dummy.getAdmin() == adminpw)
		{
			users.Add(dummy);
			loginedUser = users.GetPoint(dummy);
			cout << "\t�α��ο� �����߽��ϴ�!!";
			return;
		}
		loginedUser = NULL;
		//�ش� ȸ���� ������ ������ �����ϰ�, ã�� �� ������ NULL�� �����Ѵ�.
		int usr;
		cout << "\t�α��ο� �����߽��ϴ�.\n\t�ٽ� �õ��Ͻðڽ��ϱ�?\n\t 1.��\t2.�ƴϿ�\n";
		cout << endl << "\t --> ";
		cin >> usr;
		if (usr == 2)
			return;
		else if (usr == 1)
			continue;
		else
			cout << "\t�߸� �Է��ϼ̽��ϴ�." << endl;
	}
	return;
}

//ȸ�� ���� �ҷ�����
void Application::GetUserFromFile()
{	
	m_InFile.open("UserList.txt");

	User temp;
	string id;
	string pw, name;	//���� ����
	while (!m_InFile.eof())
	{
		m_InFile >> id;
		if (m_InFile.eof())
			break;
		m_InFile >> pw >> name;	//ȸ�� ���� �Է¹ޱ�
		temp.setUser(id, pw, name);	//ȸ�� ���� ����
		users.Add(temp);	//�ش� ȸ�� �߰�
	}

	m_InFile.close();
}

void Application::SetUserToFile()
{
	m_OutFile.open("UserList.txt");
	User temp;

	users.ResetList();
	for (int i = 0; i<users.GetLength(); i++)
	{
		users.GetNextItem(temp);
		m_OutFile << temp.getId() << '\t' << temp.getPW() << '\t' << temp.getName();
		if (i != (users.GetLength()) - 1)
			m_OutFile << endl;
	}	//��ü ȸ�� ���� ���Ͽ� ����ϱ�

	m_OutFile.close();
}