
#ifndef _GENRETYPE_H
#define _GENRETYPE_H

#include <iostream>
#include <fstream>
#include <string>

#include "MusicType.h"
#include "SortedLinkedList.h"
#include "SimpleMusicType.h"

using namespace std;


/**
*	@ brief Genre information class.
*/
class GenreType
{
public:
	/**
	*	default constructor.
	*/
	GenreType()
	{
		m_GenreID = -1;
		m_gGenre = "";
	}

	/**
	*	destructor.
	*/
	~GenreType() {}


	//대입 연산자 오버로딩 선언
	GenreType& operator= (const GenreType &obj)
	{
		this->m_GenreID = obj.m_GenreID;
		this->m_gGenre = obj.m_gGenre;

		return *this;
	}
	/**
	*	@brief	set genre id.
	*	@param[in]	inGenreId	genre id.
	*/
	void GetGenreId(int inGenreId)
	{
		m_GenreID = inGenreId;
	}

	/**
	*	@brief	get genre id.
	*	@return	genre id.
	*/
	int GetGenreId()
	{
		return m_GenreID;
	}

	/**
	*	@brief	장르명을 정한다.
	*	@pre	none.
	*	@post	장르명이 정해진다.
	*	@param	inGenre	Music Genre.
	*/
	void SetGenreName(string inGenre)
	{
		m_gGenre = inGenre;
	}

	/**
	*	@brief  장르명에 대한 정보를 얻는다.
	*	@pre	장르명이 정해져있다.
	*	@post	none.
	*	@return	장르명
	*/
	string GetGenreName()
	{
		return m_gGenre;
	}

	/**
	*	@brief	set genre information.
	*	@param[in]	inGenreId	genre id.
	*	@param[in]	inGenre	genre name.
	*/
	void SetGenreInfo(int inGenreId, std::string inGenre)
	{
		m_GenreID = inGenreId;
		m_gGenre = inGenre;
	}
	
	/**
	*	@brief	음악의 장르번호와 장르명을 화면에 띄운다.
	*	@pre	음악의 장르번호와 장르명이 정해져 있다.
	*	@post	음악의 장르번호와 장르명이 출력된다.
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\t" << m_GenreID << "번: " << "\tGenre : " << m_gGenre << endl;
	}

	/**
	*	@brief	add a music information into this genre.
	*	@param[in]	indata	music information.
	*/
	void AddMusicInGenre(SimpleMusicType indata);

	/**
	*	@brief	Displap all music information in this genre.
	*	@param[in]	list	music list.
	*/
	void DisplayMusicDetailInGenre(SortedLinkedList<MusicType> *list);

	/**
	*	Compare two genretypes.
	*	@brief	Compare two item types by genre id.
	*	@pre	two genre types should be initialized.
	*	@post	the target file is included the new genre record.
	*	@param	data	target genre for comparing.
	*	@return	왼쪽의 ID와 오른쪽 ID가 같으면 true, 다르면 false를 반환한다.
	*/
	bool operator == (const GenreType &obj);

	/**
	*	Compare two genretypes.
	*	@brief	Compare two item types by genre id.
	*	@pre	two genre types should be initialized.
	*	@post	the target file is included the new genre record.
	*	@param	data	target genre for comparing.
	*	@return	왼쪽의 ID가 오른쪽 ID보다 크면 true, 작거나 같으면 false를 반환한다.
	*/
	bool operator > (const GenreType &obj);

	/**
	*	Compare two genretypes.
	*	@brief	Compare two item types by genre id.
	*	@pre	two genre types should be initialized.
	*	@post	the target file is included the new genre record.
	*	@param	data	target genre for comparing.
	*	@return	오른쪽의 ID가 왼쪽 ID보다 크면 true, 작거나 같으면 false를 반환한다.
	*/
	bool operator < (const GenreType &obj);

	/**
	*	Compare two genretypes.
	*	@brief	Compare two item types by genre id.
	*	@pre	two genre types should be initialized.
	*	@post	the target file is included the new genre record.
	*	@param	data	target genre for comparing.
	*	@return 왼쪽의 ID가 오른쪽 ID보다 크거나 같으면 true, 작으면 false를 반환한다.
	*/
	bool operator >= (const GenreType &obj);

	/**
	*	Compare two genretypes.
	*	@brief	Compare two item types by genre id.
	*	@pre	two genre types should be initialized.
	*	@post	the target file is included the new genre record.
	*	@param	data	target genre for comparing.
	*	@return 오른쪽의 ID가 왼쪽 ID보다 크거나 같으면 true, 작으면 false를 반환한다.
	*/
	bool operator <= (const GenreType &obj);

protected:
	int m_GenreID;		///< 장르 번호
	string m_gGenre;	///< 장르 이름
	SortedLinkedList<SimpleMusicType> mGenreMusicList;	///간단한 뮤직 리스트
};

#endif	// _GENRETYPE_H
