//typedef char MasterType;

#ifndef _MasterType_H
#define _MasterType_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;


/**
*	2 아이템 사이의 관계 설정
*/
enum RelationType { LESS, GREATER, EQUAL };


/**
*	아이템 정보 클래스
*/
class MasterType
{
public:
	/**
	*	기본 생성자
	*/
	MasterType()
	{
		m_mID = 0;
		m_mName = "";
		m_mArtist = "";
		m_mAlbum = "";
		m_mGenre = "";
	}

	/**
	*	소멸자.
	*/
	~MasterType() {}

	/**
	*	@brief  곡번호의 정보를 얻는다.
	*	@pre	곡번호가 정해져있다.
	*	@post	none.
	*	@return	곡번호
	*/
	int GetID()
	{
		return m_mID;
	}

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
	*	@brief  가수명에 대한 정보를 얻는다.
	*	@pre	가수명이 정해져있다.
	*	@post	none.
	*	@return	가수명
	*/
	string GetArtist()
	{
		return m_mArtist;
	}

	/**
	*	@brief  앨범명에 대한 정보를 얻는다.
	*	@pre	앨범명이 정해져있다.
	*	@post	none.
	*	@return	앨범명
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
	*	@brief  장르명에 대한 정보를 얻는다.
	*	@pre	장르명이 정해져있다.
	*	@post	none.
	*	@return	장르명
	*/
	string GetLyrics()
	{
		return m_mLyrics;
	}

	/**
	*	@brief	곡번호를 정한다.
	*	@pre	none.
	*	@post	곡번호가 정해진다.
	*	@param	inID	Music ID.
	*/
	void SetID(int inID)
	{
		m_mID = inID;
	}

	/**
	*	@brief	곡명을 정한다.
	*	@pre	none.
	*	@post	곡명이 정해진다.
	*	@param	inName Music name.
	*/
	void SetName(string inName)
	{
		m_mName = inName;
	}

	/**
	*	@brief	가수명을 정한다.
	*	@pre	none.
	*	@post	가수명이 정해진다.
	*	@param	inArtist Music Artist.
	*/
	void SetArtist(string inArtist)
	{
		m_mArtist = inArtist;
	}

	/**
	*	@brief	앨범명을 정한다.
	*	@pre	none.
	*	@post	앨범명이 정해진다.
	*	@param	inAlbum	Music Album.
	*/
	void SetAlbum(string inAlbum)
	{
		m_mAlbum = inAlbum;
	}

	/**
	*	@brief	장르명을 정한다.
	*	@pre	none.
	*	@post	장르명이 정해진다.
	*	@param	inGenre	Music Genre.
	*/
	void SetGenre(string inGenre)
	{
		m_mGenre = inGenre;
	}

	/**
	*	@brief	가사를 정한다.
	*	@pre	none.
	*	@post	가사가 정해진다.
	*	@param	inLyrics Music lyrics.
	*/
	void SetLyrics(string inLyrics)
	{
		m_mLyrics = inLyrics;
	}

	/**
	*	@brief	음악에 대한 정보를 설정한다.
	*	@pre	none.
	*	@post	음악에 대한 정보가 설정된다.
	*	@param	inID		곡번호
	*	@param	inName		곡명
	*	@param	inArtist	가수명
	@param	inAlbum		앨범명
	*	@param	inGenre		장르명
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
	*	@brief	음악의 곡번호를 화면에 띄운다.
	*	@pre	음악의 곡번호가 정해져있다.
	*	@post	음악의 곡번호가 출력된다.
	*/
	void DisplayIDOnScreen()
	{
		cout << "\t곡 고유번호 : " << m_mID << endl;
	};

	/**
	*	@brief	음악의 곡번호를 화면에 띄운다.
	*	@pre	음악의 곡번호가 정해져있다.
	*	@post	음악의 곡번호가 출력된다.
	*/
	void DisplayNumberOnScreen()
	{
		cout << "\t 재생횟수 : " << m_mID << endl;
	};

	/**
	*	@brief	음악의 곡명을 화면에 띄운다.
	*	@pre	음악의 곡명 정해져있다.
	*	@post	음악의 곡명이 출력된다.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\t곡 명 : " << m_mName << endl;
	};

	/**
	*	@brief	음악의 가수명을 화면에 띄운다.
	*	@pre	음악의 가수명이 정해져있다.
	*	@post	음악의 가수명이 출력된다.
	*/
	void DisplayArtistOnScreen()
	{
		cout << "\t가수명 : " << m_mArtist << endl;
	};

	/**
	*	@brief	음악의 앨범명을 화면에 띄운다.
	*	@pre	음악의 앨범이 정해져있다.
	*	@post	음악의 앨범이 출력된다.
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "\t앨범명 : " << m_mAlbum << endl;
	};

	/**
	*	@brief	음악의 장르명을 화면에 띄운다.
	*	@pre	음악의 장르가 정해져있다.
	*	@post	음악의 장르가 출력된다.
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\t장르명 : " << m_mGenre << endl;
	};

	/**
	*	@brief	음악의 가사를 화면에 띄운다.
	*	@pre	음악의 가사가 정해져있다.
	*	@post	음악의 가사가 출력된다.
	*/
	void DisplayLyricsOnScreen()
	{
		cout << "\t가사 : " << m_mLyrics << endl;
	};

	/**
	*	@brief	음악의 정보를 화면에 띄운다.
	*	@pre	음악의 정보가 정해져있다.
	*	@post	음악의 정보가 출력된다.
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
	*	@brief	음악의 번호를 자동으로 정한다.
	*	@pre	없다.
	*	@post	음악의 번호가 정해진다.
	*/
	void SetIDAuto();

	/**
	*	@brief	음악의 번호를 키보드로 입력한다.
	*	@pre	없다.
	*	@post	음악의 번호가 정해진다.
	*/
	void SetIDFromKB();

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
	*	두 아이템타입을 비교한다
	*	@brief	music ID로 두 아이템타입을 비교한다
	*	@pre	두 아이템타입이 초기화되어야한다
	*	@post	타겟 파일이 새 학생 정보를 포함함
	*	@param	data	target music for comparing.
	*	@return	현재ID가 DATA의 ID보다 작을 경우 LESS를 리턴,
	*			현재ID가 DATA의 ID보다 클 경우 GREATER를 리턴,
	*			아니면 EQUAL을 리턴
	*/
	RelationType ComparedTo(const MasterType &data);


	// operator overloading
	bool operator == (const MasterType& music)
	{
		return (this->m_mName == music.m_mName);
	}

	// operator overloading
	bool operator > (const MasterType& music)
	{
		return (this->m_mName > music.m_mName);
	}

	// operator overloading
	bool operator < (const MasterType& music)
	{
		return (this->m_mName < music.m_mName);
	}

	// operator overloading
	friend ostream& operator << (ostream& out, MasterType& music)
	{
		//out << "\tID : " << music.GetID() << endl;
		out << "\t음악 :" << music.GetName() << endl;
		out << "\t가수 :" << music.GetArtist() << endl;
		out << "\t앨범 :" << music.GetAlbum() << endl;
		out << "\t장르 :" << music.GetGenre() << endl;
		out << "\t가사 :" << music.GetLyrics() << endl;
		out << endl;

		return out;
	}

protected:
	int m_mID;			///< 곡번호
	string m_mName;		///< 곡명
	string m_mArtist;	///< 가수
	string m_mAlbum;	///< 앨범
	string m_mGenre;	///< 장르
	string m_mLyrics;	///< 가사
};

#endif	// _MasterType_H
