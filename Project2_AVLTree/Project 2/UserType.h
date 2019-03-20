#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "SortedLinkedList.h"
#include "PlayType.h"


/**
*	회원 클래스
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
	*	@brief	회원의 이름과 비밀면호를 변경한다.
	*	@post	회원의 이름과 비밀번호가 변경된다.
	*/
	void changeInfo();


	/**
	*	@brief	회원 ID값을 리턴한다.
	*	@pre	회원 ID값이 설정되어 있다.
	*	@return	회원 ID값
	*/
	string getId();

	/**
	*	@brief	회원의 비밀번호를 리턴한다.
	*	@pre	회원의 비밀번호가 설정되어 있다.
	*	@return	회원의 비밀번호
	*/
	string getPW();

	/**
	*	@brief	회원의 이름을 리턴한다.
	*	@pre	회원의 이름이 설정되어 있다.
	*	@return	회원의 이름
	*/
	string getName();

	/**
	*	@brief	회원의 Admin여부를 리턴한다.
	*	@pre	회원의 Admin여부가 설정되어 있다.
	*	@return	회원의 Admin여부
	*/
	int getAdmin();

	/**
	*	@brief	음악을 재생목록에 추가한다.
	*	@post	음악의 번호가 재생목록 리스트에 추가된다.
	*	@param	추가할 음악
	*/
	void addTolist(PlayType Prod);

	/**
	*	@brief	현재 재생목록을 화면에 출력한다.
	*	@post	현재 재생목록이 화면에 출력된다.
	*/
	void showPlayList();

	/**
	*	@brief	회원의 정보를 설정한다.
	*	@post	회원의 정보가 설정된다.
	*	@param	Id	회원 ID
	*	@param	pw	회원 비밀번호
	*	@param	nick	회원의 이름
	*/
	void setUser(string Id, string pw, string nick);	//회원 설정

														/**
														*	@brief	두 회원의 ID값의 대소를 비교한다.
														*	@pre	두 회원의 ID값이 설정되어있다.
														*	@param	cust	비교할 회원
														*	@return	this의 ID가 Prod의 ID보다 클때 1을 리턴한다. 아니면 0을 리턴한다.
														*/
	bool operator >(User& cust);


	/**
	*	@brief	두 회원의 ID값의 대소를 비교한다.
	*	@pre	두 회원의 ID값이 설정되어있다.
	*	@param	cust	비교할 회원
	*	@return	this의 ID가 Prod의 ID보다 작을때 1을 리턴한다. 아니면 0을 리턴한다.
	*/
	bool operator <(User& cust);

	/**
	*	@brief	두 회원의 ID값의 대소를 비교한다.
	*	@pre	두 회원의 ID값이 설정되어있다.
	*	@param	cust	비교할 회원
	*	@return	this의 ID가 Prod의 ID와 같을 때 1을 리턴한다. 아니면 0을 리턴한다.
	*/
	bool operator ==(User& cust);	//회원 번호 일치 여부 검사


									/**
									*	@brief	대입 연산자 오버로딩
									*	@pre	두 회원의 ID, 비밀번호, 이름이 설정되어 있다.
									*	@param	cust	비교할 회원
									*	@return	this의 ID, 비밀번호, 이름을 리턴한다.
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
	*	@brief	재생목록을 가져온다.
	*	@pre	재생목록이 정해져 있다.
	*	@return	재생목록의 정보
	*/
	SortedLinkedList<PlayType>* getPlayMusicList()
	{
		return &PlayList;
	}

	/**
	*	@brief	회원정보를 출력한다.
	*	@pre	회원정보가 정해져 있다.
	*/
	void DisplayRecordOnScreen()
	{
		cout << "\t회원 ID : " << id << endl;
		cout << "\t회원 비밀번호 : " << password << endl;
		cout << "\t회원 이름 : " << name << endl;
		cout << "\t관리자 여부 : " << admin << endl;
	};

private:
	string id;								//회원 ID
	string password;						//회원 비밀번호
	string name;							//회원 이름
	int admin;								//관리자 여부.
	SortedLinkedList<PlayType> PlayList;	//재생목록
};

