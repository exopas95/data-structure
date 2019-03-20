
#ifndef _MUSICTYPE_H
#define _MUSICTYPE_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>


using namespace std;


/**
*	@ brief 음악 정보 클래스
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
		m_mNumber = 0;
		m_mLong = -1;
		m_mCompany = " ";
		m_mMade = " ";
	}

	/**
	*	destructor.
	*/
	~MusicType(){}



	/**
	*	@brief  음악번호의 정보를 얻는다.
	*	@pre	음악번호가 정해져있다.
	*	@post	none.
	*	@return	음악번호
	*/
	int GetID()
	{
		return m_mID;
	}

	/**
	*	@brief  음악명의 정보를 얻는다.
	*	@pre	음악명이 정해져있다.
	*	@post	none.
	*	@return	음악명
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
	*	@brief  소속사에 대한 정보를 얻는다.
	*	@pre	소속사가 정해져있다.
	*	@post	none.
	*	@return	소속사명
	*/
	string GetCompany()
	{
		return m_mCompany;
	}

	/**
	*	@brief  발표연월일에 대한 정보를 얻는다.
	*	@pre	발표연월일이 정해져있다.
	*	@post	none.
	*	@return	발표연월일
	*/
	string GetMade()
	{
		return m_mMade;
	}

	/**
	*	@brief  재생시간에 대한 정보를 얻는다.
	*	@pre	재생시간이 정해져있다.
	*	@post	none.
	*	@return	재생시간
	*/
	int GetLong()
	{
		return m_mLong;
	}

	/**
	*	@brief  재생횟수에 대한 정보를 얻는다.
	*	@pre	재생횟수가 정해져있다.
	*	@post	none.
	*	@return	재생횟수
	*/
	int GetNumber()
	{
		return m_mNumber;
	}

	/**
	*	@brief  악보에 대한 정보를 얻는다.
	*	@pre	악보가 정해져있다.
	*	@post	none.
	*	@return	악보
	*/
	string GetNote()
	{
		return m_mNote;
	}

	/**
	*	@brief	음악번호를 정한다.
	*	@pre	none.
	*	@post	음악번호가 정해진다.
	*	@param	inID	Music ID.
	*/
	void SetID(int inID)
	{
		m_mID = inID;
	}

	/**
	*	@brief	음악명을 정한다.
	*	@pre	none.
	*	@post	음악명이 정해진다.
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
	*	@brief	음악번호를 정한다.
	*	@pre	none.
	*	@post	음악번호가 정해진다.
	*	@param	inID	Music ID.
	*/
	void SetCompany(string inCompany)
	{
		m_mCompany = inCompany;
	}

	/**
	*	@brief	음악번호를 정한다.
	*	@pre	none.
	*	@post	음악번호가 정해진다.
	*	@param	inID	Music ID.
	*/
	void SetMade(string inMade)
	{
		m_mMade = inMade;
	}

	/**
	*	@brief	음악번호를 정한다.
	*	@pre	none.
	*	@post	음악번호가 정해진다.
	*	@param	inID	Music ID.
	*/
	void SetLong(int inLong)
	{
		m_mLong = inLong;
	}

	/**
	*	@brief	음악번호를 정한다.
	*	@pre	none.
	*	@post	음악번호가 정해진다.
	*	@param	inID	Music ID.
	*/
	void SetNumber(int inNumber)
	{
		m_mNumber = inNumber;
	}

	/**
	*	@brief	음악명을 정한다.
	*	@pre	none.
	*	@post	음악명이 정해진다.
	*	@param	inName Music name.
	*/
	void SetNote(string inNote)
	{
		m_mNote = inNote;
	}

	/**
	*	@brief	음악에 대한 정보를 설정한다.
	*	@pre	none.
	*	@post	음악에 대한 정보가 설정된다.
	*	@param	inID		음악번호
	*	@param	inName		음악명
	*	@param	inArtist	가수명
	*	@param	inCompany	소속사명
	*	@param	inMade		발표연월일
	*	@param	inLong		재생시간
		@param	inAlbum		앨범명
	*	@param	inGenre		장르명
	*	@param	inNote		악보
	*/
	void SetRecord(int inID, string inName, string inArtist, string inCompany, string inMade, int inLong, string inAlbum, string inGenre, string inNote, string inLyrics, int inNumber)
	{
		SetID(inID);
		SetName(inName);
		SetArtist(inArtist);
		SetCompany(inCompany);
		SetAlbum(inAlbum);
		SetGenre(inGenre);
		SetNumber(inNumber);
	}

	/**
	*	@brief	음악의 음악번호를 화면에 띄운다.
	*	@pre	음악의 음악번호가 정해져있다.
	*	@post	음악의 음악번호가 출력된다.
	*/
	void DisplayIDOnScreen()
	{
		cout << "\tID : " << m_mID << endl;
	};

	/**
	*	@brief	음악의 음악명을 화면에 띄운다.
	*	@pre	음악의 음악명 정해져있다.
	*	@post	음악의 음악명이 출력된다.
	*/
	void DisplayNameOnScreen() 
	{
		cout << "\t제목 : " << m_mName << endl; 
	};

	/**
	*	@brief	음악의 가수명을 화면에 띄운다.
	*	@pre	음악의 가수명이 정해져있다.
	*	@post	음악의 가수명이 출력된다.
	*/
	void DisplayArtistOnScreen() 
	{
		cout << "\t가수 : " << m_mArtist << endl; 
	};

	/**
	*	@brief	음악의 앨범명을 화면에 띄운다.
	*	@pre	음악의 앨범이 정해져있다.
	*	@post	음악의 앨범이 출력된다.
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "\t앨범 : " << m_mAlbum << endl;
	};

	/**
	*	@brief	음악의 장르명을 화면에 띄운다.
	*	@pre	음악의 장르가 정해져있다.
	*	@post	음악의 장르가 출력된다.
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\t장르 : " << m_mGenre << endl;
	};

	/**
	*	@brief	음악의 가사를 화면에 띄운다.
	*	@pre	음악의 가사가 정해져있다.
	*	@post	음악의 가사가 출력된다.
	*/
	void DisplayLyricsOnScreen()
	{
		string temp;
		int rep = 0;
		cout << "\t가사 : " << m_mLyrics << endl;
	};

	/**
	*	@brief	음악의 가사를 화면에 띄운다.
	*	@pre	음악의 가사가 정해져있다.
	*	@post	음악의 가사가 출력된다.
	*/
	void DisplayCompanyOnScreen()
	{
		cout << "\t소속사 : " << m_mCompany << endl;
	};

	/**
	*	@brief	음악의 가사를 화면에 띄운다.
	*	@pre	음악의 가사가 정해져있다.
	*	@post	음악의 가사가 출력된다.
	*/
	void DisplayMadeOnScreen()
	{
		cout << "\t발표연월일 : " << m_mMade << endl;
	};

	/**
	*	@brief	음악의 가사를 화면에 띄운다.
	*	@pre	음악의 가사가 정해져있다.
	*	@post	음악의 가사가 출력된다.
	*/
	void DisplayLongsOnScreen()
	{
		cout << "\t재생시간 : " << m_mLong << endl;
	};

	/**
	*	@brief	음악의 가사를 화면에 띄운다.
	*	@pre	음악의 가사가 정해져있다.
	*	@post	음악의 가사가 출력된다.
	*/
	void DisplayNoteOnScreen()
	{
		cout << "\t악보 : " << m_mNote << endl;
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
		DisplayCompanyOnScreen();
		DisplayAlbumOnScreen();
		DisplayGenreOnScreen();
		DisplayMadeOnScreen();
		DisplayLongsOnScreen();
		DisplayNoteOnScreen();
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
	*	@brief	음악의 음악명을 키보드로 입력한다.
	*	@pre	없다.
	*	@post	음악의 음악명이 정해진다.
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
	*	@brief	음악의 악보를 키보드로 입력한다.
	*	@pre	없다.
	*	@post	음악의 악보가 정해진다.
	*/
	void SetNoteFromKB();

	/**
	*	@brief	가수의 소속사를 키보드로 입력한다.
	*	@pre	없다.
	*	@post	가수의 소속사가 정해진다.
	*/
	void SetCompanyFromKB();

	/**
	*	@brief	음악의 발표년월일을 키보드로 입력한다.
	*	@pre	없다.
	*	@post	음악의 발표년월일이 정해진다.
	*/
	void SetMadeFromKB();

	/**
	*	@brief	음악의 재생시간을 키보드로 입력한다.
	*	@pre	없다.
	*	@post	음악의 재생시간이 정해진다.
	*/
	void SetLongFromKB();

	/**
	*	@brief	음악의 재생횟수를 키보드로 입력한다.
	*	@pre	없다.
	*	@post	음악의 재생횟수가 정해진다.
	*/
	void SetNumberFromKB();
	
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
	*	Compare two Musictypes.
	*	@brief	Compare two Music types by item id.
	*	@pre	two Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	왼쪽의 ID와 오른쪽 ID가 같으면 true, 다르면 false를 반환한다.
	*/
	bool operator == (const MusicType &obj);

	/**
	*	Compare two Musictypes.
	*	@brief	Compare two Music types by item id.
	*	@pre	two Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	왼쪽의 ID가 오른쪽보다 크면 true, 작거나 같으면 false를 반환한다.
	*/
	bool operator > (const MusicType &obj);

	/**
	*	Compare two Musictypes.
	*	@brief	Compare two Music types by item id.
	*	@pre	two Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	오른쪽의 ID가 왼쪽보다 크면 true, 작거나 같으면 false를 반환한다.
	*/
	bool operator < (const MusicType &obj);

	/**
	*	Compare two Musictypes.
	*	@brief	Compare two Music types by item id.
	*	@pre	two Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	왼쪽의 ID가 오른쪽보다 크거나 같으면 true, 작으면 false를 반환한다.
	*/
	bool operator >= (const MusicType &obj);

	/**
	*	Compare two Musictypes.
	*	@brief	Compare two Music types by item id.
	*	@pre	two Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	오른쪽의 ID가 왼쪽보다 크거나 같으면 true, 작으면 false를 반환한다.
	*/
	bool operator <= (const MusicType &obj);


	
protected:

	int m_mID;			///< 음악번호
	string m_mName;		///< 음악명
	string m_mArtist;	///< 가수
	string m_mCompany;	///< 소속사
	string m_mMade;		///< 발표연월일
	string m_mAlbum;	///< 앨범
	string m_mGenre;	///< 장르
	int m_mLong;		///< 재생시간
	int m_mNumber;		///< 재생횟수
	string m_mNote;		///< 악보
	string m_mLyrics;	///< 가사
};

#endif	// _MUSICTYPE_H
