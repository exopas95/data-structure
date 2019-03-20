#include "Application.h"


// Program driver.
void Application::Run()
{
	int select = -1;
	int login = 0;
	while (select != 0)	//0번을 입력받으면 종료한다.
	{
		loginedUser = NULL;
		cout << endl << endl;
		cout << "\t*-------------------------*" << endl;
		cout << "\t| 1 : 관리자 로그인       |" << endl;
		cout << "\t| 2 : 로그인              |" << endl;
		cout << "\t| 3 : 회원가입            |" << endl;
		cout << "\t| 0 : 종료                |" << endl;
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
			uRegister();	//회원가입
			SetUserToFile();
			break;
		case 0:
			return;
		default:
			cout << "\t다시 입력해 주세요.";
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
						// 단, 검색어가 음악명에 포함된다면 출력한다
						// 	ex) 검색어 : ‘사랑’ / 출력 : 가난한사랑,천년의사랑,..
					SearchByID();
					break;
				case 5:	// 리스트에 있는 음악 검색
						// 단, 검색어가 음악명에 포함된다면 출력한다
						// 	ex) 검색어 : ‘사랑’ / 출력 : 가난한사랑,천년의사랑,..
					SearchByName();
					break;
				case 6:	// 리스트에 있는 가수 검색
						// 단, 검색어가 가수명에 포함된다면 출력한다
					DisplayMusicByArtist();
					break;
				case 7:	// 리스트에 있는 앨범 검색
						// 단, 검색어가 앨범명에 포함된다면 출력한다
					SearchByAlbum();
					break;
				case 8:	// 리스트에 있는 장르 검색
						// 단, 검색어가 장르명에 포함된다면 출력한다
					DisplayMusicByGenre();
					break;
				case 9:	// 리스트에 있는 재생횟수 검색
						// 단, 검색어가 재생횟수에 포함된다면 출력한다
					SearchByRepetition();
					break;
				case 10:	// 최근 추가된 음악 리스트를 출력
					DisplayNewMusic();
					break;
				case 11:	// 최근 재생목록에 추가된 음악 리스트를 출력
					DisplayPlayNewMusic();
					break;
				case 12:	// 리스트에 있는 모든 음악정보 출력
					DisplayAllMusic();
					break;
				case 13:	// txt 파일에서 음악정보를 읽어온다
					ReadDataFromFile();
					break;
				case 14:	// txt 파일에 음악정보를 쓴다
					WriteDataToFile();
					break;
				case 15:	// 음악을 재생목록에 추가한다.
					AddToPlayMusic();
					break;
				case 16:	// 음악을 재생목록에 추가한다.
					DeletePlayMusic();
					break;
				case 17:	// 음악을 재생한다.
					PlayMusic();
					break;
				case 0:
					i = 2;
					break;
				default:
					cout << "\t---------------------------" << endl;
					cout << "\ 올바르지 않은 명령어 입니다...\n";
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
				case 1:	// 리스트에 있는 음악 검색
						// 단, 검색어가 음악명에 포함된다면 출력한다
						// 	ex) 검색어 : ‘사랑’ / 출력 : 가난한사랑,천년의사랑,..
					SearchByID();
					break;
				case 2:	// 리스트에 있는 음악 검색
						// 단, 검색어가 음악명에 포함된다면 출력한다
						// 	ex) 검색어 : ‘사랑’ / 출력 : 가난한사랑,천년의사랑,..
					SearchByName();
					break;
				case 3:	// 리스트에 있는 가수 검색
						// 단, 검색어가 가수명에 포함된다면 출력한다
					DisplayMusicByArtist();
					break;
				case 4:	// 리스트에 있는 앨범 검색
						// 단, 검색어가 앨범명에 포함된다면 출력한다
					SearchByAlbum();
					break;
				case 5:	// 리스트에 있는 장르 검색
						// 단, 검색어가 장르명에 포함된다면 출력한다
					DisplayMusicByGenre();
					break;
				case 6:	// 리스트에 있는 재생횟수 검색
						// 단, 검색어가 재생횟수에 포함된다면 출력한다
					SearchByRepetition();
					break;
				case 7:	// 최근 추가된 음악 리스트를 출력
					DisplayNewMusic();
					break;
				case 8:	// 최근 재생목록에 추가된 음악 리스트를 출력
					DisplayPlayNewMusic();
					break;
				case 9:	// 리스트에 있는 모든 음악정보 출력
					DisplayAllMusic();
					break;
				case 10:	// txt 파일에서 음악정보를 읽어온다
					ReadDataFromFile();
					break;
				case 11:	// txt 파일에 음악정보를 쓴다
					WriteDataToFile();
					break;
				case 12:	// 음악을 재생목록에 추가한다.
					AddToPlayMusic();
					break;
				case 13:	// 음악을 재생목록에 추가한다.
					DeletePlayMusic();
					break;
				case 14:	// 음악을 재생한다.
					PlayMusic();
					break;
				case 0:
					j = 2;
					break;
				default:
					cout << "\t---------------------------" << endl;
					cout << "\ 올바르지 않은 명령어 입니다...\n";
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
		cout << "\t   1 : 음악 추가/제거" << endl;
		cout << "\t   2 : 재생목록" << endl;
		cout << "\t   3 : 검색." << endl;
		cout << "\t   4 : 모든 음악 리스트" << endl;
		cout << "\t   5 : 정보 저장/불러오기" << endl;
		cout << "\t   0 : 로그아웃" << endl;
		cout << "\t---------------------------" << endl;
		cout << endl << "\t Choose a Command--> ";

		cin >> number;
		switch (number)
		{
		case 1:	// 음악 추가
			cout << endl << endl;
			cout << "\t---ID -- Command -----------------" << endl;
			cout << "\t   1 : 음악을 추가합니다." << endl;
			cout << "\t   2 : 음악을 제거합니다." << endl;
			cout << "\t   3 : 음악의 정보를 수정합니다." << endl;
			cout << "\t   0 : 뒤로 돌아 갑니다." << endl;
			cout << "\t----------------------------------" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			if (command != 0)
				z = 2;
			break;
		case 2:	// 리스트에서 음악 삭제
			cout << endl << endl;
			cout << "\t---ID -- Command ----------" << endl;
			cout << "\t   15 : 재생목록에 추가" << endl;
			cout << "\t   16 : 재생목록에서 제거 " << endl;
			cout << "\t   17 : 음악 재생 " << endl;
			cout << "\t   0 : 뒤로 돌아 갑니다." << endl;
			cout << "\t----------------------------" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			if (command != 0)
				z = 2;
			break;
		case 3:	// 리스트에 있는 음악 갱신
			cout << endl << endl;
			cout << "\t---ID -- Command --------------------------------" << endl;
			cout << "\t   4 : ID로 음악을 검색합니다." << endl;
			cout << "\t   5 : 제목으로 음악을 검색합니다." << endl;
			cout << "\t   6 : 가수명으로 음악을 검색합니다." << endl;
			cout << "\t   7 : 앨범명으로 음악을 검색합니다." << endl;
			cout << "\t   8 : 장르명으로 음악을 검색합니다." << endl;
			cout << "\t   9 : 재생횟수로 검색합니다" << endl;
			cout << "\t   10 : 최근 추가한 음악을 검색합니다.." << endl;
			cout << "\t   11 : 재생목록에 최근 추가한 음악을 검색합니다." << endl;
			cout << "\t   0 : 뒤로 돌아 갑니다." << endl;
			cout << "\t-------------------------------------------------" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			if (command != 0)
				z = 2;
			break;
		case 4:	// 리스트에 있는 음악 검색
				// 단, 검색어가 음악명에 포함된다면 출력한다
				// 	ex) 검색어 : ‘사랑’ / 출력 : 가난한사랑,천년의사랑,..
			command = 12;
			if (command != 0)
				z = 2;
			break;
		case 5:	// 리스트에 있는 음악 검색
				// 단, 검색어가 음악명에 포함된다면 출력한다
				// 	ex) 검색어 : ‘사랑’ / 출력 : 가난한사랑,천년의사랑,..
			cout << endl << endl;
			cout << "\t---ID -- Command ---------------------" << endl;
			cout << "\t   13 : 저장 목록을 불러옵니다." << endl;
			cout << "\t   14 : 현재까지의 결과를 저장합니다." << endl;
			cout << "\t   0 : 뒤로 돌아 갑니다." << endl;
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
			cout << "\t 올바르지 않은 명령어 입니다...\n";
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
		cout << "\t   1 : 재생목록" << endl;
		cout << "\t   2 : 검색." << endl;
		cout << "\t   3 : 모든 음악 리스트" << endl;
		cout << "\t   4 : 정보 저장/불러오기" << endl;
		cout << "\t   0 : 로그아웃" << endl;
		cout << "\t---------------------------" << endl;
		cout << endl << "\t Choose a Command--> ";

		cin >> number;
		switch (number)
		{
		case 1:	// 리스트에서 음악 삭제
			cout << endl << endl;
			cout << "\t---ID -- Command ----------" << endl;
			cout << "\t   12 : 재생목록에 추가" << endl;
			cout << "\t   13 : 재생목록에서 제거 " << endl;
			cout << "\t   14 : 음악 재생 " << endl;
			cout << "\t   0 : 뒤로 돌아 갑니다." << endl;
			cout << "\t----------------------------" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			if(command != 0)
				h = 2;
			break;
		case 2:	// 리스트에 있는 음악 갱신
			cout << endl << endl;
			cout << "\t---ID -- Command --------------------------------" << endl;
			cout << "\t   1 : ID로 음악을 검색합니다." << endl;
			cout << "\t   2 : 제목으로 음악을 검색합니다." << endl;
			cout << "\t   3 : 가수명으로 음악을 검색합니다." << endl;
			cout << "\t   4 : 앨범명으로 음악을 검색합니다." << endl;
			cout << "\t   5 : 장르명으로 음악을 검색합니다." << endl;
			cout << "\t   6 : 재생횟수로 검색합니다" << endl;
			cout << "\t   7 : 최근 추가한 음악을 검색합니다.." << endl;
			cout << "\t   8 : 재생목록에 최근 추가한 음악을 검색합니다." << endl;
			cout << "\t   0 : 뒤로 돌아 갑니다." << endl;
			cout << "\t-------------------------------------------------" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			if (command != 0)
				h = 2;
			break;
		case 3:	// 리스트에 있는 음악 검색
				// 단, 검색어가 음악명에 포함된다면 출력한다
				// 	ex) 검색어 : ‘사랑’ / 출력 : 가난한사랑,천년의사랑,..
			command = 9;
			h = 2;
			break;
		case 4:	// 리스트에 있는 음악 검색
				// 단, 검색어가 음악명에 포함된다면 출력한다
				// 	ex) 검색어 : ‘사랑’ / 출력 : 가난한사랑,천년의사랑,..
			cout << endl << endl;
			cout << "\t---ID -- Command ---------------------" << endl;
			cout << "\t   10 : 저장 목록을 불러옵니다." << endl;
			cout << "\t   11 : 현재까지의 결과를 저장합니다." << endl;
			cout << "\t   0 : 뒤로 돌아 갑니다." << endl;
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
			cout << "\t 올바르지 않은 명령어 입니다...\n";
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

	indata1.SetRecordFromKB(); // m_List에 넣을 모든 음악 정보
	indata2.SetRecord(indata1.GetID(), indata1.GetName());	// g_List에 넣을 일부 음악 정보
	indata3.SetRecord(indata1.GetID(), indata1.GetAlbum(), indata1.GetArtist(), indata1.GetCompany()); //a_List에 넣을 음악 정보

	if (m_List.Get(indata1) == 1) // 아이템이 중복되는지 확인
	{
		cout << endl;
		cout << "\t<=====음악이 이미 존재합니다!=====>" << endl;
		return 0;
	}														
	m_List.Add(indata1); // MusicList에 추가
	this->DisplayAllMusic();

	// GenreList에 추가	
	GenreType temp;	  // 입력된 음악이 어느 장르에 속하는지 찾기 위한 더미
	GenreType *pData; // g_List의 해당 장르를 포인터로 가르키기 위한 더미

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


	// ArtistList에 추가	
	ArtistType temp2; // 입력된 음악이 어느 장르에 속하는지 찾기 위한 더미
	ArtistType *pData2; // a_List의 해당 장르를 포인터로 가르키기 위한 더미

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
				pData2 = a_List.GetPoint(temp2); // 입력된 음악과 일치하는 장르를 찾아 포인터로 가르킨다
				pData2->AddAlbumInArtist(indata3); // 리스트 안 리스트에 음악 추가
			}
		}
		A_ID++; // 가수 번호 증가
	}
	if (found2 == false)
	{
		temp2.SetArtistInfo(indata1.GetID(), length + 1, indata1.GetArtist());  // temp에 가수 정보 저장
		a_List.Add(temp2);  // 가수 리스트에 장르 정보 추가
		pData2 = a_List.GetPoint(temp2); // 입력된 음악과 일치하는 가수를 찾아 포인터로 가르킨다
		pData2->AddAlbumInArtist(indata3); // 리스트 안 리스트에 음악 추가
	}
	return 1;
}

