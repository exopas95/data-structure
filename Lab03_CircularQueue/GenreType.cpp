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

	// list의 모든 데이터를 화면에 출력
	mGenreMusicList.ResetList();
	int length = mGenreMusicList.GetLength();
	int curIndex = mGenreMusicList.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		cout << "\n\t" << curIndex + 1 << "번" << endl;
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
					temp.DisplayRecordOnScreen();	//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
					cout << "<====================================>" << endl;
					cur++;	//찾은 개수를 1 늘려준다.
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
	//?? SimpleMusicType 인 data 는 music id 와 title 만을 갖는다.
	// 해당 장르에 포함되는 모든 음악 정보를 출력하기 위해서 이 정보를 가지고
	// 이 함수의 파라미터인 list를 검색하여 music information 을 출력해 주어야 함.
