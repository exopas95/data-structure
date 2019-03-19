
#ifndef _SIMPLEMUSICTYPE_H
#define _SIMPLEMUSICTYPE_H

#include <iostream>
#include <fstream>
#include <string>



using namespace std;


/**
*	item information class.
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

	// complete operation overloadings...
	bool operator== (const SimpleMusicType &obj);

	bool operator> (const SimpleMusicType &obj);

	bool operator< (const SimpleMusicType &obj);

	bool operator>= (const SimpleMusicType &obj);

	bool operator<= (const SimpleMusicType &obj);

	friend ostream &operator<< (ostream& out, const SimpleMusicType &obj)
	{
		out << "\tID : " << obj.m_sID << "\n" << "\tName : " << obj.m_sName << endl;
		return out;

	}

protected:

	int m_sID;
	string m_sName;

};

#endif	// _SimpleMusicType_H
