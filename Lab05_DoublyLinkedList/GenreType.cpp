#include "GenreType.h"

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)�� ���� ��� true, �ٸ� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool GenreType::operator == (const GenreType &obj)
{
	return (this->m_GenreID==obj.m_GenreID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� Ŭ ��� true, �۰ų� ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool GenreType::operator > (const GenreType &obj)
{
	return (this->m_GenreID>obj.m_GenreID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� ���� ��� true, ũ�ų� ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool GenreType::operator < (const GenreType &obj)
{
	return (this->m_GenreID<obj.m_GenreID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� ũ�ų� ���� ��� true, ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool GenreType::operator >= (const GenreType &obj)
{
	return (this->m_GenreID>=obj.m_GenreID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� �۰ų� ���� ��� true, Ŭ ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool GenreType::operator <= (const GenreType &obj)
{
	return (this->m_GenreID<=obj.m_GenreID);
}

// Simple Music List�� ������ ���� ������ �����Ѵ�.
void GenreType::AddMusicInGenre(SimpleMusicType indata)
{
	mGenreMusicList.Add(indata);
}

// Simple Music List�� ������ ���� ������ �����Ѵ�.
void GenreType::DeleteMusicInGenre(SimpleMusicType indata)
{
	mGenreMusicList.Delete(indata);
}

// ���� ����Ǿ��ִ� �帣 ����� ����Ѵ�.
// ���� �帣 ��Ͽ� �ִ� ��鿡 ���� �ڼ��� ������ ���� ��� �̸� ã�Ƽ� ����Ѵ�.
DoublySortedLinkedList<SimpleMusicType>* GenreType::B_DetailInfo()
{
	return &mGenreMusicList;
}

// ���� ����Ǿ��ִ� �帣 ����� ����Ѵ�.
// ���� �帣 ��Ͽ� �ִ� ��鿡 ���� �ڼ��� ������ ���� ��� �̸� ã�Ƽ� ����Ѵ�.
void GenreType::C_DetailInfo()
{
	DoublyIterator<SimpleMusicType> s_itor(mGenreMusicList);
	SimpleMusicType *sdata = s_itor.Next();
	while (s_itor.NextNotNull())
	{
		sdata->DisplayRecordOnScreen();
		sdata = s_itor.Next();
	}

	char Agree;
	cout << "\n\t���� ���λ����� Ȯ���Ͻðڽ��ϱ�? (Y/N): ";
	cin >> Agree;
	if (Agree == 'Y')
	{
		int ID;
		cout << "\n\t���� ID�� �Է��ϼ���: ";
		cin >> ID;

		MusicType *m_data;
		MusicType musicData;
		musicData.SetID(ID);
		m_data = m_List.Get(musicData);
		cout << "\n\t<���� C>\n";
		m_data->DisplayRecordOnScreen();

	}
	else
		cout << "\n\t�ش� ���� ID�� �����ϴ�!";

}