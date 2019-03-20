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
	cout << "\t���� ��ȣ : ";
	cin >> m_mID;	
}

// ���Ǹ��� Ű����� �Է��Ѵ�.
void MusicType::SetNameFromKB()
{
	cout << "\t���� : ";
	getline(cin, m_mName);
	getline(cin, m_mName);
}


// �������� Ű����� �Է��Ѵ�.
void MusicType::SetArtistFromKB()
{
	cout << "\t���� : ";
	cin >> m_mArtist;
}

// �ٹ����� Ű����� �Է��Ѵ�.
void MusicType::SetAlbumFromKB()
{
	cout << "\t�ٹ� : ";
	cin >> m_mAlbum;
}

// �帣���� Ű����� �Է��Ѵ�.
void MusicType::SetGenreFromKB()
{
	cout << "\t�帣 : ";
	cin >> m_mGenre;
}

// ���縦 Ű����� �Է��Ѵ�.
void MusicType::SetLyricsFromKB()
{
	cout << "\t���� : ";
	getline(cin, m_mLyrics);
}

// �帣���� Ű����� �Է��Ѵ�.
void MusicType::SetCompanyFromKB()
{
	cout << "\t�Ҽӻ� : ";
	cin >> m_mCompany;
}

// ���縦 Ű����� �Է��Ѵ�.
void MusicType::SetMadeFromKB()
{
	cout << "\t��ǥ������ : ";
	getline(cin, m_mMade);
	getline(cin, m_mMade);
}

// �Ǻ��� Ű����� �Է��Ѵ�.
void MusicType::SetNoteFromKB()
{
	cout << "\t�Ǻ� : ";
	getline(cin, m_mNote);
	getline(cin, m_mNote);
}

// ����ð��� Ű����� �Է��Ѵ�.
void MusicType::SetLongFromKB()
{
	cout << "\t����ð� : ";
	cin >> m_mLong;
}

// ����ð��� Ű����� �Է��Ѵ�.
void MusicType::SetNumberFromKB()
{
	cout << "\t ���Ƚ�� : ";
	cin >> m_mNumber;
}




// ���ǿ� ���� ������ Ű����� �Է��Ѵ�.
void MusicType::SetRecordFromKB()
{
	SetIDAuto();
	SetNameFromKB();
	SetArtistFromKB();
	SetCompanyFromKB();
	SetAlbumFromKB();
	SetGenreFromKB();
	SetMadeFromKB();
	SetLongFromKB();
	SetNoteFromKB();
	SetLyricsFromKB();
	
}


// ���Ͽ��� ������ �о�´�.
int MusicType::ReadDataFromFile(ifstream& fin)
{


	fin >> m_mID;
	getline(fin, m_mName);
	getline(fin, m_mName);
	fin >> m_mArtist;
	fin >> m_mCompany;
	fin >> m_mAlbum;
	fin >> m_mGenre;
	getline(fin, m_mMade);
	getline(fin, m_mMade);
	fin >> m_mLong;
	fin >> m_mNumber;
	getline(fin, m_mNote);
	getline(fin, m_mNote);
	getline(fin, m_mLyrics);

	return 1;
};


// ���Ͽ� ������ ����Ѵ�.
int MusicType::WriteDataToFile(ofstream& fout)
{
	fout << m_mID << endl;
	fout << m_mName << endl;
	fout << m_mArtist << endl;
	fout << m_mCompany << endl;
	fout << m_mAlbum << endl;
	fout << m_mGenre << endl;
	fout << m_mMade << endl;
	fout << m_mLong << endl;
	fout << m_mNumber << endl;
	fout << m_mNote << endl;
	fout << m_mLyrics << endl;

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
