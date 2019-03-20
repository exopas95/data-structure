
#ifndef _SIMPLEMUSICTYPE_H
#define _SIMPLEMUSICTYPE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
*	@ brief ������ ���� ���� Ŭ����
*/
class SimpleMusicType
{
public:
	/**
	*	default constructor.
	*/
	SimpleMusicType()
	{
		m_sID = 0;
		m_sName = "";
	}

	/**
	*	destructor.
	*/
	~SimpleMusicType() {}

	/**
	*	@brief  ���ǹ�ȣ�� ������ ��´�.
	*	@pre	���ǹ�ȣ�� �������ִ�.
	*	@post	none.
	*	@return	���ǹ�ȣ
	*/
	int GetID()
	{
		return m_sID;
	}

	/**
	*	@brief  ���Ǹ��� ������ ��´�.
	*	@pre	���Ǹ��� �������ִ�.
	*	@post	none.
	*	@return	���Ǹ�
	*/
	string GetName()
	{
		return m_sName;
	}

	/**
	*	@brief	���ǹ�ȣ�� ���Ѵ�.
	*	@pre	none.
	*	@post	���ǹ�ȣ�� ��������.
	*	@param	inID Music ID
	*/
	void SetID(int inID)
	{
		m_sID = inID;
	}

	/**
	*	@brief	���Ǹ��� ���Ѵ�.
	*	@pre	none.
	*	@post	���Ǹ��� ��������.
	*	@param	inName Music name.
	*/
	void SetName(string inName)
	{
		m_sName = inName;
	}

	/**
	*	@brief	������ ������ ������ ���Ѵ�.
	*	@pre	none.
	*	@post	������ ������ ������ ��������.
	*	@param	inID, inName = Music ID, Music name.
	*/
	void SetRecord(int inID, string inName)
	{
		SetID(inID);
		SetName(inName);
	}


	/**
	*	@brief	������ ������ ȭ�鿡 ����.
	*	@pre	������ ������ �������ִ�.
	*	@post	������ ������ ��µȴ�.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayIDOnScreen();
		DisplayNameOnScreen();
	};

	/**
	*	@brief	������ ���ǹ�ȣ�� ȭ�鿡 ����.
	*	@pre	������ ���ǹ�ȣ�� �������ִ�.
	*	@post	������ ���ǹ�ȣ�� ��µȴ�.
	*/
	void DisplayIDOnScreen()
	{
		cout << "\tID : " << m_sID << endl;
	};

	/**
	*	@brief	������ ���Ǹ��� ȭ�鿡 ����.
	*	@pre	������ ���Ǹ� �������ִ�.
	*	@post	������ ���Ǹ��� ��µȴ�.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\t���� : " << m_sName << endl;
	};

	/**
	*	Compare two SimpleMusictypes.
	*	@brief	Compare two Simple Music types by item id.
	*	@pre	two Simple Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	������ ID�� ������ ID�� ������ true, �ٸ��� false�� ��ȯ�Ѵ�.
	*/
	bool operator== (const SimpleMusicType &obj);

	/**
	*	Compare two SimpleMusictypes.
	*	@brief	Compare two Simple Music types by item id.
	*	@pre	two Simple Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	������ ID�� �����ʺ��� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator> (const SimpleMusicType &obj);

	/**
	*	Compare two SimpleMusictypes.
	*	@brief	Compare two Simple Music types by item id.
	*	@pre	two Simple Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	�������� ID�� ���ʺ��� ũ�� true, �۰ų� ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator< (const SimpleMusicType &obj);

	/**
	*	Compare two SimpleMusictypes.
	*	@brief	Compare two Simple Music types by item id.
	*	@pre	two Simple Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	������ ID�� �����ʺ��� ũ�ų� ������ true, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator>= (const SimpleMusicType &obj);

	/**
	*	Compare two SimpleMusictypes.
	*	@brief	Compare two Simple Music types by item id.
	*	@pre	two Simple Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	�������� ID�� ���ʺ��� ũ�ų� ������ true, ������ false�� ��ȯ�Ѵ�.
	*/
	bool operator<= (const SimpleMusicType &obj);

	/**
	*	Display SimpleMusictypes.
	*	@brief	��� ������
	*	@pre	ID�� ���Ǹ��� ������ �ִ�.
	*	@post	ID�� ���Ǹ��� ����Ѵ�.
	*	@return	out
	*/
	friend ostream &operator<< (ostream& out, const SimpleMusicType &obj)
	{
		out << "\t����ID : " << obj.m_sID << "\n" << "\t����: " << obj.m_sName << endl;
		return out;

	}

protected:

	int m_sID;		/// ���� ��ȣ
	string m_sName;	/// ���� �̸�

};

#endif	// _SimpleMusicType_H
