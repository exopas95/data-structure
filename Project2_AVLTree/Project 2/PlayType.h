
#ifndef _PLAYTYPE_H
#define _PLAYTYPE_H

#include <iostream>
#include <fstream>
#include <string>

#include "MasterType.h"
#include "SortedLinkedList.h"

using namespace std;


/**
*	@ brief 재생목록 정보 클래스
*/
class PlayType
{
public:
	/**
	*	default constructor.
	*/
	PlayType()
	{
		playID = -1;
		m_PlayName = "";
		m_PlayArtist = "";
		m_PlayNumber = 0;

	}

	/**
	*	destructor.
	*/
	~PlayType() {}


	//대입 연산자 오버로딩 선언
	PlayType& operator= (const PlayType &obj)
	{
		this->playID = obj.playID;
		this->m_PlayName = obj.m_PlayName;
		this->m_PlayArtist = obj.m_PlayArtist;
		this->m_PlayNumber = obj.m_PlayNumber;
		return *this;
	}

	/**
	*	@brief		음악 번호를 정한다.
	*	@param[in]	inPlayId	Play id.
	*/
	void SetPlayID(int PlayID)
	{
		playID = PlayID;
	}

	/**
	*	@brief	음악 번호를 가져온다.
	*	@return	음악 번호
	*/
	int GetPlayID()
	{
		return playID;
	}

	/**
	*	@brief		재생횟수를 정한다.
	*	@param[in]	inPlayNumber	Play time.
	*/
	void SetPlayNumber(int PlayNumber)
	{
		m_PlayNumber = PlayNumber;
	}

	/**
	*	@brief	재생횟수를 가져온다.
	*	@return	재생횟수.
	*/
	int GetPlayNumber()
	{
		return m_PlayNumber;
	}

	/**
	*	@brief		음악 이름을 정한다.
	*	@param[in]	inPlayName	PlayName.
	*/
	void SetPlayName(string inPlayName)
	{
		m_PlayName = inPlayName;
	}

	/**
	*	@brief	음악 이름을 가져온다.
	*	@return	음악 이름
	*/
	string GetPlayName()
	{
		return m_PlayName;
	}

	/**
	*	@brief	해당 음악의 가수명을 정한다.
	*	@pre	none.
	*	@post	해당 음악의 가수명이 정해진다.
	*	@param	inPlayArtist	Artist.
	*/
	void SetPlayArtist(string inPlayArtist)
	{
		m_PlayArtist = inPlayArtist;
	}

	/**
	*	@brief  가수명에 대한 정보를 얻는다.
	*	@pre	가수명이 정해져있다.
	*	@post	none.
	*	@return	가수명
	*/
	string GetPlayArtist()
	{
		return m_PlayArtist;
	}

	/**
	*	@brief	재생목록 내의 음악들에 대한 정보를 입력한다.
	*	@pre	none.
	*	@post	재생목록 내의 음악들에 대한 정보가 설정된다.
	*	@param	PlayID			음악번호
	*	@param	PlayNumber		재생횟수
	*	@param	PlayLong		재생시간
	*	@param	inPlayName		음악이름
	*	@param	inPlayArtist	가수
	*/
	void SetPlayInfo(int PlayID, string inPlayName, std::string inPlayArtist)
	{
		playID = PlayID;
		m_PlayName = inPlayName;
		m_PlayArtist = inPlayArtist;
	}

	/**
	*	@brief	재생목록에 있는 음악의 정보를 화면에 띄운다.
	*	@pre	재생목록에 있는 음악의 정보가 정해져 있다.
	*	@post	재생목록에 있는 음악의 정보가 출력된다.
	*/
	void DisplayPlayOnScreen()
	{
		cout << "\n\t제목 : " << m_PlayName << endl;
		cout << "\t가수 : " << m_PlayArtist << endl;
	}

	/**
	*	@brief	재생목록에 있는 음악의 음악번호를 키보드로 입력한다.
	*	@pre	없다.
	*	@post	재생목록에 있는 음악의 음악번호가 정해진다.
	*/
	void SetPlayIDFromKB();