// 음악명으로 아이템을 찾아 출력한다.
int Application::SearchByID()
{
	MusicType item;
	item.SetIDFromKB(); //Name입력받는다.
	SearchListByMusicID(item);
	return 0;	//실패(0)을 리턴
}

// 음악명으로 아이템을 찾아 출력한다.
int Application::SearchByName()
{
	MusicType item;
	item.SetNameFromKB(); //Name입력받는다.
	SearchListByMusicName(item);
	return 0;	//실패(0)을 리턴
}


// 앨범명으로 아이템을 찾아 출력한다.
void Application::SearchByAlbum()
{
	MusicType temp;
	temp.SetAlbumFromKB();	//SearchListByMusicAlbum함수에 넘겨줄 temp의 name을 사용자에게 입력받는다.
	SearchListByMusicAlbum(temp);	//실질적으로 찾는 동작을 하는 SearchListByMusicAlbum함수를 호출하고 temp값을 넘겨준다.
}


// 재생횟수로 아이템을 찾아 출력한다.
void Application::SearchByRepetition()
{
	MusicType temp;
	temp.SetNumberFromKB();	//SearchListByMusicGenre함수에 넘겨줄 temp의 name을 사용자에게 입력받는다.
	SearchListByMusicRepetition(temp);	//실질적으로 찾는 동작을 하는 SearchListByMusicGenre함수를 호출하고 temp값을 넘겨준다.
}

