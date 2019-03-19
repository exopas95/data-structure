
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
	*	@brief	�帣���� ���Ѵ�.
	*	@pre	none.
	*	@post	�帣���� ��������.
	*	@param	inGenre	Music Genre.
	*/
	void SetGenreName(string inGenre)
	{
		m_gGenre = inGenre;
	}


	/**
	*	@brief  �帣�� ���� ������ ��´�.
	*	@pre	�帣���� �������ִ�.
	*	@post	none.
	*	@return	�帣��
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
	*	@brief	������ ���ȣ�� ȭ�鿡 ����.
	*	@pre	������ ���ȣ�� �������ִ�.
	*	@post	������ ���ȣ�� ��µȴ�.
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\t" << m_GenreID << "��: " << "\tGenre : " << m_gGenre << endl;
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
	string m_gGenre;	///< �帣
	SortedList<SimpleMusicType> mGenreMusicList;
};

#endif	// _GENRETYPE_H
