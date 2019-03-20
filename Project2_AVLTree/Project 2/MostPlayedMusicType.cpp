#include "MostPlayedMusicType.h"

// this(저장되어있는값)가 obj(입력하는값)와 같을 경우 true, 다를 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool MostPlayedMusicType::operator == (const MostPlayedMusicType &obj)
{
	return (this->Most_Name == obj.Most_Name);
}

// this(저장되어있는값)가 obj(입력하는값)보다 클 경우 true, 작거나 같을 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool MostPlayedMusicType::operator > (const MostPlayedMusicType &obj)
{
	return (Most_Name > obj.Most_Name);
}

// this(저장되어있는값)가 obj(입력하는값)보다 작을 경우 true, 크거나 같을 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool MostPlayedMusicType::operator < (const MostPlayedMusicType &obj)
{
	return (Most_Name < obj.Most_Name);
}

// this(저장되어있는값)가 obj(입력하는값)보다 작을 경우 true, 크거나 같을 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool MostPlayedMusicType::operator <= (const MostPlayedMusicType &obj)
{
	return (Most_Number < obj.Most_Number);
}

// this(저장되어있는값)가 obj(입력하는값)보다 작을 경우 true, 크거나 같을 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool MostPlayedMusicType::operator >= (const MostPlayedMusicType &obj)
{
	return (Most_Number > obj.Most_Number);
}

// 재생목록에 있는 음악의 음악번호를 키보드로 입력한다.
void MostPlayedMusicType::SetIDFromKB()
{
	cout << "\tID : ";
	cin >> Most_ID;
}

// 재생목록에 있는 음악의 음악명을 키보드로 입력한다.
void MostPlayedMusicType::SetNameFromKB()
{
	cout << "\t제목 : ";
	getline(cin, Most_Name);
	getline(cin, Most_Name);
}


// 재생목록에 있는 음악의 가수명을 키보드로 입력한다.
void MostPlayedMusicType::SetArtistFromKB()
{
	cout << "\t가수 : ";
	cin >> Most_Artist;
}

// 재생목록에 있는 음악의 재생횟수를 키보드로 입력한다.
void MostPlayedMusicType::SetNumberFromKB()
{
	cout << "\t재생횟수 : ";
	cin >> Most_Number;
}

// 재생목록에 있는 음악의 정보를 키보드로 입력한다.
void MostPlayedMusicType::SetRecordFromKB()
{
	SetNameFromKB();
	SetArtistFromKB();
}

// 출력 연산자 오버로딩 <<
void MostPlayedMusicType::operator<<(MostPlayedMusicType item)
{
	item.DisplayRecordOnScreen();
}
