#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H


#include <iostream>
#include <fstream>
#include <string>
#include "MasterType.h"
#include "GenreType.h"
#include "AlbumType.h"
#include "ArtistType.h"
#include "PlayType.h"
#include "MostPlayedMusicType.h"
#include "AVLTree.h"
#include "CircularQueueType.h"
#include "SortedLinkedList.h"
#include "CHeapBase.h"
#include "CMaxHeap.h"
#include "UserType.h"
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <shellapi.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

#define FILENAMESIZE 1024

class Application
{
public:
	// 생성자
	Application() 
	{
		command = 0;
		G_ID = 0;
		Album_ID = 0;
		Artist_ID = 0;
		f_List = new CMaxHeap<MostPlayedMusicType>(30);
		GetUserFromFile();
		ReadDataFromFile();
	}
	// 소멸자
	~Application()
	{
		delete[] f_List;
	}

	// Application 실행 함수
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
	*	@brief	Tree에 music을 추가
	*	@pre	none
	*	@post	Tree에 music이 추가됨
	*/
	void Insertmusic();

	/**
	*	@brief	Tree에서 music을 지움
	*	@pre	none
	*	@post	Tree에서 music이 지워짐
	*/
	void Removemusic();

	/**
	*	@brief	Tree에서 music을 바꿈
	*	@pre	none
	*	@post	Tree에서 music이 바뀜
	*/
	int Replacemusic();

	/**
	*	@brief	Tree에서 음악 명으로 검색
	*	@pre	none
	*	@post	Tree에 있으면 관련 정보도 같이 출력, 없으면 없다는 문구 출력
	*/
	void SearchMusicByName();

	/**
	*	@brief	Tree에서 가수명으로 검색
	*	@pre	none
	*	@post	Tree에 있으면 관련 정보도 같이 출력, 없으면 없다는 문구 출력
	*/
	int SearchMusicByArtist();

	/**
	*	@brief	Tree에서 앨범명으로 검색
	*	@pre	none
	*	@post	Tree에 있으면 관련 정보도 같이 출력, 없으면 없다는 문구 출력
	*/
	int SearchMusicByAlbum();

	/**
	*	@brief	Tree에서 장르명으로 검색
	*	@pre	none
	*	@post	Tree에 있으면 관련 정보도 같이 출력, 없으면 없다는 문구 출력
	*/
	int SearchMusicByGenre();

	/**
	*	@brief	멜론에서 가사명으로 검색
	*	@pre	none
	*	@post	none
	*/
	void SearchMusicByLyrics();

	/**
	*	@brief	선택한 음악을 네이버에서 검색함
	*	@pre	none
	*	@post	none
	*/
	void SearchWeb(string title);

	/**
	*	@brief	최근에 추가된 뮤직 리스트를 출력한다.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayNewMusic();

	/**
	*	@brief	Tree의 모든 music을 출력함
	*	@pre	none
	*	@post	Tree의 모든 노드들이 출력됨
	*/
	void Displaymusic();

	/**
	*	@brief	가장 많이 들은 노래 30곡을 출력함
	*	@pre	none
	*	@post	가장 많이 들은 노래 30곡을 출력함
	*/
	void DisPlayMostPlayedMusic();

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
	ifstream m_InFile;								// input file descriptor.
	ofstream m_OutFile;								// output file descriptor.
	AVLTree<MasterType> m_List;						// 음악 리스트
	AVLTree<GenreType> g_List;						// 장르 리스트
	AVLTree<ArtistType> artist_List;				// 가수 리스트
	AVLTree<AlbumType> album_List;					// 앨범 리스트
	SortedLinkedList<PlayType> p_List;				// 재생 목록
	CircularQueueType<SimpleMusicType> s_List;		// 최근 음악 리스트
	CHeapBase<MostPlayedMusicType> *f_List;			// 가장 많이 재생한 음악 리스트
	SortedLinkedList<User> users;					//회원 리스트
	User* loginedUser;								//현재 로그인 된 회원
	int command;									// 커맨드
	int G_ID;										// 장르 번호
	int Artist_ID;									// 가수 번호
	int Album_ID;									// 앨범 번호

};
#endif