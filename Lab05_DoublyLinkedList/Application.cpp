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
			SearchByName(RetreiveRecordByName());
			break;
		case 5:	// ����Ʈ�� �ִ� ���� �˻�
				// ��, �˻�� ������ ���Եȴٸ� ����Ѵ�
			SearchByArtist(RetreiveRecordByArtist());
			break;
		case 6:	// ����Ʈ�� �ִ� �ٹ� �˻�
				// ��, �˻�� �ٹ��� ���Եȴٸ� ����Ѵ�
			SearchByAlbum(RetreiveRecordByAlbum());
			break;
		case 7:	// ����Ʈ�� �ִ� �帣 �˻�
				// ��, �˻�� �帣�� ���Եȴٸ� ����Ѵ�
			A_FindNDispGenrUsingMlist(RetreiveRecordByGenre());
			break;
		case 8:	// �帣���� ���� ����Ʈ�� ���
			B_FindNDispGenrUsingGlist();
			break;
		case 9:	// �帣���� ���� ����Ʈ�� ���
			C_FindNDispGenrUsingGlist();
			break;
		case 10:	// �ֱ� �߰��� ���� ����Ʈ�� ���
			DisplayNewMusic();
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
	cout << "\t   7 : A - Display music by Genre (FindNDispGenrUsingMlist)" << endl;
	cout << "\t   8 : B - Display music by Genre (FindNDispGenrUsingGlist)" << endl;
	cout << "\t   9 : C - Display music by Genre (Static)" << endl;
	cout << "\t   10 : Display new music" << endl;
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

	if (m_List.Get(indata1)!=NULL) // �������� �ߺ��Ǵ��� Ȯ��
	{
		cout << endl;
		cout << "\t<====IMusic ID already exist!====>" << endl;
		return 0;
	}														
	m_List.Add(indata1); // MusicList�� �߰�

	// GenreList�� �߰�	
	GenreType temp; // �Էµ� ������ ��� �帣�� ���ϴ��� ã�� ���� ����
	GenreType *pData; // g_List�� �ش� �帣�� �����ͷ� ����Ű�� ���� ����
	DoublyIterator<GenreType> g_itor(g_List);


	int length = g_List.GetLength();
	bool found = false;

	for (int i = 0; i < length; i++)
	{
		int G_ID = i + 1;
		g_itor.Next(temp);
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
	return 1;
}

// ������� �������� ã�� ����Ѵ�.
MusicType Application::RetreiveRecordByName()
{
	MusicType item;
	item.SetNameFromKB(); //Name�Է¹޴´�.
	return item;	//temp���� �Ѱ��ش�.
}

// ���������� �������� ã�� ����Ѵ�.
MusicType Application::RetreiveRecordByArtist()
{
	MusicType temp;
	temp.SetArtistFromKB();	//SearchListByMusicArtist�Լ��� �Ѱ��� temp�� name�� ����ڿ��� �Է¹޴´�.
	return temp;	//temp���� �Ѱ��ش�.
}
// �ٹ������� �������� ã�� ����Ѵ�.
MusicType Application::RetreiveRecordByAlbum()
{
	MusicType temp;
	temp.SetAlbumFromKB();	//SearchListByMusicAlbum�Լ��� �Ѱ��� temp�� name�� ����ڿ��� �Է¹޴´�.
	return temp;	//temp���� �Ѱ��ش�.
}

// �帣������ �������� ã�� ����Ѵ�.
MusicType Application::RetreiveRecordByGenre()
{
	MusicType temp;
	temp.SetGenreFromKB();	//SearchListByMusicGenre�Լ��� �Ѱ��� temp�� name�� ����ڿ��� �Է¹޴´�.
	return temp;	//temp���� �Ѱ��ش�.
}

