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
// 이후 장르 목록에 있는 곡들에 대한 자세한 정보를 원할 경우 이를 찾아서 출력한다.
DoublySortedLinkedList<SimpleMusicType>* GenreType::B_DetailInfo()
{
	return &mGenreMusicList;
}

// 현재 저장되어있는 장르 목록을 출력한다.
// 이후 장르 목록에 있는 곡들에 대한 자세한 정보를 원할 경우 이를 찾아서 출력한다.
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
	cout << "\n\t음악 세부사항을 확인하시겠습니까? (Y/N): ";
	cin >> Agree;
	if (Agree == 'Y')
	{
		int ID;
		cout << "\n\t음악 ID를 입력하세요: ";
		cin >> ID;

		MusicType *m_data;
		MusicType musicData;
		musicData.SetID(ID);
		m_data = m_List.Get(musicData);
		cout << "\n\t<과제 C>\n";
		m_data->DisplayRecordOnScreen();

	}
	else
		cout << "\n\t해당 음악 ID가 없습니다!";

}