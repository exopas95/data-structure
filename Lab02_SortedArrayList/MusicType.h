
#ifndef _MUSICTYPE_H
#define _MUSICTYPE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/**
*	Relation between two items.
*/
enum RelationType {LESS, GREATER, EQUAL};


/**
*	item information class.
*/
class MusicType
{
public:
	/**
	*	default constructor.
	*/
	MusicType()
	{
		m_mName = "";
		m_mArtist = "";
		m_mAlbum = "";
		m_mGenre = "";
	}

	/**
	*	destructor.
	*/
	~MusicType()	{}


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
	*	@brief  ��� ���� ������ ��´�.
	*	@pre	����� �������ִ�.
	*	@post	none.
	*	@return	���
	*/
	string GetArtist()
	{
		return m_mArtist;
	}

	/**
	*	@brief  ������ ���� ������ ��´�.
	*	@pre	�������� �������ִ�.
	*	@post	none.
	*	@return	������
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
	*	@brief	����� ���Ѵ�.
	*	@pre	none.
	*	@post	����� ��������.
	*	@param	inName	Music name.
	*/
	void SetName(string inName)
	{
		m_mName = inName;
	}

	/**
	*	@brief	�������� ���Ѵ�.
	*	@pre	none.
	*	@post	�������� ��������.
	*	@param	inName	Music name.
	*/
	void SetArtist(string inArtist)
	{
		m_mArtist = inArtist;
	}
	
	/**
	*	@brief	�ٹ����� ���Ѵ�.
	*	@pre	none.
	*	@post	�ٹ����� ��������.
	*	@param	inName	Music name.
	*/
	void SetAlbum(string inAlbum)
	{
		m_mAlbum = inAlbum;
	}

	/**
	*	@brief	�帣���� ���Ѵ�.
	*	@pre	none.
	*	@post	�帣���� ��������.
	*	@param	inName	Music name.
	*/
	void SetGenre(string inGenre)
	{
		m_mGenre = inGenre;
	}
	
	/**
	*	@brief	���縦 ���Ѵ�.
	*	@pre	none.
	*	@post	���簡 ��������.
	*	@param	inName	Music name.
	*/
	void SetLyrics(string inLyrics)
	{
		m_mLyrics = inLyrics;
	}

	/**
	*	@brief	���ǿ� ���� ������ �����Ѵ�.
	*	@pre	none.
	*	@post	���ǿ� ���� ������ �����ȴ�.
	*	@param	inName		���
	*	@param	inArtist	������
		@param	inAlbum		�ٹ���
	*	@param	inGenre		�帣��
	*/
	void SetRecord(string inName, string inArtist, string inAlbum, string inGenre)
	{
		SetName(inName);
		SetArtist(inArtist);
		SetAlbum(inAlbum);
		SetGenre(inGenre);
	}

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
		DisplayNameOnScreen();
		DisplayArtistOnScreen();
		DisplayAlbumOnScreen();
		DisplayGenreOnScreen();
		DisplayLyricsOnScreen();
	};

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
	*	�� �������� ���̳ʸ� ��ġ���� ���Ѵ�.
	*	@brief	����� �������� �� �������� ���Ѵ�.
	*	@pre	�� ������ Ÿ���� �������־�� �Ѵ�.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.Name < data.Name,
	*			return GREATER if this.Name > data.Name then,
	*			otherwise return EQUAL.
	*/
	RelationType BinaryCompareByName(const MusicType &data);

	/**
	*	�� �������� ���Ѵ�.
	*	@brief	����� �������� �� �������� ���Ѵ�.
	*	@pre	�� ������ Ÿ���� �������־�� �Ѵ�.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.Name < data.Name,
	*			return GREATER if this.Name > data.Name then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByName(const MusicType &data);

protected:

	string m_mName;		///< ���
	string m_mArtist;	///< ����
	string m_mAlbum;	///< �ٹ�
	string m_mGenre;	///< �帣
	string m_mLyrics;	///< ����
};

#endif	// _ITEMTYPE_H
