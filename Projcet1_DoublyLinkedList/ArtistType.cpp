#include "ArtistType.h"

// this(저장되어있는값)가 obj(입력하는값)와 같을 경우 true, 다를 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool ArtistType::operator == (const ArtistType &obj)
{
	return (this->m_ArtistID == obj.m_ArtistID);
}

// this(저장되어있는값)가 obj(입력하는값)보다 클 경우 true, 작거나 같을 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool ArtistType::operator > (const ArtistType &obj)
{
	return (this->m_ArtistID>obj.m_ArtistID);
}

// this(저장되어있는값)가 obj(입력하는값)보다 작을 경우 true, 크거나 같을 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool ArtistType::operator < (const ArtistType &obj)
{
	return (this->m_ArtistID<obj.m_ArtistID);
}

// this(저장되어있는값)가 obj(입력하는값)보다 크거나 같을 경우 true, 작을 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool ArtistType::operator >= (const ArtistType &obj)
{
	return (this->m_ArtistID >= obj.m_ArtistID);
}

// this(저장되어있는값)가 obj(입력하는값)보다 작거나 같을 경우 true, 클 경우 false를 리턴
// 이를 통한 연산자 오버로딩을 이용하여 대수비교를 한다.
bool ArtistType::operator <= (const ArtistType &obj)
{
	return (this->m_ArtistID <= obj.m_ArtistID);
}

// 가수 리스트에 앨범의 정보를 저장한다.
void ArtistType::AddAlbumInArtist(AlbumType indata)
{
	mAlbumList.Add(indata);
}

// 가수 리스트에서 앨범의 정보를 제거한다.
void ArtistType::DeleteAlbumInArtist(AlbumType indata)
{
	mAlbumList.Delete(indata);
}

// 현재 저장되어있는 가수 목록을 출력한다.
// 이후 가수 목록에 있는 음악들에 대한 자세한 정보를 원할 경우 이를 찾아서 출력한다.
void ArtistType::DisplayAlbumDetailInArtist(SortedLinkedList<MusicType> *list)
{
	AlbumType data;
	AlbumType copy;

	cout << "\n\t현재 목록 : " << endl;

	// list의 모든 데이터를 화면에 출력
	mAlbumList.ResetList();
	int length = mAlbumList.GetLength();
	for (int i = 0; i < length; i++)
	{
		mAlbumList.GetNextItem(data);
		cout << "\n\t" << i + 1 << "번" << endl;
		data.DisplayRecordOnScreen();
		copy = data;
	}

	char Agree;
	cout << "\n\t앨범의 세부사항을 확인하시겠습니까?? (Y/N): ";
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
			cout << "\n\t찾고자하는 앨범명을 입력하세요: ";
			cin >> album;

			for (int i = 0; i < length; i++)
			{
				mAlbumList.GetNextItem(data);
				if (data.GetAlbumName() == album)  // 리스트에 아이디가 있으면
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
							temp.DisplayRecordOnScreen();	//일치하는 문자열을 포함하는 temp의 내용을 출력한다.
							cout << "<====================================>" << endl;
							condition = false;
							found = true;
							break;
						}
					}
				}
			}
			if (found == false) // 리스트에 아이디가 없으면 
			{
				cout << "\n\t해당 ID가 없습니다!";
				condition = false;
			}
		}
		else if (Agree == 'N')
		{
			condition = false;
		}
		else
		{
			cout << "\n\tY 또는 N을 입력해주세요: ";
			cin >> Agree;
		}
	}
}
