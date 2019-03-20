#include "Application.h"


// Program driver.
void Application::Run()
{
	while(1)
	{
		m_Command = GetCommand();

		switch(m_Command)
		{
		case 1:	// 음악 추가
			AddMusic();
			break;
		case 2:	// 리스트에서 음악 삭제
			DeleteMusic();
			break;
		case 3:	// 리스트에 있는 음악 갱신
			ReplaceMusic();
			break;
		case 4:	// 리스트에 있는 음악 검색
				// 단, 검색어가 곡명에 포함된다면 출력한다
				// 	ex) 검색어 : ‘사랑’ / 출력 : 가난한사랑,천년의사랑,..
			SearchByName(RetreiveRecordByName());
			break;
		case 5:	// 리스트에 있는 가수 검색
				// 단, 검색어가 가수명에 포함된다면 출력한다
			SearchByArtist(RetreiveRecordByArtist());
			break;
		case 6:	// 리스트에 있는 앨범 검색
				// 단, 검색어가 앨범명에 포함된다면 출력한다
			SearchByAlbum(RetreiveRecordByAlbum());
			break;
		case 7:	// 리스트에 있는 장르 검색
				// 단, 검색어가 장르명에 포함된다면 출력한다
			A_FindNDispGenrUsingMlist(RetreiveRecordByGenre());
			break;
		case 8:	// 장르별로 음악 리스트를 출력
			B_FindNDispGenrUsingGlist();
			break;
		case 9:	// 장르별로 음악 리스트를 출력
			C_FindNDispGenrUsingGlist();
			break;
		case 10:	// 최근 추가된 음악 리스트를 출력
			DisplayNewMusic();
			break;
		case 11:	// 리스트에 있는 모든 음악정보 출력
			DisplayAllMusic();
			break;
		case 12:	// txt 파일에서 음악정보를 읽어온다
			ReadDataFromFile();
			break;
		case 13:	// txt 파일에 음악정보를 쓴다
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

	indata1.SetRecordFromKB(); // m_List에 넣을 모든 음악 정보
	indata2.SetRecord(indata1.GetID(), indata1.GetName());	// g_List에 넣을 일부 음악 정보

	if (m_List.Get(indata1)!=NULL) // 아이템이 중복되는지 확인
	{
		cout << endl;
		cout << "\t<====IMusic ID already exist!====>" << endl;
		return 0;
	}														
	m_List.Add(indata1); // MusicList에 추가

	// GenreList에 추가	
	GenreType temp; // 입력된 음악이 어느 장르에 속하는지 찾기 위한 더미
	GenreType *pData; // g_List의 해당 장르를 포인터로 가르키기 위한 더미
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
				pData = g_List.GetPoint(temp); // 입력된 음악과 일치하는 장르를 찾아 포인터로 가르킨다
				pData->AddMusicInGenre(indata2); // 리스트 안 리스트에 음악 추가

				if (s_List.IsFull())  // 최근 음악 목록이 가득 찼다면
					s_List.DeQueue(indata2);  //최근 음악 목록에서 가장 오래된 음악 제거
				else
					s_List.EnQueue(indata2);  // 최근 음악 목록에서 최신 음악 추가
			}
		}
		G_ID++; // 장르 번호 증가
	}
	if (found == false)
	{
		temp.SetGenreInfo(indata1.GetID(), length + 1, indata1.GetGenre());  // temp에 장르 정보 저장
		g_List.Add(temp);  // 장르 리스트에 장르 정보 추가
		pData = g_List.GetPoint(temp); // 입력된 음악과 일치하는 장르를 찾아 포인터로 가르킨다
		pData->AddMusicInGenre(indata2); // 리스트 안 리스트에 음악 추가

		if (s_List.IsFull())  // 최근 음악 목록이 가득 찼다면
		{
			s_List.DeQueue(indata2);  // 최근 음악 목록에서 가장 오래된 음악 제거
		}
		else
		{
			s_List.EnQueue(indata2);  // 최근 음악 목록에서 최신 음악 추가
		}
	}
	return 1;
}

// 곡명으로 아이템을 찾아 출력한다.
MusicType Application::RetreiveRecordByName()
{
	MusicType item;
	item.SetNameFromKB(); //Name입력받는다.
	return item;	//temp값을 넘겨준다.
}

