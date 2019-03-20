
#ifndef _MostPlayedMusicType_H
#define _MostPlayedMusicType_H

#include <iostream>
#include <string>

using namespace std;


/**
*	@ brief ������ ���� Ŭ����
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


	//���� ������ �����ε� ����
	MostPlayedMusicType& operator= (const MostPlayedMusicType &obj)
	{
		this->Most_ID = obj.Most_ID;
		this->Most_Name = obj.Most_Name;
		this->Most_Artist = obj.Most_Artist;
		this->Most_Number = obj.Most_Number;
		return *this;
	}

	/**
	*	@brief		���� ��ȣ�� ���Ѵ�.
	*	@param[in]	inMost_ID	Play id.
	*/
	void SetID(int ID)
	{
		Most_ID = ID;
	}

	/**
	*	@brief	���� ��ȣ�� �����´�.
	*	@return	���� ��ȣ
	*/
	int GetID()
	{
		return Most_ID;
	}

	/**
	*	@brief		���Ƚ���� ���Ѵ�.
	*	@param[in]	inPlayNumber	Play time.
	*/
	void SetNumber(int PlayNumber)
	{
		Most_Number = PlayNumber;
	}

	/**
	*	@brief	���Ƚ���� �����´�.
	*	@return	���Ƚ��.
	*/
	int GetNumber()
	{
		return Most_Number;
	}

	/**
	*	@brief		���� �̸��� ���Ѵ�.
	*	@param[in]	inPlayName	PlayName.
	*/
	void SetName(string inPlayName)
	{
		Most_Name = inPlayName;
	}

	/**
	*	@brief	���� �̸��� �����´�.
	*	@return	���� �̸�
	*/
	string GetName()
	{
		return Most_Name;
	}

	/**
	*	@brief	�ش� ������ �������� ���Ѵ�.
	*	@pre	none.
	*	@post	�ش� ������ �������� ��������.
	*	@param	inPlayArtist	Artist.
	*/
	void SetArtist(string inPlayArtist)
	{
		Most_Artist = inPlayArtist;
	}

	/**
	*	@brief  ������ ���� ������ ��´�.
	*	@pre	�������� �������ִ�.
	*	@post	none.
	*	@return	������
	*/
	string GetyArtist()
	{
		return Most_Artist;
	}

	/**
	*	@brief	������ ���� ���ǵ鿡 ���� ������ �Է��Ѵ�.
	*	@pre	none.
	*	@post	������ ���� ���ǵ鿡 ���� ������ �����ȴ�.
	*	@param	Most_ID			���ǹ�ȣ
	*	@param	PlayNumber		���Ƚ��
	*	@param	PlayLong		����ð�
	*	@param	inPlayName		�����̸�
	*	@param	inPlayArtist	����
	*/
	void SetInfo(int ID, string Name, std::string Artist, int Number)
	{
		SetID(ID);
		SetName(Name);
		SetArtist(Artist);
		SetNumber(Number);
	}

	/**
	*	@brief	�����Ͽ� �ִ� ������ ������ ȭ�鿡 ����.
	*	@pre	�����Ͽ� �ִ� ������ ������ ������ �ִ�.
	*	@post	�����Ͽ� �ִ� ������ ������ ��µȴ�.
	*/
	void DisplayRecordOnScreen()
	{
		cout << "\n\t���� : " << Most_Name;
		cout << "\n\t���� : " << Most_Artist;
		cout << "\n\t��� Ƚ�� : " << Most_Number;
	}

	/**
	*	@brief	�����Ͽ� �ִ� ������ ���ǹ�ȣ�� Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	�����Ͽ� �ִ� ������ ���ǹ�ȣ�� ��������.
	*/
	void SetIDFromKB();

	/**
	*	@brief	�����Ͽ� �ִ� ������ ����ð��� Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	�����Ͽ� �ִ� ������ ����ð��� ��������.
	*/
	void SetNumberFromKB();

	/**
	*	@brief	�����Ͽ� �ִ� ������ ���Ǹ��� Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	�����Ͽ� �ִ� ������ ���Ǹ��� ��������.
	*/
	void SetNameFromKB();

	/**
	*	@brief	�����Ͽ� �ִ� ������ ������ Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	�����Ͽ� �ִ� ������ ������ ��������.
	*/
	void SetArtistFromKB();

	/**
	*	@brief	�����Ͽ� �ִ� ������ ������ Ű����� �Է��Ѵ�.
	*	@pre	����.
	*	@post	�����Ͽ� �ִ� ������ ������ ��������.
	*/
	void SetRecordFromKB();

	/**
	*	Compare two MostPlayedMusicTypes.
	*	@brief	Compare two item types by Play id.
	*	@pre	two Play types should be initialized.
	*	@post	the target file is included the new Play record.
	*	@param	data	target Play for comparing.
	*	@return	������ ID�� ������ ID�� ������ true, �ٸ��� false�� ��ȯ�Ѵ�.
	*/
	bool operator == (const MostPlayedMusicType &obj);

	/**
	*	Compare two MostPlayedMusicTypes.
	*	@brief	Compare two item types by Play id.
	*	@pre	two Play types should be initialized.
	*	@post	the target file is included the new Play record.
	*	@param	data	target Play for comparing.
	*	@return	������ ID�� ������ ID���� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator > (const MostPlayedMusicType &obj);

	/**
	*	Compare two MostPlayedMusicTypes.
	*	@brief	Compare two item types by Play id.
	*	@pre	two Play types should be initialized.
	*	@post	the target file is included the new Play record.
	*	@param	data	target Play for comparing.
	*	@return	�������� ID�� ���� ID���� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator < (const MostPlayedMusicType &obj);

	/**
	*	Compare two MostPlayedMusicTypes.
	*	@brief	Compare two item types by Play id.
	*	@pre	two Play types should be initialized.
	*	@post	the target file is included the new Play record.
	*	@param	data	target Play for comparing.
	*	@return	�������� ID�� ���� ID���� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator <= (const MostPlayedMusicType &obj);

	/**
	*	Compare two MostPlayedMusicTypes.
	*	@brief	Compare two item types by Play id.
	*	@pre	two Play types should be initialized.
	*	@post	the target file is included the new Play record.
	*	@param	data	target Play for comparing.
	*	@return	�������� ID�� ���� ID���� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator >= (const MostPlayedMusicType &obj);

	/**
	*	Display SimpleMusictypes.
	*	@brief	��� ������
	*	@pre	���Ƚ��, ����, ����, ����ð��� ������ �ִ�.
	*	@post	���Ƚ��, ����, ����, ����ð��� ����Ѵ�.
	*	@return	out
	*/
	void operator<<(MostPlayedMusicType item);
	

protected:
	int Most_ID;				///< ������ ���ǹ�ȣ
	int Most_Number;			///< ��� Ƚ��
	string Most_Name;			///< ������ ���Ǹ�
	string Most_Artist;			///< ������ ����
};

#endif	// _MostPlayedMusicType_H
