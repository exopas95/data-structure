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
// ���� �帣 ��Ͽ� �ִ� ���ǵ鿡 ���� �ڼ��� ������ ���� ��� �̸� ã�Ƽ� ����Ѵ�.
void GenreType::DisplayMusicDetailInGenre(SortedLinkedList<MusicType> *list)
{
	SimpleMusicType data;
	SimpleMusicType copy;

	cout << "\n\t���� ��� : " << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	mGenreMusicList.ResetList();
	int length = mGenreMusicList.GetLength();
	for (int i = 0; i < length; i++)
	{
		mGenreMusicList.GetNextItem(data);
		cout << "\n\t" << i + 1 << "��" << endl;
		data.DisplayRecordOnScreen();
		copy = data;
	}

	char Agree;
	cout << "\n\t���� ���λ����� Ȯ���Ͻðڽ��ϱ�? (Y/N): ";
	cin >> Agree;

	bool condition = true;
	bool found = true;
	while (condition)
	{
		if (Agree == 'Y')
		{
			mGenreMusicList.ResetList();
			int length = mGenreMusicList.GetLength();
			int ID;
			cout << "\n\t���� ID�� �Է��ϼ���: ";
			cin >> ID;

			for (int i = 0; i < length; i++)
			{
				mGenreMusicList.GetNextItem(data);
				if (data.GetID() == ID)  // ����Ʈ�� ���̵� ������
				{
					MusicType temp;
					list->ResetList();
					for (int i = 0; i < list->GetLength(); i++)
					{
						list->GetNextItem(temp);
						if (temp.GetID() == ID)
						{
							cout << endl;
							cout << "<============I FOUND ITEM !==========>" << endl;
							temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
							cout << "<====================================>" << endl;
							condition = false;
							found = true;
							break;
						}
					}
				}
				else
					found = false;
			}
			if (found == false) // ����Ʈ�� ���̵� ������ 
			{
				cout << "\n\t�ش� ���� ID�� �����ϴ�!";
			}
		}
		else if (Agree == 'N')
		{
			condition = false;
		}
		else
		{
			cout << "\n\tY �Ǵ� N�� �Է����ּ���: ";
			cin >> Agree;
		}
	}
}
