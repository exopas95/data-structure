#include "ArtistType.h"

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)�� ���� ��� true, �ٸ� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool ArtistType::operator == (const ArtistType &obj)
{
	return (this->m_ArtistID == obj.m_ArtistID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� Ŭ ��� true, �۰ų� ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool ArtistType::operator > (const ArtistType &obj)
{
	return (this->m_ArtistID>obj.m_ArtistID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� ���� ��� true, ũ�ų� ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool ArtistType::operator < (const ArtistType &obj)
{
	return (this->m_ArtistID<obj.m_ArtistID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� ũ�ų� ���� ��� true, ���� ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool ArtistType::operator >= (const ArtistType &obj)
{
	return (this->m_ArtistID >= obj.m_ArtistID);
}

// this(����Ǿ��ִ°�)�� obj(�Է��ϴ°�)���� �۰ų� ���� ��� true, Ŭ ��� false�� ����
// �̸� ���� ������ �����ε��� �̿��Ͽ� ����񱳸� �Ѵ�.
bool ArtistType::operator <= (const ArtistType &obj)
{
	return (this->m_ArtistID <= obj.m_ArtistID);
}

// ���� ����Ʈ�� �ٹ��� ������ �����Ѵ�.
void ArtistType::AddAlbumInArtist(AlbumType indata)
{
	mAlbumList.Add(indata);
}

// ���� ����Ʈ���� �ٹ��� ������ �����Ѵ�.
void ArtistType::DeleteAlbumInArtist(AlbumType indata)
{
	mAlbumList.Delete(indata);
}

// ���� ����Ǿ��ִ� ���� ����� ����Ѵ�.
// ���� ���� ��Ͽ� �ִ� ���ǵ鿡 ���� �ڼ��� ������ ���� ��� �̸� ã�Ƽ� ����Ѵ�.
void ArtistType::DisplayAlbumDetailInArtist(SortedLinkedList<MusicType> *list)
{
	AlbumType data;
	AlbumType copy;

	cout << "\n\t���� ��� : " << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	mAlbumList.ResetList();
	int length = mAlbumList.GetLength();
	for (int i = 0; i < length; i++)
	{
		mAlbumList.GetNextItem(data);
		cout << "\n\t" << i + 1 << "��" << endl;
		data.DisplayRecordOnScreen();
		copy = data;
	}

	char Agree;
	cout << "\n\t�ٹ��� ���λ����� Ȯ���Ͻðڽ��ϱ�?? (Y/N): ";
	cin >> Agree;

	bool condition = true;
	bool found = true;
	while (condition)
	{
		if (Agree == 'Y')
		{
			mAlbumList.ResetList();
			int length = mAlbumList.GetLength();
			string album;
			cout << "\n\tã�����ϴ� �ٹ����� �Է��ϼ���: ";
			cin >> album;

			for (int i = 0; i < length; i++)
			{
				mAlbumList.GetNextItem(data);
				if (data.GetAlbumName() == album)  // ����Ʈ�� ���̵� ������
				{
					MusicType temp;
					list->ResetList();
					for (int i = 0; i < list->GetLength(); i++)
					{
						list->GetNextItem(temp);
						if (temp.GetAlbum() == album)
						{
							cout << endl;
							cout << "<============I FOUND ITEM !==========>" << endl;
							temp.DisplayRecordOnScreen();	//��ġ�ϴ� ���ڿ��� �����ϴ� temp�� ������ ����Ѵ�.
							cout << "<====================================>" << endl;
							condition = false;
							found = true;
							break;
						}
					}
				}
			}
			if (found == false) // ����Ʈ�� ���̵� ������ 
			{
				cout << "\n\t�ش� ID�� �����ϴ�!";
				condition = false;
			}
		}
		else if (Agree == 'N')
		{
			condition = false;
		}
		else
		{
			cout << "\n\tY �Ǵ� N�� �Է����ּ���: ";
			cin >> Agree;
		}
	}
}
