#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "SortedLinkedList.h"
#include "PlayType.h"


/**
*	ȸ�� Ŭ����
*/

class User
{
public:
	/**
	*	@brief	Constructor
	*/
	User()
	{
		id = "exopas";
		password = "jini2568";
		admin = 2568;
	}

	/**
	*	@brief	Destructor
	*/
	~User(void);


	/**
	*	@brief	ȸ���� �̸��� ��и�ȣ�� �����Ѵ�.
	*	@post	ȸ���� �̸��� ��й�ȣ�� ����ȴ�.
	*/
	void changeInfo();


	/**
	*	@brief	ȸ�� ID���� �����Ѵ�.
	*	@pre	ȸ�� ID���� �����Ǿ� �ִ�.
	*	@return	ȸ�� ID��
	*/
	string getId();

	/**
	*	@brief	ȸ���� ��й�ȣ�� �����Ѵ�.
	*	@pre	ȸ���� ��й�ȣ�� �����Ǿ� �ִ�.
	*	@return	ȸ���� ��й�ȣ
	*/
	string getPW();

	/**
	*	@brief	ȸ���� �̸��� �����Ѵ�.
	*	@pre	ȸ���� �̸��� �����Ǿ� �ִ�.
	*	@return	ȸ���� �̸�
	*/
	string getName();

	/**
	*	@brief	ȸ���� Admin���θ� �����Ѵ�.
	*	@pre	ȸ���� Admin���ΰ� �����Ǿ� �ִ�.
	*	@return	ȸ���� Admin����
	*/
	int getAdmin();

	/**
	*	@brief	������ �����Ͽ� �߰��Ѵ�.
	*	@post	������ ��ȣ�� ������ ����Ʈ�� �߰��ȴ�.
	*	@param	�߰��� ����
	*/
	void addTolist(PlayType Prod);

	/**
	*	@brief	���� �������� ȭ�鿡 ����Ѵ�.
	*	@post	���� �������� ȭ�鿡 ��µȴ�.
	*/
	void showPlayList();

	/**
	*	@brief	ȸ���� ������ �����Ѵ�.
	*	@post	ȸ���� ������ �����ȴ�.
	*	@param	Id	ȸ�� ID
	*	@param	pw	ȸ�� ��й�ȣ
	*	@param	nick	ȸ���� �̸�
	*/
	void setUser(string Id, string pw, string nick);	//ȸ�� ����

														/**
														*	@brief	�� ȸ���� ID���� ��Ҹ� ���Ѵ�.
														*	@pre	�� ȸ���� ID���� �����Ǿ��ִ�.
														*	@param	cust	���� ȸ��
														*	@return	this�� ID�� Prod�� ID���� Ŭ�� 1�� �����Ѵ�. �ƴϸ� 0�� �����Ѵ�.
														*/
	bool operator >(User& cust);


	/**
	*	@brief	�� ȸ���� ID���� ��Ҹ� ���Ѵ�.
	*	@pre	�� ȸ���� ID���� �����Ǿ��ִ�.
	*	@param	cust	���� ȸ��
	*	@return	this�� ID�� Prod�� ID���� ������ 1�� �����Ѵ�. �ƴϸ� 0�� �����Ѵ�.
	*/
	bool operator <(User& cust);

	/**
	*	@brief	�� ȸ���� ID���� ��Ҹ� ���Ѵ�.
	*	@pre	�� ȸ���� ID���� �����Ǿ��ִ�.
	*	@param	cust	���� ȸ��
	*	@return	this�� ID�� Prod�� ID�� ���� �� 1�� �����Ѵ�. �ƴϸ� 0�� �����Ѵ�.
	*/
	bool operator ==(User& cust);	//ȸ�� ��ȣ ��ġ ���� �˻�


									/**
									*	@brief	���� ������ �����ε�
									*	@pre	�� ȸ���� ID, ��й�ȣ, �̸��� �����Ǿ� �ִ�.
									*	@param	cust	���� ȸ��
									*	@return	this�� ID, ��й�ȣ, �̸��� �����Ѵ�.
									*/
	User& operator= (User &obj)
	{
		this->id = obj.id;
		this->password = obj.password;
		this->name = obj.name;

		SortedLinkedList<PlayType>* list = obj.getPlayMusicList();
		PlayList = *list;

		return *this;
	}

	/**
	*	@brief	�������� �����´�.
	*	@pre	�������� ������ �ִ�.
	*	@return	�������� ����
	*/
	SortedLinkedList<PlayType>* getPlayMusicList()
	{
		return &PlayList;
	}

	/**
	*	@brief	ȸ�������� ����Ѵ�.
	*	@pre	ȸ�������� ������ �ִ�.
	*/
	void DisplayRecordOnScreen()
	{
		cout << "\tȸ�� ID : " << id << endl;
		cout << "\tȸ�� ��й�ȣ : " << password << endl;
		cout << "\tȸ�� �̸� : " << name << endl;
		cout << "\t������ ���� : " << admin << endl;
	};

private:
	string id;								//ȸ�� ID
	string password;						//ȸ�� ��й�ȣ
	string name;							//ȸ�� �̸�
	int admin;								//������ ����.
	SortedLinkedList<PlayType> PlayList;	//������
};

