#include "MusicType.h"



// ���Ǹ��� Ű����� �Է��Ѵ�.
void MusicType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_mName;
}


// �������� Ű����� �Է��Ѵ�.
void MusicType::SetArtistFromKB()
{
	cout << "\tArtist : ";
	cin >> m_mArtist;
}

// �ٹ����� Ű����� �Է��Ѵ�.
void MusicType::SetAlbumFromKB()
{
	cout << "\tAlbum : ";
	cin >> m_mAlbum;
}

// �帣���� Ű����� �Է��Ѵ�.
void MusicType::SetGenreFromKB()
{
	cout << "\tGenre : ";
	cin >> m_mGenre;
}

// ���縦 Ű����� �Է��Ѵ�.
void MusicType::SetLyricsFromKB()
{
	cout << "\tLyrics : ";
	getline(cin, m_mLyrics);
	getline(cin, m_mLyrics);
}


// ���ǿ� ���� ������ Ű����� �Է��Ѵ�.
void MusicType::SetRecordFromKB()
{
	SetNameFromKB();
	SetArtistFromKB();
	SetAlbumFromKB();
	SetGenreFromKB();
	SetLyricsFromKB();
}


// ���Ͽ��� ������ �о�´�.
int MusicType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_mName;
	fin >> m_mArtist;
	fin >> m_mAlbum;
	fin >> m_mGenre;
	fin >> m_mLyrics;

	return 1;
};


// ���Ͽ� ������ ����Ѵ�.
int MusicType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_mName << " ";
	fout << m_mArtist << " ";
	fout << m_mAlbum << " ";
	fout << m_mGenre << " ";
	fout << m_mLyrics << " ";

	return 1;
}


// �ΰ��� MusicType�� ���Ѵ�. - BinarySearch ����
RelationType MusicType::BinaryCompareByName(const MusicType &data) 
{
	if (m_mName == data.m_mName) //�� MusicType�� ������ EQUAL�� ��ȯ�Ѵ�.
		return EQUAL;
	else
	{
		if (this->m_mName > data.m_mName)
			return GREATER;
		else if (this->m_mName < data.m_mName)
			return LESS;
	}
}

// �ΰ��� MusicType�� ���Ѵ�. - �Ϲ� ����
RelationType MusicType::CompareByName(const MusicType &data)
{
	if(this->m_mName > data.m_mName) // �� MusicType�� ������ EQUAL�� ��ȯ�Ѵ�.
		return GREATER;
	else if(this->m_mName < data.m_mName)
		return LESS;
	else
		return EQUAL;
}