	/**
	*	@brief	재생목록에 있는 음악의 재생시간을 키보드로 입력한다.
	*	@pre	없다.
	*	@post	재생목록에 있는 음악의 재생시간이 정해진다.
	*/
	void SetPlayNumberFromKB();

	/**
	*	@brief	재생목록에 있는 음악의 음악명을 키보드로 입력한다.
	*	@pre	없다.
	*	@post	재생목록에 있는 음악의 음악명이 정해진다.
	*/
	void SetPlayNameFromKB();

	/**
	*	@brief	재생목록에 있는 음악의 가수를 키보드로 입력한다.
	*	@pre	없다.
	*	@post	재생목록에 있는 음악의 가수가 정해진다.
	*/
	void SetPlayArtistFromKB();

	/**
	*	@brief	재생목록에 있는 음악의 정보를 키보드로 입력한다.
	*	@pre	없다.
	*	@post	재생목록에 있는 음악의 정보가 정해진다.
	*/
	void SetPlayRecordFromKB();

	/**
	*	Compare two Playtypes.
	*	@brief	Compare two item types by Play id.
	*	@pre	two Play types should be initialized.
	*	@post	the target file is included the new Play record.
	*	@param	data	target Play for comparing.
	*	@return	왼쪽의 ID와 오른쪽 ID가 같으면 true, 다르면 false를 반환한다.
	*/
	bool operator == (const PlayType &obj);

	/**
	*	Compare two Playtypes.
	*	@brief	Compare two item types by Play id.
	*	@pre	two Play types should be initialized.
	*	@post	the target file is included the new Play record.
	*	@param	data	target Play for comparing.
	*	@return	왼쪽의 ID가 오른쪽 ID보다 크면 true, 작거나 같으면 false를 반환한다.
	*/
	bool operator > (const PlayType &obj);

	/**
	*	Compare two Playtypes.
	*	@brief	Compare two item types by Play id.
	*	@pre	two Play types should be initialized.
	*	@post	the target file is included the new Play record.
	*	@param	data	target Play for comparing.
	*	@return	오른쪽의 ID가 왼쪽 ID보다 크면 true, 작거나 같으면 false를 반환한다.
	*/
	bool operator < (const PlayType &obj);

	/**
	*	Compare two Playtypes.
	*	@brief	Compare two item types by Play id.
	*	@pre	two Play types should be initialized.
	*	@post	the target file is included the new Play record.
	*	@param	data	target Play for comparing.
	*	@return 왼쪽의 ID가 오른쪽 ID보다 크거나 같으면 true, 작으면 false를 반환한다.
	*/
	bool operator >= (const PlayType &obj);

	/**
	*	Compare two Playtypes.
	*	@brief	Compare two item types by Play id.
	*	@pre	two Play types should be initialized.
	*	@post	the target file is included the new Play record.
	*	@param	data	target Play for comparing.
	*	@return 오른쪽의 ID가 왼쪽 ID보다 크거나 같으면 true, 작으면 false를 반환한다.
	*/
	bool operator <= (const PlayType &obj);

	/**
	*	Display SimpleMusictypes.
	*	@brief	출력 연산자
	*	@pre	재생횟수, 제목, 가수, 재생시간이 정해져 있다.
	*	@post	재생횟수, 제목, 가수, 재생시간을 출력한다.
	*	@return	out
	*/
	friend ostream &operator<< (ostream& out, const PlayType &obj)
	{
		out << "\t제목 : " << obj.m_PlayName << endl;
		out << "\t가수 : " << obj.m_PlayArtist << endl;
		out << "\n\t재생횟수 : " << obj.m_PlayNumber << endl;
		return out;
	}

protected:
	int playID;				///< 재생목록 음악번호
	string m_PlayName;		///< 재생목록 음악명
	string m_PlayArtist;	///< 재생목록 가수
	int m_PlayNumber;			///< 재생 횟수

};

#endif	// _PlayTYPE_H
