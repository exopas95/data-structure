#pragma once
#include <iostream>
#include "DoublySortedLinkedList.h"

using namespace std;

//Application과 GenreType이 접근 가능한 BaseClass
class BaseClass 
{
protected:
	static 	DoublySortedLinkedList<MusicType> m_List;				///< 음악 리스트;

public:

};