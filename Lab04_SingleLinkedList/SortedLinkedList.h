#ifndef _SORTEDLINKED_LIST_H
#define _SORTEDLINKED_LIST_H


/**
*	@ brief Structure for NodeType to use in Linked structure.
*/
template <typename T>
struct NodeType
{
	T data;	///< A data for each node.
	NodeType* next;	///< A node pointer to point succeed node.
};


/**
*	@ brief Sorted Linked list class for managing items.
*/
template <typename T>
class SortedLinkedList
{
public:
	/**
	*	default constructor.
	*/
	SortedLinkedList();

	/**
	*	destructor.
	*/
	~SortedLinkedList();

	/**
	*	@brief	Initialize list to empty state.
	*	@pre	None
	*	@post	List is empty.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get number of elements in the list.
	*	@pre	None.
	*	@post	Function value = number of elements in list.
	*	@return	Number of elements in this list.
	*/
	int GetLength() const;

	/**
	*	@brief	Add music into this list.
	*	@pre	List is not full. item is not in list.
	*	@post	music is inserted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Add(T item);

	/**
	*	@brief	Retrieve list element whose key matches music's key (if present).
	*	@pre	Key member of music is initialized.
	*	@post	If there is an element whose key matches with music's key then the element's record is copied to the item.
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	int Get(T& item);

	/**
	*	@brief	Retrieve address of the list element whose key matches music's key (if present).
	*	@pre	Key member of music is initialized.
	*	@post	If there is an element whose key matches with music's key then the element's record is copied to the item.
	*	@return	adress of the list if any element's primary key matches with music's, otherwise NULL.
	*/
	T* GetPoint(T& data);

	/**
	*	@brief	Initialize current pointer for an iteration through the list.
	*	@pre	None.
	*	@post	current pointer is prior to list. current pointer has been initialized.
	*/
	void ResetList();

	/**
	*	@brief	Get the next element in list.
	*	@pre	current pointer is defined. Element at current pointer is not last in list.
	*	@post	current pointer is updated to next position. item is a copy of element at current pointer.
	*/
	void GetNextItem(T& item);

	/**
	*	@brief	Music�� ��ġ�ϴ� id�� ���� ���ڵ带 ����.
	*	@pre	�ش��ϴ� id�� ���� ���ڵ尡 �־����
	*	@post	�ش� ���ڵ尡 ���ŵ�.
	*/
	int Delete(T item);
	/**
	*	@brief	Music�� ��ġ�ϴ� id�� ���� ���ڵ带 ����.
	*	@pre	�ش��ϴ� id�� ���� ���ڵ尡 �־����
	*	@post	�ش� ���ڵ尡 Music�� �������� ���ŵ�.
	*/
	int Replace(T item);

	
	

private:
	NodeType<T>* m_pList;	///< Pointer for pointing a first node.
	NodeType<T>* m_pCurPointer;	///< Node pointer for pointing current node to use iteration.
	int m_nLength;	///< Number of node in the list.
};





// Class constructor
template <typename T>
SortedLinkedList<T>::SortedLinkedList()
{
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;
}


// Class destructor
template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
	//����Ʈ���� ��� node ����
	MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void SortedLinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	NodeType<T>* tempPtr;

	while (m_pList != NULL)
	{
		tempPtr = m_pList;
		m_pList = m_pList->next;
		delete tempPtr;
	}

	m_nLength = 0;
}


// Get number of elements in the list.
template <typename T>
int SortedLinkedList<T>::GetLength() const
{
	return m_nLength;
}


