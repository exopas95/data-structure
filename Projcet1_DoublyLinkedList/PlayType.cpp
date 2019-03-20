#include "PlayType.h"

// this(저장되어있는값)가 obj(입력하는값)와 같을 경우 true, 다를 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool PlayType::operator == (const PlayType &obj)
{
	return (this->playlong == obj.playlong);
}

// this(저장되어있는값)가 obj(입력하는값)보다 클 경우 true, 작거나 같을 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool PlayType::operator > (const PlayType &obj)
{
	return (playlong < obj.playlong);
}

// this(저장되어있는값)가 obj(입력하는값)보다 작을 경우 true, 크거나 같을 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool PlayType::operator < (const PlayType &obj)
{
	return (playlong > obj.playlong);
}

// this(저장되어있는값)가 obj(입력하는값)보다 크거나 같을 경우 true, 작을 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool PlayType::operator >= (const PlayType &obj)
{
	return (this->playlong >= obj.playlong);
}

// this(저장되어있는값)가 obj(입력하는값)보다 작거나 같을 경우 true, 클 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool PlayType::operator <= (const PlayType &obj)
{
	return (this->playlong <= obj.playlong);
}

// 재생목록에 있는 음악의 음악번호를 키보드로 입력한다.
void PlayType::SetPlayIDFromKB()
{
	cout << "\tID : ";
	cin >> playID;
}

// 재생목록에 있는 음악의 음악명을 키보드로 입력한다.
void PlayType::SetPlayNameFromKB()
{
	cout << "\t제목 : ";
	getline(cin, m_PlayName);
	getline(cin, m_PlayName);
}


// 재생목록에 있는 음악의 가수명을 키보드로 입력한다.
void PlayType::SetPlayArtistFromKB()
{
	cout << "\t가수 : ";
	cin >> m_PlayArtist;
}

// 재생목록에 있는 음악의 재생횟수를 키보드로 입력한다.
void PlayType::SetPlayTimeFromKB()
{
	cout << "\t재생횟수 : ";
	cin >> playtime;
}

// 재생목록에 있는 음악의 재생시간을 키보드로 입력한다.
void PlayType::SetPlayLongFromKB()
{
	cout << "\t재생시간 : ";
	cin >> playlong;
}

// 재생목록에 있는 음악의 정보를 키보드로 입력한다.
void PlayType::SetPlayRecordFromKB()
{
	SetPlayNameFromKB();
	SetPlayArtistFromKB();
}