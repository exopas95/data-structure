
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


	//대입 연산자 오버로딩 선언
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
	*	@brief	장르명을 정한다.
	*	@pre	none.
	*	@post	장르명이 정해진다.
	*	@param	inArtist	Music Artist.
	*/
	void SetArtistName(string inArtist)
	{
		m_gArtist = inArtist;
	}

	/**
	*	@brief  장르명에 대한 정보를 얻는다.
	*	@pre	장르명이 정해져있다.
	*	@post	none.
	*	@return	장르명
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
	*	@brief	음악의 장르번호와 장르명을 화면에 띄운다.
	*	@pre	음악의 장르번호와 장르명이 정해져 있다.
	*	@post	음악의 장르번호와 장르명이 출력된다.
	*/
	void DisplayArtistOnScreen()
	{
		cout << "\t" << m_ArtistID << "번: " << "\tArtist : " << m_gArtist << endl;
	}

	/**
	*	@brief	add a music information into this Artist.
	*	@param[in]	indata	music information.
	*/
	void AddMusicInArtist(SimpleMusicType indata);

	/**
	*	@brief		간단한 음악 정보를 장르리스트에서 제거한다.
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
	*	@return	왼쪽의 ID와 오른쪽 ID가 같으면 true, 다르면 false를 반환한다.
	*/
	bool operator == (const ArtistType &obj);

	/**
	*	Compare two Artisttypes.
	*	@brief	Compare two item types by Artist id.
	*	@pre	two Artist types should be initialized.
	*	@post	the target file is included the new Artist record.
	*	@param	data	target Artist for comparing.
	*	@return	왼쪽의 ID가 오른쪽 ID보다 크면 true, 작거나 같으면 false를 반환한다.
	*/
	bool operator > (const ArtistType &obj);

	/**
	*	Compare two Artisttypes.
	*	@brief	Compare two item types by Artist id.
	*	@pre	two Artist types should be initialized.
	*	@post	the target file is included the new Artist record.
	*	@param	data	target Artist for comparing.
	*	@return	오른쪽의 ID가 왼쪽 ID보다 크면 true, 작거나 같으면 false를 반환한다.
	*/
	bool operator < (const ArtistType &obj);

	/**
	*	Compare two Artisttypes.
	*	@brief	Compare two item types by Artist id.
	*	@pre	two Artist types should be initialized.
	*	@post	the target file is included the new Artist record.
	*	@param	data	target Artist for comparing.
	*	@return 왼쪽의 ID가 오른쪽 ID보다 크거나 같으면 true, 작으면 false를 반환한다.
	*/
	bool operator >= (const ArtistType &obj);

	/**
	*	Compare two Artisttypes.
	*	@brief	Compare two item types by Artist id.
	*	@pre	two Artist types should be initialized.
	*	@post	the target file is included the new Artist record.
	*	@param	data	target Artist for comparing.
	*	@return 오른쪽의 ID가 왼쪽 ID보다 크거나 같으면 true, 작으면 false를 반환한다.
	*/
	bool operator <= (const ArtistType &obj);

	// operator overloading
	friend ostream& operator << (ostream& out, ArtistType& Artist)
	{
		out << "\t" << Artist.GetArtistId() << "번 : ";
		out << "\t가수 이름 : " << Artist.GetArtistName() << endl;

		return out;
	}

protected:
	int ID;				///< 음악 번호
	int m_ArtistID;		///< 장르 번호
	string m_gArtist;	///< 장르 이름
	AVLTree<SimpleMusicType> mArtistMusicList;	///간단한 뮤직 리스트
};

#endif	// _ArtistTYPE_H
