
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
	*	@brief  곡명의 정보를 얻는다.
	*	@pre	곡명이 정해져있다.
	*	@post	none.
	*	@return	곡명
	*/
	string GetName()
	{
		return m_mName;
	}

	/**
	*	@brief  곡명에 대한 정보를 얻는다.
	*	@pre	곡명이 정해져있다.
	*	@post	none.
	*	@return	곡명
	*/
	string GetArtist()
	{
		return m_mArtist;
	}

	/**
	*	@brief  가수명에 대한 정보를 얻는다.
	*	@pre	가수명이 정해져있다.
	*	@post	none.
	*	@return	가수명
	*/
	string GetAlbum()
	{
		return m_mAlbum;
	}

	/**
	*	@brief  장르명에 대한 정보를 얻는다.
	*	@pre	장르명이 정해져있다.
	*	@post	none.
	*	@return	장르명
	*/
	string GetGenre()
	{
		return m_mGenre;
	}

	
	/**
	*	@brief	곡명을 정한다.
	*	@pre	none.
	*	@post	곡명이 정해진다.
	*	@param	inName	Music name.
	*/
	void SetName(string inName)
	{
		m_mName = inName;
	}

	/**
	*	@brief	가수명을 정한다.
	*	@pre	none.
	*	@post	가수명이 정해진다.
	*	@param	inName	Music name.
	*/
	void SetArtist(string inArtist)
	{
		m_mArtist = inArtist;
	}
	
	/**
	*	@brief	앨범명을 정한다.
	*	@pre	none.
	*	@post	앨범명이 정해진다.
	*	@param	inName	Music name.
	*/
	void SetAlbum(string inAlbum)
	{
		m_mAlbum = inAlbum;
	}

	/**
	*	@brief	장르명을 정한다.
	*	@pre	none.
	*	@post	장르명이 정해진다.
	*	@param	inName	Music name.
	*/
	void SetGenre(string inGenre)
	{
		m_mGenre = inGenre;
	}
	
	/**
	*	@brief	가사를 정한다.
	*	@pre	none.
	*	@post	가사가 정해진다.
	*	@param	inName	Music name.
	*/
	void SetLyrics(string inLyrics)
	{
		m_mLyrics = inLyrics;
	}

	/**
	*	@brief	음악에 대한 정보를 설정한다.
	*	@pre	none.
	*	@post	음악에 대한 정보가 설정된다.
	*	@param	inName		곡명
	*	@param	inArtist	가수명
		@param	inAlbum		앨범명
	*	@param	inGenre		장르명
	*/
	void SetRecord(string inName, string inArtist, string inAlbum, string inGenre)
	{
		SetName(inName);
		SetArtist(inArtist);
		SetAlbum(inAlbum);
		SetGenre(inGenre);
	}

	/**
	*	@brief	음악의 곡명을 화면에 띄운다.
	*	@pre	음악의 곡명 정해져있다.
	*	@post	음악의 곡명이 출력된다.
	*/
	void DisplayNameOnScreen() 
	{
		cout << "\tName : " << m_mName << endl; 
	};

	/**
	*	@brief	음악의 가수명을 화면에 띄운다.
	*	@pre	음악의 가수명이 정해져있다.
	*	@post	음악의 가수명이 출력된다.
	*/
	void DisplayArtistOnScreen() 
	{
		cout << "\tArtist : " << m_mArtist << endl; 
	};

	/**
	*	@brief	음악의 앨범명을 화면에 띄운다.
	*	@pre	음악의 앨범이 정해져있다.
	*	@post	음악의 앨범이 출력된다.
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "\tAlbum : " << m_mAlbum << endl;
	};

	/**
	*	@brief	음악의 장르명을 화면에 띄운다.
	*	@pre	음악의 장르가 정해져있다.
	*	@post	음악의 장르가 출력된다.
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\tGenre : " << m_mGenre << endl;
	};

	/**
	*	@brief	음악의 가사를 화면에 띄운다.
	*	@pre	음악의 가사가 정해져있다.
	*	@post	음악의 가사가 출력된다.
	*/
	void DisplayLyricsOnScreen()
	{
		cout << "\tLyrics : " << m_mLyrics << endl;
	};

	/**
	*	@brief	음악의 정보를 화면에 띄운다.
	*	@pre	음악의 정보가 정해져있다.
	*	@post	음악의 정보가 출력된다.
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
	*	@brief	음악의 곡명을 키보드로 입력한다.
	*	@pre	없다.
	*	@post	음악의 곡명이 정해진다.
	*/
	void SetNameFromKB();

	/**
	*	@brief	음악의 가수를 키보드로 입력한다.
	*	@pre	없다.
	*	@post	음악의 가수가 정해진다.
	*/
	void SetArtistFromKB();

	/**
	*	@brief	음악의 앨범을 키보드로 입력한다.
	*	@pre	없다.
	*	@post	음악의 앨범을 정해진다.
	*/
	void SetAlbumFromKB();

	/**
	*	@brief	음악의 장르를 키보드로 입력한다.
	*	@pre	없다.
	*	@post	음악의 장르가 정해진다.
	*/
	void SetGenreFromKB();

	/**
	*	@brief	음악의 가사를 키보드로 입력한다.
	*	@pre	없다.
	*	@post	음악의 가사가 정해진다.
	*/
	void SetLyricsFromKB();
	
	/**
	*	@brief	음악의 정보를 키보드로 입력한다.
	*	@pre	없다.
	*	@post	음악의 정보가 정해진다.
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
	*	두 아이템을 바이너리 서치에서 비교한다.
	*	@brief	곡명을 기준으로 두 아이템을 비교한다.
	*	@pre	두 아이템 타입이 정해져있어야 한다.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.Name < data.Name,
	*			return GREATER if this.Name > data.Name then,
	*			otherwise return EQUAL.
	*/
	RelationType BinaryCompareByName(const MusicType &data);

	/**
	*	두 아이템을 비교한다.
	*	@brief	곡명을 기준으로 두 아이템을 비교한다.
	*	@pre	두 아이템 타입이 정해져있어야 한다.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.Name < data.Name,
	*			return GREATER if this.Name > data.Name then,
	*			otherwise return EQUAL.
	*/
	RelationType CompareByName(const MusicType &data);

protected:

	string m_mName;		///< 곡명
	string m_mArtist;	///< 가수
	string m_mAlbum;	///< 앨범
	string m_mGenre;	///< 장르
	string m_mLyrics;	///< 가사
};

#endif	// _ITEMTYPE_H
