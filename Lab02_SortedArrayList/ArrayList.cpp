#include "ArrayList.h"


// ����Ʈ�� ����.
void ArrayList::MakeEmpty()
{
	m_Length = 0;
}


// ����Ʈ�� ���̸� ��ȯ�Ѵ�.
int ArrayList::GetLength()
{
	return m_Length;
}


// ����Ʈ�� ���� á���� Ȯ���Ѵ�.
bool ArrayList::IsFull()
{
	if(m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


// ����Ʈ�� ���ο� �����͸� �߰��Ѵ�.
int ArrayList::Add(MusicType inData)
{
	if (!IsFull())
	{
		MusicType CurItem;
		ResetList();
		GetNextItem(CurItem);

		while (m_CurPointer <= m_Length) //ó������ ������
		{
			if (CurItem.CompareByName(inData) == GREATER || m_CurPointer == m_Length)	//���� CurItem>inData�ϰ�� Ȥ�� �迭�� �������̶� �񱳴���� ���°��
			{
				for (int i = m_Length; i > m_CurPointer; i--)	//�ǵڿ��� ���� �ϳ��� �����.
					m_Array[i] = m_Array[i - 1];	//�迭 �б�
				m_Array[m_CurPointer] = inData;	//�迭 ���� �� ���� �����Ϳ� ������ �ִ´�.
				m_Length++;	//���� ����
				break;
			}
			GetNextItem(CurItem);	//��������������
		}
		
	}
	else
	{
		ReSize();
		MusicType CurItem;
		ResetList();
		GetNextItem(CurItem);

		while (m_CurPointer <= m_Length) //ó������ ������
		{
			if (CurItem.CompareByName(inData) == GREATER || m_CurPointer == m_Length)	//���� CurItem>inData�ϰ�� Ȥ�� �迭�� �������̶� �񱳴���� ���°��
			{
				for (int i = m_Length; i > m_CurPointer; i--)	//�ǵڿ��� ���� �ϳ��� �����.
					m_Array[i] = m_Array[i - 1];	//�迭 �б�
				m_Array[m_CurPointer] = inData;	//�迭 ���� �� ���� �����Ϳ� ������ �ִ´�.
				m_Length++;	//���� ����
				break;
			}
			GetNextItem(CurItem);	//��������������
		}
	}
	return 1;
}


// Initialize list iterator.
void ArrayList::ResetList()
{
	m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
int ArrayList::GetNextItem(MusicType& data)
{
	m_CurPointer++;	// list pointer ����
	if(m_CurPointer == MAXSIZE)	// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}

//���� ��ġ�ϴ� item�� ã�Ƽ� ��ȯ��
int ArrayList::Get(MusicType& data)
{
	MusicType CurItem;
	
	ResetList();	//iterator �ʱ�ȭ
	GetNextItem(CurItem);	//ù������ ������
	while(m_CurPointer<m_Length)	//ó������ ������
	{
		switch(CurItem.CompareByName(data))	//�Է� �����۰� ���� �������� ��
		{
		case EQUAL:	//��ġ�ϸ�
			data=CurItem;	//data�� ���� �������� ��ȯ
			return 1;	//����(1)�� ����
			break;
		case GREATER:	//���� �������� ����� �� ũ��(���ĵ������Ƿ� �������� ã�°� ����)
			return 0;	//����(0)�� ����
			break;
		default:	//���� �������� ����� �� ������
			GetNextItem(CurItem);	//���� �������� �����´�.(��� Ž��)
			break;
		}
	}
	return 0; //���н�0
}

//���� ��ġ�ϴ� item�� ã�Ƽ� ������
int ArrayList::Delete(MusicType data)
{
	if(Get(data))	//����� ��ġ�ϴ� item�� �߰��Ѵٸ�(1)
	{
		for(int i=m_CurPointer;i<m_Length;i++)	//���� �����ͺ��� �Էµ� �迭 ������ �ݺ�
			m_Array[i]=m_Array[i+1];	//�迭 �ڿ��� ������ �ϳ��� ����
		m_Length--;	//������ ������ �ϳ� ����
		return 1;	//����(1)�� ����
	}
	return 0;	//���� ��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}

//����� ��ġ�ϴ� item�� ������ ��ü��Ŵ
int ArrayList::Replace(MusicType data)
{
	MusicType tmp(data);	//�Է¹��� item�� ���

	if(Get(data))	//��ġ�ϴ� �������� ã�� ���
	{
		m_Array[m_CurPointer]=tmp;	//�迭���� ���������Ͱ� ����Ű�� ���� ����ߴ� ���������� ��ü��Ŵ
		return 1;	//����(1)�� ����
	}
	return 0;	//���� ��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����
}

//����� ��ġ�ϴ� item�� ����Ž������ �˻��ؼ� ��ȯ�Ѵ�.
int ArrayList::GetBinarySearch(MusicType& data )
{
	if(m_Length==0)	//���� �迭�� ����ٸ�
		return 0;	//����(0)�� ����
	int currentPos=m_Length/2;	//�迭�� �߰����� ����
	MusicType const item = data;
	while (1)
	{
		switch (m_Array[currentPos].BinaryCompareByName(item))
		{
		case EQUAL:	//���� �����۰� �Է� �������� ����� ��ġ�Ѵٸ�
			data = m_Array[currentPos];	//data�� �߰��� ���� ����
			cout << "<============I FOUND ITEM !==========>" << endl;
			data.DisplayRecordOnScreen(); 	//��ġ�ϴ� ata�� ������ ����Ѵ�.
			cout << "<====================================>" << endl;
			/* BinarySearch ���� ��ġ�ϴ� ���ڿ� �������� �����Ϸ��� ��� �ڵ�
			for (int i = currentPos - 1; i >= 0; i--) // ���� ������ ������ �������� Ȯ��
			{
			if (m_Array[i].BinaryCompareByName(item) == EQUAL)
			{
			m_Array[i].DisplayRecordOnScreen();
			}
			else if (LESS || GREATER)
			break;
			}
			for (int i = currentPos + 1;; i++) //���� ������ ������ �������� Ȯ��
			{

			if (m_Array[i].BinaryCompareByName(item) == EQUAL)
			{
			m_Array[i].DisplayRecordOnScreen();
			}
			else
			break;
			}
			*/
			return 1;
			break;
		case GREATER:	//���� �������� ����� �Է� �������� ����� ũ�ٸ�
			if (currentPos == 0)	//ó�� �迭�� ������ �������
				return 0;	//����(0)�� ����
			currentPos /= 2;	//�� ������ �ε����� ���ݷ� �̵�
			break;
		case LESS:	//���� �������� ����� �Է� �������� ����� �۴ٸ�
			if (currentPos == m_Length - 1)	//������ �迭�� ������ ū���
				return 0;	//����(0)�� ����
			currentPos = (currentPos + m_Length) / 2;	//�� ū�� �ε����� �������� �̵�
			break;
		}
	}
	return 0;	//ȣ��� �� ���� ����(WARNING ������)
}
