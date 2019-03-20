
#ifndef _SIMPLEMUSICTYPE_H
#define _SIMPLEMUSICTYPE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
*	@ brief simple music type information class.
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
	*	@brief  ���ȣ�� ������ ��´�.
	*	@pre	���ȣ�� �������ִ�.
	*	@post	none.
	*	@return	���ȣ
	*/
	int GetID()
	{
		return m_sID;
	}

	/**
	*	@brief  ����� ������ ��´�.
	*	@pre	����� �������ִ�.
	*	@post	none.
	*	@return	���
	*/
	string GetName()
	{
		return m_sName;
	}

	/**
	*	@brief	���ȣ�� ���Ѵ�.
	*	@pre	none.
	*	@post	���ȣ�� ��������.
	*	@param	inID Music ID
	*/
	void SetID(int inID)
	{
		m_sID = inID;
	}

	/**
	*	@brief	����� ���Ѵ�.
	*	@pre	none.
	*	@post	����� ��������.
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
	*	@brief	������ ���ȣ�� ȭ�鿡 ����.
	*	@pre	������ ���ȣ�� �������ִ�.
	*	@post	������ ���ȣ�� ��µȴ�.
	*/
	void DisplayIDOnScreen()
	{
		cout << "\tID : " << m_sID << endl;
	};

	/**
	*	@brief	������ ����� ȭ�鿡 ����.
	*	@pre	������ ��� �������ִ�.
	*	@post	������ ����� ��µȴ�.
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tName : " << m_sName << endl;
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

	// ��� ������ �����ε�
	friend ostream &operator<< (ostream& out, const SimpleMusicType &obj)
	{
		out << "\tID : " << obj.m_sID << "\n" << "\tName : " << obj.m_sName << endl;
		return out;

	}

protected:

	int m_sID;		/// �� ��ȣ
	string m_sName;	/// �� �̸�

};

#endif	// _SimpleMusicType_H
