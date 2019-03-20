
#ifndef _ALBUMTYPE_H
#define _ALBUMTYPE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
*	@ �ٹ� ���� Ŭ����
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
	*	@brief  ���ǹ�ȣ�� ������ ��´�.
	*	@pre	���ǹ�ȣ�� �������ִ�.
	*	@post	����.
	*	@return	���ǹ�ȣ
	*/
	int GetID()
	{
		return m_aID;
	}

	/**
	*	@brief  �ٹ����� ������ ��´�.
	*	@pre	�ٹ����� �������ִ�.
	*	@post	none.
	*	@return	�ٹ���
	*/
	string GetAlbumName()
	{
		return m_aAlbum;
	}


	/**
	*	@brief  ������ ������ ��´�.
	*	@pre	������ �������ִ�.
	*	@post	none.
	*	@return	����
	*/
	string GetArtistName()
	{
		return m_aArtist;
	}


	/**
	*	@brief  �Ҽӻ��� ������ ��´�.
	*	@pre	�Ҽӻ簡 �������ִ�.
	*	@post	none.
	*	@return	�Ҽӻ�
	*/
	string GetACompanyName()
	{
		return m_aCompany;
	}

	/**
	*	@brief	���ǹ�ȣ�� ���Ѵ�.
	*	@pre	none.
	*	@post	���ǹ�ȣ�� ��������.
	*	@param	inID Music ID
	*/
	void SetID(int inID)
	{
		m_aID = inID;
	}

	/**
	*	@brief	�ٹ����� ���Ѵ�.
	*	@pre	none.
	*	@post	�ٹ����� ��������.
	*	@param	inName �ٹ���.
	*/
	void SetAlbumName(string inName)
	{
		m_aAlbum = inName;
	}

	/**
	*	@brief	�������� ���Ѵ�.
	*	@pre	none.
	*	@post	�������� ��������.
	*	@param	inName ������.
	*/
	void SetArtistName(string inArtist)
	{
		m_aArtist = inArtist;
	}

	/**
	*	@brief	�Ҽӻ���� ���Ѵ�.
	*	@pre	none.
	*	@post	�Ҽӻ���� ��������.
	*	@param	inName �Ҽӻ��.
	*/
	void SetCompanyName(string inCompany)
	{
		m_aCompany = inCompany;
	}

	/**
	*	@brief	�ٹ��� ���õ� ������ ���Ѵ�.
	*	@pre	none.
	*	@post	�ٹ��� ���õ� ������ ��������.
	*	@param	inID, inName, inArtist, in Company  ���ǹ�ȣ, �ٹ���, ������, �Ҽӻ��
	*/
	void SetRecord(int inID, string inName, string inArtist, string inCompany)
	{
		SetID(inID);
		SetAlbumName(inName);
		SetArtistName(inArtist);
		SetCompanyName(inCompany);
	}


	/**
	*	@brief	�ٹ��� ������ ȭ�鿡 ����.
	*	@pre	�ٹ��� ������ �������ִ�.
	*	@post	�ٹ��� ������ ��µȴ�.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayAlbumOnScreen();
		DisplayArtistOnScreen();
		DisplayCompanyOnScreen();
	};

	/**
	*	@brief	������ �ٹ����� ȭ�鿡 ����.
	*	@pre	������ �ٹ��� �������ִ�.
	*	@post	������ �ٹ����� ��µȴ�.
	*/
	void DisplayAlbumOnScreen()
	{
		cout << "\t�ٹ� : " << m_aAlbum << endl;
	};

	/**
	*	@brief	������ �������� ȭ�鿡 ����.
	*	@pre	������ �������� �������ִ�.
	*	@post	������ �������� ��µȴ�.
	*/
	void DisplayArtistOnScreen()
	{
		cout << "\t���� : " << m_aArtist << endl;
	};

	/**
	*	@brief	������ �Ҽӻ���� ȭ�鿡 ����.
	*	@pre	������ �Ҽӻ���� �������ִ�.
	*	@post	������ �Ҽӻ���� ��µȴ�.
	*/
	void DisplayCompanyOnScreen()
	{
		cout << "\t�Ҽӻ� : " << m_aCompany << endl;
	};

	/**
	*	Compare two AlbumTypes.
	*	@brief	Compare two Simple Music types by item id.
	*	@pre	two Simple Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	������ ID�� ������ ID�� ������ true, �ٸ��� false�� ��ȯ�Ѵ�.
	*/
	bool operator== (const AlbumType &obj);

	/**
	*	Compare two AlbumTypes.
	*	@brief	Compare two Simple Music types by item id.
	*	@pre	two Simple Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	������ ID�� �����ʺ��� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator> (const AlbumType &obj);

	/**
	*	Compare two AlbumTypes.
	*	@brief	Compare two Simple Music types by item id.
	*	@pre	two Simple Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	�������� ID�� ���ʺ��� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator< (const AlbumType &obj);

	/**
	*	Compare two AlbumTypes.
	*	@brief	Compare two Simple Music types by item id.
	*	@pre	two Simple Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	������ ID�� �����ʺ��� ũ�ų� ������ true, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator>= (const AlbumType &obj);

	/**
	*	Compare two AlbumTypes.
	*	@brief	Compare two Simple Music types by item id.
	*	@pre	two Simple Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	�������� ID�� ���ʺ��� ũ�ų� ������ true, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator<= (const AlbumType &obj);

	/**
	*	Display SimpleMusictypes.
	*	@brief	��� ������
	*	@pre	�ٹ�, ����, �Ҽӻ簡 ������ �ִ�.
	*	@post	�ٹ�, ����, �Ҽӻ縦 ����Ѵ�.
	*	@return	out
	*/
	friend ostream &operator<< (ostream& out, const AlbumType &obj)
	{
		out << "\t�ٹ� : " << obj.m_aAlbum << "\n" << "\t���� : " << obj.m_aArtist << '\n'
			<< "\t�Ҽӻ� : " << obj.m_aCompany << endl;
		return out;
	}

protected:

	int m_aID;				/// ���� ��ȣ
	string m_aAlbum;		/// ���� �ٹ�
	string m_aCompany;		/// ���� �Ҽӻ�
	string m_aArtist;		/// ���� �̸�

};

#endif	// _ALBUMTYPE_H //
