#include "GenreType.h"

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)�� ���� ��� true, �ٸ� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool GenreType::operator == (const GenreType &obj)
{
	return (this->ID ==obj.ID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� Ŭ ��� true, �۰ų� ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool GenreType::operator > (const GenreType &obj)
{
	return (this->m_gGenre>obj.m_gGenre);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� ���� ��� true, ũ�ų� ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool GenreType::operator < (const GenreType &obj)
{
	return (this->m_gGenre<obj.m_gGenre);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� ũ�ų� ���� ��� true, ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool GenreType::operator >= (const GenreType &obj)
{
	return (this->ID>obj.ID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� �۰ų� ���� ��� true, Ŭ ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool GenreType::operator <= (const GenreType &obj)
{
	return (this->ID<obj.ID);
}

// Simple Music List�� ������ ���� ������ �����Ѵ�.
void GenreType::AddMusicInGenre(SimpleMusicType& indata)
{
	mGenreMusicList.Add(indata);
}

// Simple Music List�� ������ ���� ������ �����Ѵ�.
void GenreType::DeleteMusicInGenre(SimpleMusicType& indata)
{
	mGenreMusicList.Delete(indata);
}

// ���� ����Ǿ��ִ� �帣 ����� ����Ѵ�.
// ���� �帣 ��Ͽ� �ִ� ��鿡 ���� �ڼ��� ������ ���� ��� �̸� ã�Ƽ� ����Ѵ�.
AVLTree<SimpleMusicType>* GenreType::DetailInfo()
{
	return &mGenreMusicList;
}

