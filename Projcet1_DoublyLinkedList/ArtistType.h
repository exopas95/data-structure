
#ifndef _ARTISTTYPE_H
#define _ARTISTTYPE_H

#include <iostream>
#include <fstream>
#include <string>

#include "MusicType.h"
#include "SortedLinkedList.h"
#include "AlbumType.h"

using namespace std;


/**
*	@ brief 가수 정보 클래스
*/
class ArtistType
{
public:
	/**
	*	default constructor.
	*/
	ArtistType()
	{
		ID = -1;
		m_ArtistID = -1;
		m_ArtistName = "";
	}

	/**
	*	destructor.
	*/
	~ArtistType() {}


	//대입 연산자 오버로딩 선언
	ArtistType& operator= (const ArtistType &obj)
	{
		this->ID = obj.ID;
		this->m_ArtistID = obj.m_ArtistID;
		this->m_ArtistName = obj.m_ArtistName;

		return *this;
	}

	/**
	*	@brief		set music id.
	*	@param[in]	inId	music id.
	*/
	void SetID(int inId)
	{
		ID = inId;
	}

	/**
	*	@brief	get music id.
	*	@return	music id.
	*/
	int GetID()
	{
		return ID;
	}

	/**
	*	@brief		set artist
	*	@param[in]	inArtistId	Aritst id.
	*/
	void SetArtistId(int inArtistId)
	{
		m_ArtistID = inArtistId;
	}

	/**
	*	@brief	get Artist id.
	*	@return	Artist id.
	*/
	int GetArtistId()
	{
		return m_ArtistID;
	}

	/**
	*	@brief	가수명이 정한다.
	*	@pre	none.
	*	@post	가수명이 정해진다.
	*	@param	inGenre	Music Artist.
	*/
	void SetArtistName(string inArtist)
	{
		m_ArtistName = inArtist;
	}

	/**
	*	@brief  가수명에 대한 정보를 얻는다.
	*	@pre	가수명명이 정해져있다.
	*	@post	none.
	*	@return	가수명
	*/
	string GetArtistName()
	{
		return m_ArtistName;
	}

	/**
	*	@brief	set 가수명에 대한 정보를 저장한다.
	*	@param[in]	inArtistId	Artist id.
	*	@param[in]	inAritst	Artist name.
	*/
	void SetArtistInfo(int inId, int inArtistId, std::string inArtist)
	{
		ID = inId;
		m_ArtistID = inArtistId;
		m_ArtistName = inArtist;
	}

	/**
	*	@brief	음악의 가수번호와 가수명을 화면에 띄운다.
	*	@pre	음악의 가수번호와 가수명이 정해져 있다.
	*	@post	음악의 가수번호와 가수명이 출력된다.
	*/
	void DisplayArtistOnScreen()
	{
		cout << "\t" << m_ArtistID << "번: " << "\t가수 : " << m_ArtistName << endl;
	}

	/**
	*	@brief		앨범의 정보를 가수리스트에 넣는다.
	*	@param[in]	indata	앨범 정보
	*/
	void AddAlbumInArtist(AlbumType indata);

	/**
	*	@brief		앨범의 정보를 가수리스트에서 제거한다.
	*	@param[in]	indata	앨범 정보
	*/
	void DeleteAlbumInArtist(AlbumType indata);

	/**
	*	@brief		해당 앨범의 음악 목록을 출력한다.
	*	@param[in]	list	music list.
	*/
	void DisplayAlbumDetailInArtist(SortedLinkedList<MusicType> *list);

	/**
	*	Compare two ArtistTypes.
	*	@brief	Compare two item types by genre id.
	*	@pre	two genre types should be initialized.
	*	@post	the target file is included the new genre record.
	*	@param	data	target genre for comparing.
	*	@return	왼쪽의 ID와 오른쪽 ID가 같으면 true, 다르면 false를 반환한다.
	*/
	bool operator == (const ArtistType &obj);

	/**
	*	Compare two ArtistTypes.
	*	@brief	Compare two item types by genre id.
	*	@pre	two genre types should be initialized.
	*	@post	the target file is included the new genre record.
	*	@param	data	target genre for comparing.
	*	@return	왼쪽의 ID가 오른쪽 ID보다 크면 true, 작거나 같으면 false를 반환한다.
	*/
	bool operator > (const ArtistType &obj);

	/**
	*	Compare two ArtistTypes.
	*	@brief	Compare two item types by genre id.
	*	@pre	two genre types should be initialized.
	*	@post	the target file is included the new genre record.
	*	@param	data	target genre for comparing.
	*	@return	오른쪽의 ID가 왼쪽 ID보다 크면 true, 작거나 같으면 false를 반환한다.
	*/
	bool operator < (const ArtistType &obj);

	/**
	*	Compare two ArtistTypes.
	*	@brief	Compare two item types by genre id.
	*	@pre	two genre types should be initialized.
	*	@post	the target file is included the new genre record.
	*	@param	data	target genre for comparing.
	*	@return 왼쪽의 ID가 오른쪽 ID보다 크거나 같으면 true, 작으면 false를 반환한다.
	*/
	bool operator >= (const ArtistType &obj);

	/**
	*	Compare two ArtistTypes.
	*	@brief	Compare two item types by genre id.
	*	@pre	two genre types should be initialized.
	*	@post	the target file is included the new genre record.
	*	@param	data	target genre for comparing.
	*	@return 오른쪽의 ID가 왼쪽 ID보다 크거나 같으면 true, 작으면 false를 반환한다.
	*/
	bool operator <= (const ArtistType &obj);

protected:
	int ID;									///< 음악 번호
	int m_ArtistID;							///< 가수 번호
	string m_ArtistName;					///< 가수 이름
	SortedLinkedList<AlbumType> mAlbumList;	///간단한 뮤직 리스트
};

#endif	// _ARTISTTYPE_H
