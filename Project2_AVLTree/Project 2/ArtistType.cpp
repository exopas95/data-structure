#include "ArtistType.h"

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)�� ���� ��� true, �ٸ� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool ArtistType::operator == (const ArtistType &obj)
{
	return (this->ID == obj.ID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� Ŭ ��� true, �۰ų� ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool ArtistType::operator > (const ArtistType &obj)
{
	return (this->m_gArtist>obj.m_gArtist);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� ���� ��� true, ũ�ų� ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool ArtistType::operator < (const ArtistType &obj)
{
	return (this->m_gArtist<obj.m_gArtist);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� ũ�ų� ���� ��� true, ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool ArtistType::operator >= (const ArtistType &obj)
{
	return (this->m_ArtistID >= obj.m_ArtistID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� �۰ų� ���� ��� true, Ŭ ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool ArtistType::operator <= (const ArtistType &obj)
{
	return (this->m_ArtistID <= obj.m_ArtistID);
}

// Simple Music List�� ������ ���� ������ �����Ѵ�.
void ArtistType::AddMusicInArtist(SimpleMusicType indata)
{
	mArtistMusicList.Add(indata);
}

// Simple Music List�� ������ ���� ������ �����Ѵ�.
void ArtistType::DeleteMusicInArtist(SimpleMusicType indata)
{
	mArtistMusicList.Delete(indata);
}

// ���� ����Ǿ��ִ� �帣 ����� ����Ѵ�.
// ���� �帣 ��Ͽ� �ִ� ��鿡 ���� �ڼ��� ������ ���� ��� �̸� ã�Ƽ� ����Ѵ�.
AVLTree<SimpleMusicType>* ArtistType::DetailInfo()
{
	return &mArtistMusicList;
}

