#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


#include "GenreType.h"
#include "MusicType.h"
#include "PlayType.h"
#include "ArtistType.h"
#include "UserType.h"
#include "CircularQueueType.h"


#define FILENAMESIZE 1024



/**
*	@ brief application class for music management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		ReadDataFromFile();
		GetUserFromFile();
		m_Command = -1;
	}
	
	/**
	*	destructor.
	*/
	~Application()	{}

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	Admin's command.
	*/
	int GetCommand_Admin();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand_User();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddMusic();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllMusic();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();

	/**
	*	@brief	재생하고 싶은 음악을 재생목록에 추가한다.
	*	@pre	선택할 음악이 존재한다.
	*	@post	선택한 음악을 재생목록에 추가한다
	*	@return	return 0 if this function works well, otherwise 1.
	*/
	int AddToPlayMusic();

	/**
	*	@brief	지우고 싶은 음악을 재생목록에서 제거한다.
	*	@pre	재생목록에 음악이 존재한다.
	*	@post	선택한 음악이 재생목록에서 제거된다.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DeletePlayMusic();

	/**
	*	@brief	재생목록에 있는 음악을 재생한다.
	*	@pre	재생목록에 음악이 존재한다.
	*	@post	해당 음악의 재생횟수가 증가한다.
	*/
	void PlayMusic();

	/**
	*	@brief	리스트에서 해당 음악 번호를 가진 item을 찾는다.
	*	@pre	없음.
	*	@post	찾은 item을 출력한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int SearchByID();

	/**
	*	@brief	리스트에서 해당 음악명 가진 item을 찾는다.
	*	@pre	없음.
	*	@post	찾은 item을 출력한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int SearchByName();


	/**
	*	@brief	리스트에서 해당 앨범명 가진 item을 찾는다.
	*	@pre	없음.
	*	@post	찾은 item을 출력한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	void SearchByAlbum();

	/**
	*	@brief	리스트에서 해당 재생횟수를 가진 item을 찾는다.
	*	@pre	없음.
	*	@post	찾은 item을 출력한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	void SearchByRepetition();

	/**
	*	@brief	리스트에서 해당 음악명을 가진 item을 찾아 제거한다.
	*	@pre	입력하는 음악명이 리스트에 존재해야 한다.
	*	@post	리스트에 해당 item을 제거한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int DeleteMusic();
	
	/**
	*	@brief	리스트에서 해당 음악명를 가진 item을 찾아 변경한다.
	*	@pre	입력하는 음악명이 리스트에 존재해야 한다.
	*	@post	리스트에 item이 변경된다.
	*/
	int ReplaceMusic();

	/**
	*	@brief	inData의 음악번호 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 음악번호 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	음악번호가 설정되어있고 나머지는 비어있는 MusicType.
	*	@return	없다.
	*/
	void SearchListByMusicID(MusicType &inData);

	/**
	*	@brief	inData의 음악명 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 음악명 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	음악명 설정되어있고 나머지는 비어있는 MusicType.
	*	@return	없다.
	*/
	void SearchListByMusicName(MusicType &inData);

	/**
	*	@brief	inData의 앨범명 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 앨범명 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	앨범명 설정되어있고 나머지는 비어있는 MusicType.
	*	@return	없다.
	*/
	void SearchListByMusicAlbum(MusicType &inData);

	/**
	*	@brief	inData의 재생횟수 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 재생횟수 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	재생횟수가 설정되어있고 나머지는 비어있는 MusicType.
	*	@return	없다.
	*/
	void SearchListByMusicRepetition(MusicType &inData);

	/**
	*	@brief	최근에 추가된 뮤직 리스트를 출력한다.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayNewMusic();

	/**
	*	@brief	최근에 추가된 재생목록을 출력한다.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayPlayNewMusic();

	/**
	*	@brief	장르별 음악 리스트를 출력한다.
	*	@pre	none.
	*	@post	none.
	*/
	int DisplayMusicByGenre();

	/**
	*	@brief	가수별 음악 리스트를 출력한다.
	*	@pre	none.
	*	@post	none.
	*/
	int DisplayMusicByArtist();

	/**
	*	@brief	회원 가입을 진행한다.
	*	@post	새로운 회원이 회원 리스트에 추가된다.
	*/
	void uRegister();

	/**
	*	@brief	회원 로그인을 진행한다.
	*	@pre	회원이 회원리스트에 존재한다.
	*	@post	현재 로그인한 회원의 주소가 저장된다.
	*/
	void userLogin();

	/**
	*	@brief	관리자 로그인을 진행한다.
	*	@pre	관리자가 리스트에 존재한다.
	*	@post	관리자로 로그인된다.
	*/
	void userAdminLogin();

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void GetUserFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	void SetUserToFile();

private:
	ifstream m_InFile;								///< input file descriptor.
	ofstream m_OutFile;								///< output file descriptor.
	SortedLinkedList<MusicType> m_List;				///< 음악 리스트
	SortedLinkedList<PlayType> p_List;				///< 재생 목록
	SortedLinkedList<GenreType> g_List;				///< 장르 리스트
	SortedLinkedList<ArtistType> a_List;			///< 앨범 리스트
	SortedLinkedList<PlayType> rp_List;				///< 최근 들은 음악 리스트
	CircularQueueType<SimpleMusicType> s_List;		///< 간단한 음악 리스트
	int m_Command;									///< current command number.

	SortedLinkedList<User> users;					///회원 리스트
	User* loginedUser;								///현재 로그인 된 회원
};

#endif	// _APPLICATION_H