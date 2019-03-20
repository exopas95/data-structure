
#ifndef _MUSICTYPE_H
#define _MUSICTYPE_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;


/**
*	@ brief music information class.
*/
class MusicType
{
public:
	/**
	*	default constructor.
	*/
	MusicType()
	{
		m_mID = 0;
		m_mName = "";
		m_mArtist = "";
		m_mAlbum = "";
		m_mGenre = "";
	}

	/**
	*	destructor.
	*/
	~MusicType(){}



	/**
	*	@brief  ���ȣ�� ������ ��´�.
	*	@pre	���ȣ�� �������ִ�.
	*	@post	none.
	*	@return	���ȣ
	*/
	int GetID()
	{
		return m_mID;
	}

	/**
	*	@brief  ����� ������ ��´�.
	*	@pre	����� �������ִ�.
	*	@post	none.
	*	@return	���
	*/
	string GetName()
	{
		return m_mName;
	}

	/**
	*	@brief  ������ ���� ������ ��´�.
	*	@pre	�������� �������ִ�.
	*	@post	none.
	*	@return	������
	*/
	string GetArtist()
	{
		return m_mArtist;
	}

	/**
	*	@brief  �ٹ��� ���� ������ ��´�.
	*	@pre	�ٹ����� �������ִ�.
	*	@post	none.
	*	@return	�ٹ���
	*/
	string GetAlbum()
	{
		return m_mAlbum;
	}

	/**
	*	@brief  �帣�� ���� ������ ��´�.
	*	@pre	�帣���� �������ִ�.
	*	@post	none.
	*	@return	�帣��
	*/
	string GetGenre()
	{
		return m_mGenre;
	}
	
	/**
	*	@brief	���ȣ�� ���Ѵ�.
	*	@pre	none.
	*	@post	���ȣ�� ��������.
	*	@param	inID	Music ID.
	*/
	void SetID(int inID)
	{
		m_mID = inID;
	}

	/**
	*	@brief	����� ���Ѵ�.
	*	@pre	none.
	*	@post	����� ��������.
	*	@param	inName Music name.
	*/
	void SetName(string inName)
	{
		m_mName = inName;
	}

	/**
	*	@brief	�������� ���Ѵ�.
	*	@pre	none.
	*	@post	�������� ��������.
	*	@param	inArtist Music Artist.
	*/
	void SetArtist(string inArtist)
	{
		m_mArtist = inArtist;
	}
	
	/**
	*	@brief	�ٹ����� ���Ѵ�.
	*	@pre	none.
	*	@post	�ٹ����� ��������.
	*	@param	inAlbum	Music Album.
	*/
	void SetAlbum(string inAlbum)
	{
		m_mAlbum = inAlbum;
	}

	/**
	*	@brief	�帣���� ���Ѵ�.
	*	@pre	none.
	*	@post	�帣���� ��������.
	*	@param	inGenre	Music Genre.
	*/
	void SetGenre(string inGenre)
	{
		m_mGenre = inGenre;
	}
	
	/**
	*	@brief	���縦 ���Ѵ�.
	*	@pre	none.
	*	@post	���簡 ��������.
	*	@param	inLyrics Music lyrics.
	*/
	void SetLyrics(string inLyrics)
	{
		m_mLyrics = inLyrics;
	}

	/**
	*	@brief	���ǿ� ���� ������ �����Ѵ�.
	*	@pre	none.
	*	@post	���ǿ� ���� ������ �����ȴ�.
	*	@param	inID		���ȣ
	*	@param	inName		���
	*	@param	inArtist	������
		@param	inAlbum		�ٹ���
	*	@param	inGenre		�帣��
	*/
	void SetRecord(int inID, string inName, string inArtist, string inAlbum, string inGenre)
	{
		SetID(inID);
		SetName(inName);
		SetArtist(inArtist);
		SetAlbum(inAlbum);
		SetGenre(inGenre);
	}

	/**
	*	@brief	������ ���ȣ�� ȭ�鿡 ����.
	*	@pre	������ ���ȣ�� �������ִ�.
	*	@post	������ ���ȣ�� ��µȴ�.
	*/
	void DisplayIDOnScreen()
	{
		cout << "\tID : " << m_mID << endl;
	};

