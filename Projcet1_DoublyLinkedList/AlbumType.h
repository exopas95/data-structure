
#ifndef _ALBUMTYPE_H
#define _ALBUMTYPE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
*	@ 앨범 정보 클래스
*/
class AlbumType
{
public:
	/**
	*	constructor
	*/
	AlbumType()
	{
		m_aID = -1;
		m_aAlbum = "";
		m_aCompany = "";
		m_aArtist = "";
	}

	/**
	*	destructor
	*/
	~AlbumType() {}

	/**
	*	@brief  음악번호의 정보를 얻는다.
	*	@pre	음악번호가 정해져있다.
	*	@post	없다.
	*	@return	음악번호
	*/
	int GetID()
	{
		return m_aID;
	}

	/**
	*	@brief  앨범명의 정보를 얻는다.
	*	@pre	앨범명이 정해져있다.
	*	@post	none.
	*	@return	앨범명
	*/
	string GetAlbumName()
	{
		return m_aAlbum;
	}


	/**
	*	@brief  가수의 정보를 얻는다.
	*	@pre	가수가 정해져있다.
	*	@post	none.
	*	@return	가수
	*/
	string GetArtistName()
	{
		return m_aArtist;
	}


	/**
	*	@brief  소속사의 정보를 얻는다.
	*	@pre	소속사가 정해져있다.
	*	@post	none.
	*	@return	소속사
	*/
	string GetACompanyName()
	{
		return m_aCompany;
	}

	/**
	*	@brief	음악번호를 정한다.
	*	@pre	none.
	*	@post	음악번호가 정해진다.
	*	@param	inID Music ID
	*/
	void SetID(int inID)
	{
		m_aID = inID;
	}

	/**
	*	@brief	앨범명을 정한다.
	*	@pre	none.
	*	@post	앨범명이 정해진다.
	*	@param	inName 앨범명.
	*/
	void SetAlbumName(string inName)
	{
		m_aAlbum = inName;
	}

	/**
	*	@brief	가수명을 정한다.
	*	@pre	none.
	*	@post	가수명이 정해진다.
	*	@param	inName 가수명.
	*/
	void SetArtistName(string inArtist)
	{
		m_aArtist = inArtist;
	}

	/**
	*	@brief	소속사명을 정한다.
	*	@pre	none.
	*	@post	소속사명이 정해진다.
	*	@param	inName 소속사명.
	*/
	void SetCompanyName(string inCompany)
	{
		m_aCompany = inCompany;
	}

	/**
	*	@brief	앨범과 관련된 정보를 정한다.
	*	@pre	none.
	*	@post	앨범과 관련된 정보가 정해진다.
	*	@param	inID, inName, inArtist, in Company  음악번호, 앨범명, 가수명, 소속사명
	*/
	void SetRecord(int inID, string inName, string inArtist, string inCompany)
	{
		SetID(inID);
		SetAlbumName(inName);
		SetArtistName(inArtist);
		SetCompanyName(inCompany);
	}


	/**
	*	@brief	앨범의 정보를 화면에 띄운다.
	*	@pre	앨범의 정보가 정해져있다.
	*	@post	앨범의 정보가 출력된다.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayAlbumOnScreen();
		DisplayArtistOnScreen();
		DisplayCompanyOnScreen();
	};

	/**
	*	@brief	음악의 앨범명을 화면에 띄운다.
	*	@pre	음악의 앨범명 정해져있다.
	*	@post	음악의 앨범명이 출력된다.
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "\t앨범 : " << m_aAlbum << endl;
	};

	/**
	*	@brief	음악의 가수명을 화면에 띄운다.
	*	@pre	음악의 가수명이 정해져있다.
	*	@post	음악의 가수명이 출력된다.
	*/
	void DisplayArtistOnScreen()
	{
		cout << "\t가수 : " << m_aArtist << endl;
	};

	/**
	*	@brief	가수의 소속사명을 화면에 띄운다.
	*	@pre	가수의 소속사명이 정해져있다.
	*	@post	가수의 소속사명이 출력된다.
	*/
	void DisplayCompanyOnScreen()
	{
		cout << "\t소속사 : " << m_aCompany << endl;
	};

	/**
	*	Compare two AlbumTypes.
	*	@brief	Compare two Simple Music types by item id.
	*	@pre	two Simple Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	왼쪽의 ID와 오른쪽 ID가 같으면 true, 다르면 false를 반환한다.
	*/
	bool operator== (const AlbumType &obj);

	/**
	*	Compare two AlbumTypes.
	*	@brief	Compare two Simple Music types by item id.
	*	@pre	two Simple Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	왼쪽의 ID가 오른쪽보다 크면 true, 작거나 같으면 false를 반환한다.
	*/
	bool operator> (const AlbumType &obj);

	/**
	*	Compare two AlbumTypes.
	*	@brief	Compare two Simple Music types by item id.
	*	@pre	two Simple Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	오른쪽의 ID가 왼쪽보다 크면 true, 작거나 같으면 false를 반환한다.
	*/
	bool operator< (const AlbumType &obj);

	/**
	*	Compare two AlbumTypes.
	*	@brief	Compare two Simple Music types by item id.
	*	@pre	two Simple Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	왼쪽의 ID가 오른쪽보다 크거나 같으면 true, 작으면 false를 반환한다.
	*/
	bool operator>= (const AlbumType &obj);

	/**
	*	Compare two AlbumTypes.
	*	@brief	Compare two Simple Music types by item id.
	*	@pre	two Simple Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	오른쪽의 ID가 왼쪽보다 크거나 같으면 true, 작으면 false를 반환한다.
	*/
	bool operator<= (const AlbumType &obj);

	/**
	*	Display SimpleMusictypes.
	*	@brief	출력 연산자
	*	@pre	앨범, 가수, 소속사가 정해져 있다.
	*	@post	앨범, 가수, 소속사를 출력한다.
	*	@return	out
	*/
	friend ostream &operator<< (ostream& out, const AlbumType &obj)
	{
		out << "\t앨범 : " << obj.m_aAlbum << "\n" << "\t가수 : " << obj.m_aArtist << '\n'
			<< "\t소속사 : " << obj.m_aCompany << endl;
		return out;
	}

protected:

	int m_aID;				/// 음악 번호
	string m_aAlbum;		/// 음악 앨범
	string m_aCompany;		/// 음악 소속사
	string m_aArtist;		/// 음악 이름

};

#endif	// _ALBUMTYPE_H //
