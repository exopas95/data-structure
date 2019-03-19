#include "GenreType.h"

bool GenreType::operator == (const GenreType &obj)
{
	return (this->m_GenreID==obj.m_GenreID);
}

bool GenreType::operator > (const GenreType &obj)
{
	return (this->m_GenreID>obj.m_GenreID);
}

bool GenreType::operator < (const GenreType &obj)
{
	return (this->m_GenreID<obj.m_GenreID);
}

bool GenreType::operator >= (const GenreType &obj)
{
	return (this->m_GenreID>=obj.m_GenreID);
}

bool GenreType::operator <= (const GenreType &obj)
{
	return (this->m_GenreID<=obj.m_GenreID);
}


void GenreType::AddMusicInGenre(SimpleMusicType indata)
{
	mGenreMusicList.Add(indata);
}

void GenreType::DisplayMusicDetailInGenre(SortedList<MusicType> *list)
{
	SimpleMusicType data;
	SimpleMusicType copy;

	cout << "\n\tCurrent list" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	mGenreMusicList.ResetList();
	int length = mGenreMusicList.GetLength();
	int curIndex = mGenreMusicList.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		cout << "\n\t" << curIndex + 1 << "��" << endl;
		data.DisplayRecordOnScreen();
		copy = data;
		curIndex = mGenreMusicList.GetNextItem(data);
	}

	char Agree;
	cout << "\n\tMore Detail Search? (Y/N): ";
	cin >> Agree;

	bool condition = true;
	while (condition)
	{
		if (Agree == 'Y')
		{
			int ID;
			cout << "\n\tType Genre ID number: ";
			cin >> ID;

			if (copy.GetID() == ID)
			{
				MusicType temp;
				list->ResetList();
				int cur = list->GetNextItem(temp), count = 0;
				while (cur < list->GetLength() && cur != -1)
				{
					cout << endl;
					cout << "<============I FOUND ITEM !==========>" << endl;
					temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
					cout << "<====================================>" << endl;
					cur++;	//ã�� ������ 1 �÷��ش�.
				}
				break;
			}
			else
			{
				cout << "\t\nID not exist!";
				break;
			}
			condition = false;
		}
		else if (Agree == 'N')
		{
			condition = false;
		}
		else
		{
			cout << "\n\tPlease Type Y or N";
		}
	}
	

}
	//?? SimpleMusicType �� data �� music id �� title ���� ���´�.
	// �ش� �帣�� ���ԵǴ� ��� ���� ������ ����ϱ� ���ؼ� �� ������ ������
	// �� �Լ��� �Ķ������ list�� �˻��Ͽ� music information �� ����� �־�� ��.
