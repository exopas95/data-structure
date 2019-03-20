#pragma once
#include <iostream>
#include <fstream>
using namespace std;
/**
*	AVLƮ�����
*/
template <typename T>
struct TreeNode
{
	T data;
	TreeNode* left;
	TreeNode* right;
};
/**
*	AVLƮ��
*/
template<typename T>
class AVLTree
{
public:
	/**
	*	������,���� �ʱ�ȭ
	*/
	AVLTree();
	/**
	*	�Ҹ���,�޸� ����
	*/
	~AVLTree();
	/**
	*	���� ����� ����(������ ��ȯ)
	*/
	int GetLength();
	/**
	*	����ִ��� Ȯ��
	*/
	bool IsEmpty();
	/**
	*	��ü Ʈ������
	*/
	void RemoveAll(TreeNode<T>*& Node);
	/**
	*	�Ķ���ͷ� ���� �����͸� Ʈ���� �߰�
	*/
	void Add(T data);
	/**
	*	�Ķ���ͷ� ���� �����͸� Ʈ������ ����
	*/
	void Delete(T data);
	/**
	*	�����͸� �Ķ���ͷ� �޾� ��ġ�ϴ� �����Ͱ� �ִ��� Ȯ�� �� �����͸� ��������
	*/
	bool Find(T& data);
	/**
	*	�����͸� �Ķ���ͷ� �޾� ��ġ�ϴ� �����Ͱ� �ִ���  �帣 �̸� �񱳸� ���� Ȯ�� �� �������� �ּҰ��� ��������
	*/
	T* Get(T& data);
	/**
	*	�����͸� �Ķ���ͷ� �޾� ��ġ�ϴ� �����Ͱ� �ִ��� ID �񱳸� ���� Ȯ�� �� �������� �ּҰ��� ��������
	*/
	T* GetByID(T& data);
	/**
	*	�����͸� �Ķ���ͷ� �޾� ��ġ�ϴ� �����Ͱ� �ִ��� Ȯ�� �� �����͸� ��������
	*/
	void Replace(T data);
	/**
	*	��Ʈ�� ����
	*/
	TreeNode<T>* getroot();
	/**
	*	@brief	Tree�� node�� ��ũ���� ����Ѵ�.
	*	@pre	none
	*	@post	��ũ���� Tree�� InOrder, PreOrder, PostOrder ������� ���� ��µ�.
	*/
	void PrintTree(ostream &out);
	/**
	*	@brief	Tree�� node�� ���Ͽ� �����Ѵ�.
	*	@pre	none
	*	@post	���Ͽ� Tree�� InOrder, PreOrder, PostOrder ������� ���� ��µ�.
	*/
	void SaveTree(ofstream &fout);

private:
	/**
	*	�ƽ��Լ� �� �Ķ������ ū���� ������
	*/
	int Max(int i, int j);
	/**
	*	����� ���̸� ����, �Ķ���ͷ� ���� ����� �ִ� ���� (���� ����� �ִ� �������� �� ����)
	*/
	int getHeight(TreeNode<T>* Node);
	/**
	*	������ �������ִ��� Ȯ����, �Ķ���ͷ� ���� ����� ���� Ʈ���� ������Ʈ���� ���� ���̸� ��ȯ��
	*/
	int getBalance(TreeNode<T>* Node);

	/**
	*	Ʈ�� ���� ���
	*/
	void PrintInOrderTraversal(TreeNode<T>* root, ostream& out);

	/**
	*	Ʈ�� ���� ����
	*/
	void SaveInOrderTraversal(TreeNode<T>* root, ofstream& out);
	/**
	*	���������� �̱� �����̼��� ��
	*/
	TreeNode<T>* Rotate_LL(TreeNode<T>* parent);
	/**
	*	�������� �̱� �����̼��� ��
	*/
	TreeNode<T>* Rotate_RR(TreeNode<T>* parent);
	/**
	*	���� ���������� ��������̼��� ��
	*/
	TreeNode<T>* Rotate_LR(TreeNode<T>* parent);
	/**
	*	������ �������� ���� �����̼��� ��
	*/
	TreeNode<T>* Rotate_RL(TreeNode<T>* parent);

	/**
	*	�����Լ��� ���� ����Լ�
	*/
	TreeNode<T>* RecursiveInsert(TreeNode<T>* Node, T data);
	/**
	*	����Ʈ�� ���� ����Լ�
	*/
	TreeNode<T>* Recursivedelete(TreeNode<T>* Node, T data);
	/**
	*	������ �����ʰ� ������ ������ ������
	*/
	TreeNode<T>* MakeBalance(TreeNode<T>* Node);

