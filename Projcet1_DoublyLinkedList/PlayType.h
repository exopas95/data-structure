
#ifndef _PLAYTYPE_H
#define _PLAYTYPE_H

#include <iostream>
#include <fstream>
#include <string>

#include "MusicType.h"
#include "SortedLinkedList.h"

using namespace std;


/**
*	@ brief ������ ���� Ŭ����
*/
class PlayType
{
public:
	/**
	*	default constructor.
	*/
	PlayType()
	{
		playlong = -1;
		playID = -1;
		m_PlayName = "";
		m_PlayArtist = "";
		playtime = 0;
		
	}

	/**
	*	destructor.
	*/
	~PlayType() {}


	//���� ������ �����ε� ����
	PlayType& operator= (const PlayType &obj)
	{
		this->playlong = obj.playlong;
		this->playID = obj.playID;
		this->m_PlayName = obj.m_PlayName;
		this->m_PlayArtist = obj.m_PlayArtist;
		this->playtime = obj.playtime;
		return *this;
	}

	/**
	*	@brief		���� ��ȣ�� ���Ѵ�.
	*	@param[in]	inPlayId	Play id.
	*/
	void SetPlayID(int PlayID)
	{
		playID = PlayID;
	}

	/**
	*	@brief	���� ��ȣ�� �����´�.
	*	@return	���� ��ȣ
	*/
	int GetPlayID()
	{
		return playID;
	}

	/**
	*	@brief		���Ƚ���� ���Ѵ�.
	*	@param[in]	inPlayTime	Play time.
	*/
	void SetPlayTime(int PlayTime)
	{
		playtime = PlayTime;
	}

	/**
	*	@brief	���Ƚ���� �����´�.
	*	@return	���Ƚ��.
	*/
	int GetPlayTime()
	{
		return playtime;
	}

	/**
	*	@brief		����ð��� ���Ѵ�.
	*	@param[in]	PlayLong	playlong.
	*/
	void SetPlayLong(int PlayLong)
	{
		playlong = PlayLong;
	}

	/**
	*	@brief	����ð��� �����´�.
	*	@return	����ð�.
	*/
	int GetPlayLong()
	{
		return playlong;
	}

	/**
	*	@brief		���� �̸��� ���Ѵ�.
	*	@param[in]	inPlayName	PlayName.
	*/
	void SetPlayName(string inPlayName)
	{
		m_PlayName = inPlayName;
	}

	/**
	*	@brief	���� �̸��� �����´�.
	*	@return	���� �̸�
	*/
	string GetPlayName()
	{
		return m_PlayName;
	}

	/**
	*	@brief	�ش� ������ �������� ���Ѵ�.
	*	@pre	none.
	*	@post	�ش� ������ �������� ��������.
	*	@param	inPlayArtist	Artist.
	*/
	void SetPlayArtist(string inPlayArtist)
	{
		m_PlayArtist = inPlayArtist;
	}

	/**
	*	@brief  ������ ���� ������ ��´�.
	*	@pre	�������� �������ִ�.
	*	@post	none.
	*	@return	������
	*/
	string GetPlayArtist()
	{
		return m_PlayArtist;
	}

	/**
	*	@brief	������ ���� ���ǵ鿡 ���� ������ �Է��Ѵ�.
	*	@pre	none.
	*	@post	������ ���� ���ǵ鿡 ���� ������ �����ȴ�.
	*	@param	PlayID			���ǹ�ȣ
	*	@param	PlayTime		���Ƚ��
	*	@param	PlayLong		����ð�
	*	@param	inPlayName		�����̸�
	*	@param	inPlayArtist	����
	*/
	void SetPlayInfo(int PlayID, int PlayTime, int PlayLong, string inPlayName, std::string inPlayArtist)
	{
		playID = PlayID;
		playtime = PlayTime;
		playlong = PlayLong;
		m_PlayName = inPlayName;
		m_PlayArtist = inPlayArtist;
	}

