#include "Application.h"


// Program driver.
void Application::Run()
{
	while(1)
	{
		m_Command = GetCommand();

		switch(m_Command)
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
				// ��, �˻�� ��� ���Եȴٸ� ����Ѵ�
				// 	ex) �˻��� : ������� / ��� : �����ѻ��,õ���ǻ��,..
			SearchByName();
			break;
		case 5:	// ����Ʈ�� �ִ� ���� �˻�
				// ��, �˻�� ������ ���Եȴٸ� ����Ѵ�
			SearchByArtist();
			break;
		case 6:	// ����Ʈ�� �ִ� �ٹ� �˻�
				// ��, �˻�� �ٹ��� ���Եȴٸ� ����Ѵ�
			SearchByAlbum();
			break;
		case 7:	// ����Ʈ�� �ִ� �帣 �˻�
				// ��, �˻�� �帣�� ���Եȴٸ� ����Ѵ�
			SearchByGenre();
			break;
		case 8:	// �ֱ� �߰��� ���� ����Ʈ�� ���
			DisplayNewMusic();
			break;
		case 9:	// �帣���� ���� ����Ʈ�� ���
			DisplayMusicByGenre();
			break;
		case 10: // ���ȣ�� �帣��� �����ϴ� ���� ���� ���
			RetrieveByNameNGenre();
			break;
		case 11:	// ����Ʈ�� �ִ� ��� �������� ���
			DisplayAllMusic();
			break;
		case 12:	// txt ���Ͽ��� ���������� �о�´�
			ReadDataFromFile();
			break;
		case 13:	// txt ���Ͽ� ���������� ����
			WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add Music" << endl;
	cout << "\t   2 : Delete Music" << endl;
	cout << "\t   3 : Replace Music" << endl;
	cout << "\t   4 : Search music by name" << endl;
	cout << "\t   5 : Search music by Artist" << endl;
	cout << "\t   6 : Search music by Album" << endl;
	cout << "\t   7 : Search music by Genre" << endl;
	cout << "\t   8 : Display new music" << endl;
	cout << "\t   9 : Display music by Genre" << endl;
	cout << "\t   10 : Retreive by Name and Genre" << endl;
	cout << "\t   11 : Print all on screen" << endl;
	cout << "\t   12 : Get from file" << endl; 
	cout << "\t   13 : Put to file " << endl;
	cout << "\t   0 : Quit" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::AddMusic()
{
	MusicType indata1;
	SimpleMusicType indata2;

	indata1.SetRecordFromKB(); // m_List�� ���� ��� ���� ����
	indata2.SetRecord(indata1.GetID(), indata1.GetName());	// g_List�� ���� �Ϻ� ���� ����

	if (m_List.Get(indata1) == 1) // �������� �ߺ��Ǵ��� Ȯ��
	{
		cout << endl;
		cout << "\t<====IMusic ID already exist!====>" << endl;
		return 0;
	}														
	m_List.Add(indata1); // MusicList�� �߰�

	// GenreList�� �߰�	
	GenreType temp; // �Էµ� ������ ��� �帣�� ���ϴ��� ã�� ���� ����
	GenreType *pData; // g_List�� �ش� �帣�� �����ͷ� ����Ű�� ���� ����

	g_List.ResetList();
	int length = g_List.GetLength();

	bool found = false;

	for (int i = 0; i < length; i++)
	{
		int G_ID = i + 1;
		//temp.SetGenreInfo(G_ID, indata1.GetGenre());

		g_List.GetNextItem(temp);
		if (temp.GetGenreName() == indata1.GetGenre())
		{
			{
				found = true;
				temp.SetGenreInfo(G_ID, indata1.GetGenre());
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
		// �Է��� �帣�� �帣 ����Ʈ�� ���ٸ�
		//if (temp.GetGenreName() == indata1.GetGenre())
		//{
			temp.SetGenreInfo(length + 1, indata1.GetGenre());  // temp�� �帣 ���� ����
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
		//}
	}
	return 1;
}

// ������� �������� ã�� ����Ѵ�.
int Application::SearchByName()
{
	MusicType item;
	item.SetNameFromKB(); //Name�Է¹޴´�.
	SearchListByMusicName(item);
	return 0;	//����(0)�� ����
}

// ���������� �������� ã�� ����Ѵ�.
void Application::SearchByArtist()
{
	MusicType temp;
	temp.SetArtistFromKB();	//SearchListByMusicArtist�Լ��� �Ѱ��� temp�� name�� ����ڿ��� �Է¹޴´�.
	SearchListByMusicArtist(temp);	//���������� ã�� ������ �ϴ� SearchListByMusicArtist�Լ��� ȣ���ϰ� temp���� �Ѱ��ش�.
}
// �ٹ������� �������� ã�� ����Ѵ�.
void Application::SearchByAlbum()
{
	MusicType temp;
	temp.SetAlbumFromKB();	//SearchListByMusicAlbum�Լ��� �Ѱ��� temp�� name�� ����ڿ��� �Է¹޴´�.
	SearchListByMusicAlbum(temp);	//���������� ã�� ������ �ϴ� SearchListByMusicAlbum�Լ��� ȣ���ϰ� temp���� �Ѱ��ش�.
}

// �帣������ �������� ã�� ����Ѵ�.
void Application::SearchByGenre()
{
	MusicType temp;
	temp.SetGenreFromKB();	//SearchListByMusicGenre�Լ��� �Ѱ��� temp�� name�� ����ڿ��� �Է¹޴´�.
	SearchListByMusicGenre(temp);	//���������� ã�� ������ �ϴ� SearchListByMusicGenre�Լ��� ȣ���ϰ� temp���� �Ѱ��ش�.
}

// ������� �������� ã�� ����Ѵ�.
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
			cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
			cout << "<====================================>" << endl;
			count++;	//ã�� ������ 1 �÷��ش�.
		}
	}
	if (count == 0)
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}

// ���������� �������� ã�� ����Ѵ�.
void Application::SearchListByMusicArtist(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� ItemType.
	m_List.ResetList();
	int count = 0;
	for (int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(temp);
		if (temp.GetArtist().find(inData.GetArtist()) != -1)	//find�Լ������� ��ġ�ϴ� �׸��� �������� ������ -1�� �����ϹǷ� -1�� �ƴϸ� ��ġ�ϴ� ���ڿ��� �ִ°��̴�.
		{
			cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
			cout << "<====================================>" << endl;
			count++;	//ã�� ������ 1 �÷��ش�.
		}
	}
	if (count == 0)
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
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
			cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
			cout << "<====================================>" << endl;
			count++;	//ã�� ������ 1 �÷��ش�.
		}
	}
	if (count == 0)
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}

