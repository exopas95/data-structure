
#ifndef _ArtistTYPE_H
#define _ArtistTYPE_H

#include <iostream>
#include <fstream>
#include <string>

#include "MasterType.h"
#include "SimpleMusicType.h"
#include "AVLTree.h"

using namespace std;


/**
*	@ brief Artist information class.
*/
class ArtistType
{
public:
	/**
	*	default constructor.
	*/
	ArtistType()
	{
		m_ArtistID = 0;
		m_gArtist = "";
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
		this->m_gArtist = obj.m_gArtist;
		//this->mArtistMusicList = obj.mArtistMusicList;

		return *this;
	}

	/**
	*	@brief	set Artist id.
	*	@param[in]	inArtistId	Artist id.
	*/
	void SetID(int inId)
	{
		ID = inId;
	}

	/**
	*	@brief	get Artist id.
	*	@return	Artist id.
	*/
	int GetID()
	{
		return ID;
	}

	/**
	*	@brief	set Artist id.
	*	@param[in]	inArtistId	Artist id.
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
	*	@brief	�帣���� ���Ѵ�.
	*	@pre	none.
	*	@post	�帣���� ��������.
	*	@param	inArtist	Music Artist.
	*/
	void SetArtistName(string inArtist)
	{
		m_gArtist = inArtist;
	}

	/**
	*	@brief  �帣�� ���� ������ ��´�.
	*	@pre	�帣���� �������ִ�.
	*	@post	none.
	*	@return	�帣��
	*/
	string GetArtistName()
	{
		return m_gArtist;
	}

	/**
	*	@brief	set Artist information.
	*	@param[in]	inArtistId	Artist id.
	*	@param[in]	inArtist	Artist name.
	*/
	void SetArtistInfo(int inid, int inArtistId, std::string inArtist)
	{
		ID = inid;
		m_ArtistID = inArtistId;
		m_gArtist = inArtist;
	}

	/**
	*	@brief	������ �帣��ȣ�� �帣���� ȭ�鿡 ����.
	*	@pre	������ �帣��ȣ�� �帣���� ������ �ִ�.
	*	@post	������ �帣��ȣ�� �帣���� ��µȴ�.
	*/
	void DisplayArtistOnScreen()
	{
		cout << "\t" << m_ArtistID << "��: " << "\tArtist : " << m_gArtist << endl;
	}

	/**
	*	@brief	add a music information into this Artist.
	*	@param[in]	indata	music information.
	*/
	void AddMusicInArtist(SimpleMusicType indata);

	/**
	*	@brief		������ ���� ������ �帣����Ʈ���� �����Ѵ�.
	*	@param[in]	indata	music information.
	*/
	void DeleteMusicInArtist(SimpleMusicType indata);

	/**
	*	@brief	Displap all music information in this Artist.
	*	@param[in]	list	music list.
	*/
	AVLTree<SimpleMusicType>* DetailInfo();

	/**
	*	Compare two Artisttypes.
	*	@brief	Compare two item types by Artist id.
	*	@pre	two Artist types should be initialized.
	*	@post	the target file is included the new Artist record.
	*	@param	data	target Artist for comparing.
	*	@return	������ ID�� ������ ID�� ������ true, �ٸ��� false�� ��ȯ�Ѵ�.
	*/
	bool operator == (const ArtistType &obj);

	/**
	*	Compare two Artisttypes.
	*	@brief	Compare two item types by Artist id.
	*	@pre	two Artist types should be initialized.
	*	@post	the target file is included the new Artist record.
	*	@param	data	target Artist for comparing.
	*	@return	������ ID�� ������ ID���� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator > (const ArtistType &obj);

	/**
	*	Compare two Artisttypes.
	*	@brief	Compare two item types by Artist id.
	*	@pre	two Artist types should be initialized.
	*	@post	the target file is included the new Artist record.
	*	@param	data	target Artist for comparing.
	*	@return	�������� ID�� ���� ID���� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator < (const ArtistType &obj);

	/**
	*	Compare two Artisttypes.
	*	@brief	Compare two item types by Artist id.
	*	@pre	two Artist types should be initialized.
	*	@post	the target file is included the new Artist record.
	*	@param	data	target Artist for comparing.
	*	@return ������ ID�� ������ ID���� ũ�ų� ������ true, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator >= (const ArtistType &obj);

	/**
	*	Compare two Artisttypes.
	*	@brief	Compare two item types by Artist id.
	*	@pre	two Artist types should be initialized.
	*	@post	the target file is included the new Artist record.
	*	@param	data	target Artist for comparing.
	*	@return �������� ID�� ���� ID���� ũ�ų� ������ true, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator <= (const ArtistType &obj);

	// operator overloading
	friend ostream& operator << (ostream& out, ArtistType& Artist)
	{
		out << "\t" << Artist.GetArtistId() << "�� : ";
		out << "\t���� �̸� : " << Artist.GetArtistName() << endl;

		return out;
	}

protected:
	int ID;				///< ���� ��ȣ
	int m_ArtistID;		///< �帣 ��ȣ
	string m_gArtist;	///< �帣 �̸�
	AVLTree<SimpleMusicType> mArtistMusicList;	///������ ���� ����Ʈ
};

#endif	// _ArtistTYPE_H
