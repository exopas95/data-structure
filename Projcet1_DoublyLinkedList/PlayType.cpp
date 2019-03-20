#include "PlayType.h"

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)�� ���� ��� true, �ٸ� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool PlayType::operator == (const PlayType &obj)
{
	return (this->playlong == obj.playlong);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� Ŭ ��� true, �۰ų� ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool PlayType::operator > (const PlayType &obj)
{
	return (playlong < obj.playlong);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� ���� ��� true, ũ�ų� ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool PlayType::operator < (const PlayType &obj)
{
	return (playlong > obj.playlong);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� ũ�ų� ���� ��� true, ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool PlayType::operator >= (const PlayType &obj)
{
	return (this->playlong >= obj.playlong);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� �۰ų� ���� ��� true, Ŭ ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool PlayType::operator <= (const PlayType &obj)
{
	return (this->playlong <= obj.playlong);
}

// �����Ͽ� �ִ� ������ ���ǹ�ȣ�� Ű����� �Է��Ѵ�.
void PlayType::SetPlayIDFromKB()
{
	cout << "\tID : ";
	cin >> playID;
}

// �����Ͽ� �ִ� ������ ���Ǹ��� Ű����� �Է��Ѵ�.
void PlayType::SetPlayNameFromKB()
{
	cout << "\t���� : ";
	getline(cin, m_PlayName);
	getline(cin, m_PlayName);
}


// �����Ͽ� �ִ� ������ �������� Ű����� �Է��Ѵ�.
void PlayType::SetPlayArtistFromKB()
{
	cout << "\t���� : ";
	cin >> m_PlayArtist;
}

// �����Ͽ� �ִ� ������ ���Ƚ���� Ű����� �Է��Ѵ�.
void PlayType::SetPlayTimeFromKB()
{
	cout << "\t���Ƚ�� : ";
	cin >> playtime;
}

// �����Ͽ� �ִ� ������ ����ð��� Ű����� �Է��Ѵ�.
void PlayType::SetPlayLongFromKB()
{
	cout << "\t����ð� : ";
	cin >> playlong;
}

// �����Ͽ� �ִ� ������ ������ Ű����� �Է��Ѵ�.
void PlayType::SetPlayRecordFromKB()
{
	SetPlayNameFromKB();
	SetPlayArtistFromKB();
}