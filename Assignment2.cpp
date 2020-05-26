#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct MapFiles
{
public:
	string rootMap = "maps//";
	string currentMap = "map1.txt";
	string mapLocation = rootMap + currentMap;
};

void LoadFile(int HeightofMap[9][9], int ColumnHeight, int RowsHeight,MapFiles &maps)
{

	ifstream infile(maps.mapLocation);                //Reads the file from the map folder
	if (!infile)
	{
		cout << "ERROR: ";                            // If the file does not exist shows error message
		cout << "Can't open input file";
	}

	for (int Row = 8; Row >= RowsHeight; Row--)
	{
		for (int Column = 0; Column < ColumnHeight; Column++)
		{
			infile >> HeightofMap[Row][Column]; //Read the Rows and the Column into the file
		}
	}

}

void ReadMap(int HeightofMap[9][9])
{
	int RowsHeight = 0;
	int ColumnHeight = 9;

	for (int Row = 8; Row >= RowsHeight; Row--)    //Displays the Rows in the correct position
	{
		for (int Column = 0; Column < ColumnHeight; Column++) //Displays the Column in the correct position
		{
			cout << HeightofMap[Row][Column] << " "; //Outputs in the corrrect order
		}
		cout << endl;
	}
}

void MountainPass(int HeightofMap[9][9], int ColumnHeight, int CurrentRow)
{
	ReadMap(HeightofMap);										//Display Map to show which map the user is working on
	int UserChoice;
	cout << "Please enter a starting position" << endl;
	cin >> UserChoice;
	int StoreRow;
	bool Display = false;
	int MaxChoice = 8; 
	int MinChoice = 0;
	if (UserChoice < MinChoice || UserChoice > MaxChoice)		// Makes sure that the user only enters numbers 1 to 8 
	{
		cout << "Enter a number between 0 and 8";
	}
	else cout << HeightofMap[UserChoice][0] << " ", Display = true; // When UserChoice is 1 to 8 starts Mountain Pass

	if (Display)
	{
		for (int Column = 1; Column < ColumnHeight; Column++)
		{
			StoreRow = CurrentRow;
			int SmallestPiece = 900;
			int LowestNumber = 1; //Checks the lowest value 
			int MinY = 0; //Min value that the user can enter
			int MaxY = 9; //Max value of the map

			if (HeightofMap[UserChoice - LowestNumber][Column] < SmallestPiece && UserChoice > MinY) //This will check to see the the bottom number is lower '-'
			{
				SmallestPiece = HeightofMap[UserChoice - LowestNumber][Column];
				StoreRow = UserChoice - LowestNumber;
			}
			if (HeightofMap[UserChoice][Column] < SmallestPiece)	//Check if the middle number is low
			{
				SmallestPiece = HeightofMap[UserChoice][Column];
				StoreRow = UserChoice;
			}
			if (HeightofMap[UserChoice + LowestNumber][Column] < SmallestPiece && UserChoice < MaxY) //Checks to see the top number is lower '+'
			{
				SmallestPiece = HeightofMap[UserChoice + LowestNumber][Column];
				StoreRow = UserChoice + LowestNumber;
			}
			cout << SmallestPiece << " "; // Output the lowest numbers left to right depending on UserChoice
			UserChoice = StoreRow;

		}
	}
	cout << endl;
}

void Rotation(int HeightofMap[9][9])
{
	int GridLength = 9;   //Make sure that it has the correct length to rotate it 

	for (int Column = 0; Column < GridLength; Column++)
	{
		for (int Row = 0; Row < GridLength; Row++)
		{
			cout << HeightofMap[Row][Column] << " "; //Output 90 degree 
		}

		cout << endl;
	}
}

void VerticalRotation(int HeightofMap[9][9])
{
	int VerticalStartPos = 0; //Starts at the bottom as 0
	int VerticalEndPos = 9; //Goes to top to 9

	for (int Row = 8; Row >= VerticalStartPos; Row--)			//Flips on the correct axis 
	{
		for (int Column = 0; Column < VerticalEndPos; Column++)
		{
			cout << HeightofMap[Column][Row] << " "; //Output would have the map flipped 
		}
		cout << endl;
	}
}

void TransPose(int HeightofMap[9][9])
{
	int TopValue = 9;
	int BottomValue = 0;

	for (int Row = 0; Row < TopValue; Row++)
	{
		for (int Column = 8; Column >= BottomValue; Column--) //Gets the correct position to transpose the map
		{
			cout << HeightofMap[Column][Row] << " ";  //Output will be transposed 
		}
		cout << endl;
	}
}


void ChangeMap(MapFiles & maps)
{
	int UsersMap; //Depending on the users choice of map
	cout << "1 for Map 1 " << endl;
	cout << "2 for Map 2 " << endl;
	cout << "3 for Map 3 " << endl;
	cout << "Which map would you like to access" << endl;
	cin >> UsersMap;
	switch (UsersMap)
	{
	case 1:
		maps.currentMap = "map1.txt";   
		
		break;
	case 2:
		maps.currentMap = "map2.txt";
		
		break;
	case 3:
		maps.currentMap = "map3.txt";
		
		break;
	default:
		cout << "Not a Valid Choice. \n";  //Validation if user enter something other than 1 to 3 
		cout << "Choose again.\n";
		cin >> UsersMap;
		break;

	}
	maps.mapLocation = maps.rootMap + maps.currentMap; //This will update the map location and will store it 
	
}

int main()
{
	MapFiles maps; // This will be the UserChoice of Map 
	int HeightofMap[9][9]; //Stores Map as a 9 by 9

	int RowsHeight = 0; 
	int ColumnHeight = 9;

	int choice;
	int CurrentRow = 4; //Defalut Row
	bool running = true; 
	while (running != false)
	{
		cout << "*******************************\n";
		cout << " 1 - Map Option " << endl;
		cout << " 2 - Read Map" << endl;
		cout << " 3 - Mountain Pass" << endl;
		cout << " 4 - Rotation" << endl;
		cout << " 5 - Vertical Rotation" << endl;
		cout << " 6 - TransPose" << endl;
		cout << " 7 - Quit" << endl;
		cout << " Enter your choice and press return: ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			ChangeMap(maps); //	Passing things through the parameter throughout this switch statement 
			break;
		case 2:
			LoadFile(HeightofMap, ColumnHeight, RowsHeight, maps); //Loads file and read it so it is displayed
			ReadMap(HeightofMap);
			break;
		case 3:
			LoadFile(HeightofMap, ColumnHeight, RowsHeight, maps); //Loads the map 
			MountainPass(HeightofMap, ColumnHeight, CurrentRow); //Shows mountains pass
			break;
		case 4:
			Rotation(HeightofMap); //Only diplayes the map rotated 
			break;
		case 5:
			VerticalRotation(HeightofMap); //Only diplayes the map vertically
			break;
		case 6:
			TransPose(HeightofMap); //Only diplayes the map transposed
			break;
		case 7:
			cout << "End of Program.\n";
			running = false;
			break;
		
		default:
			cout << "Not a Valid Choice. \n";  //Validation for when the user enters something other then 1 to 7
			cout << "Choose again.\n";
			cin >> choice;
			break;
		}

	}
	return 0;

}
