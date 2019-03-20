#include "MasterType.h"

// 음악번호를 자동으로 저장한다.
void MasterType::SetIDAuto()
{
	time_t curr_time;

	struct tm *curr_tm;

	curr_time = time(NULL);
	curr_tm = localtime(&curr_time);

	int current_time = curr_tm->tm_hour * 10000
		+ curr_tm->tm_min * 100 + curr_tm->tm_sec;

	int current_time_2 = (curr_tm->tm_year + 1900) * 10000 + (curr_tm->tm_mon + 1) * 100
		+ curr_tm->tm_mday;

	m_mID = current_time + current_time_2;
}

// 음악번호를 키보드로 입력한다.
void MasterType::SetIDFromKB()
{
	cout << "\tID : ";
	cin >> m_mID;
}

// 음악명을 키보드로 입력한다.
void MasterType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_mName;
}


// 가수명을 키보드로 입력한다.
void MasterType::SetArtistFromKB()
{
	cout << "\tArtist : ";
	cin >> m_mArtist;
}

// 앨범명을 키보드로 입력한다.
void MasterType::SetAlbumFromKB()
{
	cout << "\tAlbum : ";
	cin >> m_mAlbum;
}

// 장르명을 키보드로 입력한다.
void MasterType::SetGenreFromKB()
{
	cout << "\tGenre : ";
	cin >> m_mGenre;
}

// 가사를 키보드로 입력한다.
void MasterType::SetLyricsFromKB()
{
	cout << "\tLyrics : ";
	getline(cin, m_mLyrics);
	getline(cin, m_mLyrics);
}


// 음악에 대한 정보를 키보드로 입력한다.
void MasterType::SetRecordFromKB()
{
	SetIDAuto();
	SetNameFromKB();
	SetArtistFromKB();
	SetAlbumFromKB();
	SetGenreFromKB();
	SetLyricsFromKB();
}


// 파일에서 정보를 읽어온다.
int MasterType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_mID;
	fin >> m_mName;
	fin >> m_mArtist;
	fin >> m_mAlbum;
	fin >> m_mGenre;
	getline(fin, m_mLyrics);
	getline(fin, m_mLyrics);

	return 1;
};


// 파일에 정보를 기록한다.
int MasterType::WriteDataToFile(ofstream& fout)
{
	fout << m_mID << endl;
	fout << m_mName << endl;
	fout << m_mArtist << endl;
	fout << m_mAlbum << endl;
	fout << m_mGenre << endl;
	fout << m_mLyrics << endl;

	return 1;
}


// 2개의 아이템타입을 비교한다
RelationType MasterType::ComparedTo(const MasterType &data)
{
	if (this->m_mName > data.m_mName)
		return GREATER;
	else if (this->m_mName < data.m_mName)
		return LESS;
	else
		return EQUAL;
}