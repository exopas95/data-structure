#include "MusicType.h"

// ���ǹ�ȣ�� �ڵ����� �����Ѵ�.
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

// ���ǹ�ȣ�� Ű����� �Է��Ѵ�.
void MusicType::SetIDFromKB()
{
	cout << "\tID : ";
	cin >> m_mID;
}

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
	SetIDAuto();
	SetNameFromKB();
	SetArtistFromKB();
	SetAlbumFromKB();
	SetGenreFromKB();
	SetLyricsFromKB();
}


// ���Ͽ��� ������ �о�´�.
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


// ���Ͽ� ������ ����Ѵ�.
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

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)�� ���� ��� true, �ٸ� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool MusicType::operator == (const MusicType &obj)
{
	return (this->m_mID == obj.m_mID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� Ŭ ��� true, �۰ų� ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool MusicType::operator > (const MusicType &obj)
{
	return (this->m_mID > obj.m_mID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� ���� ��� true, ũ�ų� ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool MusicType::operator < (const MusicType &obj)
{
	return (this->m_mID < obj.m_mID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� ũ�ų� ���� ��� true, ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool MusicType::operator >= (const MusicType &obj)
{
	return (this->m_mID >= obj.m_mID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� �۰ų� ���� ��� true, Ŭ ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool MusicType::operator <= (const MusicType &obj)
{
	return (this->m_mID <= obj.m_mID);
}