// 음악 번호로 아이템을 찾아 출력한다.
void Application::SearchListByMusicID(MusicType &inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 ItemType.
	m_List.ResetList();
	int count = 0;
	for (int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(temp);
		if (temp.GetID() == (inData.GetID()))	//find함수에서는 일치하는 항목이 존재하지 않을때 -1을 리턴하므로 -1이 아니면 일치하는 문자열이 있는것이다.
		{
			cout << "<=======I 아이템을 찾았습니다 !======>" << endl;
			temp.DisplayRecordOnScreen();	//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
			cout << "<====================================>" << endl;
			count++;	//찾은 개수를 1 늘려준다.
		}
	}
	if (count == 0)
		cout << "<=====I 아이템을 찾을 수 없습니다 !=====>" << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}

// 음악명으로 아이템을 찾아 출력한다.
void Application::SearchListByMusicName(MusicType &inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 ItemType.
	m_List.ResetList();
	int count = 0;
	for (int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(temp);
		if (temp.GetName().find(inData.GetName()) != -1)	//find함수에서는 일치하는 항목이 존재하지 않을때 -1을 리턴하므로 -1이 아니면 일치하는 문자열이 있는것이다.
		{
			cout << "<=======I 아이템을 찾았습니다 !======>" << endl;
			temp.DisplayRecordOnScreen();	//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
			cout << "<====================================>" << endl;
			count++;	//찾은 개수를 1 늘려준다.
		}
	}
	if (count == 0)
		cout << "<=====I 아이템을 찾을 수 없습니다 !=====>" << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}

