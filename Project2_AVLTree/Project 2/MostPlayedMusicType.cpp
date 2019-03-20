#include "MostPlayedMusicType.h"

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)�� ���� ��� true, �ٸ� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool MostPlayedMusicType::operator == (const MostPlayedMusicType &obj)
{
	return (this->Most_Name == obj.Most_Name);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� Ŭ ��� true, �۰ų� ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool MostPlayedMusicType::operator > (const MostPlayedMusicType &obj)
{
	return (Most_Name > obj.Most_Name);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� ���� ��� true, ũ�ų� ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool MostPlayedMusicType::operator < (const MostPlayedMusicType &obj)
{
	return (Most_Name < obj.Most_Name);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� ���� ��� true, ũ�ų� ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool MostPlayedMusicType::operator <= (const MostPlayedMusicType &obj)
{
	return (Most_Number < obj.Most_Number);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� ���� ��� true, ũ�ų� ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool MostPlayedMusicType::operator >= (const MostPlayedMusicType &obj)
{
	return (Most_Number > obj.Most_Number);
}

// �����Ͽ� �ִ� ������ ���ǹ�ȣ�� Ű����� �Է��Ѵ�.
void MostPlayedMusicType::SetIDFromKB()
{
	cout << "\tID : ";
	cin >> Most_ID;
}

// �����Ͽ� �ִ� ������ ���Ǹ��� Ű����� �Է��Ѵ�.
void MostPlayedMusicType::SetNameFromKB()
{
	cout << "\t���� : ";
	getline(cin, Most_Name);
	getline(cin, Most_Name);
}


// �����Ͽ� �ִ� ������ �������� Ű����� �Է��Ѵ�.
void MostPlayedMusicType::SetArtistFromKB()
{
	cout << "\t���� : ";
	cin >> Most_Artist;
}

// �����Ͽ� �ִ� ������ ���Ƚ���� Ű����� �Է��Ѵ�.
void MostPlayedMusicType::SetNumberFromKB()
{
	cout << "\t���Ƚ�� : ";
	cin >> Most_Number;
}

// �����Ͽ� �ִ� ������ ������ Ű����� �Է��Ѵ�.
void MostPlayedMusicType::SetRecordFromKB()
{
	SetNameFromKB();
	SetArtistFromKB();
}

// ��� ������ �����ε� <<
void MostPlayedMusicType::operator<<(MostPlayedMusicType item)
{
	item.DisplayRecordOnScreen();
}
