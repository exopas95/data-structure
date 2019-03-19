#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


#include "GenreType.h"
#include "MusicType.h"
#include "CircularQueueType.h"


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
		m_List.MakeEmpty();
		m_Command = -1;

		/*GenreType indata;
		indata.SetGenreInfo(1, "�߶��");
		g_List.Add(indata);
		indata.SetGenreInfo(2, "����");
		g_List.Add(indata);
		indata.SetGenreInfo(3, "�˼�");
		g_List.Add(indata);*/
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
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	int SearchByName();

	/**
	*	@brief	����Ʈ���� �ش� �������� ���� item�� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	void SearchByArtist();

	/**
	*	@brief	����Ʈ���� �ش� �ٹ��� ���� item�� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	void SearchByAlbum();

	/**
	*	@brief	����Ʈ���� �ش� �帣���� ���� item�� ã�´�.
	*	@pre	����.
	*	@post	ã�� item�� ����Ѵ�.
	*	@return	������ 1�� ����, ���н� 0�� ����.
	*/
	void SearchByGenre();


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

	void SearchListByMusicName(MusicType &inData);

	/**
	*	@brief	inData�� ������ �κ��� �����ϴ� ���ڿ��� ã�� ����Ѵ�.
	*	@pre	inData�� ������ �κ��� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	inData�� �˸��� �׸��� ����ȴ�.
	*	@param	inData	������ �����Ǿ��ְ� �������� ����ִ� MusicType.
	*	@return	����.
	*/
	void SearchListByMusicArtist(MusicType &inData);

	/**
	*	@brief	inData�� �ٹ��� �κ��� �����ϴ� ���ڿ��� ã�� ����Ѵ�.
	*	@pre	inData�� �ٹ��� �κ��� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	inData�� �˸��� �׸��� ����ȴ�.
	*	@param	inData	�ٹ��� �����Ǿ��ְ� �������� ����ִ� MusicType.
	*	@return	����.
	*/
	void SearchListByMusicAlbum(MusicType &inData);

	/**
	*	@brief	inData�� ���� �κ��� �����ϴ� ���ڿ��� ã�� ����Ѵ�.
	*	@pre	inData�� ���� �κ��� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	inData�� �˸��� �׸��� ����ȴ�.
	*	@param	inData	���簡 �����Ǿ��ְ� �������� ����ִ� MusicType.
	*	@return	����.
	*/
	void SearchListByMusicGenre(MusicType &inData);

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayNewMusic();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	int DisplayMusicByGenre();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void RetrieveByNameNGenre();

	/**
	*	@brief	���ο� ���� queue�� �߰�
	*	@pre	queue�� ������ �ʾƾ���.
	*	@post	���ο� ���� queue�� �߰���.
	*	@return	������ 1, ���н� 0.
	*/
	int EnqueueItem(GenreType &inData);

	/**
	*	@brief	������ queue���� ����
	*	@pre	queue�� ���� �־����
	*	@post	������ ���� ������
	*	@return	������ 1, ���н� 0.
	*/
	int DequeueItem();

	/**
	*	@brief	��� ���� ȭ�鿡 ���.
	*	@pre	ť�� ��������� �ȵ�.
	*	@post	��簪�� ���, ��������� It is empty ���.
	*/
	void DisplayQueueItem();



private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	SortedList<MusicType> m_List;		///< item list.
	SortedList<GenreType> g_List;
	CircularQueueType<SimpleMusicType> s_List;
	int m_Command;			///< current command number.
};

#endif	// _APPLICATION_H