// 가수명으로 아이템을 찾아 출력한다.
MusicType Application::RetreiveRecordByArtist()
{
	MusicType temp;
	temp.SetArtistFromKB();	//SearchListByMusicArtist함수에 넘겨줄 temp의 name을 사용자에게 입력받는다.
	return temp;	//temp값을 넘겨준다.
}
// 앨범명으로 아이템을 찾아 출력한다.
MusicType Application::RetreiveRecordByAlbum()
{
	MusicType temp;
	temp.SetAlbumFromKB();	//SearchListByMusicAlbum함수에 넘겨줄 temp의 name을 사용자에게 입력받는다.
	return temp;	//temp값을 넘겨준다.
}

// 장르명으로 아이템을 찾아 출력한다.
MusicType Application::RetreiveRecordByGenre()
{
	MusicType temp;
	temp.SetGenreFromKB();	//SearchListByMusicGenre함수에 넘겨줄 temp의 name을 사용자에게 입력받는다.
	return temp;	//temp값을 넘겨준다.
}

// 곡명으로 아이템을 찾아 출력한다.
void Application::SearchByName(MusicType &inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 ItemType.
	DoublyIterator<MusicType> itor(m_List);
	itor.Next(temp);
	int count = 0;

	while (itor.NextNotNull())
	{
		if (temp.GetName().find(inData.GetName()) != -1)	//find함수에서는 일치하는 항목이 존재하지 않을때 -1을 리턴하므로 -1이 아니면 일치하는 문자열이 있는것이다.
		{
			cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();	//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
			cout << "<====================================>" << endl;
			itor.Next(temp);
			count++;
		}
	}
	if (count == 0)
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}

// 가수명으로 아이템을 찾아 출력한다.
void Application::SearchByArtist(MusicType &inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 ItemType.
	DoublyIterator<MusicType> itor(m_List);
	itor.Next(temp);
	int count = 0;

	while (itor.NextNotNull())
	{
		if (temp.GetArtist().find(inData.GetArtist()) != -1)	//find함수에서는 일치하는 항목이 존재하지 않을때 -1을 리턴하므로 -1이 아니면 일치하는 문자열이 있는것이다.
		{
			cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();	//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
			cout << "<====================================>" << endl;
			itor.Next(temp);
			count++;
		}
	}
	if (count == 0)
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}

// 앨범명으로 아이템을 찾아 출력한다.
void Application::SearchByAlbum(MusicType &inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 ItemType.
	DoublyIterator<MusicType> itor(m_List);
	itor.Next(temp);
	int count = 0;

	while (itor.NextNotNull())
	{
		if (temp.GetAlbum().find(inData.GetAlbum()) != -1)	//find함수에서는 일치하는 항목이 존재하지 않을때 -1을 리턴하므로 -1이 아니면 일치하는 문자열이 있는것이다.
		{
			cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();	//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
			cout << "<====================================>" << endl;
			itor.Next(temp);
			count++;
		}
	}
	if (count == 0)
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}

// 장르명으로 아이템을 찾아 출력한다.
void Application::A_FindNDispGenrUsingMlist(MusicType &inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 ItemType.
	DoublyIterator<MusicType> itor(m_List);
	itor.Next(temp);
	int count = 0;

	while (itor.NextNotNull())
	{
		if (temp.GetGenre().find(inData.GetGenre()) != -1)	//find함수에서는 일치하는 항목이 존재하지 않을때 -1을 리턴하므로 -1이 아니면 일치하는 문자열이 있는것이다.
		{
			cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();	//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
			cout << "<====================================>" << endl;
			itor.Next(temp);
			count++;
		}
	}
	if (count == 0)
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}

//곡번호로 음악을 찾아서 제거한다.
int Application::DeleteMusic()
{
	int pre = m_List.GetLength();//이전 item개수를 받아온다.
	int length = g_List.GetLength();

	MusicType item;
	SimpleMusicType simpleitem;

	GenreType temp; // 입력된 음악이 어느 장르에 속하는지 찾기 위한 더미
	GenreType *pData; // g_List의 해당 장르를 포인터로 가르키기 위한 더미
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
			pData = g_List.GetPoint(temp); // 입력된 음악과 일치하는 장르를 찾아 포인터로 가르킨다
			pData->DeleteMusicInGenre(simpleitem); // 리스트 안 리스트에 있는 음악 제거
		}
	}

	if(pre> m_List.GetLength()) //이전 item개수보다 현재 item개수가 많아지면 제거성공
	{
		cout << endl;
		cout<<"<========DELETE SUCCESS !===========>"<<endl;
		this->DisplayAllMusic(); //모든 item을 출력한다.
		return 1;
	}
	
	cout<<"<========DELETE FAIL !=======>"<<endl;
	this->DisplayAllMusic();//모든 item을 출력한다.
	return 0;
}

