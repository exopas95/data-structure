#include "Application.h"

// Application 실행 함수
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
		case 1:		// 관리자 로그인
			userAdminLogin();
			if (loginedUser != NULL)
				login = 1;
			break;
		case 2:		// 회원 로그인
			userLogin();
			if (loginedUser != NULL)
				login = 2;
			break;
		case 3:		// 회원 가입
			uRegister();	
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
				command = GetCommand_Admin();

				switch (command)
				{
				case 1:		// 음악을 추가한다.
					Insertmusic();
					break;
				case 2:		// 음악을 제거한다.
					Removemusic();
					break;
				case 3:		// 음악을 변경한다.
					Replacemusic();
					break;
				case 4:		// 음악을 제목으로 검색한다.
					SearchMusicByName();
					break;
				case 5:		// 음악을 가수명으로 검색한다.
					SearchMusicByArtist();
					break;
				case 6:		// 음악을 앨범명으로 검색한다.
					SearchMusicByAlbum();
					break;
				case 7:		// 음악을 장르명으로 검색한다.
					SearchMusicByGenre();
					break;
				case 8:		// 음악 가사를 인터넷에서 검색한다..
					SearchMusicByLyrics();
					break;
				case 9:		// 저장된 음악 정보를 모두 출력한다.
					Displaymusic();
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
				case 13:	// 음악을 재생목록에서 제거한다.
					DeletePlayMusic();
					break;
				case 14:	// 음악을 재생한다.
					PlayMusic();
					break;
				case 15:	// 가장 많이 재생된 음악 30곡을 출력한다.
					DisPlayMostPlayedMusic();
					break;
				case 16:	// 최신 음악 30곡을 출력한다.
					DisplayNewMusic();
					break;
				case 0:
					return;
				default:
					cout << "\tIllegal sellection...\n";
					break;
				}
			}
		}
		if (login == 2)
		{
			while (j == 1)
			{
				command = GetCommand_User();

				switch (command)
				{
				case 1:		// 음악을 제목으로 검색한다.
					SearchMusicByName();
					break;
				case 2:		// 음악을 가수명으로 검색한다.
					SearchMusicByArtist();
					break;
				case 3:		// 음악을 앨범명으로 검색한다.
					SearchMusicByAlbum();
					break;
				case 4:		// 음악을 장르명으로 검색한다.
					SearchMusicByGenre();
					break;
				case 5:		// 음악 가사를 인터넷에서 검색한다..
					SearchMusicByLyrics();
					break;
				case 6:		// 저장된 음악 정보를 모두 출력한다.
					Displaymusic();
					break;
				case 7:		// txt 파일에서 음악정보를 읽어온다
					ReadDataFromFile();
					break;
				case 8:		// txt 파일에 음악정보를 쓴다
					WriteDataToFile();
					break;
				case 9:		// 음악을 재생목록에 추가한다.
					AddToPlayMusic();
					break;
				case 10:	// 음악을 재생목록에서 제거한다.
					DeletePlayMusic();
					break;
				case 11:	// 음악을 재생한다.
					PlayMusic();
					break;
				case 12:	// 가장 많이 재생된 음악 30곡을 출력한다.
					DisPlayMostPlayedMusic();
					break;
				case 13:	// 최신 음악 30곡을 출력한다.
					DisplayNewMusic();
					break;
				case 0:
					return;
				default:
					cout << "\tIllegal sellection...\n";
					break;
				}
			}
		}
		
	}
}

