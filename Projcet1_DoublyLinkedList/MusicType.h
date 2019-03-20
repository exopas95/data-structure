
#ifndef _MUSICTYPE_H
#define _MUSICTYPE_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>


using namespace std;


/**
*	@ brief ���� ���� Ŭ����
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
	*	@brief  ���ǹ�ȣ�� ������ ��´�.
	*	@pre	���ǹ�ȣ�� �������ִ�.
	*	@post	none.
	*	@return	���ǹ�ȣ
	*/
	int GetID()
	{
		return m_mID;
	}

	/**
	*	@brief  ���Ǹ��� ������ ��´�.
	*	@pre	���Ǹ��� �������ִ�.
	*	@post	none.
	*	@return	���Ǹ�
	*/
	string GetName()
	{
		return m_mName;
	}

	/**
	*	@brief  ������ ���� ������ ��´�.
	*	@pre	�������� �������ִ�.
	*	@post	none.
	*	@return	������
	*/
	string GetArtist()
	{
		return m_mArtist;
	}

	/**
	*	@brief  �ٹ��� ���� ������ ��´�.
	*	@pre	�ٹ����� �������ִ�.
	*	@post	none.
	*	@return	�ٹ���
	*/
	string GetAlbum()
	{
		return m_mAlbum;
	}

	/**
	*	@brief  �帣�� ���� ������ ��´�.
	*	@pre	�帣���� �������ִ�.
	*	@post	none.
	*	@return	�帣��
	*/
	string GetGenre()
	{
		return m_mGenre;
	}
	
	/**
	*	@brief  �Ҽӻ翡 ���� ������ ��´�.
	*	@pre	�Ҽӻ簡 �������ִ�.
	*	@post	none.
	*	@return	�Ҽӻ��
	*/
	string GetCompany()
	{
		return m_mCompany;
	}

	/**
	*	@brief  ��ǥ�����Ͽ� ���� ������ ��´�.
	*	@pre	��ǥ�������� �������ִ�.
	*	@post	none.
	*	@return	��ǥ������
	*/
	string GetMade()
	{
		return m_mMade;
	}

	/**
	*	@brief  ����ð��� ���� ������ ��´�.
	*	@pre	����ð��� �������ִ�.
	*	@post	none.
	*	@return	����ð�
	*/
	int GetLong()
	{
		return m_mLong;
	}

	/**
	*	@brief  ���Ƚ���� ���� ������ ��´�.
	*	@pre	���Ƚ���� �������ִ�.
	*	@post	none.
	*	@return	���Ƚ��
	*/
	int GetNumber()
	{
		return m_mNumber;
	}

	/**
	*	@brief  �Ǻ��� ���� ������ ��´�.
	*	@pre	�Ǻ��� �������ִ�.
	*	@post	none.
	*	@return	�Ǻ�
	*/
	string GetNote()
	{
		return m_mNote;
	}

	/**
	*	@brief	���ǹ�ȣ�� ���Ѵ�.
	*	@pre	none.
	*	@post	���ǹ�ȣ�� ��������.
	*	@param	inID	Music ID.
	*/
	void SetID(int inID)
	{
		m_mID = inID;
	}

	/**
	*	@brief	���Ǹ��� ���Ѵ�.
	*	@pre	none.
	*	@post	���Ǹ��� ��������.
	*	@param	inName Music name.
	*/
	void SetName(string inName)
	{
		m_mName = inName;
	}

	/**
	*	@brief	�������� ���Ѵ�.
	*	@pre	none.
	*	@post	�������� ��������.
	*	@param	inArtist Music Artist.
	*/
	void SetArtist(string inArtist)
	{
		m_mArtist = inArtist;
	}
	
	/**
	*	@brief	�ٹ����� ���Ѵ�.
	*	@pre	none.
	*	@post	�ٹ����� ��������.
	*	@param	inAlbum	Music Album.
	*/
	void SetAlbum(string inAlbum)
	{
		m_mAlbum = inAlbum;
	}

	/**
	*	@brief	�帣���� ���Ѵ�.
	*	@pre	none.
	*	@post	�帣���� ��������.
	*	@param	inGenre	Music Genre.
	*/
	void SetGenre(string inGenre)
	{
		m_mGenre = inGenre;
	}
	
	/**
	*	@brief	���縦 ���Ѵ�.
	*	@pre	none.
	*	@post	���簡 ��������.
	*	@param	inLyrics Music lyrics.
	*/
	void SetLyrics(string inLyrics)
	{
		m_mLyrics = inLyrics;
	}

	/**
	*	@brief	���ǹ�ȣ�� ���Ѵ�.
	*	@pre	none.
	*	@post	���ǹ�ȣ�� ��������.
	*	@param	inID	Music ID.
	*/
	void SetCompany(string inCompany)
	{
		m_mCompany = inCompany;
	}

	/**
	*	@brief	���ǹ�ȣ�� ���Ѵ�.
	*	@pre	none.
	*	@post	���ǹ�ȣ�� ��������.
	*	@param	inID	Music ID.
	*/
	void SetMade(string inMade)
	{
		m_mMade = inMade;
	}

	/**
	*	@brief	���ǹ�ȣ�� ���Ѵ�.
	*	@pre	none.
	*	@post	���ǹ�ȣ�� ��������.
	*	@param	inID	Music ID.
	*/
	void SetLong(int inLong)
	{
		m_mLong = inLong;
	}

	/**
	*	@brief	���ǹ�ȣ�� ���Ѵ�.
	*	@pre	none.
	*	@post	���ǹ�ȣ�� ��������.
	*	@param	inID	Music ID.
	*/
	void SetNumber(int inNumber)
	{
		m_mNumber = inNumber;
	}

	/**
	*	@brief	���Ǹ��� ���Ѵ�.
	*	@pre	none.
	*	@post	���Ǹ��� ��������.
	*	@param	inName Music name.
	*/
	void SetNote(string inNote)
	{
		m_mNote = inNote;
	}

	/**
	*	@brief	���ǿ� ���� ������ �����Ѵ�.
	*	@pre	none.
	*	@post	���ǿ� ���� ������ �����ȴ�.
	*	@param	inID		���ǹ�ȣ
	*	@param	inName		���Ǹ�
	*	@param	inArtist	������
	*	@param	inCompany	�Ҽӻ��
	*	@param	inMade		��ǥ������
	*	@param	inLong		����ð�
		@param	inAlbum		�ٹ���
	*	@param	inGenre		�帣��
	*	@param	inNote		�Ǻ�
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
	*	@brief	������ ���ǹ�ȣ�� ȭ�鿡 ����.
	*	@pre	������ ���ǹ�ȣ�� �������ִ�.
	*	@post	������ ���ǹ�ȣ�� ��µȴ�.
	*/
	void DisplayIDOnScreen()
	{
		cout << "\tID : " << m_mID << endl;
	};

	/**
	*	@brief	������ ���Ǹ��� ȭ�鿡 ����.
	*	@pre	������ ���Ǹ� �������ִ�.
	*	@post	������ ���Ǹ��� ��µȴ�.
	*/
	void DisplayNameOnScreen() 
	{
		cout << "\t���� : " << m_mName << endl; 
	};

	/**
	*	@brief	������ �������� ȭ�鿡 ����.
	*	@pre	������ �������� �������ִ�.
	*	@post	������ �������� ��µȴ�.
	*/
	void DisplayArtistOnScreen() 
	{
		cout << "\t���� : " << m_mArtist << endl; 
	};

	/**
	*	@brief	������ �ٹ����� ȭ�鿡 ����.
	*	@pre	������ �ٹ��� �������ִ�.
	*	@post	������ �ٹ��� ��µȴ�.
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "\t�ٹ� : " << m_mAlbum << endl;
	};

	/**
	*	@brief	������ �帣���� ȭ�鿡 ����.
	*	@pre	������ �帣�� �������ִ�.
	*	@post	������ �帣�� ��µȴ�.
	*/
	void DisplayGenreOnScreen()
	{
		cout << "\t�帣 : " << m_mGenre << endl;
	};

	/**
	*	@brief	������ ���縦 ȭ�鿡 ����.
	*	@pre	������ ���簡 �������ִ�.
	*	@post	������ ���簡 ��µȴ�.
	*/
	void DisplayLyricsOnScreen()
	{
		string temp;
		int rep = 0;
		cout << "\t���� : " << m_mLyrics << endl;
	};

	/**
	*	@brief	������ ���縦 ȭ�鿡 ����.
	*	@pre	������ ���簡 �������ִ�.
	*	@post	������ ���簡 ��µȴ�.
	*/
	void DisplayCompanyOnScreen()
	{
		cout << "\t�Ҽӻ� : " << m_mCompany << endl;
	};

	/**
	*	@brief	������ ���縦 ȭ�鿡 ����.
	*	@pre	������ ���簡 �������ִ�.
	*	@post	������ ���簡 ��µȴ�.
	*/
	void DisplayMadeOnScreen()
	{
		cout << "\t��ǥ������ : " << m_mMade << endl;
	};

	/**
	*	@brief	������ ���縦 ȭ�鿡 ����.
	*	@pre	������ ���簡 �������ִ�.
	*	@post	������ ���簡 ��µȴ�.
	*/
	void DisplayLongsOnScreen()
	{
		cout << "\t����ð� : " << m_mLong << endl;
	};

	/**
	*	@brief	������ ���縦 ȭ�鿡 ����.
	*	@pre	������ ���簡 �������ִ�.
	*	@post	������ ���簡 ��µȴ�.
	*/
	void DisplayNoteOnScreen()
	{
		cout << "\t�Ǻ� : " << m_mNote << endl;
	};

	/**
	*	@brief	������ ������ ȭ�鿡 ����.
	*	@pre	������ ������ �������ִ�.
	*	@post	������ ������ ��µȴ�.
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
	*	@brief	������ ��ȣ�� �ڵ����� ���Ѵ�.
	*	@pre	����.
	*	@post	������ ��ȣ�� ��������.
	*/
	void SetIDAuto();

	/**
	*	@brief	������ ��ȣ�� Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	������ ��ȣ�� ��������.
	*/
	void SetIDFromKB();

	/**
	*	@brief	������ ���Ǹ��� Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	������ ���Ǹ��� ��������.
	*/
	void SetNameFromKB();

	/**
	*	@brief	������ ������ Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	������ ������ ��������.
	*/
	void SetArtistFromKB();

	/**
	*	@brief	������ �ٹ��� Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	������ �ٹ��� ��������.
	*/
	void SetAlbumFromKB();

	/**
	*	@brief	������ �帣�� Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	������ �帣�� ��������.
	*/
	void SetGenreFromKB();

	/**
	*	@brief	������ ���縦 Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	������ ���簡 ��������.
	*/
	void SetLyricsFromKB();

	/**
	*	@brief	������ �Ǻ��� Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	������ �Ǻ��� ��������.
	*/
	void SetNoteFromKB();

	/**
	*	@brief	������ �Ҽӻ縦 Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	������ �Ҽӻ簡 ��������.
	*/
	void SetCompanyFromKB();

	/**
	*	@brief	������ ��ǥ������� Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	������ ��ǥ������� ��������.
	*/
	void SetMadeFromKB();

	/**
	*	@brief	������ ����ð��� Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	������ ����ð��� ��������.
	*/
	void SetLongFromKB();

	/**
	*	@brief	������ ���Ƚ���� Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	������ ���Ƚ���� ��������.
	*/
	void SetNumberFromKB();
	
	/**
	*	@brief	������ ������ Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	������ ������ ��������.
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
	*	@return	������ ID�� ������ ID�� ������ true, �ٸ��� false�� ��ȯ�Ѵ�.
	*/
	bool operator == (const MusicType &obj);

	/**
	*	Compare two Musictypes.
	*	@brief	Compare two Music types by item id.
	*	@pre	two Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	������ ID�� �����ʺ��� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator > (const MusicType &obj);

	/**
	*	Compare two Musictypes.
	*	@brief	Compare two Music types by item id.
	*	@pre	two Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	�������� ID�� ���ʺ��� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator < (const MusicType &obj);

	/**
	*	Compare two Musictypes.
	*	@brief	Compare two Music types by item id.
	*	@pre	two Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	������ ID�� �����ʺ��� ũ�ų� ������ true, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator >= (const MusicType &obj);

	/**
	*	Compare two Musictypes.
	*	@brief	Compare two Music types by item id.
	*	@pre	two Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	�������� ID�� ���ʺ��� ũ�ų� ������ true, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator <= (const MusicType &obj);


	
protected:

	int m_mID;			///< ���ǹ�ȣ
	string m_mName;		///< ���Ǹ�
	string m_mArtist;	///< ����
	string m_mCompany;	///< �Ҽӻ�
	string m_mMade;		///< ��ǥ������
	string m_mAlbum;	///< �ٹ�
	string m_mGenre;	///< �帣
	int m_mLong;		///< ����ð�
	int m_mNumber;		///< ���Ƚ��
	string m_mNote;		///< �Ǻ�
	string m_mLyrics;	///< ����
};

#endif	// _MUSICTYPE_H
