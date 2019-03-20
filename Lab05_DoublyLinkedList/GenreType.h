
#ifndef _GENRETYPE_H
#define _GENRETYPE_H

#include <iostream>
#include <fstream>
#include <string>

#include "BaseClass.h"
#include "MusicType.h"
#include "DoublySortedLinkedList.h"
#include "SimpleMusicType.h"

using namespace std;


/**
*	@ brief Genre information class.
*/
class GenreType : public BaseClass
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


	//���� ������ �����ε� ����
	GenreType& operator= (const GenreType &obj)
	{
		this->ID = obj.ID;
		this->m_GenreID = obj.m_GenreID;
		this->m_gGenre = obj.m_gGenre;
		this->mGenreMusicList = obj.mGenreMusicList;

		return *this;
	}

	/**
	*	@brief	set genre id.
	*	@param[in]	inGenreId	genre id.
	*/
	void SetID(int inId)
	{
		ID = inId;
	}

	/**
	*	@brief	get genre id.
	*	@return	genre id.
	*/
	int GetID()
	{
		return ID;
	}

	/**
	*	@brief	set genre id.
	*	@param[in]	inGenreId	genre id.
	*/
	void SetGenreId(int inGenreId)
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
	*	@brief  �帣���� ���� ������ ��´�.
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
	void SetGenreInfo(int inid, int inGenreId, std::string inGenre)
	{
		ID = inid;
		m_GenreID = inGenreId;
		m_gGenre = inGenre;
	}
	
	/**
	*	@brief	������ �帣��ȣ�� �帣���� ȭ�鿡 ����.
	*	@pre	������ �帣��ȣ�� �帣���� ������ �ִ�.
	*	@post	������ �帣��ȣ�� �帣���� ��µȴ�.
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
	*	@brief		������ ���� ������ �帣����Ʈ���� �����Ѵ�.
	*	@param[in]	indata	music information.
	*/
	void DeleteMusicInGenre(SimpleMusicType indata);

	/**
	*	@brief	Displap all music information in this genre.
	*	@param[in]	list	music list.
	*/
	DoublySortedLinkedList<SimpleMusicType>* B_DetailInfo();

	/**
	*	@brief	Displap all music information in this genre.
	*	@param[in]	list	music list.
	*/
	void C_DetailInfo();

	/**
	*	Compare two genretypes.
	*	@brief	Compare two item types by genre id.
	*	@pre	two genre types should be initialized.
	*	@post	the target file is included the new genre record.
	*	@param	data	target genre for comparing.
	*	@return	������ ID�� ������ ID�� ������ true, �ٸ��� false�� ��ȯ�Ѵ�.
	*/
	bool operator == (const GenreType &obj);

	/**
	*	Compare two genretypes.
	*	@brief	Compare two item types by genre id.
	*	@pre	two genre types should be initialized.
	*	@post	the target file is included the new genre record.
	*	@param	data	target genre for comparing.
	*	@return	������ ID�� ������ ID���� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator > (const GenreType &obj);

	/**
	*	Compare two genretypes.
	*	@brief	Compare two item types by genre id.
	*	@pre	two genre types should be initialized.
	*	@post	the target file is included the new genre record.
	*	@param	data	target genre for comparing.
	*	@return	�������� ID�� ���� ID���� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator < (const GenreType &obj);

	/**
	*	Compare two genretypes.
	*	@brief	Compare two item types by genre id.
	*	@pre	two genre types should be initialized.
	*	@post	the target file is included the new genre record.
	*	@param	data	target genre for comparing.
	*	@return ������ ID�� ������ ID���� ũ�ų� ������ true, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator >= (const GenreType &obj);

	/**
	*	Compare two genretypes.
	*	@brief	Compare two item types by genre id.
	*	@pre	two genre types should be initialized.
	*	@post	the target file is included the new genre record.
	*	@param	data	target genre for comparing.
	*	@return �������� ID�� ���� ID���� ũ�ų� ������ true, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator <= (const GenreType &obj);

protected:
	int ID;				///< ���� ��ȣ
	int m_GenreID;		///< �帣 ��ȣ
	string m_gGenre;	///< �帣 �̸�
	DoublySortedLinkedList<SimpleMusicType> mGenreMusicList;	///������ ���� ����Ʈ
};

#endif	// _GENRETYPE_H