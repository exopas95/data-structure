
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
*	@ brief ���� ���� Ŭ����
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


	//���� ������ �����ε� ����
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
	*	@brief	�������� ���Ѵ�.
	*	@pre	none.
	*	@post	�������� ��������.
	*	@param	inGenre	Music Artist.
	*/
	void SetArtistName(string inArtist)
	{
		m_ArtistName = inArtist;
	}

	/**
	*	@brief  ������ ���� ������ ��´�.
	*	@pre	��������� �������ִ�.
	*	@post	none.
	*	@return	������
	*/
	string GetArtistName()
	{
		return m_ArtistName;
	}

	/**
	*	@brief	set ������ ���� ������ �����Ѵ�.
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
	*	@brief	������ ������ȣ�� �������� ȭ�鿡 ����.
	*	@pre	������ ������ȣ�� �������� ������ �ִ�.
	*	@post	������ ������ȣ�� �������� ��µȴ�.
	*/
	void DisplayArtistOnScreen()
	{
		cout << "\t" << m_ArtistID << "��: " << "\t���� : " << m_ArtistName << endl;
	}

	/**
	*	@brief		�ٹ��� ������ ��������Ʈ�� �ִ´�.
	*	@param[in]	indata	�ٹ� ����
	*/
	void AddAlbumInArtist(AlbumType indata);

	/**
	*	@brief		�ٹ��� ������ ��������Ʈ���� �����Ѵ�.
	*	@param[in]	indata	�ٹ� ����
	*/
	void DeleteAlbumInArtist(AlbumType indata);

	/**
	*	@brief		�ش� �ٹ��� ���� ����� ����Ѵ�.
	*	@param[in]	list	music list.
	*/
	void DisplayAlbumDetailInArtist(SortedLinkedList<MusicType> *list);

	/**
	*	Compare two ArtistTypes.
	*	@brief	Compare two item types by genre id.
	*	@pre	two genre types should be initialized.
	*	@post	the target file is included the new genre record.
	*	@param	data	target genre for comparing.
	*	@return	������ ID�� ������ ID�� ������ true, �ٸ��� false�� ��ȯ�Ѵ�.
	*/
	bool operator == (const ArtistType &obj);

	/**
	*	Compare two ArtistTypes.
	*	@brief	Compare two item types by genre id.
	*	@pre	two genre types should be initialized.
	*	@post	the target file is included the new genre record.
	*	@param	data	target genre for comparing.
	*	@return	������ ID�� ������ ID���� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator > (const ArtistType &obj);

	/**
	*	Compare two ArtistTypes.
	*	@brief	Compare two item types by genre id.
	*	@pre	two genre types should be initialized.
	*	@post	the target file is included the new genre record.
	*	@param	data	target genre for comparing.
	*	@return	�������� ID�� ���� ID���� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator < (const ArtistType &obj);

	/**
	*	Compare two ArtistTypes.
	*	@brief	Compare two item types by genre id.
	*	@pre	two genre types should be initialized.
	*	@post	the target file is included the new genre record.
	*	@param	data	target genre for comparing.
	*	@return ������ ID�� ������ ID���� ũ�ų� ������ true, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator >= (const ArtistType &obj);

	/**
	*	Compare two ArtistTypes.
	*	@brief	Compare two item types by genre id.
	*	@pre	two genre types should be initialized.
	*	@post	the target file is included the new genre record.
	*	@param	data	target genre for comparing.
	*	@return �������� ID�� ���� ID���� ũ�ų� ������ true, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator <= (const ArtistType &obj);

protected:
	int ID;									///< ���� ��ȣ
	int m_ArtistID;							///< ���� ��ȣ
	string m_ArtistName;					///< ���� �̸�
	SortedLinkedList<AlbumType> mAlbumList;	///������ ���� ����Ʈ
};

#endif	// _ARTISTTYPE_H