// 앨범명으로 아이템을 찾아 출력한다.
void Application::SearchListByMusicAlbum(MusicType &inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 ItemType.
	m_List.ResetList();
	int count = 0;
	for (int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(temp);
		if (temp.GetAlbum().find(inData.GetAlbum()) != -1)	//find함수에서는 일치하는 항목이 존재하지 않을때 -1을 리턴하므로 -1이 아니면 일치하는 문자열이 있는것이다.
		{
			cout << "<=======I 아이템을 찾았습니다 !======>" << endl;
			temp.DisplayRecordOnScreen();	//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
			cout << "<====================================>" << endl;
			count++;	//찾은 개수를 1 늘려준다.
		}
	}
	if (count == 0)
		cout << "<=====I 아이템을 찾을 수 없습니다 !=====>" << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}

// 재생횟수로 아이템을 찾아 출력한다.
void  Application::SearchListByMusicRepetition(MusicType &inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 ItemType.
	m_List.ResetList();
	int count = 0;
	for (int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(temp);
		if (temp.GetNumber() == inData.GetNumber())	//find함수에서는 일치하는 항목이 존재하지 않을때 -1을 리턴하므로 -1이 아니면 일치하는 문자열이 있는것이다.
		{
			cout << "<=======I 아이템을 찾았습니다 !======>" << endl;
			temp.DisplayRecordOnScreen();	//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
			cout << "<====================================>" << endl;
			count++;	//찾은 개수를 1 늘려준다.
		}
	}
	if (count == 0)
		cout << "<=====I 아이템을 찾을 수 없습니다 !=====>" << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}