	TreeNode<T>* root; // ��¥��Ʈ
	int length; // ���� (����)
};
template<typename T>
AVLTree<T>::AVLTree()
{
	root = nullptr; //ó���� ��Ʈ�� ���� �ʱ�ȭ��
	this->length = 0; // ����(����) 0���� �ʱ�ȭ
}
template<typename T>
AVLTree<T>::~AVLTree()
{
	RemoveAll(root); // �Ķ���Ϳ� ��Ʈ�� �־ Ʈ���� �� ������
}
template<typename T>
int AVLTree<T>::GetLength()
{
	return this->length;
}
template<typename T>
bool AVLTree<T>::IsEmpty()
{
	if (length == 0)
		return true;
	else
		return false;
}
template<typename T>
void AVLTree<T>::RemoveAll(TreeNode<T>*& Node)
{
	if (Node == nullptr) // ����ִٸ�
		return;
	else
	{
		RemoveAll(Node->left); // �������� ����Լ�����
		RemoveAll(Node->right); // ���������� ����Լ�����
		delete Node; // ��带 ������ ����Լ��̹Ƿ� ���������� ��������.
		Node = nullptr; // �������� ���۷����� ���� ����
	}
}
template<typename T>
void AVLTree<T>::Add(T data)
{
	if (root == nullptr) // Ʈ���� ����ִٸ�
	{
		// ������
		TreeNode<T>* temp = new TreeNode<T>;
		temp->data = data;
		temp->left = nullptr;
		temp->right = nullptr;
		root = temp; // ��Ʈ�� ����
		length++; // �����߰�
	}
	else
	{
		// Ʈ���� ��������ʴٸ� RecursiveInsert�� ��Ʈ�� �����͸� �־��ְ� ��ȯ���� ��Ʈ�� �ٲ���
		root = RecursiveInsert(root, data);
	}
}
template<typename T>
void AVLTree<T>::Delete(T data)
{
	// ��Ʈ�� �����͸� �Ķ���ͷ� �־��ְ� ������� ��Ʈ�� ����
	root = Recursivedelete(root, data);
	length--; // ���̰���
}
template<typename T>
bool AVLTree<T>::Find(T& data)
{
	TreeNode<T>* temp;// �ӽú���
	temp = root;
	while (temp != nullptr)
	{
		if (temp->data > data) // ���� ����� �����Ͱ� ã�� �����ͺ��� Ŭ ���
		{
			temp = temp->left; // �������ΰ�
		}
		else if (temp->data < data) // ���� ����� �����Ͱ� ã�� �����ͺ��� ���� ���
		{
			temp = temp->right; // ���������ΰ�
		}
		else // ã�Ҵٸ�
		{
			data = temp->data; // ����� �����͸� ����
			return true; // �������
		}
	}
	return false; // ��ã������� �޽�
}
template<typename T>
T* AVLTree<T>::Get(T& data)
{
	TreeNode<T>* temp;// �ӽú���
	temp = root;
	while (temp != nullptr)
	{
		if (temp->data > data) // ���� ����� �����Ͱ� ã�� �����ͺ��� Ŭ ���
		{
			temp = temp->left; // �������ΰ�
		}
		else if (temp->data < data) // ���� ����� �����Ͱ� ã�� �����ͺ��� ���� ���
		{
			temp = temp->right; // ���������ΰ�
		}
		else // ã�Ҵٸ�
		{
			data = temp->data; // ����� �����͸� ����
			return &temp->data; // �������
		}
	}
	return false; // ��ã������� �޽�
}

template<typename T>
T* AVLTree<T>::GetByID(T& data)
{
	TreeNode<T>* temp;// �ӽú���
	temp = root;
	while (temp != nullptr)
	{
		if (temp->data >= data) // ���� ����� �����Ͱ� ã�� �����ͺ��� Ŭ ���
		{
			temp = temp->left; // �������ΰ�
		}
		else if (temp->data <= data) // ���� ����� �����Ͱ� ã�� �����ͺ��� ���� ���
		{
			temp = temp->right; // ���������ΰ�
		}
		else // ã�Ҵٸ�
		{
			data = temp->data; // ����� �����͸� ����
			return &temp->data; // �������
		}
	}
	return false; // ��ã������� �޽�
}

template<typename T>
void AVLTree<T>::Replace(T data)
{
	TreeNode<T>* temp;// �ӽú���
	temp = root;
	temp->data = data; // ��忡 �����͸� ����
}

