#include "GenreType.h"

// this(저장되어있는값)가 obj(입력하는값)와 같을 경우 true, 다를 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool GenreType::operator == (const GenreType &obj)
{
	return (this->m_GenreID==obj.m_GenreID);
}

// this(저장되어있는값)가 obj(입력하는값)보다 클 경우 true, 작거나 같을 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool GenreType::operator > (const GenreType &obj)
{
	return (this->m_GenreID>obj.m_GenreID);
}

// this(저장되어있는값)가 obj(입력하는값)보다 작을 경우 true, 크거나 같을 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool GenreType::operator < (const GenreType &obj)
{
	return (this->m_GenreID<obj.m_GenreID);
}

// this(저장되어있는값)가 obj(입력하는값)보다 크거나 같을 경우 true, 작을 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool GenreType::operator >= (const GenreType &obj)
{
	return (this->m_GenreID>=obj.m_GenreID);
}

// this(저장되어있는값)가 obj(입력하는값)보다 작거나 같을 경우 true, 클 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool GenreType::operator <= (const GenreType &obj)
{
	return (this->m_GenreID<=obj.m_GenreID);
}

// Simple Music List에 간단한 음악 정보를 저장한다.
void GenreType::AddMusicInGenre(SimpleMusicType indata)
{
	mGenreMusicList.Add(indata);
}

// Simple Music List에 간단한 음악 정보를 제거한다.
void GenreType::DeleteMusicInGenre(SimpleMusicType indata)
{
	mGenreMusicList.Delete(indata);
}

// 현재 저장되어있는 장르 목록을 출력한다.
// 이후 장르 목록에 있는 음악들에 대한 자세한 정보를 원할 경우 이를 찾아서 출력한다.
void GenreType::DisplayMusicDetailInGenre(SortedLinkedList<MusicType> *list)
{
	SimpleMusicType data;
	SimpleMusicType copy;

	cout << "\n\t현재 목록 : " << endl;

	// list의 모든 데이터를 화면에 출력
	mGenreMusicList.ResetList();
	int length = mGenreMusicList.GetLength();
	for (int i = 0; i < length; i++)
	{
		mGenreMusicList.GetNextItem(data);
		cout << "\n\t" << i + 1 << "번" << endl;
		data.DisplayRecordOnScreen();
		copy = data;
	}

	char Agree;
	cout << "\n\t음악 세부사항을 확인하시겠습니까? (Y/N): ";
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
			cout << "\n\t음악 ID를 입력하세요: ";
			cin >> ID;

			for (int i = 0; i < length; i++)
			{
				mGenreMusicList.GetNextItem(data);
				if (data.GetID() == ID)  // 리스트에 아이디가 있으면
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
							temp.DisplayRecordOnScreen();	//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
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
			if (found == false) // 리스트에 아이디가 없으면 
			{
				cout << "\n\t해당 음악 ID가 없습니다!";
			}
		}
		else if (Agree == 'N')
		{
			condition = false;
		}
		else
		{
			cout << "\n\tY 또는 N을 입력해주세요: ";
			cin >> Agree;
		}
	}
}
