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
	*	@brief	����ϰ� ���� ������ �����Ͽ� �߰��Ѵ�.
	*	@pre	������ ������ �����Ѵ�.
	*	@post	������ ������ �����Ͽ� �߰��Ѵ�
	*	@return	return 0 if this function works well, otherwise 1.
	*/
	int AddToPlayMusic();

	/**
	*	@brief	����� ���� ������ �����Ͽ��� �����Ѵ�.
	*	@pre	�����Ͽ� ������ �����Ѵ�.
	*	@post	������ ������ �����Ͽ��� ���ŵȴ�.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DeletePlayMusic();

	/**
	*	@brief	�����Ͽ� �ִ� ������ ����Ѵ�.
	*	@pre	�����Ͽ� ������ �����Ѵ�.
	*	@post	�ش� ������ ���Ƚ���� �����Ѵ�.
	*/
	void PlayMusic();

	/**
	*	@brief	����Ʈ���� �ش� ���� ��ȣ�� ���� item�� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchByID();

	/**
	*	@brief	����Ʈ���� �ش� ���Ǹ� ���� item�� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchByName();


	/**
	*	@brief	����Ʈ���� �ش� �ٹ��� ���� item�� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	void SearchByAlbum();

	/**
	*	@brief	����Ʈ���� �ش� ���Ƚ���� ���� item�� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	void SearchByRepetition();

	/**
	*	@brief	����Ʈ���� �ش� ���Ǹ��� ���� item�� ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� ���Ǹ��� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� �ش� item�� �����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int DeleteMusic();
	
	/**
	*	@brief	����Ʈ���� �ش� ���Ǹ� ���� item�� ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� ���Ǹ��� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� item�� ����ȴ�.
	*/
	int ReplaceMusic();

	/**
	*	@brief	inData�� ���ǹ�ȣ �κ��� �����ϴ� ���ڿ��� ã�� ����Ѵ�.
	*	@pre	inData�� ���ǹ�ȣ �κ��� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	inData�� �˸��� �׸��� ����ȴ�.
	*	@param	inData	���ǹ�ȣ�� �����Ǿ��ְ� �������� ����ִ� MusicType.
	*	@return	����.
	*/
	void SearchListByMusicID(MusicType &inData);

	/**
	*	@brief	inData�� ���Ǹ� �κ��� �����ϴ� ���ڿ��� ã�� ����Ѵ�.
	*	@pre	inData�� ���Ǹ� �κ��� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	inData�� �˸��� �׸��� ����ȴ�.
	*	@param	inData	���Ǹ� �����Ǿ��ְ� �������� ����ִ� MusicType.
	*	@return	����.
	*/
	void SearchListByMusicName(MusicType &inData);

	/**
	*	@brief	inData�� �ٹ��� �κ��� �����ϴ� ���ڿ��� ã�� ����Ѵ�.
	*	@pre	inData�� �ٹ��� �κ��� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	inData�� �˸��� �׸��� ����ȴ�.
	*	@param	inData	�ٹ��� �����Ǿ��ְ� �������� ����ִ� MusicType.
	*	@return	����.
	*/
	void SearchListByMusicAlbum(MusicType &inData);

	/**
	*	@brief	inData�� ���Ƚ�� �κ��� �����ϴ� ���ڿ��� ã�� ����Ѵ�.
	*	@pre	inData�� ���Ƚ�� �κ��� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	inData�� �˸��� �׸��� ����ȴ�.
	*	@param	inData	���Ƚ���� �����Ǿ��ְ� �������� ����ִ� MusicType.
	*	@return	����.
	*/
	void SearchListByMusicRepetition(MusicType &inData);

	/**
	*	@brief	�ֱٿ� �߰��� ���� ����Ʈ�� ����Ѵ�.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayNewMusic();

	/**
	*	@brief	�ֱٿ� �߰��� �������� ����Ѵ�.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayPlayNewMusic();

	/**
	*	@brief	�帣�� ���� ����Ʈ�� ����Ѵ�.
	*	@pre	none.
	*	@post	none.
	*/
	int DisplayMusicByGenre();

	/**
	*	@brief	������ ���� ����Ʈ�� ����Ѵ�.
	*	@pre	none.
	*	@post	none.
	*/
	int DisplayMusicByArtist();

	/**
	*	@brief	ȸ�� ������ �����Ѵ�.
	*	@post	���ο� ȸ���� ȸ�� ����Ʈ�� �߰��ȴ�.
	*/
	void uRegister();

	/**
	*	@brief	ȸ�� �α����� �����Ѵ�.
	*	@pre	ȸ���� ȸ������Ʈ�� �����Ѵ�.
	*	@post	���� �α����� ȸ���� �ּҰ� ����ȴ�.
	*/
	void userLogin();

	/**
	*	@brief	������ �α����� �����Ѵ�.
	*	@pre	�����ڰ� ����Ʈ�� �����Ѵ�.
	*	@post	�����ڷ� �α��εȴ�.
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
	SortedLinkedList<MusicType> m_List;				///< ���� ����Ʈ
	SortedLinkedList<PlayType> p_List;				///< ��� ���
	SortedLinkedList<GenreType> g_List;				///< �帣 ����Ʈ
	SortedLinkedList<ArtistType> a_List;			///< �ٹ� ����Ʈ
	SortedLinkedList<PlayType> rp_List;				///< �ֱ� ���� ���� ����Ʈ
	CircularQueueType<SimpleMusicType> s_List;		///< ������ ���� ����Ʈ
	int m_Command;									///< current command number.

	SortedLinkedList<User> users;					///ȸ�� ����Ʈ
	User* loginedUser;								///���� �α��� �� ȸ��
};

#endif	// _APPLICATION_H