// Tree�� node�� ������ ������ �����
template<class T>
void AVLTree<T>::PrintTree(ostream &out)
{
	PrintInOrderTraversal(root, out);			// InOrder ������� ���
}

// Tree�� node�� ������ ������ �����
template<class T>
void AVLTree<T>::SaveTree(ofstream &fout)
{
	SaveInOrderTraversal(root, fout);			// InOrder ������� ���
}

template<typename T>
int AVLTree<T>::Max(int i, int j)
{
	return i > j ? i : j;
}
template<typename T>
int AVLTree<T>::getHeight(TreeNode<T>* Node)
{
	// ���� �� ���ִ� �������κ��� 1���������� �ö��
	int height = 0; //����
	if (Node != nullptr)
	{
		int i = getHeight(Node->left); // ����� �������� ���
		int j = getHeight(Node->right); // ����� ���������� ���
		height = Max(i, j); // ū�Ÿ� ���̿� �ְ�
	}
	return 1 + height; // ����Ʈ +1 ����
}
template<typename T>
int AVLTree<T>::getBalance(TreeNode<T>* Node)
{
	return getHeight(Node->left) - getHeight(Node->right); // ���� ���� - �����ʳ���
}
template<typename T>
TreeNode<T>* AVLTree<T>::Rotate_LL(TreeNode<T>* parent)
{
	// ���� �������� ������ִ°�� ���������� ȸ���ϰ� �з�Ʈ�� ���ϵ��� �������̵ǰ� ���ϵ尡 �θ𰡵�
	TreeNode<T>* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}
template<typename T>
TreeNode<T>* AVLTree<T>::Rotate_RR(TreeNode<T>* parent)
{
	// ������ ���������� ������ִ°�� �������� ȸ���ϰ� �з�Ʈ�� ���ϵ��� �����̵ǰ� ���ϵ尡 �θ𰡵�
	TreeNode<T>* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}
