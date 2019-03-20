
#ifndef _MostPlayedMusicType_H
#define _MostPlayedMusicType_H

#include <iostream>
#include <string>

using namespace std;


/**
*	@ brief 재생목록 정보 클래스
*/
class MostPlayedMusicType
{
public:
	/**
	*	default constructor.
	*/
	MostPlayedMusicType()
	{
		Most_ID = -1;
		Most_Name = "";
		Most_Artist = "";
		Most_Number = 0;
	}

	/**
	*	destructor.
	*/
	~MostPlayedMusicType() {}


	//대입 연산자 오버로딩 선언
	MostPlayedMusicType& operator= (const MostPlayedMusicType &obj)
	{
		this->Most_ID = obj.Most_ID;
		this->Most_Name = obj.Most_Name;
		this->Most_Artist = obj.Most_Artist;
		this->Most_Number = obj.Most_Number;
		return *this;
	}

	/**
	*	@brief		음악 번호를 정한다.
	*	@param[in]	inMost_ID	Play id.
	*/
	void SetID(int ID)
	{
		Most_ID = ID;
	}

	/**
	*	@brief	음악 번호를 가져온다.
	*	@return	음악 번호
	*/
	int GetID()
	{
		return Most_ID;
	}

	/**
	*	@brief		재생횟수를 정한다.
	*	@param[in]	inPlayNumber	Play time.
	*/
	void SetNumber(int PlayNumber)
	{
		Most_Number = PlayNumber;
	}

	/**
	*	@brief	재생횟수를 가져온다.
	*	@return	재생횟수.
	*/
	int GetNumber()
	{
		return Most_Number;
	}

	/**
	*	@brief		음악 이름을 정한다.
	*	@param[in]	inPlayName	PlayName.
	*/
	void SetName(string inPlayName)
	{
		Most_Name = inPlayName;
	}

	/**
	*	@brief	음악 이름을 가져온다.
	*	@return	음악 이름
	*/
	string GetName()
	{
		return Most_Name;
	}

	/**
	*	@brief	해당 음악의 가수명을 정한다.
	*	@pre	none.
	*	@post	해당 음악의 가수명이 정해진다.
	*	@param	inPlayArtist	Artist.
	*/
	void SetArtist(string inPlayArtist)
	{
		Most_Artist = inPlayArtist;
	}

	/**
	*	@brief  가수명에 대한 정보를 얻는다.
	*	@pre	가수명이 정해져있다.
	*	@post	none.
	*	@return	가수명
	*/
	string GetyArtist()
	{
		return Most_Artist;
	}

	/**
	*	@brief	재생목록 내의 음악들에 대한 정보를 입력한다.
	*	@pre	none.
	*	@post	재생목록 내의 음악들에 대한 정보가 설정된다.
	*	@param	Most_ID			음악번호
	*	@param	PlayNumber		재생횟수
	*	@param	PlayLong		재생시간
	*	@param	inPlayName		음악이름
	*	@param	inPlayArtist	가수
	*/
	void SetInfo(int ID, string Name, std::string Artist, int Number)
	{
		SetID(ID);
		SetName(Name);
		SetArtist(Artist);
		SetNumber(Number);
	}

	/**
	*	@brief	재생목록에 있는 음악의 정보를 화면에 띄운다.
	*	@pre	재생목록에 있는 음악의 정보가 정해져 있다.
	*	@post	재생목록에 있는 음악의 정보가 출력된다.
	*/
	void DisplayRecordOnScreen()
	{
		cout << "\n\t제목 : " << Most_Name;
		cout << "\n\t가수 : " << Most_Artist;
		cout << "\n\t재생 횟수 : " << Most_Number;
	}

	/**
	*	@brief	재생목록에 있는 음악의 음악번호를 키보드로 입력한다.
	*	@pre	없다.
	*	@post	재생목록에 있는 음악의 음악번호가 정해진다.
	*/
	void SetIDFromKB();

	/**
	*	@brief	재생목록에 있는 음악의 재생시간을 키보드로 입력한다.
	*	@pre	없다.
	*	@post	재생목록에 있는 음악의 재생시간이 정해진다.
	*/
	void SetNumberFromKB();

	/**
	*	@brief	재생목록에 있는 음악의 음악명을 키보드로 입력한다.
	*	@pre	없다.
	*	@post	재생목록에 있는 음악의 음악명이 정해진다.
	*/
	void SetNameFromKB();

	/**
	*	@brief	재생목록에 있는 음악의 가수를 키보드로 입력한다.
	*	@pre	없다.
	*	@post	재생목록에 있는 음악의 가수가 정해진다.
	*/
	void SetArtistFromKB();

	/**
	*	@brief	재생목록에 있는 음악의 정보를 키보드로 입력한다.
	*	@pre	없다.
	*	@post	재생목록에 있는 음악의 정보가 정해진다.
	*/
	void SetRecordFromKB();

	/**
	*	Compare two MostPlayedMusicTypes.
	*	@brief	Compare two item types by Play id.
	*	@pre	two Play types should be initialized.
	*	@post	the target file is included the new Play record.
	*	@param	data	target Play for comparing.
	*	@return	왼쪽의 ID와 오른쪽 ID가 같으면 true, 다르면 false를 반환한다.
	*/
	bool operator == (const MostPlayedMusicType &obj);

	/**
	*	Compare two MostPlayedMusicTypes.
	*	@brief	Compare two item types by Play id.
	*	@pre	two Play types should be initialized.
	*	@post	the target file is included the new Play record.
	*	@param	data	target Play for comparing.
	*	@return	왼쪽의 ID가 오른쪽 ID보다 크면 true, 작거나 같으면 false를 반환한다.
	*/
	bool operator > (const MostPlayedMusicType &obj);

	/**
	*	Compare two MostPlayedMusicTypes.
	*	@brief	Compare two item types by Play id.
	*	@pre	two Play types should be initialized.
	*	@post	the target file is included the new Play record.
	*	@param	data	target Play for comparing.
	*	@return	오른쪽의 ID가 왼쪽 ID보다 크면 true, 작거나 같으면 false를 반환한다.
	*/
	bool operator < (const MostPlayedMusicType &obj);

	/**
	*	Compare two MostPlayedMusicTypes.
	*	@brief	Compare two item types by Play id.
	*	@pre	two Play types should be initialized.
	*	@post	the target file is included the new Play record.
	*	@param	data	target Play for comparing.
	*	@return	오른쪽의 ID가 왼쪽 ID보다 크면 true, 작거나 같으면 false를 반환한다.
	*/
	bool operator <= (const MostPlayedMusicType &obj);

	/**
	*	Compare two MostPlayedMusicTypes.
	*	@brief	Compare two item types by Play id.
	*	@pre	two Play types should be initialized.
	*	@post	the target file is included the new Play record.
	*	@param	data	target Play for comparing.
	*	@return	오른쪽의 ID가 왼쪽 ID보다 크면 true, 작거나 같으면 false를 반환한다.
	*/
	bool operator >= (const MostPlayedMusicType &obj);

	/**
	*	Display SimpleMusictypes.
	*	@brief	출력 연산자
	*	@pre	재생횟수, 제목, 가수, 재생시간이 정해져 있다.
	*	@post	재생횟수, 제목, 가수, 재생시간을 출력한다.
	*	@return	out
	*/
	void operator<<(MostPlayedMusicType item);
	

protected:
	int Most_ID;				///< 재생목록 음악번호
	int Most_Number;			///< 재생 횟수
	string Most_Name;			///< 재생목록 음악명
	string Most_Artist;			///< 재생목록 가수
};

#endif	// _MostPlayedMusicType_H