//음악번호로 음악을 찾아서 제거한다.
int Application::DeleteMusic()
{
	int pre = m_List.GetLength();//이전 item개수를 받아온다.
	int length = g_List.GetLength();
	int alength = a_List.GetLength();

	MusicType item;
	SimpleMusicType simpleitem;
	AlbumType albumitem;

	GenreType temp; // 입력된 음악이 어느 장르에 속하는지 찾기 위한 더미
	GenreType *pData; // g_List의 해당 장르를 포인터로 가르키기 위한 더미

	ArtistType atemp; // 입력된 음악이 어느 가수목록에 속하는지 찾기 위한 더미
	ArtistType *apData; // a_List의 해당 장르를 포인터로 가르키기 위한 더미

	int num;
	cout << "\tID : ";
	cin >> num;

	item.SetID(num);
	simpleitem.SetID(num);
	albumitem.SetID(num);
	

	//리스트에 있는 음악을 제거한다.
	m_List.Delete(item);

	////////////////////////////////////////SIMPLEMUSICLIST 제거//////////////////////////////////////////

	g_List.ResetList();

	for (int i = 0; i < length; i++)
	{
		g_List.GetNextItem(temp);
		if (temp.GetID() == item.GetID())
		{
			pData = g_List.GetPoint(temp); // 입력된 음악과 일치하는 장르를 찾아 포인터로 가르킨다
			pData->DeleteMusicInGenre(simpleitem); // 리스트 안 리스트에 있는 음악 제거
		}
	}

	//////////////////////////////////////재생목록에 있는 음악 제거///////////////////////////////////////

	p_List.ResetList();
	int pre2 = p_List.GetLength();//이전 item개수를 받아온다.
	PlayType item2;

	item2.SetPlayID(num);

	//리스트에 있는 음악을 제거한다.
	p_List.Delete(item2);

	if (pre2 > p_List.GetLength()) //이전 item개수보다 현재 item개수가 많아지면 제거성공
	{
		cout << "\n\t! 재생 목록에 있는 노래도 제거 되었습니다 !" << endl;
	}

	//////////////////////////////////////앨범목록에 있는 음악 제거////////////////////////////////////////

	a_List.ResetList();

	for (int i = 0; i < alength; i++)
	{
		a_List.GetNextItem(atemp);
		if (atemp.GetID() == item.GetID())
		{
			apData = a_List.GetPoint(atemp); // 입력된 음악과 일치하는 장르를 찾아 포인터로 가르킨다
			apData->DeleteAlbumInArtist(albumitem); // 리스트 안 리스트에 있는 음악 제거
		}
	}

	/////////////////////////////////현재 목록 출력////////////////////////////////////////////////////////

	if (pre> m_List.GetLength()) //이전 item개수보다 현재 item개수가 많아지면 제거성공
	{
		cout << endl;
		cout << "<========! 제거 성공 !===========>" << endl;
		this->DisplayAllMusic(); //모든 item을 출력한다.
		return 1;
	}

	cout << "<=========! 제거 실패 !==========>" << endl;
	this->DisplayAllMusic();//모든 item을 출력한다.
}

//해당 음악명의 정보를 변경한다.
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
	item.SetLyricsFromKB(); //키보드로부터 정보를 입력받음

	m_List.Replace(item); //해당 item의 음악명 일치하는 것을 찾아 바꾼다.

	cout << "\n\t음악 정보 수정 완료!!!";
	this->DisplayAllMusic();
	return 0;
}

// 최근 음악 목록을 출력한다(30개 이하)
void Application::DisplayNewMusic()
{
	s_List.Print();
}