	/**
	*	@brief	�����Ͽ� �ִ� ������ ������ ȭ�鿡 ����.
	*	@pre	�����Ͽ� �ִ� ������ ������ ������ �ִ�.
	*	@post	�����Ͽ� �ִ� ������ ������ ��µȴ�.
	*/
	void DisplayPlayOnScreen()
	{
		cout << "\n\t����: " << m_PlayName << '\n'<< "\t���� : " << m_PlayArtist << endl;
		cout << "\t����ð�: " << playlong << endl;
	}

	/**
	*	@brief	�����Ͽ� �ִ� ������ ���ǹ�ȣ�� Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	�����Ͽ� �ִ� ������ ���ǹ�ȣ�� ��������.
	*/
	void SetPlayIDFromKB();

	/**
	*	@brief	�����Ͽ� �ִ� ������ ����ð��� Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	�����Ͽ� �ִ� ������ ����ð��� ��������.
	*/
	void SetPlayTimeFromKB();

	/**
	*	@brief	�����Ͽ� �ִ� ������ ���Ƚ���� Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	�����Ͽ� �ִ� ������ ���Ƚ���� ��������.
	*/
	void SetPlayLongFromKB();

	/**
	*	@brief	�����Ͽ� �ִ� ������ ���Ǹ��� Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	�����Ͽ� �ִ� ������ ���Ǹ��� ��������.
	*/
	void SetPlayNameFromKB();

	/**
	*	@brief	�����Ͽ� �ִ� ������ ������ Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	�����Ͽ� �ִ� ������ ������ ��������.
	*/
	void SetPlayArtistFromKB();

	/**
	*	@brief	�����Ͽ� �ִ� ������ ������ Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	�����Ͽ� �ִ� ������ ������ ��������.
	*/
	void SetPlayRecordFromKB();

	/**
	*	Compare two Playtypes.
	*	@brief	Compare two item types by Play id.
	*	@pre	two Play types should be initialized.
	*	@post	the target file is included the new Play record.
	*	@param	data	target Play for comparing.
	*	@return	������ ID�� ������ ID�� ������ true, �ٸ��� false�� ��ȯ�Ѵ�.
	*/
	bool operator == (const PlayType &obj);

	/**
	*	Compare two Playtypes.
	*	@brief	Compare two item types by Play id.
	*	@pre	two Play types should be initialized.
	*	@post	the target file is included the new Play record.
	*	@param	data	target Play for comparing.
	*	@return	������ ID�� ������ ID���� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator > (const PlayType &obj);

	/**
	*	Compare two Playtypes.
	*	@brief	Compare two item types by Play id.
	*	@pre	two Play types should be initialized.
	*	@post	the target file is included the new Play record.
	*	@param	data	target Play for comparing.
	*	@return	�������� ID�� ���� ID���� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator < (const PlayType &obj);

	/**
	*	Compare two Playtypes.
	*	@brief	Compare two item types by Play id.
	*	@pre	two Play types should be initialized.
	*	@post	the target file is included the new Play record.
	*	@param	data	target Play for comparing.
	*	@return ������ ID�� ������ ID���� ũ�ų� ������ true, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator >= (const PlayType &obj);

	/**
	*	Compare two Playtypes.
	*	@brief	Compare two item types by Play id.
	*	@pre	two Play types should be initialized.
	*	@post	the target file is included the new Play record.
	*	@param	data	target Play for comparing.
	*	@return �������� ID�� ���� ID���� ũ�ų� ������ true, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator <= (const PlayType &obj);

	/**
	*	Display SimpleMusictypes.
	*	@brief	��� ������
	*	@pre	���Ƚ��, ����, ����, ����ð��� ������ �ִ�.
	*	@post	���Ƚ��, ����, ����, ����ð��� ����Ѵ�.
	*	@return	out
	*/
	friend ostream &operator<< (ostream& out, const PlayType &obj)
	{
		out << "\n\t���Ƚ�� : " << obj.playtime <<endl;
		out << "\t���� : " << obj.m_PlayName << "\n" << "\t���� : " << obj.m_PlayArtist;
		out << "\n\t����ð� : " << obj.playlong;
		return out;

	}

protected:
	int playlong;
	int playID;				///< ������ ���ǹ�ȣ
	string m_PlayName;		///< ������ ���Ǹ�
	string m_PlayArtist;	///< ������ ����
	int playtime;			///< ��� Ƚ��
	
};

#endif	// _PlayTYPE_H
