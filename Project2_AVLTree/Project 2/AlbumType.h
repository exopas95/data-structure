
#ifndef _AlbumTYPE_H
#define _AlbumTYPE_H

#include <iostream>
#include <fstream>
#include <string>

#include "MasterType.h"
#include "SimpleMusicType.h"
#include "AVLTree.h"

using namespace std;


/**
*	@ brief Album information class.
*/
class AlbumType
{
public:
	/**
	*	default constructor.
	*/
	AlbumType()
	{
		m_AlbumID = 0;
		m_gAlbum = "";
	}

	/**
	*	destructor.
	*/
	~AlbumType() {}


	//대입 연산자 오버로딩 선언
	AlbumType& operator= (const AlbumType &obj)
	{
		this->ID = obj.ID;
		this->m_AlbumID = obj.m_AlbumID;
		this->m_gAlbum = obj.m_gAlbum;
		//this->mAlbumMusicList = obj.mAlbumMusicList;

		return *this;
	}

	/**
	*	@brief	set Album id.
	*	@param[in]	inAlbumId	Album id.
	*/
	void SetID(int inId)
	{
		ID = inId;
	}

	/**
	*	@brief	get Album id.
	*	@return	Album id.
	*/
	int GetID()
	{
		return ID;
	}

	/**
	*	@brief	set Album id.
	*	@param[in]	inAlbumId	Album id.
	*/
	void SetAlbumId(int inAlbumId)
	{
		m_AlbumID = inAlbumId;
	}

	/**
	*	@brief	get Album id.
	*	@return	Album id.
	*/
	int GetAlbumId()
	{
		return m_AlbumID;
	}

	/**
	*	@brief	장르명을 정한다.
	*	@pre	none.
	*	@post	장르명이 정해진다.
	*	@param	inAlbum	Music Album.
	*/
	void SetAlbumName(string inAlbum)
	{
		m_gAlbum = inAlbum;
	}

	/**
	*	@brief  장르명에 대한 정보를 얻는다.
	*	@pre	장르명이 정해져있다.
	*	@post	none.
	*	@return	장르명
	*/
	string GetAlbumName()
	{
		return m_gAlbum;
	}

	/**
	*	@brief	set Album information.
	*	@param[in]	inAlbumId	Album id.
	*	@param[in]	inAlbum	Album name.
	*/
	void SetAlbumInfo(int inid, int inAlbumId, std::string inAlbum)
	{
		ID = inid;
		m_AlbumID = inAlbumId;
		m_gAlbum = inAlbum;
	}

	/**
	*	@brief	음악의 장르번호와 장르명을 화면에 띄운다.
	*	@pre	음악의 장르번호와 장르명이 정해져 있다.
	*	@post	음악의 장르번호와 장르명이 출력된다.
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "\t" << m_AlbumID << "번: " << "\tAlbum : " << m_gAlbum << endl;
	}

	/**
	*	@brief	add a music information into this Album.
	*	@param[in]	indata	music information.
	*/
	void AddMusicInAlbum(SimpleMusicType indata);

	/**
	*	@brief		간단한 음악 정보를 장르리스트에서 제거한다.
	*	@param[in]	indata	music information.
	*/
	void DeleteMusicInAlbum(SimpleMusicType indata);

	/**
	*	@brief	Displap all music information in this Album.
	*	@param[in]	list	music list.
	*/
	AVLTree<SimpleMusicType>* DetailInfo();

	/**
	*	Compare two Albumtypes.
	*	@brief	Compare two item types by Album id.
	*	@pre	two Album types should be initialized.
	*	@post	the target file is included the new Album record.
	*	@param	data	target Album for comparing.
	*	@return	왼쪽의 ID와 오른쪽 ID가 같으면 true, 다르면 false를 반환한다.
	*/
	bool operator == (const AlbumType &obj);

	/**
	*	Compare two Albumtypes.
	*	@brief	Compare two item types by Album id.
	*	@pre	two Album types should be initialized.
	*	@post	the target file is included the new Album record.
	*	@param	data	target Album for comparing.
	*	@return	왼쪽의 ID가 오른쪽 ID보다 크면 true, 작거나 같으면 false를 반환한다.
	*/
	bool operator > (const AlbumType &obj);

	/**
	*	Compare two Albumtypes.
	*	@brief	Compare two item types by Album id.
	*	@pre	two Album types should be initialized.
	*	@post	the target file is included the new Album record.
	*	@param	data	target Album for comparing.
	*	@return	오른쪽의 ID가 왼쪽 ID보다 크면 true, 작거나 같으면 false를 반환한다.
	*/
	bool operator < (const AlbumType &obj);

	/**
	*	Compare two Albumtypes.
	*	@brief	Compare two item types by Album id.
	*	@pre	two Album types should be initialized.
	*	@post	the target file is included the new Album record.
	*	@param	data	target Album for comparing.
	*	@return 왼쪽의 ID가 오른쪽 ID보다 크거나 같으면 true, 작으면 false를 반환한다.
	*/
	bool operator >= (const AlbumType &obj);

	/**
	*	Compare two Albumtypes.
	*	@brief	Compare two item types by Album id.
	*	@pre	two Album types should be initialized.
	*	@post	the target file is included the new Album record.
	*	@param	data	target Album for comparing.
	*	@return 오른쪽의 ID가 왼쪽 ID보다 크거나 같으면 true, 작으면 false를 반환한다.
	*/
	bool operator <= (const AlbumType &obj);

	// operator overloading
	friend ostream& operator << (ostream& out, AlbumType& Album)
	{
		out << "\t" << Album.GetAlbumId() << "번 : ";
		out << "\t앨범 이름 : " << Album.GetAlbumName() << endl;

		return out;
	}

protected:
	int ID;				///< 음악 번호
	int m_AlbumID;		///< 장르 번호
	string m_gAlbum;	///< 장르 이름
	AVLTree<SimpleMusicType> mAlbumMusicList;	///간단한 뮤직 리스트
};

#endif	// _AlbumTYPE_H
