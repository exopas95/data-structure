
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
	*	@brief  곡명의 정보를 얻는다.
	*	@pre	곡명이 정해져있다.
	*	@post	none.
	*	@return	곡명
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
	*	@brief	곡명을 정한다.
	*	@pre	none.
	*	@post	곡명이 정해진다.
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
	*	@brief	음악의 정보를 화면에 띄운다.
	*	@pre	음악의 정보가 정해져있다.
	*	@post	음악의 정보가 출력된다.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayIDOnScreen();
		DisplayNameOnScreen();
	};

	/**
	*	@brief	음악의 곡번호를 화면에 띄운다.
	*	@pre	음악의 곡번호가 정해져있다.
	*	@post	음악의 곡번호가 출력된다.
	*/
	void DisplayIDOnScreen()
	{
		cout << "\tID : " << m_sID << endl;
	};

	/**
	*	@brief	음악의 곡명을 화면에 띄운다.
	*	@pre	음악의 곡명 정해져있다.
	*	@post	음악의 곡명이 출력된다.
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
