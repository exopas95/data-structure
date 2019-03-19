#include "Application.h"


// Program driver.
void Application::Run()
{
	while(1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// Get data from the user and add it to the list.					
			AddItem();
			break;
		case 2:		// Get data from the user and delete it from the list.					
			DeleteItem();
			break;
		case 3:		// Get data from the user and replace it in the list.					
			ReplaceItem();
			break;
		case 4:		// Get data from the user and display it from the list.				
			DisplayItem();
			break;
		case 5:		// Display all item.
			DisplayAllItem();
			break;
		case 6: 	// Delete all item in the list.
			MakeEmpty();
			break;
		case 7:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 8:		// save list data into a file.
			WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;

		}
	}
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Delete item" << endl;
	cout << "\t   3 : Replace item" << endl;
	cout << "\t   4 : Print item on screen" << endl;
	cout << "\t   5 : Print all on screen" << endl;
	cout << "\t   6 : Make empty list" << endl;
	cout << "\t   7 : load list data from a file" << endl; 
	cout << "\t   8 : save list data into a file " << endl; 
	cout << "\t   0 : Quit" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::AddItem()
{
	// Add the input record, if the list is full return 0.
	if(m_List.IsFull())
	{
		cout << "List is full" << endl;
		return 0;
	}

	ItemType item;

	item.SetRecordFromKB();
	m_List.Add(item);

	// Display current list.
	DisplayAllItem();

	return 1;
}

// Delete record from the list.
int Application::DeleteItem()
{
	// Delete input data from the list, if the list is empty, return 0.
	if (m_List.IsEmpty() == 1)
	{
		cout << "\n\tList is empty" << endl;
		return 0;
	}

	ItemType item;

	item.SetRecordFromKB();
	m_List.Delete(item);

	// Display current list.
	DisplayAllItem();

	return 1;
}

// Replace record from the list.
int Application::ReplaceItem()
{
	// Replace the data to new data, if the list is empty, return 0.
	if (m_List.IsEmpty() == 1)
	{
		cout << "\n\tList is empty" << endl;
		return 0;
	}
	ItemType data;

	cout << "\n\tWhich ID do you want to replace?" << endl;
	data.SetIdFromKB();
	cout << "\n\tType new ID and Adress to replace" << endl;
	data.SetNameFromKB();
	data.SetAddressFromKB();

	if (!m_List.Replace(data))
	{
		cout << "\n\tData is not on the list" << endl;
	}

	// Display current list.
	DisplayAllItem();
	return 1;
}

// Display input data from the list.
int Application::DisplayItem()
{
	
	// Display input data from the list, if the list is empty, return 0.
	if (m_List.IsEmpty() == 1)
	{
		cout << "\n\tList is empty" << endl;
		return 0;
	}
	else
		cout << "\n\tID you want to display ->";
	
	ItemType data;
	data.SetIdFromKB();
	if (m_List.Get(data) != -1)
	{
		data.DisplayRecordOnScreen();
		return -1;
	}
	else
		cout << "\n\tData is not on the list" << endl;
	return 1;

}


// Display all records in the list on screen.
void Application::DisplayAllItem()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	// Display all data in the screen
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.DisplayRecordOnScreen();
		curIndex = m_List.GetNextItem(data);
	}
}
//	Remove all data in the list.
void Application::MakeEmpty()
{
	m_List.MakeEmpty();
	cout << "\n\tList is empty" << endl;
}



// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.
	
	// if file opens, return 1, otherwise 0.
	if(!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// if file opens, return 1, otherwise 0.
	if(!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	ItemType data;	
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error occurs, return 0.
	if(!OpenInFile(filename))
		return 0;

	// read all data from the file and put it to the list.
	while(!m_InFile.eof())
	{
		// save student information in array to structure
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// 현재 list 출력
	DisplayAllItem();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	ItemType data;	

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error occurs, return 0.
	if(!OpenOutFile(filename))
		return 0;

	// initialize list.
	m_List.ResetList();

	// Write all data in the list to file.
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}