// 최근 재생한 목록을 출력한다(30개 이하)
void Application::DisplayPlayNewMusic()
{

	PlayType data;

	cout << "\n\t최근 재생한 목록 - 재생시간 순 : " << endl;

	// list의 모든 데이터를 화면에 출력
	rp_List.ResetList();

	for (int i = 0; i < rp_List.GetLength(); i++)
	{
		rp_List.GetNextItem(data);
		data.DisplayPlayOnScreen();
		cout << endl;
	}
}


// 리스트에 저장된 모든 데이터를 출력한다.
void Application::DisplayAllMusic()
{
	MusicType data;

	cout << "\n\t현재 목록 : " << endl;

	// list의 모든 데이터를 화면에 출력
	m_List.ResetList();

	for (int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(data);
		data.DisplayRecordOnScreen();
		cout << endl;
	}
}

// 음악 리스트를 장르별로 출력한다.
int Application::DisplayMusicByGenre()
{
	GenreType data;

	cout << "\n\t현재 목록" << endl;

	// genre list의 모든 데이터를 화면에 출력
	g_List.ResetList();
	int length = g_List.GetLength();
	for (int i = 0; i < length; i++)
	{
		g_List.GetNextItem(data);
		data.DisplayGenreOnScreen();
	}

	// 특정 장르의 음악 정보만 보고 싶을 때
	int id;
	GenreType *pData;

	cout << "\n\t찾고자 하는 장르의 번호를 입력하세요 : ";
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
				pData->DisplayMusicDetailInGenre(&m_List); // 해당 장르 음악 출력
				return 1;
			}
		}
		cout << "\n\t!!!! 번호가 존재하지 않습니다 !!!!";
		cout << "\n\t 장르명 앞에 있는 번호를 입력해 주세요: ";
	}
	return 0;
}

// 음악 리스트를 가수별로 출력한다.
int Application::DisplayMusicByArtist()
{
	ArtistType data;

	cout << "\n\t현재 목록" << endl;

	// artist list의 모든 데이터를 화면에 출력
	a_List.ResetList();
	int length = a_List.GetLength();
	for (int i = 0; i < length; i++)
	{
		a_List.GetNextItem(data);
		data.DisplayArtistOnScreen();
	}

	// 특정 가수의 앨범 정보만 보고 싶을 때
	int id;
	ArtistType *pData;

	cout << "\n\t찾고자 하는 가수의 번호를 입력해 주세요 : ";
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
				pData->DisplayAlbumDetailInArtist(&m_List); // 해당 장르 음악 출력
				return 1;
			}
		}
		cout << "\n\t!!!! 번호가 존재하지 않습니다 !!!!";
		cout << "\n\t 가수명 앞에 있는 번호를 입력해 주세요: ";
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
	SimpleMusicType data2;
	AlbumType data3;
	
	char filename[FILENAMESIZE] = "노래목록.txt";
	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(filename))
	{
		cout << "\n\t파일이 존재하지 않습니다!";
		return 0;
	}

	// 모든 리스트 초기화
	m_List.MakeEmpty();
	g_List.MakeEmpty();
	a_List.MakeEmpty();
	// 파일의 모든 내용을 읽어 list에 추가
	while(!m_InFile.eof())
	{
		// 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);

		data2.SetRecord(data.GetID(), data.GetName());	// g_List에 넣을 일부 음악 정보
		data3.SetRecord(data.GetID(), data.GetAlbum(), data.GetArtist(), data.GetCompany()); //a_List에 넣을 음악 정보
		

		// GenreList에 추가	
		GenreType temp;	  // 입력된 음악이 어느 장르에 속하는지 찾기 위한 더미
		GenreType *pData; // g_List의 해당 장르를 포인터로 가르키기 위한 더미

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
					pData = g_List.GetPoint(temp); // 입력된 음악과 일치하는 장르를 찾아 포인터로 가르킨다
					pData->AddMusicInGenre(data2); // 리스트 안 리스트에 음악 추가

					if (s_List.IsFull())  // 최근 음악 목록이 가득 찼다면
						s_List.DeQueue(data2);  //최근 음악 목록에서 가장 오래된 음악 제거
					else
						s_List.EnQueue(data2);  // 최근 음악 목록에서 최신 음악 추가
				}
			}
			G_ID++; // 장르 번호 증가
		}
		if (found == false)
		{
			temp.SetGenreInfo(data.GetID(), length + 1, data.GetGenre());  // temp에 장르 정보 저장
			g_List.Add(temp);  // 장르 리스트에 장르 정보 추가
			pData = g_List.GetPoint(temp); // 입력된 음악과 일치하는 장르를 찾아 포인터로 가르킨다
			pData->AddMusicInGenre(data2); // 리스트 안 리스트에 음악 추가

			if (s_List.IsFull())  // 최근 음악 목록이 가득 찼다면
			{
				s_List.DeQueue(data2);  // 최근 음악 목록에서 가장 오래된 음악 제거
			}
			else
			{
				s_List.EnQueue(data2);  // 최근 음악 목록에서 최신 음악 추가
			}
		}


		// ArtistList에 추가	
		ArtistType temp2; // 입력된 음악이 어느 장르에 속하는지 찾기 위한 더미
		ArtistType *pData2; // a_List의 해당 장르를 포인터로 가르키기 위한 더미

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
					pData2 = a_List.GetPoint(temp2); // 입력된 음악과 일치하는 장르를 찾아 포인터로 가르킨다
					pData2->AddAlbumInArtist(data3); // 리스트 안 리스트에 음악 추가
				}
			}
			A_ID++; // 가수 번호 증가
		}
		if (found2 == false)
		{
			temp2.SetArtistInfo(data.GetID(), length + 1, data.GetArtist());  // temp에 가수 정보 저장
			a_List.Add(temp2);  // 가수 리스트에 장르 정보 추가
			pData2 = a_List.GetPoint(temp2); // 입력된 음악과 일치하는 가수를 찾아 포인터로 가르킨다
			pData2->AddAlbumInArtist(data3); // 리스트 안 리스트에 음악 추가
		}
	}

	m_InFile.close();	// file close

	// 현재 list 출력
	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	MusicType data;	// 쓰기용 임시 변수
	char filename[FILENAMESIZE] = "노래목록.txt";
	//cout << "\n\t저장할 파일명을 정의해 주세요 : ";
	//cin >> filename;


	// file open, open error가 발생하면 0을 리턴
	if (!OpenOutFile(filename))
	{
		cout << "\n\t파일이 존재하지 않습니다!";
		return 0;
	}
		
	// list 포인터를 초기화
	m_List.ResetList();

	// list의 길이를 리턴받아 저장
	int length = m_List.GetLength();

	// iteration을 이용하여 모든 item 출력
	for (int i = 0; i<length; i++)
	{
		m_List.GetNextItem(data);
		data.WriteDataToFile(m_OutFile);
	}

	cout << "\n\t저장에 성공했습니다!";
	m_OutFile.close();	// file close

	return 1;
}