// ������� �������� ã�� ����Ѵ�.
void Application::SearchByName(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� ItemType.
	DoublyIterator<MusicType> itor(m_List);
	itor.Next(temp);
	int count = 0;

	while (itor.NextNotNull())
	{
		if (temp.GetName().find(inData.GetName()) != -1)	//find�Լ������� ��ġ�ϴ� �׸��� �������� ������ -1�� �����ϹǷ� -1�� �ƴϸ� ��ġ�ϴ� ���ڿ��� �ִ°��̴�.
		{
			cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
			cout << "<====================================>" << endl;
			itor.Next(temp);
			count++;
		}
	}
	if (count == 0)
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}

// ���������� �������� ã�� ����Ѵ�.
void Application::SearchByArtist(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� ItemType.
	DoublyIterator<MusicType> itor(m_List);
	itor.Next(temp);
	int count = 0;

	while (itor.NextNotNull())
	{
		if (temp.GetArtist().find(inData.GetArtist()) != -1)	//find�Լ������� ��ġ�ϴ� �׸��� �������� ������ -1�� �����ϹǷ� -1�� �ƴϸ� ��ġ�ϴ� ���ڿ��� �ִ°��̴�.
		{
			cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
			cout << "<====================================>" << endl;
			itor.Next(temp);
			count++;
		}
	}
	if (count == 0)
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}

// �ٹ������� �������� ã�� ����Ѵ�.
void Application::SearchByAlbum(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� ItemType.
	DoublyIterator<MusicType> itor(m_List);
	itor.Next(temp);
	int count = 0;

	while (itor.NextNotNull())
	{
		if (temp.GetAlbum().find(inData.GetAlbum()) != -1)	//find�Լ������� ��ġ�ϴ� �׸��� �������� ������ -1�� �����ϹǷ� -1�� �ƴϸ� ��ġ�ϴ� ���ڿ��� �ִ°��̴�.
		{
			cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
			cout << "<====================================>" << endl;
			itor.Next(temp);
			count++;
		}
	}
	if (count == 0)
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}

// �帣������ �������� ã�� ����Ѵ�.
void Application::A_FindNDispGenrUsingMlist(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� ItemType.
	DoublyIterator<MusicType> itor(m_List);
	itor.Next(temp);
	int count = 0;

	while (itor.NextNotNull())
	{
		if (temp.GetGenre().find(inData.GetGenre()) != -1)	//find�Լ������� ��ġ�ϴ� �׸��� �������� ������ -1�� �����ϹǷ� -1�� �ƴϸ� ��ġ�ϴ� ���ڿ��� �ִ°��̴�.
		{
			cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
			cout << "<====================================>" << endl;
			itor.Next(temp);
			count++;
		}
	}
	if (count == 0)
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}

//���ȣ�� ������ ã�Ƽ� �����Ѵ�.
int Application::DeleteMusic()
{
	int pre = m_List.GetLength();//���� item������ �޾ƿ´�.
	int length = g_List.GetLength();

	MusicType item;
	SimpleMusicType simpleitem;

	GenreType temp; // �Էµ� ������ ��� �帣�� ���ϴ��� ã�� ���� ����
	GenreType *pData; // g_List�� �ش� �帣�� �����ͷ� ����Ű�� ���� ����
	DoublyIterator<GenreType> g_itor(g_List);
	int num;
	cout << "\tID : ";
	cin >> num;

	item.SetID(num);
	simpleitem.SetID(num);

	m_List.Delete(item);

	while(g_itor.NextNotNull())
	{
		g_itor.Next(temp);
		if (temp.GetID() == item.GetID())
		{
			pData = g_List.GetPoint(temp); // �Էµ� ���ǰ� ��ġ�ϴ� �帣�� ã�� �����ͷ� ����Ų��
			pData->DeleteMusicInGenre(simpleitem); // ����Ʈ �� ����Ʈ�� �ִ� ���� ����
		}
	}

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

	cout << "\n\t���� ���� ���� �Ϸ�!!!";
	this->DisplayAllMusic();
	return 0;
}