// command 값 입력받는 사용자용 함수
int Application::GetCommand_User()
{
	int z = 1;
	int command;
	int number;

	while (z == 1)
	{
		cout << endl << endl;
		cout << "\t---ID -- Command ---------" << endl;
		cout << "\t   1 : 재생목록" << endl;
		cout << "\t   2 : 검색" << endl;
		cout << "\t   3 : 모든 음악 리스트" << endl;
		cout << "\t   4 : 가장 많이 들은 음악 리스트" << endl;
		cout << "\t   5 : 최신 음악 리스트" << endl;
		cout << "\t   6 : 정보 저장/불러오기" << endl;
		cout << "\t   0 : 로그아웃" << endl;
		cout << "\t---------------------------" << endl;
		cout << endl << "\t Choose a Command--> ";

		cin >> number;
		switch (number)
		{
		case 1:	// 재생목록
			cout << endl << endl;
			cout << "\t---ID -- Command ----------" << endl;
			cout << "\t   9 : 재생목록에 추가" << endl;
			cout << "\t   10 : 재생목록에서 제거 " << endl;
			cout << "\t   11 : 음악 재생 " << endl;
			cout << "\t   0 : 뒤로 돌아 갑니다." << endl;
			cout << "\t----------------------------" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			if (command != 0)
				z = 2;
			break;
		case 2:	// 검색기능
			cout << endl << endl;
			cout << "\t---ID -- Command --------------------------------" << endl;
			cout << "\t   1 : 곡명으로 음악을 검색합니다." << endl;
			cout << "\t   2 : 가수명으로 음악을 검색합니다." << endl;
			cout << "\t   3 : 앨범명으로 음악을 검색합니다." << endl;
			cout << "\t   4 : 장르명으로 음악을 검색합니다." << endl;
			cout << "\t   5 : 가사로 음악을 검색합니다." << endl;
			cout << "\t   0 : 뒤로 돌아 갑니다." << endl;
			cout << "\t-------------------------------------------------" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			if (command != 0)
				z = 2;
			break;
		case 3:	// 리스트에 있는 모든 음악 출력
			command = 6;
			z = 2;
			break;
		case 4:	// 리스트에서 가장 많이 들은 음악 30곡 출력
			command = 12;
			z = 2;
			break;
		case 5:	// 최신 음악 출력
			command = 13;
			z = 2;
			break;
		case 6:	// 현재 정보 저장/불러오기
			cout << endl << endl;
			cout << "\t---ID -- Command ---------------------" << endl;
			cout << "\t   7 : 저장 목록을 불러옵니다." << endl;
			cout << "\t   8 : 현재까지의 결과를 저장합니다." << endl;
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

// command 값 입력받는 관리자용 함수
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
		cout << "\t   3 : 검색" << endl;
		cout << "\t   4 : 모든 음악 리스트" << endl;
		cout << "\t   5 : 가장 많이 들은 음악 리스트" << endl;
		cout << "\t   6 : 최신 음악 리스트" << endl;
		cout << "\t   7 : 정보 저장/불러오기" << endl;
		cout << "\t   0 : 로그아웃" << endl;
		cout << "\t---------------------------" << endl;
		cout << endl << "\t Choose a Command--> ";

		cin >> number;
		switch (number)
		{
		case 1:	// 음악 추가/제거
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
		case 2:	// 재생목록
			cout << endl << endl;
			cout << "\t---ID -- Command ----------" << endl;
			cout << "\t   12 : 재생목록에 추가" << endl;
			cout << "\t   13 : 재생목록에서 제거 " << endl;
			cout << "\t   14 : 음악 재생 " << endl;
			cout << "\t   0 : 뒤로 돌아 갑니다." << endl;
			cout << "\t----------------------------" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			if (command != 0)
				z = 2;
			break;
		case 3:	// 검색기능
			cout << endl << endl;
			cout << "\t---ID -- Command --------------------------------" << endl;
			cout << "\t   4 : 곡명으로 음악을 검색합니다." << endl;
			cout << "\t   5 : 가수명으로 음악을 검색합니다." << endl;
			cout << "\t   6 : 앨범명으로 음악을 검색합니다." << endl;
			cout << "\t   7 : 장르명으로 음악을 검색합니다." << endl;
			cout << "\t   8 : 가사로 음악을 검색합니다." << endl;
			cout << "\t   0 : 뒤로 돌아 갑니다." << endl;
			cout << "\t-------------------------------------------------" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			if (command != 0)
				z = 2;
			break;
		case 4:	// 리스트에 있는 음악 출력
			command = 9;
			z = 2;
			break;
		case 5:	// 리스트에서 가장 많이 들은 음악 30곡 출력
			command = 15;
			z = 2;
			break;
		case 6:	// 최신 노래 출력
			command = 16;
			z = 2;
			break;
		case 7:	// 현재 정보 저장/불러오기
			cout << endl << endl;
			cout << "\t---ID -- Command ---------------------" << endl;
			cout << "\t   10 : 저장 목록을 불러옵니다." << endl;
			cout << "\t   11 : 현재까지의 결과를 저장합니다." << endl;
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

// Tree에 music을 추가하는 함수 
void Application::Insertmusic()
{
	MasterType music;
	SimpleMusicType simple;

	cout << "\tInsert Music " << endl;
	music.SetRecordFromKB();				// Tree에 추가할 music 값을 키보드로부터 입력받음
	simple.SetRecord(music.GetID(), music.GetName());

	m_List.Add(music);						// Add함수를 통해서 music을 Tree에 추가함

	///////////////////////////////////////////장르////////////////////////////////////////

	GenreType genre;
	GenreType *pData;

	genre.SetGenreName(music.GetGenre());
	g_List.Find(genre);

	if (g_List.Find(genre))
	{
		genre.SetGenreInfo(music.GetID(), G_ID, music.GetGenre());
		pData = g_List.Get(genre);
		pData->AddMusicInGenre(simple);

		if (s_List.IsFull())
			s_List.DeQueue(simple);  //최근 음악 목록에서 가장 오래된 음악 제거
		else
			s_List.EnQueue(simple);  // 최근 음악 목록에서 최신 음악 추가
	}
	else
	{
		G_ID++;
		genre.SetGenreInfo(music.GetID(), G_ID, music.GetGenre());
		g_List.Add(genre);
		pData = g_List.Get(genre);
		pData->AddMusicInGenre(simple);

		if (s_List.IsFull())
			s_List.DeQueue(simple);  //최근 음악 목록에서 가장 오래된 음악 제거
		else
			s_List.EnQueue(simple);  // 최근 음악 목록에서 최신 음악 추가		
	}

	///////////////////////////////////////////앨범////////////////////////////////////////

	AlbumType Album;
	AlbumType *pAlbumData;

	Album.SetAlbumName(music.GetAlbum());
	album_List.Find(Album);

	if (album_List.Find(Album))
	{
		Album.SetAlbumInfo(music.GetID(), Album_ID, music.GetAlbum());
		pAlbumData = album_List.Get(Album);
		pAlbumData->AddMusicInAlbum(simple);
	}
	else
	{
		Album_ID++;
		Album.SetAlbumInfo(music.GetID(), Album_ID, music.GetAlbum());
		album_List.Add(Album);
		pAlbumData = album_List.Get(Album);
		pAlbumData->AddMusicInAlbum(simple);	
	}

	///////////////////////////////////////////가수////////////////////////////////////////

	ArtistType Artist;
	ArtistType *pArtistData;

	Artist.SetArtistName(music.GetArtist());
	artist_List.Find(Artist);

	if (artist_List.Find(Artist))
	{
		Artist.SetArtistInfo(music.GetID(), Artist_ID, music.GetArtist());
		pArtistData = artist_List.Get(Artist);
		pArtistData->AddMusicInArtist(simple);
	}
	else
	{
		Artist_ID++;
		Artist.SetArtistInfo(music.GetID(), Artist_ID, music.GetArtist());
		artist_List.Add(Artist);
		pArtistData = artist_List.Get(Artist);
		pArtistData->AddMusicInArtist(simple);	
	}

	cout << "\n\t<<현재 목록>>" << endl;
	Displaymusic();						// 현재 Tree의 node를 모두 출력함
}

// Tree에서 music을 지우는 함수
void Application::Removemusic()
{
	MasterType music;
	GenreType genre;
	GenreType *pData;
	SimpleMusicType simple;
	SimpleMusicType *sdata;
	AVLTree<SimpleMusicType>* smlist;


	cout << "\n\tInput Music ID to delete music " << endl;
	music.SetIDFromKB();					// Tree에서 지우려고 하는 music 값을 키보드로부터 입력받음

	m_List.Find(music);		// Find 함수를 통해서 Tree에서 검색
	genre.SetGenreName(music.GetGenre());

	if (m_List.Find(music))					// Tree에 music이 있으면
	{
		m_List.Delete(music);			// Deletemusic함수를 통해서 Tree에서 music값에 해당하는 노드를 삭제함

		pData = g_List.Get(genre);
		smlist = pData->DetailInfo(); // 해당 장르 음악 출력
		simple.SetID(music.GetID());
		sdata = smlist->Get(simple);
		smlist->Delete(simple);

		if (smlist->GetLength() == 0)
		{
			g_List.Delete(genre);
		}

		cout << "\n\t음악 제거에 성공하였습니다!\n" << endl;
		Displaymusic();					// 지우고 나서의 Tree를 출력
	}
	else
		cout << "\tNo music to delete" << endl;	// 지우려고 하는 값의 node가 없을 경우 
}

//해당 음악명의 정보를 변경한다.
int Application::Replacemusic()
{
	MasterType music, *mtemp;
	GenreType genre, gtemp, *pData, *temp1;
	AlbumType album, altemp, *temp2;
	ArtistType artist, artemp, *temp3;
	SimpleMusicType simple;
	SimpleMusicType *sdata;
	AVLTree<SimpleMusicType>* smlist;

	if (!m_List.IsEmpty()) // 음악 리스트가 Empty인지 아닌지 검사
	{
		cout << "\n\t변경하고 싶은 곡 이름을 입력하세요 : " << endl;
		music.SetNameFromKB();
		if (m_List.Find(music) == false)
			cout << "\n\t해당 음악이 존재하지 않습니다!";
		else
		{
			mtemp = m_List.Get(music);
			cout << "\n\t수정할 내용을 입력하세요 : " << endl;
			music.SetArtistFromKB();
			music.SetAlbumFromKB();
			music.SetGenreFromKB();
			music.SetLyricsFromKB();

			gtemp.SetGenreName(mtemp->GetGenre());
			artemp.SetArtistName(mtemp->GetArtist());
			altemp.SetAlbumName(mtemp->GetAlbum());
			temp1 = g_List.Get(gtemp);
			temp2 = album_List.Get(altemp);
			temp3 = artist_List.Get(artemp);

			genre.SetGenreInfo(music.GetID(), temp1->GetGenreId(), music.GetGenre());
			artist.SetArtistInfo(music.GetID(), temp3->GetArtistId(), music.GetArtist());
			album.SetAlbumInfo(music.GetID(), temp2->GetAlbumId(), music.GetAlbum());

			m_List.Replace(music); //해당 item의 음악명 일치하는 것을 찾아 바꾼다.
			g_List.Replace(genre); //해당 item의 음악명 일치하는 것을 찾아 바꾼다.
			artist_List.Replace(artist); //해당 item의 음악명 일치하는 것을 찾아 바꾼다.
			album_List.Replace(album); //해당 item의 음악명 일치하는 것을 찾아 바꾼다.

			cout << "\n\t음악 정보 수정 완료!!!\n";
			this->Displaymusic();
			return 0;
		}
	}
	else
	{
		cout << "\n\t변경할 수 있는 음악이 현재 없습니다!";
	}

}


// 음악 제목으로 Tree에서 찾고자 하는 값의 노드를 검색하는 함수
void Application::SearchMusicByName()
{
	MasterType music;
	PlayType temp;
	cout << "\n\t찾고 싶은 음악의 이름을 입력하세요." << endl;
	music.SetNameFromKB();								// 검색하고자 하는 값(곡명)을 키보드로부터 입력받음
									
	m_List.Find(music);					// Find 함수를 통해 Tree에서 검색
	if (m_List.Find(music) == true)								// 찾으면 찾았다는 문구와 함께, 관련 정보까지 출력
	{
		cout << "\t<==========I FOUND ITEM !========>" << endl;
		m_List.Get(music);
		music.DisplayRecordOnScreen();
		cout << "\t<================================>" << endl;

		cout << "\t선택한 노래를 재생목록에 추가하시겠습니까? (Y/N) : ";
		char answer1;
		cin >> answer1;
		if (answer1 == 'Y')
		{
			temp.SetPlayInfo(music.GetID(), music.GetName(), music.GetArtist());
			p_List.Add(temp);
			cout << "\n\t음악이 추가되었습니다!" << endl;
		}

		cout << "\n\t선택한 노래를 인터넷에서 검색하시겠습니까? (Y/N) : ";
		char answer2;
		cin >> answer2;
		if (answer2 == 'Y')
		{
			SearchWeb(music.GetName());
		}
		else
			return;
	}
	else
	{
		cout << "\t<======I CAN'T FIND ITEM !=======>" << endl;		// 못 찾았으면 못 찾았다는 문구를 출력
	}
}

// 가수명으로 Tree에서 찾고자 하는 값의 노드를 검색하는 함수
int Application::SearchMusicByArtist()
{
	ArtistType Artist;
	ArtistType *pData;
	AVLTree<SimpleMusicType>* smlist;
	string ArtistName;

	cout << "\n\t<현재 목록>" << endl;
	artist_List.PrintTree(cout);

	cout << "\n\t상세보기 하고 싶은 가수명을 입력하세요 : ";
	while (true)
	{
		cin >> ArtistName;
		Artist.SetArtistName(ArtistName);
		pData = artist_List.Get(Artist);

		if (artist_List.Find(Artist))
		{
			smlist = pData->DetailInfo(); // 해당 장르 음악 출력
			SimpleMusicType *sdata;
			SimpleMusicType simple;
			simple.SetID(Artist.GetID());
			sdata = smlist->Get(simple);
			smlist->PrintTree(cout);

			char Agree;
			cout << "\n\t음악 세부사항을 확인하시겠습니까? (Y/N): ";
			cin >> Agree;
			if (Agree == 'Y')
			{
				SearchMusicByName();
			}
			else
				return 1;
		}
	}
	return 0;
}

// 앨범명으로 Tree에서 찾고자 하는 값의 노드를 검색하는 함수
int Application::SearchMusicByAlbum()
{
	AlbumType Album;
	AlbumType *pData;
	AVLTree<SimpleMusicType>* smlist;
	string AlbumName;

	cout << "\n\t<현재 목록>" << endl;
	album_List.PrintTree(cout);

	cout << "\n\t상세보기 하고 싶은 앨범명을 입력하세요 : ";
	while (true)
	{
		cin >> AlbumName;
		Album.SetAlbumName(AlbumName);
		pData = album_List.Get(Album);

		if (album_List.Find(Album))
		{
			smlist = pData->DetailInfo(); // 해당 장르 음악 출력
			SimpleMusicType *sdata;
			SimpleMusicType simple;
			simple.SetID(Album.GetID());
			sdata = smlist->Get(simple);
			smlist->PrintTree(cout);


			char Agree;
			cout << "\n\t음악 세부사항을 확인하시겠습니까? (Y/N): ";
			cin >> Agree;
			if (Agree == 'Y')
			{
				SearchMusicByName();
			}
			else
				return 1;
		}
	}
	return 0;
}

// 장르명으로 Tree에서 찾고자 하는 값의 노드를 검색하는 함수
int Application::SearchMusicByGenre()
{
	GenreType genre;
	GenreType *pData;
	AVLTree<SimpleMusicType>* smlist;
	string GenreName;

	cout << "\n\t<현재 목록>" << endl;
	g_List.PrintTree(cout);

	cout << "\n\t상세보기 하고 싶은 장르명을 입력하세요 : ";
	while (true)
	{
		cin >> GenreName;
		genre.SetGenreName(GenreName);
		pData = g_List.Get(genre);

		if (g_List.Find(genre))
		{
			smlist = pData->DetailInfo(); // 해당 장르 음악 출력
			SimpleMusicType *sdata;
			SimpleMusicType simple;
			simple.SetID(genre.GetID());
			sdata = smlist->Get(simple);
			smlist->PrintTree(cout);
			

			char Agree;
			cout << "\n\t음악 세부사항을 확인하시겠습니까? (Y/N): ";
			cin >> Agree;
			if (Agree == 'Y')
			{
				SearchMusicByName();
			}
			else
				return 1;
		}
		break;
	}
	return 0;
}

// 음악 가사를 멜론에서 검색하는 함수
void Application::SearchMusicByLyrics()
{
	string Lyrics;
	cout << "\t가사를 입력하세요 : ";
	getline(cin, Lyrics);
	getline(cin, Lyrics);
	
	string address1 = "https://www.melon.com/search/total/index.htm?q=";
	string address2 = "&section=&linkOrText=T&ipath=srch_form";
	string total = address1 + Lyrics + address2;
	const char * c = total.c_str();

	ShellExecute(NULL, "open", c, NULL, NULL, SW_SHOWNORMAL);
}

// 곡 이름을 네이버에서 검색하는 함수
void Application::SearchWeb(string title)
{
	string address = "https://search.naver.com/search.naver?sm=top_hty&fbm=1&ie=utf8&query=";
	string total = address + title;
	const char * c = total.c_str();

	ShellExecute(NULL, "open", c, NULL, NULL, SW_SHOWNORMAL);
}

// 현재 Tree의 모든 노드를 출력하는 함수
void Application::Displaymusic()
{
	m_List.PrintTree(cout);				// PrintTree함수를 통해서 출력
	cout << endl;
}

// 최근 추가한 음악을 출력한다(30개 이하)
void Application::DisplayNewMusic()
{
	s_List.Print();
}


// 가장 많이 재생된 노래 30곡을 재생한다.
void Application::DisPlayMostPlayedMusic()
{
	if (!f_List->IsEmpty()) // Heap가 Empty인지 아닌지 검사
	{
		f_List->PrintHeap(); // 음악정보 출력
	}
	else
		cout << "\n\t재생한 노래가 없습니다!!!" << endl;
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.

								// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

								// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_OutFile)	return 0;
	else	return 1;
}

// 재생목록에 음악 추가
int Application::AddToPlayMusic()
{
	MasterType copy;
	MasterType *mData;
	PlayType temp; // 입력된 음악이 어느 장르에 속하는지 찾기 위한 더미
	PlayType *pData; // p_List의 해당 장르를 포인터로 가르키기 위한 더미

	cout << "\t재생목록에 추가할 노래를 입력하세요." << endl;
	temp.SetPlayRecordFromKB();
	copy.SetName(temp.GetPlayName());

	p_List.ResetList();
	int length = p_List.GetLength();
	int m_length = m_List.GetLength();
	bool found = false;

	mData = m_List.Get(copy);
	for (int i = 0; i <= length; i++)
	{
		if (temp.GetPlayName() == mData->GetName() && temp.GetPlayArtist() == mData->GetArtist())
		{
			found = true;
			temp.SetPlayInfo(mData->GetID(), mData->GetName(), mData->GetArtist());
			p_List.Add(temp);
			cout << "\n\t음악이 추가되었습니다!";
			return 0;
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

	item.SetPlayNameFromKB();
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

string ExePath()
{
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	string::size_type pos = string(buffer).find_last_of("\\/");
	return string(buffer).substr(0, pos);
}

// 선택한 음악을 재생목록에 추가한다.
void Application::PlayMusic()
{
	int Number;
	PlayType item;
	PlayType *pData;
	MasterType temp;	//m_List의 값을 비교해주기 위한 임시 ItemType.
	MasterType *mData;
	MostPlayedMusicType MostItem;
	MostPlayedMusicType *MostData;

	if (p_List.IsEmpty() == true)
	{
		cout << "\t재생목록에 아무것도 없습니다!!!";
		return;
	}

	p_List.ResetList();
	cout << "<=============I 재생목록 !===========>";
	for (int i = 0; i < p_List.GetLength(); i++)
	{
		p_List.GetNextItem(item);
		item.DisplayPlayOnScreen();
	}
	cout << "<====================================>" << endl;

	cout << "\n\t재생하고 싶은 노래의 제목을 입력하세요 : " << endl;
	item.SetPlayRecordFromKB();
	temp.SetName(item.GetPlayName());
	
	if (m_List.Find(temp))	//find함수에서는 일치하는 항목이 존재하지 않을때 -1을 리턴하므로 -1이 아니면 일치하는 문자열이 있는것이다.
	{
		temp = *m_List.Get(temp);
		if (temp.GetArtist() == item.GetPlayArtist())
		{
			pData = p_List.GetPoint(item);
			cout << "\n<==============I 재생중 !============>";
			pData->DisplayPlayOnScreen();
			cout << "<====================================>" << endl;

			Number = pData->GetPlayNumber();
			Number++;
			pData->SetPlayNumber(Number);

			MostItem.SetInfo(pData->GetPlayID(), pData->GetPlayName(), pData->GetPlayArtist(), pData->GetPlayNumber());
			if (f_List->IsEmpty())
			{
				f_List->Add(MostItem);
			}
			else
			{
				bool found = false;
				f_List->RetrieveItem(MostItem, found); // 음악정보 검색
				if (found)
				{
					found = false;
					MostItem.SetInfo(pData->GetPlayID(), pData->GetPlayName(), pData->GetPlayArtist(), pData->GetPlayNumber());
					f_List->ReplaceItem(MostItem, found);
				}
				else
				{
					f_List->Add(MostItem);
				}
			}

			string name = item.GetPlayName() + "-" + item.GetPlayArtist();
			string back = ".wav";
			string song = ExePath() + "\\" + name + back;
			LPCSTR m_title = song.c_str();

			PlaySound(m_title, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			while (!_kbhit());
			PlaySound(NULL, 0, 0);
		}
	}
	else
	{
		cout << "\n<======I 아이템을 찾을 수 없습니다 !=======>" << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
		return;
	}
}

// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	
	int index = 0;
	MasterType music;	// 읽기용 임시 변수
	SimpleMusicType simple;

	char filename[FILENAMESIZE] = "노래목록.txt";

	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(filename))
		return 0;

	// 파일의 모든 내용을 읽어 list에 추가
	while (!m_InFile.eof())
	{
		// array에 학생들의 정보가 들어있는 structure 저장
		music.ReadDataFromFile(m_InFile);
		m_List.Add(music);
		simple.SetRecord(music.GetID(), music.GetName());

		///////////////////////////////////////////장르////////////////////////////////////////

		GenreType genre;
		GenreType *pData;

		genre.SetGenreName(music.GetGenre());
		g_List.Find(genre);

		if (g_List.Find(genre))
		{
			genre.SetGenreInfo(music.GetID(), G_ID, music.GetGenre());
			pData = g_List.Get(genre);
			pData->AddMusicInGenre(simple);

			if (s_List.IsFull())
				s_List.DeQueue(simple);  //최근 음악 목록에서 가장 오래된 음악 제거
			else
				s_List.EnQueue(simple);  // 최근 음악 목록에서 최신 음악 추가
		}
		else
		{
			G_ID++;
			genre.SetGenreInfo(music.GetID(), G_ID, music.GetGenre());
			g_List.Add(genre);
			pData = g_List.Get(genre);
			pData->AddMusicInGenre(simple);

			if (s_List.IsFull())
				s_List.DeQueue(simple);  //최근 음악 목록에서 가장 오래된 음악 제거
			else
				s_List.EnQueue(simple);  // 최근 음악 목록에서 최신 음악 추가		
		}

		///////////////////////////////////////////앨범////////////////////////////////////////

		AlbumType Album;
		AlbumType *pAlbumData;

		Album.SetAlbumName(music.GetAlbum());
		album_List.Find(Album);

		if (album_List.Find(Album))
		{
			Album.SetAlbumInfo(music.GetID(), Album_ID, music.GetAlbum());
			pAlbumData = album_List.Get(Album);
			pAlbumData->AddMusicInAlbum(simple);
		}
		else
		{
			Album_ID++;
			Album.SetAlbumInfo(music.GetID(), Album_ID, music.GetAlbum());
			album_List.Add(Album);
			pAlbumData = album_List.Get(Album);
			pAlbumData->AddMusicInAlbum(simple);
		}

		///////////////////////////////////////////가수////////////////////////////////////////

		ArtistType Artist;
		ArtistType *pArtistData;

		Artist.SetArtistName(music.GetArtist());
		artist_List.Find(Artist);

		if (artist_List.Find(Artist))
		{
			Artist.SetArtistInfo(music.GetID(), Artist_ID, music.GetArtist());
			pArtistData = artist_List.Get(Artist);
			pArtistData->AddMusicInArtist(simple);
		}
		else
		{
			Artist_ID++;
			Artist.SetArtistInfo(music.GetID(), Artist_ID, music.GetArtist());
			artist_List.Add(Artist);
			pArtistData = artist_List.Get(Artist);
			pArtistData->AddMusicInArtist(simple);
		}
	}
	m_InFile.close();	// file close

	return 1;
}

// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	
	MasterType data;	// 쓰기용 임시 변수
	char filename[FILENAMESIZE] = "노래목록.txt";

	// file open, open error가 발생하면 0을 리턴
	if (!OpenOutFile(filename))
	{
		cout << "\n\t파일이 존재하지 않습니다!";
		return 0;
	}

	m_List.SaveTree(m_OutFile);				// PrintTree함수를 통해서 출력
	cout << "\n\t저장에 성공했습니다!";
	m_OutFile.close();	// file close
	return 1;
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

//회원 정보 설정하기
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