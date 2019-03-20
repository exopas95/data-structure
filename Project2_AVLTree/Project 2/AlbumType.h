
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


	//���� ������ �����ε� ����
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
	*	@brief	�帣���� ���Ѵ�.
	*	@pre	none.
	*	@post	�帣���� ��������.
	*	@param	inAlbum	Music Album.
	*/
	void SetAlbumName(string inAlbum)
	{
		m_gAlbum = inAlbum;
	}

	/**
	*	@brief  �帣�� ���� ������ ��´�.
	*	@pre	�帣���� �������ִ�.
	*	@post	none.
	*	@return	�帣��
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
	*	@brief	������ �帣��ȣ�� �帣���� ȭ�鿡 ����.
	*	@pre	������ �帣��ȣ�� �帣���� ������ �ִ�.
	*	@post	������ �帣��ȣ�� �帣���� ��µȴ�.
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "\t" << m_AlbumID << "��: " << "\tAlbum : " << m_gAlbum << endl;
	}

	/**
	*	@brief	add a music information into this Album.
	*	@param[in]	indata	music information.
	*/
	void AddMusicInAlbum(SimpleMusicType indata);

	/**
	*	@brief		������ ���� ������ �帣����Ʈ���� �����Ѵ�.
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
	*	@return	������ ID�� ������ ID�� ������ true, �ٸ��� false�� ��ȯ�Ѵ�.
	*/
	bool operator == (const AlbumType &obj);

	/**
	*	Compare two Albumtypes.
	*	@brief	Compare two item types by Album id.
	*	@pre	two Album types should be initialized.
	*	@post	the target file is included the new Album record.
	*	@param	data	target Album for comparing.
	*	@return	������ ID�� ������ ID���� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator > (const AlbumType &obj);

	/**
	*	Compare two Albumtypes.
	*	@brief	Compare two item types by Album id.
	*	@pre	two Album types should be initialized.
	*	@post	the target file is included the new Album record.
	*	@param	data	target Album for comparing.
	*	@return	�������� ID�� ���� ID���� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator < (const AlbumType &obj);

	/**
	*	Compare two Albumtypes.
	*	@brief	Compare two item types by Album id.
	*	@pre	two Album types should be initialized.
	*	@post	the target file is included the new Album record.
	*	@param	data	target Album for comparing.
	*	@return ������ ID�� ������ ID���� ũ�ų� ������ true, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator >= (const AlbumType &obj);

	/**
	*	Compare two Albumtypes.
	*	@brief	Compare two item types by Album id.
	*	@pre	two Album types should be initialized.
	*	@post	the target file is included the new Album record.
	*	@param	data	target Album for comparing.
	*	@return �������� ID�� ���� ID���� ũ�ų� ������ true, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator <= (const AlbumType &obj);

	// operator overloading
	friend ostream& operator << (ostream& out, AlbumType& Album)
	{
		out << "\t" << Album.GetAlbumId() << "�� : ";
		out << "\t�ٹ� �̸� : " << Album.GetAlbumName() << endl;

		return out;
	}

protected:
	int ID;				///< ���� ��ȣ
	int m_AlbumID;		///< �帣 ��ȣ
	string m_gAlbum;	///< �帣 �̸�
	AVLTree<SimpleMusicType> mAlbumMusicList;	///������ ���� ����Ʈ
};

#endif	// _AlbumTYPE_H
