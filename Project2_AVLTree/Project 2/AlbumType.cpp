#include "AlbumType.h"

// this(저장되어있는값)가 obj(입력하는값)와 같을 경우 true, 다를 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool AlbumType::operator == (const AlbumType &obj)
{
	return (this->ID == obj.ID);
}

// this(저장되어있는값)가 obj(입력하는값)보다 클 경우 true, 작거나 같을 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool AlbumType::operator > (const AlbumType &obj)
{
	return (this->m_gAlbum>obj.m_gAlbum);
}

// this(저장되어있는값)가 obj(입력하는값)보다 작을 경우 true, 크거나 같을 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool AlbumType::operator < (const AlbumType &obj)
{
	return (this->m_gAlbum<obj.m_gAlbum);
}

// this(저장되어있는값)가 obj(입력하는값)보다 크거나 같을 경우 true, 작을 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool AlbumType::operator >= (const AlbumType &obj)
{
	return (this->m_AlbumID >= obj.m_AlbumID);
}

// this(저장되어있는값)가 obj(입력하는값)보다 작거나 같을 경우 true, 클 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool AlbumType::operator <= (const AlbumType &obj)
{
	return (this->m_AlbumID <= obj.m_AlbumID);
}

// Simple Music List에 간단한 음악 정보를 저장한다.
void AlbumType::AddMusicInAlbum(SimpleMusicType indata)
{
	mAlbumMusicList.Add(indata);
}

// Simple Music List에 간단한 음악 정보를 제거한다.
void AlbumType::DeleteMusicInAlbum(SimpleMusicType indata)
{
	mAlbumMusicList.Delete(indata);
}

// 현재 저장되어있는 장르 목록을 출력한다.
// 이후 장르 목록에 있는 곡들에 대한 자세한 정보를 원할 경우 이를 찾아서 출력한다.
AVLTree<SimpleMusicType>* AlbumType::DetailInfo()
{
	return &mAlbumMusicList;
}

