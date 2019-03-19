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
			RetreiveRecordByArtist();
			break;
		case 6:	// ����Ʈ�� �ִ� �ٹ� �˻�
				// ��, �˻�� �ٹ��� ���Եȴٸ� ����Ѵ�
			RetreiveRecordByAlbum();
			break;
		case 7:	// ����Ʈ�� �ִ� �帣 �˻�
				// ��, �˻�� �帣�� ���Եȴٸ� ����Ѵ�
			RetreiveRecordByGenre();
			break;
		case 8:	// ����Ʈ�� �ִ� ��� �������� ���
			DisplayAllMusic();
			break;
		case 9:	// txt ���Ͽ��� ���������� �о�´�
			ReadDataFromFile();
			break;
		case 10:	// txt ���Ͽ� ���������� ����
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
	cout << "\t   8 : Print all on screen" << endl;
	cout << "\t   9 : Get from file" << endl; 
	cout << "\t   10 : Put to file " << endl;
	cout << "\t   0 : Quit" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::AddMusic()
{

	MusicType item;
	item.SetRecordFromKB();
	if (m_List.Get(item) == 1) // �������� �ߺ��Ǵ��� Ȯ��
	{
		cout << "\tItem already exist" << endl;
		return 0;
	}

	m_List.Add(item);

	// ���� list ���
	DisplayAllMusic();

	return 1;
}

// ������� �������� ã�� ����Ѵ�.
int Application::SearchByName()
{
	MusicType item;
	item.SetNameFromKB(); //Name�Է¹޴´�.
	
	m_List.GetBinarySearch(item);
	return 0;	//����(0)�� ����
}

// ���������� �������� ã�� ����Ѵ�.
void Application::RetreiveRecordByArtist()
{
	MusicType temp;
	temp.SetArtistFromKB();	//SearchListByMusicArtist�Լ��� �Ѱ��� temp�� name�� ����ڿ��� �Է¹޴´�.
	SearchListByMusicArtist(temp);	//���������� ã�� ������ �ϴ� SearchListByMusicArtist�Լ��� ȣ���ϰ� temp���� �Ѱ��ش�.
}
// �ٹ������� �������� ã�� ����Ѵ�.
void Application::RetreiveRecordByAlbum()
{
	MusicType temp;
	temp.SetAlbumFromKB();	//SearchListByMusicAlbum�Լ��� �Ѱ��� temp�� name�� ����ڿ��� �Է¹޴´�.
	SearchListByMusicAlbum(temp);	//���������� ã�� ������ �ϴ� SearchListByMusicAlbum�Լ��� ȣ���ϰ� temp���� �Ѱ��ش�.
}

// �帣������ �������� ã�� ����Ѵ�.
void Application::RetreiveRecordByGenre()
{
	MusicType temp;
	temp.SetGenreFromKB();	//SearchListByMusicGenre�Լ��� �Ѱ��� temp�� name�� ����ڿ��� �Է¹޴´�.
	SearchListByMusicGenre(temp);	//���������� ã�� ������ �ϴ� SearchListByMusicGenre�Լ��� ȣ���ϰ� temp���� �Ѱ��ش�.
}



// ���������� �������� ã�� ����Ѵ�.
void Application::SearchListByMusicArtist(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� ItemType.
	m_List.ResetList();
	int cur = m_List.GetNextItem(temp), count = 0;	//cur�� temp�� index���� �������ش�. count�� ã�� �׸��� ������ �������ֱ� ���� ����.
	while (cur<m_List.GetLength() && cur != -1)	//index�� length�� �ѱ� ������, List�� ������ �����ϸ� GetNextItem�Լ��� -1�� �����ϹǷ� cur==-1�̾ �ݺ��� �����.
	{
		if (temp.GetArtist().find(inData.GetArtist()) != -1)	//find�Լ������� ��ġ�ϴ� �׸��� �������� ������ -1�� �����ϹǷ� -1�� �ƴϸ� ��ġ�ϴ� ���ڿ��� �ִ°��̴�.
		{
			cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
			cout << "<====================================>" << endl;
			count++;	//ã�� ������ 1 �÷��ش�.
		}
		cur = m_List.GetNextItem(temp);	//cur�� 1 �÷��ش�.
	}
	if (count == 0)
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}

