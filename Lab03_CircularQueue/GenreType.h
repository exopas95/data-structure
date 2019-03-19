
#ifndef _GENRETYPE_H
#define _GENRETYPE_H

#include <iostream>
#include <fstream>
#include <string>

#include "MusicType.h"
#include "SortedList.h"
#include "SimpleMusicType.h"

using namespace std;


/**
*	item information class.
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

	//void Add(SimpleMusicType& newItem)
	//{
	//	mGenreMusicList.Add(newItem);
	//}


	
	/**
	*	@brief	음악의 곡번호를 화면에 띄운다.
	*	@pre	음악의 곡번호가 정해져있다.
	*	@post	음악의 곡번호가 출력된다.
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
	void DisplayMusicDetailInGenre(SortedList<MusicType> *list);


	bool operator == (const GenreType &obj);

	bool operator > (const GenreType &obj);

	bool operator < (const GenreType &obj);

	bool operator >= (const GenreType &obj);

	bool operator <= (const GenreType &obj);


protected:
	int m_GenreID;
	string m_gGenre;	///< 장르
	SortedList<SimpleMusicType> mGenreMusicList;
};

#endif	// _GENRETYPE_H