// 재생목록에 음악 추가
int Application::AddToPlayMusic()
{
	MusicType copy;
	PlayType temp; // 입력된 음악이 어느 장르에 속하는지 찾기 위한 더미
	PlayType *pData; // p_List의 해당 장르를 포인터로 가르키기 위한 더미

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
					cout << "\n\t음악이 추가되었습니다!";
					return 0;
				}
			}
		}
	}
	if (found == false)
	{
		cout << "\n\t음악이 존재하지 않습니다!";
		return 1;
	}
}

// 재생목록에 있는 음악 제거
int Application::DeletePlayMusic()
{
	p_List.ResetList();
	int pre = p_List.GetLength();//이전 item개수를 받아온다.
	PlayType item;

	item.SetPlayIDFromKB();

	p_List.Delete(item);

	if (pre> p_List.GetLength()) //이전 item개수보다 현재 item개수가 많아지면 제거성공
	{
		cout << endl;
		cout << "<===========! 제거 성공 !===========>" << endl;
		

		// list의 모든 데이터를 화면에 출력
		p_List.ResetList();

		for (int i = 0; i < p_List.GetLength(); i++)
		{
			p_List.GetNextItem(item);
			item.DisplayPlayOnScreen();
			cout << endl;
		}
		return 1;
	}

	cout << "<===========! 제거 성공 !===========>" << endl;
	cout << endl;
	cout << "\n\t현재 목록" << endl;
	p_List.ResetList();

	for (int i = 0; i < p_List.GetLength(); i++)
	{
		p_List.GetNextItem(item);
		item.DisplayPlayOnScreen();
		cout << endl;
	}
	return 0;
}