	/**
	*	@brief	������ ����� ȭ�鿡 ����.
	*	@pre	������ ��� �������ִ�.
	*	@post	������ ����� ��µȴ�.
	*/
	void DisplayNameOnScreen() 
	{
		cout << "\tName : " << m_mName << endl; 
	};

	/**
	*	@brief	������ �������� ȭ�鿡 ����.
	*	@pre	������ �������� �������ִ�.
	*	@post	������ �������� ��µȴ�.
	*/
	void DisplayArtistOnScreen() 
	{
		cout << "\tArtist : " << m_mArtist << endl; 
	};

	/**
	*	@brief	������ �ٹ����� ȭ�鿡 ����.
	*	@pre	������ �ٹ��� �������ִ�.
	*	@post	������ �ٹ��� ��µȴ�.
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "\tAlbum : " << m_mAlbum << endl;
	};

	/**
	*	@brief	������ �帣���� ȭ�鿡 ����.
	*	@pre	������ �帣�� �������ִ�.
	*	@post	������ �帣�� ��µȴ�.
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\tGenre : " << m_mGenre << endl;
	};

	/**
	*	@brief	������ ���縦 ȭ�鿡 ����.
	*	@pre	������ ���簡 �������ִ�.
	*	@post	������ ���簡 ��µȴ�.
	*/
	void DisplayLyricsOnScreen()
	{
		cout << "\tLyrics : " << m_mLyrics << endl;
	};

	/**
	*	@brief	������ ������ ȭ�鿡 ����.
	*	@pre	������ ������ �������ִ�.
	*	@post	������ ������ ��µȴ�.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayIDOnScreen();
		DisplayNameOnScreen();
		DisplayArtistOnScreen();
		DisplayAlbumOnScreen();
		DisplayGenreOnScreen();
		DisplayLyricsOnScreen();
	};

	/**
	*	@brief	������ ��ȣ�� �ڵ����� ���Ѵ�.
	*	@pre	����.
	*	@post	������ ��ȣ�� ��������.
	*/
	void SetIDAuto();

	/**
	*	@brief	������ ��ȣ�� Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	������ ��ȣ�� ��������.
	*/
	void SetIDFromKB();

	/**
	*	@brief	������ ����� Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	������ ����� ��������.
	*/
	void SetNameFromKB();

	/**
	*	@brief	������ ������ Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	������ ������ ��������.
	*/
	void SetArtistFromKB();

	/**
	*	@brief	������ �ٹ��� Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	������ �ٹ��� ��������.
	*/
	void SetAlbumFromKB();

	/**
	*	@brief	������ �帣�� Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	������ �帣�� ��������.
	*/
	void SetGenreFromKB();

	/**
	*	@brief	������ ���縦 Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	������ ���簡 ��������.
	*/
	void SetLyricsFromKB();
	
	/**
	*	@brief	������ ������ Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	������ ������ ��������.
	*/
	void SetRecordFromKB();

	/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	student record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new student record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout);
	
	/**
	*	Compare two Musictypes.
	*	@brief	Compare two Music types by item id.
	*	@pre	two Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	������ ID�� ������ ID�� ������ true, �ٸ��� false�� ��ȯ�Ѵ�.
	*/
	bool operator == (const MusicType &obj);

	/**
	*	Compare two Musictypes.
	*	@brief	Compare two Music types by item id.
	*	@pre	two Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	������ ID�� �����ʺ��� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator > (const MusicType &obj);

	/**
	*	Compare two Musictypes.
	*	@brief	Compare two Music types by item id.
	*	@pre	two Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	�������� ID�� ���ʺ��� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator < (const MusicType &obj);

	/**
	*	Compare two Musictypes.
	*	@brief	Compare two Music types by item id.
	*	@pre	two Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	������ ID�� �����ʺ��� ũ�ų� ������ true, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator >= (const MusicType &obj);

	/**
	*	Compare two Musictypes.
	*	@brief	Compare two Music types by item id.
	*	@pre	two Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	�������� ID�� ���ʺ��� ũ�ų� ������ true, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator <= (const MusicType &obj);


	
protected:

	int m_mID;			///< ���ȣ
	string m_mName;		///< ���
	string m_mArtist;	///< ����
	string m_mAlbum;	///< �ٹ�
	string m_mGenre;	///< �帣
	string m_mLyrics;	///< ����
};

#endif	// _MUSICTYPE_H