// �ֱ� ���� ����� ����Ѵ�(30�� ����)
void Application::DisplayNewMusic()
{
	s_List.Print();
}

// ����Ʈ�� ����� ��� �����͸� ����Ѵ�.
void Application::DisplayAllMusic()
{
	MusicType data;

	cout << "\n\tCurrent list" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	DoublyIterator<MusicType> itor(m_List);
	itor.Next(data);
	while (itor.NextNotNull())
	{
		data.DisplayRecordOnScreen();
		itor.Next(data);
	}
}

// ���� ����Ʈ�� �帣���� ����Ѵ�.
int Application::B_FindNDispGenrUsingGlist()
{
	GenreType* data;
	GenreType forGetData;
	DoublyIterator<GenreType> g_itor(g_List);
	DoublySortedLinkedList<SimpleMusicType> *smlist;
	

	cout << "\n\tCurrent list" << endl;

	// genre list�� ��� �����͸� ȭ�鿡 ���
	data = g_itor.Next();
	while(g_itor.NextNotNull()) // data != NULL
	{	
		data->DisplayGenreOnScreen();
		data = g_itor.Next();
	}

	// Ư�� �帣�� ���� ������ ���� ���� ��
	int id;
	cout << "\n\tSelect Genre number : ";
	while (true)
	{
		cin >> id;
		forGetData.SetGenreId(id);
		data = g_List.Get(forGetData);

		if (data != NULL) 
		{
			smlist = data->B_DetailInfo(); // �ش� �帣 ���� ���
			DoublyIterator<SimpleMusicType> s_itor(*smlist);
			SimpleMusicType *sdata = s_itor.Next();
			while (s_itor.NextNotNull()) 
			{
				sdata->DisplayRecordOnScreen();
				sdata = s_itor.Next();
			}

			char Agree;
			cout << "\n\t���� ���λ����� Ȯ���Ͻðڽ��ϱ�? (Y/N): ";
			cin >> Agree;
			if (Agree == 'Y')
			{
				int ID;
				cout << "\n\t���� ID�� �Է��ϼ���: ";
				cin >> ID;

				MusicType *m_data;
				MusicType musicData;
				musicData.SetID(ID);
				m_data = m_List.Get(musicData);
				cout << "\n\t<���� B>\n";
				m_data->DisplayRecordOnScreen();

			}
			else
				cout << "\n\t�ش� ���� ID�� �����ϴ�!";

			return 1;
		}
		cout << "\n\t!!!! Genre number not exist !!!!";
		cout << "\n\t Please select Genre number again: ";
	}
	return 0;
}

// ���� ����Ʈ�� �帣���� ����Ѵ�.
int Application::C_FindNDispGenrUsingGlist()
{
	GenreType* data;
	GenreType forGetData;
	DoublyIterator<GenreType> g_itor(g_List);

	cout << "\n\tCurrent list" << endl;

	// genre list�� ��� �����͸� ȭ�鿡 ���
	data = g_itor.Next();
	while (g_itor.NextNotNull()) // data != NULL
	{
		data->DisplayGenreOnScreen();
		data = g_itor.Next();
	}

	// Ư�� �帣�� ���� ������ ���� ���� ��
	int id;
	cout << "\n\tSelect Genre number : ";
	while (true)
	{
		cin >> id;
		forGetData.SetGenreId(id);
		data = g_List.Get(forGetData);

		if (data != NULL)
		{
			data->C_DetailInfo(); // �ش� �帣 ���� ���

			return 1;
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

	// list�� ��� �����͸� ���Ͽ� ����
	DoublyIterator<MusicType> itor(m_List);
	itor.Next(data);
	while (itor.NextNotNull())
	{
		data.WriteDataToFile(m_OutFile);
		itor.Next(data);
	}

	m_OutFile.close();	// file close

	return 1;
}