// 선택한 음악을 재생목록에 추가한다.
void Application::PlayMusic()
{
	PlayType item;
	PlayType temp;	//m_List의 값을 비교해주기 위한 임시 ItemType.
	item.SetPlayRecordFromKB();
	p_List.ResetList();

	int count = 0;
	for (int i = 0; i < p_List.GetLength(); i++)
	{
		p_List.GetNextItem(temp);
		if (temp.GetPlayName() == (item.GetPlayName()))	//find함수에서는 일치하는 항목이 존재하지 않을때 -1을 리턴하므로 -1이 아니면 일치하는 문자열이 있는것이다.
		{
			if (temp.GetPlayArtist() == (item.GetPlayArtist()))
			{
				cout << "<==============I 재생중 !============>" << endl;
				temp.DisplayPlayOnScreen();
				cout << "<====================================>" << endl;
				count++;	
				int repetition = temp.GetPlayTime();
				repetition++; //재생한 횟수를 1 늘려준다.
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
		cout << "<======I 아이템을 찾을 수 없습니다 !=======>" << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}

//회원 가입
void Application::uRegister()
{
	string id;
	string password, name;
	User user;
	cout << "\t\t회원가입을 진행합니다.\n\tID : ";
	cin >> id;	//사용자에게서 ID를 입력받는다.
	users.ResetList();
	for (int i = 0; i < users.GetLength(); i++)
	{
		users.GetNextItem(user);
		if (user.getId() == id)
		{
			cout << "\t\t중복된 id가 있습니다. 메인 메뉴로 돌아갑니다." << endl;
			return;
		}
	}	//중복 검사를 한다.
	cout << "\t패스워드 : ";
	cin >> password;
	cout << "\t이름 : ";
	cin >> name;	//비밀번호와 이름을 입력받는다.

	User user2;
	user2.setUser(id, password, name);	//해당 정보를 저장한다.
	users.Add(user2);	//회원 리스트에 추가한다.
	cout << "\n\t회원가입이 성공적으로 완료되었습니다. 다시 로그인하세요." << endl;
}


//회원 로그인
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
		cin >> pw;	//사용자에게서 ID와 비밀번호를 입력받는다.
		users.ResetList();
		for (int i = 0; i < users.GetLength(); i++)
		{
			users.GetNextItem(dummy);
			loginedUser = users.GetPoint(dummy);
			if (dummy.getId() == id && dummy.getPW() == pw)
			{
				cout << "\t로그인에 성공했습니다!!";
				return;
			}
			loginedUser = NULL;
		}	//해당 회원이 있으면 정보를 저장하고, 찾을 수 없으면 NULL을 저장한다.
		int usr;
		cout << "\t로그인에 실패했습니다.\n\t다시 시도하시겠습니까?\n\t 1.네\t2.아니오\n";
		cout << endl << "\t --> ";
		cin >> usr;
		if (usr == 2)
			return;
		else if (usr == 1)
			continue;
		else
			cout << "\t잘못 입력하셨습니다." << endl;
	}
	return;
}

//회원 로그인
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
		cin >> pw;	//사용자에게서 ID와 비밀번호를 입력받는다.
		cout << "\tAdmin Code : ";
		cin >> adminpw;


		if (dummy.getId() == id && dummy.getPW() == pw && dummy.getAdmin() == adminpw)
		{
			users.Add(dummy);
			loginedUser = users.GetPoint(dummy);
			cout << "\t로그인에 성공했습니다!!";
			return;
		}
		loginedUser = NULL;
		//해당 회원이 있으면 정보를 저장하고, 찾을 수 없으면 NULL을 저장한다.
		int usr;
		cout << "\t로그인에 실패했습니다.\n\t다시 시도하시겠습니까?\n\t 1.네\t2.아니오\n";
		cout << endl << "\t --> ";
		cin >> usr;
		if (usr == 2)
			return;
		else if (usr == 1)
			continue;
		else
			cout << "\t잘못 입력하셨습니다." << endl;
	}
	return;
}

//회원 정보 불러오기
void Application::GetUserFromFile()
{	
	m_InFile.open("UserList.txt");

	User temp;
	string id;
	string pw, name;	//변수 선언
	while (!m_InFile.eof())
	{
		m_InFile >> id;
		if (m_InFile.eof())
			break;
		m_InFile >> pw >> name;	//회원 정보 입력받기
		temp.setUser(id, pw, name);	//회원 정보 저장
		users.Add(temp);	//해당 회원 추가
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
	}	//전체 회원 정보 파일에 출력하기

	m_OutFile.close();
}