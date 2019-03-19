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
			SearchByName();
			break;
		case 5:	// 리스트에 있는 가수 검색
				// 단, 검색어가 가수명에 포함된다면 출력한다
			RetreiveRecordByArtist();
			break;
		case 6:	// 리스트에 있는 앨범 검색
				// 단, 검색어가 앨범명에 포함된다면 출력한다
			RetreiveRecordByAlbum();
			break;
		case 7:	// 리스트에 있는 장르 검색
				// 단, 검색어가 장르명에 포함된다면 출력한다
			RetreiveRecordByGenre();
			break;
		case 8:	// 리스트에 있는 모든 음악정보 출력
			DisplayAllMusic();
			break;
		case 9:	// txt 파일에서 음악정보를 읽어온다
			ReadDataFromFile();
			break;
		case 10:	// txt 파일에 음악정보를 쓴다
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
	if (m_List.Get(item) == 1) // 아이템이 중복되는지 확인
	{
		cout << "\tItem already exist" << endl;
		return 0;
	}

	m_List.Add(item);

	// 현재 list 출력
	DisplayAllMusic();

	return 1;
}

// 곡명으로 아이템을 찾아 출력한다.
int Application::SearchByName()
{
	MusicType item;
	item.SetNameFromKB(); //Name입력받는다.
	
	m_List.GetBinarySearch(item);
	return 0;	//실패(0)을 리턴
}

// 가수명으로 아이템을 찾아 출력한다.
void Application::RetreiveRecordByArtist()
{
	MusicType temp;
	temp.SetArtistFromKB();	//SearchListByMusicArtist함수에 넘겨줄 temp의 name을 사용자에게 입력받는다.
	SearchListByMusicArtist(temp);	//실질적으로 찾는 동작을 하는 SearchListByMusicArtist함수를 호출하고 temp값을 넘겨준다.
}
// 앨범명으로 아이템을 찾아 출력한다.
void Application::RetreiveRecordByAlbum()
{
	MusicType temp;
	temp.SetAlbumFromKB();	//SearchListByMusicAlbum함수에 넘겨줄 temp의 name을 사용자에게 입력받는다.
	SearchListByMusicAlbum(temp);	//실질적으로 찾는 동작을 하는 SearchListByMusicAlbum함수를 호출하고 temp값을 넘겨준다.
}

// 장르명으로 아이템을 찾아 출력한다.
void Application::RetreiveRecordByGenre()
{
	MusicType temp;
	temp.SetGenreFromKB();	//SearchListByMusicGenre함수에 넘겨줄 temp의 name을 사용자에게 입력받는다.
	SearchListByMusicGenre(temp);	//실질적으로 찾는 동작을 하는 SearchListByMusicGenre함수를 호출하고 temp값을 넘겨준다.
}



// 가수명으로 아이템을 찾아 출력한다.
void Application::SearchListByMusicArtist(MusicType &inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 ItemType.
	m_List.ResetList();
	int cur = m_List.GetNextItem(temp), count = 0;	//cur에 temp의 index값을 저장해준다. count는 찾은 항목의 개수를 저장해주기 위한 변수.
	while (cur<m_List.GetLength() && cur != -1)	//index가 length를 넘기 전까지, List의 끝까지 도달하면 GetNextItem함수는 -1을 리턴하므로 cur==-1이어도 반복을 멈춘다.
	{
		if (temp.GetArtist().find(inData.GetArtist()) != -1)	//find함수에서는 일치하는 항목이 존재하지 않을때 -1을 리턴하므로 -1이 아니면 일치하는 문자열이 있는것이다.
		{
			cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();	//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
			cout << "<====================================>" << endl;
			count++;	//찾은 개수를 1 늘려준다.
		}
		cur = m_List.GetNextItem(temp);	//cur를 1 늘려준다.
	}
	if (count == 0)
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}

// 앨범명으로 아이템을 찾아 출력한다.
void Application::SearchListByMusicAlbum(MusicType &inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 ItemType.
	m_List.ResetList();
	int cur = m_List.GetNextItem(temp), count = 0;	//cur에 temp의 index값을 저장해준다. count는 찾은 항목의 개수를 저장해주기 위한 변수.
	while (cur<m_List.GetLength() && cur != -1)	//index가 length를 넘기 전까지, List의 끝까지 도달하면 GetNextItem함수는 -1을 리턴하므로 cur==-1이어도 반복을 멈춘다.
	{
		if (temp.GetAlbum().find(inData.GetAlbum()) != -1)	//find함수에서는 일치하는 항목이 존재하지 않을때 -1을 리턴하므로 -1이 아니면 일치하는 문자열이 있는것이다.
		{
			cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();	//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
			cout << "<====================================>" << endl;
			count++;	//찾은 개수를 1 늘려준다.
		}
		cur = m_List.GetNextItem(temp);	//cur를 1 늘려준다.
	}
	if (count == 0)
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}

// 장르명으로 아이템을 찾아 출력한다.
void Application::SearchListByMusicGenre(MusicType &inData)
{
	MusicType temp;	//m_List의 값을 비교해주기 위한 임시 ItemType.
	m_List.ResetList();
	int cur = m_List.GetNextItem(temp), count = 0;	//cur에 temp의 index값을 저장해준다. count는 찾은 항목의 개수를 저장해주기 위한 변수.
	while (cur<m_List.GetLength() && cur != -1)	//index가 length를 넘기 전까지, List의 끝까지 도달하면 GetNextItem함수는 -1을 리턴하므로 cur==-1이어도 반복을 멈춘다.
	{
		if (temp.GetGenre().find(inData.GetGenre()) != -1)	//find함수에서는 일치하는 항목이 존재하지 않을때 -1을 리턴하므로 -1이 아니면 일치하는 문자열이 있는것이다.
		{
			cout << "<============I FOUND ITEM !==========>" << endl;
			temp.DisplayRecordOnScreen();	//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
			cout << "<====================================>" << endl;
			count++;	//찾은 개수를 1 늘려준다.
		}
		cur = m_List.GetNextItem(temp);	//cur를 1 늘려준다.
	}
	if (count == 0)
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;	//찾은 개수가 0개이면 찾을 수 없다는 메시지를 출력한다.
}

//곡명으로 item을 찾아서 제거한다.
int Application::DeleteMusic()
{
	int pre = m_List.GetLength();//이전 item개수를 받아온다.
	MusicType item;
	item.SetNameFromKB();
	
	m_List.Delete(item);

	if(pre> m_List.GetLength()) //이전 item개수보다 현재 item개수가 많아지면 제거성공
	{
		cout<<"<========DELETE SUCCESS !===========>"<<endl;
		this->DisplayAllMusic(); //모든 item을 출력한다.
		return 1;
	}
	
	cout<<"<========DELETE FAIL !=======>"<<endl;
	this->DisplayAllMusic();//모든 item을 출력한다.
	return 0;
}

//해당 곡명의 item을 변경한다.
int Application::ReplaceMusic()
{
	MusicType item;
	item.SetRecordFromKB(); //키보드로부터 정보를 입력받음

	m_List.Replace(item); //해당 item의 곡명 일치하는 것을 찾아 바꾼다.
	this->DisplayAllMusic();
	return 0;
}


// 리스트에 저장된 모든 데이터를 출력한다.
void Application::DisplayAllMusic()
{
	MusicType data;

	cout << "\n\tCurrent list" << endl;

	// list의 모든 데이터를 화면에 출력
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
	if(!OpenOutFile(filename))
		return 0;

	// list 포인터를 초기화
	m_List.ResetList();

	// list의 모든 데이터를 파일에 쓰기
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