// �帣������ �������� ã�� ����Ѵ�.
void Application::SearchListByMusicGenre(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� ItemType.
	m_List.ResetList();
	int count = 0;
	for (int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(temp);
		if (temp.GetGenre().find(inData.GetGenre()) != -1)	//find�Լ������� ��ġ�ϴ� �׸��� �������� ������ -1�� �����ϹǷ� -1�� �ƴϸ� ��ġ�ϴ� ���ڿ��� �ִ°��̴�.
		{
			cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
			cout << "<====================================>" << endl;
			count++;	//ã�� ������ 1 �÷��ش�.
		}
	}
	if (count == 0)
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}

//���ȣ�� ������ ã�Ƽ� �����Ѵ�.
int Application::DeleteMusic()
{
	int pre = m_List.GetLength();//���� item������ �޾ƿ´�.
	MusicType item;
	item.SetIDFromKB();
	
	m_List.Delete(item);

	if(pre> m_List.GetLength()) //���� item�������� ���� item������ �������� ���ż���
	{
		cout << endl;
		cout<<"<========DELETE SUCCESS !===========>"<<endl;
		this->DisplayAllMusic(); //��� item�� ����Ѵ�.
		return 1;
	}
	
	cout<<"<========DELETE FAIL !=======>"<<endl;
	this->DisplayAllMusic();//��� item�� ����Ѵ�.
	return 0;
}

//�ش� ����� ������ �����Ѵ�.
int Application::ReplaceMusic()
{
	MusicType item;
	item.SetRecordFromKB(); //Ű����κ��� ������ �Է¹���

	m_List.Replace(item); //�ش� item�� ��� ��ġ�ϴ� ���� ã�� �ٲ۴�.
	this->DisplayAllMusic();
	return 0;
}

// �ֱ� ���� ����� ����Ѵ�(30�� ����)
void Application::DisplayNewMusic()
{
	s_List.Print();
}

// ���� �帣������ ������ ã�� �� �̸� ����Ѵ�.
void Application::RetrieveByNameNGenre()
{
	MusicType item;
	item.SetNameFromKB();
	item.SetGenreFromKB();

	MusicType temp;
	m_List.ResetList();
	int count = 0;
	for (int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(temp);
		if (temp.GetName().find(item.GetName()) != -1)
		{
			if (temp.GetGenre().find(item.GetGenre()) != -1)
			{
				cout << "<============I FOUND ITEM !==========>" << endl;
				temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
				cout << "<====================================>" << endl;
				count++;	//ã�� ������ 1 �÷��ش�.
			}
		}
	}
	if (count == 0)
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}

// ����Ʈ�� ����� ��� �����͸� ����Ѵ�.
void Application::DisplayAllMusic()
{
	MusicType data;

	cout << "\n\tCurrent list" << endl;

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

	cout << "\n\tCurrent list" << endl;

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

	cout << "\n\tSelect Genre number : ";
	while (true)
	{
		cin >> id;
		g_List.ResetList();
		for (int i = 0; i < length; i++)
		{
			g_List.GetNextItem(data);
			if (data.GetGenreId() == id)
			{
				data.SetGenreInfo(id, "");
				pData = g_List.GetPoint(data);
				pData->DisplayMusicDetailInGenre(&m_List); // �ش� �帣 ���� ���
				return 1;
			}
		}
		cout << "\n\t!!!! Genre number not exist !!!!";
		cout << "\n\t Please select Genre number again: ";
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
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenInFile(filename))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while(!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// ���� list ���
	DisplayAllMusic();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	MusicType data;	// ����� �ӽ� ����
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenOutFile(filename))
		return 0;

	// list �����͸� �ʱ�ȭ
	m_List.ResetList();

	// list�� ���̸� ���Ϲ޾� ����
	int length = m_List.GetLength();

	// iteration�� �̿��Ͽ� ��� item ���
	for (int i = 0; i<length; i++)
	{
		m_List.GetNextItem(data);
		data.WriteDataToFile(m_OutFile);
		if (i != length - 1)
			m_OutFile << endl;
	}

	m_OutFile.close();	// file close

	return 1;
}
