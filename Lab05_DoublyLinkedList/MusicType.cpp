#include "MusicType.h"

// 음악번호를 자동으로 저장한다.
void MusicType::SetIDAuto()
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
void MusicType::SetIDFromKB()
{
	cout << "\tID : ";
	cin >> m_mID;
}

// 음악명을 키보드로 입력한다.
void MusicType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_mName;
}


// 가수명을 키보드로 입력한다.
void MusicType::SetArtistFromKB()
{
	cout << "\tArtist : ";
	cin >> m_mArtist;
}

// 앨범명을 키보드로 입력한다.
void MusicType::SetAlbumFromKB()
{
	cout << "\tAlbum : ";
	cin >> m_mAlbum;
}

// 장르명을 키보드로 입력한다.
void MusicType::SetGenreFromKB()
{
	cout << "\tGenre : ";
	cin >> m_mGenre;
}

// 가사를 키보드로 입력한다.
void MusicType::SetLyricsFromKB()
{
	cout << "\tLyrics : ";
	getline(cin, m_mLyrics);
	getline(cin, m_mLyrics);
}


// 음악에 대한 정보를 키보드로 입력한다.
void MusicType::SetRecordFromKB()
{
	SetIDAuto();
	SetNameFromKB();
	SetArtistFromKB();
	SetAlbumFromKB();
	SetGenreFromKB();
	SetLyricsFromKB();
}


// 파일에서 정보를 읽어온다.
int MusicType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_mID;
	fin >> m_mName;
	fin >> m_mArtist;
	fin >> m_mAlbum;
	fin >> m_mGenre;
	fin >> m_mLyrics;

	return 1;
};


// 파일에 정보를 기록한다.
int MusicType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_mID << " ";
	fout << m_mName << " ";
	fout << m_mArtist << " ";
	fout << m_mAlbum << " ";
	fout << m_mGenre << " ";
	fout << m_mLyrics << " ";

	return 1;
}

// this(저장되어있는값)가 obj(입력하는값)와 같을 경우 true, 다를 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool MusicType::operator == (const MusicType &obj)
{
	return (this->m_mID == obj.m_mID);
}

// this(저장되어있는값)가 obj(입력하는값)보다 클 경우 true, 작거나 같을 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool MusicType::operator > (const MusicType &obj)
{
	return (this->m_mID > obj.m_mID);
}

// this(저장되어있는값)가 obj(입력하는값)보다 작을 경우 true, 크거나 같을 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool MusicType::operator < (const MusicType &obj)
{
	return (this->m_mID < obj.m_mID);
}

// this(저장되어있는값)가 obj(입력하는값)보다 크거나 같을 경우 true, 작을 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool MusicType::operator >= (const MusicType &obj)
{
	return (this->m_mID >= obj.m_mID);
}

// this(저장되어있는값)가 obj(입력하는값)보다 작거나 같을 경우 true, 클 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool MusicType::operator <= (const MusicType &obj)
{
	return (this->m_mID <= obj.m_mID);
}
