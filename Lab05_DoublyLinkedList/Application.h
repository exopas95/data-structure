#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "BaseClass.h"
#include "GenreType.h"
#include "MusicType.h"
#include "CircularQueueType.h"


#define FILENAMESIZE 1024



/**
*	@ brief application class for music management simply.
*/
class Application : public BaseClass
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_List.MakeEmpty();
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
	*	@brief	����Ʈ���� �ش� ��� ���� item�� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ����Ѵ�.
	*	@return	data�� ����
	*/
	MusicType RetreiveRecordByName();

	/**
	*	@brief	����Ʈ���� �ش� �������� ���� item�� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ����Ѵ�.
	*	@return	data�� ����
	*/
	MusicType RetreiveRecordByArtist();

	/**
	*	@brief	����Ʈ���� �ش� �ٹ��� ���� item�� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ����Ѵ�.
	*	@return	data�� ����
	*/
	MusicType RetreiveRecordByAlbum();

	/**
	*	@brief	����Ʈ���� �ش� �帣���� ���� item�� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ����Ѵ�.
	*	@return	data�� ����
	*/
	MusicType RetreiveRecordByGenre();


	/**
	*	@brief	����Ʈ���� �ش� ����� ���� item�� ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� ����� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� �ش� item�� �����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int DeleteMusic();
	
	/**
	*	@brief	����Ʈ���� �ش� ��� ���� item�� ã�� �����Ѵ�.
	*	@pre	�Է��ϴ� ����� ����Ʈ�� �����ؾ� �Ѵ�.
	*	@post	����Ʈ�� item�� ����ȴ�.
	*/
	int ReplaceMusic();

	/**
	*	@brief	inData�� ��� �κ��� �����ϴ� ���ڿ��� ã�� ����Ѵ�.
	*	@pre	inData�� ��� �κ��� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	inData�� �˸��� �׸��� ����ȴ�.
	*	@param	inData	��� �����Ǿ��ְ� �������� ����ִ� MusicType.
	*	@return	����.
	*/
	void SearchByName(MusicType &inData);

	/**
	*	@brief	inData�� ������ �κ��� �����ϴ� ���ڿ��� ã�� ����Ѵ�.
	*	@pre	inData�� ������ �κ��� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	inData�� �˸��� �׸��� ����ȴ�.
	*	@param	inData	������ �����Ǿ��ְ� �������� ����ִ� MusicType.
	*	@return	����.
	*/
	void SearchByArtist(MusicType &inData);

	/**
	*	@brief	inData�� �ٹ��� �κ��� �����ϴ� ���ڿ��� ã�� ����Ѵ�.
	*	@pre	inData�� �ٹ��� �κ��� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	inData�� �˸��� �׸��� ����ȴ�.
	*	@param	inData	�ٹ��� �����Ǿ��ְ� �������� ����ִ� MusicType.
	*	@return	����.
	*/
	void SearchByAlbum(MusicType &inData);

	/**
	*	@brief	���� A��
	*	@pre	inData�� �帣 �κ��� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	inData�� �˸��� �׸��� ����ȴ�.
	*	@param	inData	�帣�� �����Ǿ��ְ� �������� ����ִ� MusicType.
	*	@return	����.
	*/
	void A_FindNDispGenrUsingMlist(MusicType &inData);

	/**
	*	@brief	�ֱٿ� �߰��� ���� ����Ʈ�� ����Ѵ�.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayNewMusic();

	/**
	*	@brief	���� B��
	*	@pre	none.
	*	@post	none.
	*/
	int B_FindNDispGenrUsingGlist();

	/**
	*	@brief	���� C��
	*	@pre	none.
	*	@post	none.
	*/
	int C_FindNDispGenrUsingGlist();


private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	DoublySortedLinkedList<GenreType> g_List;				///< �帣 ����Ʈ
	CircularQueueType<SimpleMusicType> s_List;		///< ������ ���� ����Ʈ
	int m_Command;			///< current command number.
};

#endif	// _APPLICATION_H