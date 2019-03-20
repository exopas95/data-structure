#include "AlbumType.h"

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)�� ���� ��� true, �ٸ� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool AlbumType::operator == (const AlbumType &obj)
{
	return (this->ID == obj.ID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� Ŭ ��� true, �۰ų� ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool AlbumType::operator > (const AlbumType &obj)
{
	return (this->m_gAlbum>obj.m_gAlbum);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� ���� ��� true, ũ�ų� ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool AlbumType::operator < (const AlbumType &obj)
{
	return (this->m_gAlbum<obj.m_gAlbum);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� ũ�ų� ���� ��� true, ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool AlbumType::operator >= (const AlbumType &obj)
{
	return (this->m_AlbumID >= obj.m_AlbumID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� �۰ų� ���� ��� true, Ŭ ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool AlbumType::operator <= (const AlbumType &obj)
{
	return (this->m_AlbumID <= obj.m_AlbumID);
}

// Simple Music List�� ������ ���� ������ �����Ѵ�.
void AlbumType::AddMusicInAlbum(SimpleMusicType indata)
{
	mAlbumMusicList.Add(indata);
}

// Simple Music List�� ������ ���� ������ �����Ѵ�.
void AlbumType::DeleteMusicInAlbum(SimpleMusicType indata)
{
	mAlbumMusicList.Delete(indata);
}

// ���� ����Ǿ��ִ� �帣 ����� ����Ѵ�.
// ���� �帣 ��Ͽ� �ִ� ��鿡 ���� �ڼ��� ������ ���� ��� �̸� ã�Ƽ� ����Ѵ�.
AVLTree<SimpleMusicType>* AlbumType::DetailInfo()
{
	return &mAlbumMusicList;
}

