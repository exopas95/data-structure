
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
	*	@brief  곡번호의 정보를 얻는다.
	*	@pre	곡번호가 정해져있다.
	*	@post	none.
	*	@return	곡번호
	*/
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

	/**
	*	@brief	곡번호를 정한다.
	*	@pre	none.
	*	@post	곡번호가 정해진다.
	*	@param	inID Music ID
	*/
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

	/**
	*	@brief	음악의 간단한 정보를 정한다.
	*	@pre	none.
	*	@post	음악의 간단한 정보가 정해진다.
	*	@param	inID, inName = Music ID, Music name.
	*/
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

	/**
	*	Compare two SimpleMusictypes.
	*	@brief	Compare two Simple Music types by item id.
	*	@pre	two Simple Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	왼쪽의 ID와 오른쪽 ID가 같으면 true, 다르면 false를 반환한다.
	*/
	bool operator== (const SimpleMusicType &obj);

	/**
	*	Compare two SimpleMusictypes.
	*	@brief	Compare two Simple Music types by item id.
	*	@pre	two Simple Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	왼쪽의 ID가 오른쪽보다 크면 true, 작거나 같으면 false를 반환한다.
	*/
	bool operator> (const SimpleMusicType &obj);

	/**
	*	Compare two SimpleMusictypes.
	*	@brief	Compare two Simple Music types by item id.
	*	@pre	two Simple Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	오른쪽의 ID가 왼쪽보다 크면 true, 작거나 같으면 false를 반환한다.
	*/
	bool operator< (const SimpleMusicType &obj);

	/**
	*	Compare two SimpleMusictypes.
	*	@brief	Compare two Simple Music types by item id.
	*	@pre	two Simple Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	왼쪽의 ID가 오른쪽보다 크거나 같으면 true, 작으면 false를 반환한다.
	*/
	bool operator>= (const SimpleMusicType &obj);

	/**
	*	Compare two SimpleMusictypes.
	*	@brief	Compare two Simple Music types by item id.
	*	@pre	two Simple Music types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	오른쪽의 ID가 왼쪽보다 크거나 같으면 true, 작으면 false를 반환한다.
	*/
	bool operator<= (const SimpleMusicType &obj);

	// 출력 연산자 오버로딩
	friend ostream &operator<< (ostream& out, const SimpleMusicType &obj)
	{
		out << "\tID : " << obj.m_sID << "\n" << "\tName : " << obj.m_sName << endl;
		return out;

	}

protected:

	int m_sID;		/// 곡 번호
	string m_sName;	/// 곡 이름

};

#endif	// _SimpleMusicType_H
