#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ArrayList.h"

#define FILENAMESIZE 1024

/**
*	application class for item management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_Command = 0;
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
	*	@return	user's command.
	*/
	int GetCommand();

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
	*	@brief	리스트에서 해당 곡명 가진 item을 찾는다.
	*	@pre	없음.
	*	@post	찾은 item을 출력한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int SearchByName();

	/**
	*	@brief	리스트에서 해당 가수명을 가진 item을 찾는다.
	*	@pre	없음.
	*	@post	찾은 item을 출력한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	void RetreiveRecordByArtist();

	/**
	*	@brief	리스트에서 해당 앨범명 가진 item을 찾는다.
	*	@pre	없음.
	*	@post	찾은 item을 출력한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	void RetreiveRecordByAlbum();

	/**
	*	@brief	리스트에서 해당 장르명을 가진 item을 찾는다.
	*	@pre	없음.
	*	@post	찾은 item을 출력한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	void RetreiveRecordByGenre();


	/**
	*	@brief	리스트에서 해당 곡명을 가진 item을 찾아 제거한다.
	*	@pre	입력하는 곡명이 리스트에 존재해야 한다.
	*	@post	리스트에 해당 item을 제거한다.
	*	@return	성공시 1을 리턴, 실패시 0을 리턴.
	*/
	int DeleteMusic();
	
	/**
	*	@brief	리스트에서 해당 곡명를 가진 item을 찾아 변경한다.
	*	@pre	입력하는 곡명이 리스트에 존재해야 한다.
	*	@post	리스트에 item이 변경된다.
	*/
	int ReplaceMusic();

	/**
	*	@brief	inData의 가수명 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 가수명 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	가수명 설정되어있고 나머지는 비어있는 MusicType.
	*	@return	없다.
	*/
	void SearchListByMusicArtist(MusicType &inData);

	/**
	*	@brief	inData의 앨범명 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 앨범명 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	앨범명 설정되어있고 나머지는 비어있는 MusicType.
	*	@return	없다.
	*/
	void SearchListByMusicAlbum(MusicType &inData);

	/**
	*	@brief	inData의 가사 부분을 포함하는 문자열을 찾아 출력한다.
	*	@pre	inData의 가사 부분이 초기화되어있어야 한다.
	*	@post	inData에 알맞은 항목이 복사된다.
	*	@param	inData	가사가 설정되어있고 나머지는 비어있는 MusicType.
	*	@return	없다.
	*/
	void SearchListByMusicGenre(MusicType &inData);

private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	ArrayList m_List;		///< item list.
	int m_Command;			///< current command number.
};

#endif	// _APPLICATION_H