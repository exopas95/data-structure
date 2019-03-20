#include "UserType.h"

User::~User(void)
{
}

//회원 ID리턴
string User::getId()
{
	return id;
}

//회원 비밀번호 리턴
string User::getPW()
{
	return password;
}

//회원 비밀번호 리턴
int User::getAdmin()
{
	return admin;
}

//회원 이름 리턴
string User::getName()
{
	return name;
}

//회원 설정
void User::setUser(string Id, string pw, string nick)
{
	id = Id;
	password = pw;
	name = nick;
}

//회원 정보 변경
void User::changeInfo()
{
	cout << "바꿀 비밀번호 : ";
	cin >> password;
	cout << "이름 바꾸기 : ";
	cin >> name;
}

//회원 번호 대소 비교
bool User::operator>(User& cust)
{
	return (this->id > cust.id);
}

//회원 번호 대소 비교
bool User::operator<(User& cust)
{
	return (this->id < cust.id);
}

//회원 번호 일치 여부 검사
bool User::operator==(User& cust)
{
	return (this->id == cust.id);
}

//재생목록에 추가
void User::addTolist(PlayType Prod)
{
	PlayList.Add(Prod);
}

//재생목록 출력
void User::showPlayList()
{
	PlayType dummy;

	PlayList.ResetList();
	for (int i = 0; i < PlayList.GetLength(); i++)
	{
		PlayList.GetNextItem(dummy);
		dummy.DisplayPlayOnScreen();
	}
}