// Add music into this list.
template <typename T>
int SortedLinkedList<T>::Add(T item)
{
	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;
	bool bFound = false;

	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;

	pre = m_pList;

	// ����Ʈ �ʱ�ȭ
	ResetList();

	// list �� node �� �������� �ʴ� ���
	if (!m_nLength)
	{
		m_pList = node; //���۳�忡 �߰��ϰ��� �ϴ� ��� �߰�
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		GetNextItem(dummy); //�ϳ��̻� �����Ƿ� ������ �̵�
		while (m_pCurPointer != NULL) //���� �ƴ� ��
		{
			if (item < m_pCurPointer->data) //�������� ������ġ�� ������ �����鼭
			{
				if (m_pCurPointer == m_pList) //�������̸�
				{
					node->next = m_pList;
					m_pList = node; //���� �����Ͱ� ��带 ���ϰ� �Ѵ�.
					break;
				}
				else //�������� �ƴϸ�
				{
					node->next = m_pCurPointer;
					pre->next = node; //���������� ���� �����Ͱ� ���� ���ϰ� �Ѵ�.
					break;
				}
			}
			else //�������� ������ġ���� ũ�� ������ �� ���� �߰��ؾ��Ѵ�.
			{
				if (m_pCurPointer->next == NULL) //���� �������̸�
				{
					node->next = m_pCurPointer->next; //����� �������� ���������� NULL�̴�
					m_pCurPointer->next = node; //���� �������� ������ �߰����� ����Ű�� �Ѵ�.
					break;
				}
				else
				{
					pre = m_pCurPointer; //�������� �������
					GetNextItem(dummy); //�������ȣ��
				}
			}
		}
	}
	m_nLength++; //�߰��� ����̹Ƿ� ���� �߰�
	return 1;
}


// Retrieve list element whose key matches music's key (if present).
template <typename T>
int SortedLinkedList<T>::Get(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}

	if (found)
		return 1;
	else
		return 0;
}

// Retrieve list element's address whose key matches music's key (if present).
template <typename T>
T* SortedLinkedList<T>::GetPoint(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}

	if (found)
		return &location->data;
	else
		return NULL;
}


// Initializes current pointer for an iteration through the list.
template <typename T>
void SortedLinkedList<T>::ResetList()
{
	// current pointer �ʱ�ȭ
	m_pCurPointer = NULL;
}


// Gets the next element in list.
template <typename T>
void SortedLinkedList<T>::GetNextItem(T& item)
{
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;

	//item �� current position �� info �� ����
	item = m_pCurPointer->data;
}

//���ϴ� ��ġ�� �ڷḦ �����ϴ� �޼ҵ�, ���� �ڷ�� 0�� ����Ѵ�.
template <typename T>
int SortedLinkedList<T>::Delete(T item)
{
	NodeType<T> *pre;
	NodeType<T> *toDel;
	ResetList();
	T tmp;
	bool found = false;

	if (Get(item) == 0)	//�ش��ϴ� ���� ������, 0������ ����
		return 0;

	while (1)
	{
		pre = m_pCurPointer;
		GetNextItem(tmp);
		if (tmp == item)		//id���� ��ġ
		{
			if (pre == NULL) //�����ؾ��� ��尡 ��ó���϶�
			{
				toDel = m_pList;	//��� �Űܵΰ� ����
				m_pList = m_pList->next;	//��ó���� �ι�°�ιٲ�
				delete toDel;
				found = true;
				break;
			}
			else
			{
				toDel = m_pCurPointer;
				pre->next = m_pCurPointer->next;	//�� �����Ϳ� ���������͸� ����
				delete toDel;
				found = true;
				break;
			}
		}
		if (m_pCurPointer->next == NULL)	//�Ǹ�����, ������ �ٵ�������
			break;
	}
	m_nLength--;
	if (found)
		return 1;
	else
		return 0;

}

//�ش��ϴ� ��带 �������ְ� ���� ��� 0�� ���
template <typename T>
int SortedLinkedList<T>::Replace(T item)
{
	NodeType<T> *pre;
	ResetList();
	T isthere = item;
	T tmp;
	bool found = false;
	//Get(T& item)�� pass by reference������ �����Ϳְ�߻�
	if (Get(isthere) == 0)	//�ش��ϴ� ���� ������, 0������ ����
		return 0;

	while (1)
	{
		pre = m_pCurPointer;
		GetNextItem(tmp);
		if (tmp == item)			//'=='�����ڸ� id���� ���� �����ε�����. 	
		{
			m_pCurPointer->data = item;	//id���� ������ �����͸� ��ü
			found = true;
			break;
		}
		if (m_pCurPointer->next == NULL)	//�Ǹ�����
		{
			found = true;
			break;
		}
	}
	if (found)
		return 1;
	else
		return 0;
}


#endif	// SORTEDLINKED_LIST