template<typename T>
TreeNode<T>* AVLTree<T>::Rotate_LR(TreeNode<T>* parent)
{
	// ���� ���������� ������ִ� ��� ���ϵ��� ���ϵ尡 �������� �����̼��ϰ� ���ϵ尡 ���������� �����̼���
	TreeNode<T>* child = parent->left;
	parent->left = Rotate_RR(child);
	return Rotate_LL(parent);
}
template<typename T>
TreeNode<T>* AVLTree<T>::Rotate_RL(TreeNode<T>* parent)
{
	// ������ �������� ������ִ� ��� ���ϵ��� ���ϵ尡 ���������� �����̼��ϰ� ���ϵ尡 �������� �����̼���
	TreeNode<T>* child = parent->right;
	parent->right = Rotate_LL(child);
	return Rotate_RR(parent);
}
template<typename T>
TreeNode<T>* AVLTree<T>::MakeBalance(TreeNode<T>* Node)
{
	int hight_different = getBalance(Node); // ��������

	if (hight_different > 1) // 1�ʰ��ϰ�� �� ���� �κ�Ʈ���� ���̰� �� ū ���
	{
		if (getBalance(Node->left) > 0) // ����� ������ �����μ��� 0���� ū��� �� ����� ������ �� ���� 
			Node = Rotate_LL(Node);
		else // �ݴ���
			Node = Rotate_LR(Node);
	}
	else if (hight_different < -1) // -1�̸��ϰ�� �� ������ �κ�Ʈ���� ���̰� �� ū ���
	{
		if (getBalance(Node->right) < 0) // ����� ������ �����μ��� 0���� ���� ��� �� ����� �������� �� ����
			Node = Rotate_RR(Node);
		else // �ݴ���
			Node = Rotate_RL(Node);
	}
	return Node; // ��帮�� �� ���ϵ带 �����ϰԵ�
}
template<typename T>
TreeNode<T>*  AVLTree<T>::RecursiveInsert(TreeNode<T>* Node, T data)
{
	if (Node->data > data) // �����Ͱ� ����� �����ͺ��� ������ �������� ����
	{
		if (Node->left == nullptr) // ����� ������ ����ٸ�
		{
			// �߰�
			TreeNode<T>* temp = new TreeNode<T>;
			temp->data = data;
			temp->left = nullptr;
			temp->right = nullptr;
			Node->left = temp;
			length++;
		}
		else //�� ����ٸ�
			Node->left = RecursiveInsert(Node->left, data); // ��带 ����� �������� �Űܼ� �ٽ� ����
		Node = MakeBalance(Node); // ��͸� ���������鼭 �߰��� ����� �θ���� ��Ʈ���� ������ ���� , Ȥ�� �߰� �ǰ� �� �θ������ ����������
	}
	else // �����Ͱ� ����� �����ͺ��� Ŭ�� ���������� �� ��
	{
		if (Node->right == nullptr) // ����� �������� ����ٸ�
		{
			// �߰�
			TreeNode<T>* temp = new TreeNode<T>;
			temp->data = data;
			temp->left = nullptr;
			temp->right = nullptr;
			Node->right = temp;
			length++;
		}
		else
			Node->right = RecursiveInsert(Node->right, data); // ��带 ����� ���������� �Űܼ� �ٽ� ����
		Node = MakeBalance(Node); // ��͸� ���������鼭 �߰��� ����� �θ���� ��Ʈ���� ������ ����
	}
	return Node; //��带 ���������ν� ����Լ��� ���������鼭 ������ ����
}
template<typename T>
TreeNode<T>* AVLTree<T>::Recursivedelete(TreeNode<T>* Node, T data)
{
	if (Node == nullptr) // ��尡 ���̶�� 
	{
		return nullptr;
	}
	else // ���� �ƴ϶��
	{
		if (Node->data > data) // �������� ��
		{
			Node->left = Recursivedelete(Node->left, data); // ��带 ����� �������� ���߾� ��͸� ����
			Node = MakeBalance(Node); // ��͸� ���������鼭 ������ ����� �θ���� ������ ����
		}
		else if (Node->data < data) // ���������� ��
		{
			Node->right = Recursivedelete(Node->right, data); // ��带 ����� ���������� ���߾� ��͸� ����
			Node = MakeBalance(Node); // ��͸� ���������鼭 ������ ����� �θ���� ������ ����
		}
		else // ã�Ҵٸ�
		{
			if (Node->left == nullptr && Node->right == nullptr) // ����� ���ʰ� �������� �� ����ٸ�
			{
				delete Node;
				Node = nullptr;
				return Node;
			}
			else if (Node->left == nullptr && Node->right != nullptr) // �����ʸ� �ִٸ�
			{
				TreeNode<T>* temp = Node->right; // ����� ������ ����
				delete Node;
				return temp; // ����� ������ ����
			}
			else if (Node->right == nullptr && Node->left != nullptr) // ���ʸ� �ִٸ�
			{
				TreeNode<T>* temp = Node->left; // ����� ������ ����
				delete Node;
				return temp; // ����� ���� ����
			}
			else // ���ʴ� �ִٸ�
			{
				// ������ ����� �������� �̵��Ͽ� ���������� ����̵��Ͽ� Ʈ���� ���� ����� �������� ã��
				TreeNode<T>* dummy = Node->left;
				while (dummy->right != nullptr)
				{
					dummy = dummy->right;
				}
				Node->data = dummy->data; // ã�� ���� ��忡 �߰�����
				Node->left = Recursivedelete(Node->left, Node->data); // ����� ������ �������� �� �Ʒ� Ʈ������ ã�� ���� ������
				Node = MakeBalance(Node); // ������ ����� �θ���� ������ ���߾��ָ鼭 �ö�
				return Node; // ��帮��
			}
		}
	}
	return Node;
}
template<typename T>
TreeNode<T>* AVLTree<T>::getroot()
{
	return this->root;
}

// InOrder ������� ����ϴ� �Լ� 
template<typename T>
void AVLTree<T>::PrintInOrderTraversal(TreeNode<T>* root, ostream& out)
{
	if (root != NULL)								// root�� �����ϴ� ���
	{
		PrintInOrderTraversal(root->left, out);		// root�� �������� ���� �ٽ� InOrder �Լ� ȣ��
		out << root->data;							// root ���
		PrintInOrderTraversal(root->right, out);	// root�� ���������� ���� �ٽ� InOrder �Լ� ȣ��
	}
}

// InOrder ������� �����ϴ� �Լ� 
template<typename T>
void AVLTree<T>::SaveInOrderTraversal(TreeNode<T>* root, ofstream& out)
{
	MasterType temp;
	if (root != NULL)								// root�� �����ϴ� ���
	{
		SaveInOrderTraversal(root->left, out);		// root�� �������� ���� �ٽ� InOrder �Լ� ȣ��
		temp = root->data;
		//temp = data;
		temp.WriteDataToFile(out);
		//out << root->data;
		SaveInOrderTraversal(root->right, out);	// root�� ���������� ���� �ٽ� InOrder �Լ� ȣ��
	}
}