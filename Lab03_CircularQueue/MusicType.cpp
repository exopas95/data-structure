#include "MusicType.h"

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
	SetIDFromKB();
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


//// 두가지 MusicType를 비교한다. - BinarySearch 버전
//RelationType MusicType::BinaryCompareByName(const MusicType &data) 
//{
//	if (m_mName == data.m_mName) //두 MusicType이 같으면 EQUAL을 반환한다.
//		return EQUAL;
//	else
//	{
//		if (this->m_mName > data.m_mName)
//			return GREATER;
//		else if (this->m_mName < data.m_mName)
//			return LESS;
//	}
//}
//
//// 두가지 MusicType를 비교한다. - 일반 버전
//RelationType MusicType::CompareByName(const MusicType &data)
//{
//	if(this->m_mName > data.m_mName) // 두 MusicType이 같으면 EQUAL을 반환한다.
//		return GREATER;
//	else if(this->m_mName < data.m_mName)
//		return LESS;
//	else
//		return EQUAL;
//}
//
//RelationType MusicType::CompareByID(const MusicType &data)
//{
//	if (this->m_mID > data.m_mID) // 두 MusicType이 같으면 EQUAL을 반환한다.
//		return GREATER;
//	else if (this->m_mID < data.m_mID)
//		return LESS;
//	else
//		return EQUAL;
//}


bool MusicType::operator == (const MusicType &obj)
{
	return (this->m_mID == obj.m_mID);
}

bool MusicType::operator > (const MusicType &obj)
{
	return (this->m_mID > obj.m_mID);
}

bool MusicType::operator < (const MusicType &obj)
{
	return (this->m_mID < obj.m_mID);
}

bool MusicType::operator >= (const MusicType &obj)
{
	return (this->m_mID >= obj.m_mID);
}

bool MusicType::operator <= (const MusicType &obj)
{
	return (this->m_mID <= obj.m_mID);
}