//해당 곡명의 정보를 변경한다.
int Application::ReplaceMusic()
{
	MusicType item;
	item.SetRecordFromKB(); //키보드로부터 정보를 입력받음

	m_List.Replace(item); //해당 item의 곡명 일치하는 것을 찾아 바꾼다.

	cout << "\n\t음악 정보 수정 완료!!!";
	this->DisplayAllMusic();
	return 0;
}

// 최근 음악 목록을 출력한다(30개 이하)
void Application::DisplayNewMusic()
{
	s_List.Print();
}

// 리스트에 저장된 모든 데이터를 출력한다.
void Application::DisplayAllMusic()
{
	MusicType data;

	cout << "\n\tCurrent list" << endl;

	// list의 모든 데이터를 화면에 출력
	DoublyIterator<MusicType> itor(m_List);
	itor.Next(data);
	while (itor.NextNotNull())
	{
		data.DisplayRecordOnScreen();
		itor.Next(data);
	}
}

// 음악 리스트를 장르별로 출력한다.
int Application::B_FindNDispGenrUsingGlist()
{
	GenreType* data;
	GenreType forGetData;
	DoublyIterator<GenreType> g_itor(g_List);
	DoublySortedLinkedList<SimpleMusicType> *smlist;
	

	cout << "\n\tCurrent list" << endl;

	// genre list의 모든 데이터를 화면에 출력
	data = g_itor.Next();
	while(g_itor.NextNotNull()) // data != NULL
	{	
		data->DisplayGenreOnScreen();
		data = g_itor.Next();
	}

	// 특정 장르의 음악 정보만 보고 싶을 때
	int id;
	cout << "\n\tSelect Genre number : ";
	while (true)
	{
		cin >> id;
		forGetData.SetGenreId(id);
		data = g_List.Get(forGetData);

		if (data != NULL) 
		{
			smlist = data->B_DetailInfo(); // 해당 장르 음악 출력
			DoublyIterator<SimpleMusicType> s_itor(*smlist);
			SimpleMusicType *sdata = s_itor.Next();
			while (s_itor.NextNotNull()) 
			{
				sdata->DisplayRecordOnScreen();
				sdata = s_itor.Next();
			}

			char Agree;
			cout << "\n\t음악 세부사항을 확인하시겠습니까? (Y/N): ";
			cin >> Agree;
			if (Agree == 'Y')
			{
				int ID;
				cout << "\n\t음악 ID를 입력하세요: ";
				cin >> ID;

				MusicType *m_data;
				MusicType musicData;
				musicData.SetID(ID);
				m_data = m_List.Get(musicData);
				cout << "\n\t<과제 B>\n";
				m_data->DisplayRecordOnScreen();

			}
			else
				cout << "\n\t해당 음악 ID가 없습니다!";

			return 1;
		}
		cout << "\n\t!!!! Genre number not exist !!!!";
		cout << "\n\t Please select Genre number again: ";
	}
	return 0;
}

// 음악 리스트를 장르별로 출력한다.
int Application::C_FindNDispGenrUsingGlist()
{
	GenreType* data;
	GenreType forGetData;
	DoublyIterator<GenreType> g_itor(g_List);

	cout << "\n\tCurrent list" << endl;

	// genre list의 모든 데이터를 화면에 출력
	data = g_itor.Next();
	while (g_itor.NextNotNull()) // data != NULL
	{
		data->DisplayGenreOnScreen();
		data = g_itor.Next();
	}

	// 특정 장르의 음악 정보만 보고 싶을 때
	int id;
	cout << "\n\tSelect Genre number : ";
	while (true)
	{
		cin >> id;
		forGetData.SetGenreId(id);
		data = g_List.Get(forGetData);

		if (data != NULL)
		{
			data->C_DetailInfo(); // 해당 장르 음악 출력

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
	
	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if(!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if(!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	MusicType data;	// 읽기용 임시 변수
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if(!OpenInFile(filename))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while(!m_InFile.eof())
	{
		// array에 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// 현재 list 출력
	DisplayAllMusic();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	MusicType data;	// 쓰기용 임시 변수
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenOutFile(filename))
		return 0;

	// list의 모든 데이터를 파일에 쓰기
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
