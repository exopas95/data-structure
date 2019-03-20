#include "UserType.h"

User::~User(void)
{
}

//ȸ�� ID����
string User::getId()
{
	return id;
}

//ȸ�� ��й�ȣ ����
string User::getPW()
{
	return password;
}

//ȸ�� ��й�ȣ ����
int User::getAdmin()
{
	return admin;
}

//ȸ�� �̸� ����
string User::getName()
{
	return name;
}

//ȸ�� ����
void User::setUser(string Id, string pw, string nick)
{
	id = Id;
	password = pw;
	name = nick;
}

//ȸ�� ���� ����
void User::changeInfo()
{
	cout << "�ٲ� ��й�ȣ : ";
	cin >> password;
	cout << "�̸� �ٲٱ� : ";
	cin >> name;
}

//ȸ�� ��ȣ ��� ��
bool User::operator>(User& cust)
{
	return (this->id > cust.id);
}

//ȸ�� ��ȣ ��� ��
bool User::operator<(User& cust)
{
	return (this->id < cust.id);
}

//ȸ�� ��ȣ ��ġ ���� �˻�
bool User::operator==(User& cust)
{
	return (this->id == cust.id);
}

//�����Ͽ� �߰�
void User::addTolist(PlayType Prod)
{
	PlayList.Add(Prod);
}

//������ ���
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