// �ٹ������� �������� ã�� ����Ѵ�.
void Application::SearchListByMusicAlbum(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� ItemType.
	m_List.ResetList();
	int cur = m_List.GetNextItem(temp), count = 0;	//cur�� temp�� index���� �������ش�. count�� ã�� �׸��� ������ �������ֱ� ���� ����.
	while (cur<m_List.GetLength() && cur != -1)	//index�� length�� �ѱ� ������, List�� ������ �����ϸ� GetNextItem�Լ��� -1�� �����ϹǷ� cur==-1�̾ �ݺ��� �����.
	{
		if (temp.GetAlbum().find(inData.GetAlbum()) != -1)	//find�Լ������� ��ġ�ϴ� �׸��� �������� ������ -1�� �����ϹǷ� -1�� �ƴϸ� ��ġ�ϴ� ���ڿ��� �ִ°��̴�.
		{
			cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
			cout << "<====================================>" << endl;
			count++;	//ã�� ������ 1 �÷��ش�.
		}
		cur = m_List.GetNextItem(temp);	//cur�� 1 �÷��ش�.
	}
	if (count == 0)
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}

// �帣������ �������� ã�� ����Ѵ�.
void Application::SearchListByMusicGenre(MusicType &inData)
{
	MusicType temp;	//m_List�� ���� �����ֱ� ���� �ӽ� ItemType.
	m_List.ResetList();
	int cur = m_List.GetNextItem(temp), count = 0;	//cur�� temp�� index���� �������ش�. count�� ã�� �׸��� ������ �������ֱ� ���� ����.
	while (cur<m_List.GetLength() && cur != -1)	//index�� length�� �ѱ� ������, List�� ������ �����ϸ� GetNextItem�Լ��� -1�� �����ϹǷ� cur==-1�̾ �ݺ��� �����.
	{
		if (temp.GetGenre().find(inData.GetGenre()) != -1)	//find�Լ������� ��ġ�ϴ� �׸��� �������� ������ -1�� �����ϹǷ� -1�� �ƴϸ� ��ġ�ϴ� ���ڿ��� �ִ°��̴�.
		{
			cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
			cout << "<====================================>" << endl;
			count++;	//ã�� ������ 1 �÷��ش�.
		}
		cur = m_List.GetNextItem(temp);	//cur�� 1 �÷��ش�.
	}
	if (count == 0)
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;	//ã�� ������ 0���̸� ã�� �� ���ٴ� �޽����� ����Ѵ�.
}

//������� item�� ã�Ƽ� �����Ѵ�.
int Application::DeleteMusic()
{
	int pre = m_List.GetLength();//���� item������ �޾ƿ´�.
	MusicType item;
	item.SetNameFromKB();
	
	m_List.Delete(item);

	if(pre> m_List.GetLength()) //���� item�������� ���� item������ �������� ���ż���
	{
		cout<<"<========DELETE SUCCESS !===========>"<<endl;
		this->DisplayAllMusic(); //��� item�� ����Ѵ�.
		return 1;
	}
	
	cout<<"<========DELETE FAIL !=======>"<<endl;
	this->DisplayAllMusic();//��� item�� ����Ѵ�.
	return 0;
}

//�ش� ����� item�� �����Ѵ�.
int Application::ReplaceMusic()
{
	MusicType item;
	item.SetRecordFromKB(); //Ű����κ��� ������ �Է¹���

	m_List.Replace(item); //�ش� item�� ��� ��ġ�ϴ� ���� ã�� �ٲ۴�.
	this->DisplayAllMusic();
	return 0;
}


// ����Ʈ�� ����� ��� �����͸� ����Ѵ�.
void Application::DisplayAllMusic()
{
	MusicType data;

	cout << "\n\tCurrent list" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.DisplayRecordOnScreen();
		curIndex = m_List.GetNextItem(data);
	}
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
	if(!OpenOutFile(filename))
		return 0;

	// list �����͸� �ʱ�ȭ
	m_List.ResetList();

	// list�� ��� �����͸� ���Ͽ� ����
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}

