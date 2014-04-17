/*
 * FILE:			BinarySearch.cpp
 * LAST REVISED:	28 Jan 2014
 * AUTHOR:			Todd Parker
 * EMAIL:			todd.i.parker@maine.edu
 * COURSE:			CIS354 - Algorithms and Data Structures
 *
 * BinarySearch.cpp creates three static arrays with 10 items of data types int, double, and string. It then calls
 * static methods from the BinarySearch header file to print the unsorted array, sort it, and then print the sorted
 * array. It then prompts the user to search for a key within the sorted array, and returns either the index where it
 * was found or a key not found message.
*/
#include "BinarySearch.h"
#include "SignatureBlock.h"

int main()
{
	// Declare three arrays of data types int, double, and string for testing binarySearch generic template
	int list[] = {9, 10, 15, 5, 0, 100, 250, 76, 1212, 1};
	double list1[] = {0.125, 99.99, .314, 5.93, 25, 25.01, 1111.11, 12.95, 30.5, 66.6};
	string list2[] = {"out", "best", "programming", "agony", "i", "describes", "live", "school", "work", "experiences"};

	int key = 0; // store the user-specified integer key
	double key1 = 0; // store the user-specified double key
	string key2 = ""; // store the user-specified string key
	int keyLocation = 0; // store the location result of user-seached key
	int menuChoice = 0; //  store the user-entered menu choice
	char exitLoop = 'N'; // control exit of menu loop
	do
	{
		SignatureBlock::printHeader(); // Print signature block
		cout << "Which array would you like to test generic Binary Search on?" << endl;
		cout << "\tInteger -- 1" << endl;
		cout << "\tDouble  -- 2" << endl;
		cout << "\tString  -- 3" << endl;
		cout << "Choice: ";

		cin >> menuChoice; // get menu option

		switch (menuChoice)
		{
			case 1:
			{
				cout << "\n10 element Integer array" << endl;
				BinarySearch<int>::copyArray(list,10); // make a copy of integer array and sort it 

				cout << "Please enter a key to search for: ";
				cin >> key;
				cout << endl;
				keyLocation = BinarySearch<int>::binarySearch(key); // search int array for entered key

				if (keyLocation != -1)
					cout << "The index of " << key << " was found at index " << keyLocation << endl;
				else
					cout << "The key " << key << " was NOT found." << endl;
				break;
			}
			case 2:
			{
				cout << "\n10 element Double array" << endl;
				BinarySearch<double>::copyArray(list1,10); // make a copy of double array and sort it

				cout << "Please enter a key to search for: ";
				cin >> key1;
				cout << endl;
				keyLocation = BinarySearch<double>::binarySearch(key1); // search double array for entered key

				if (keyLocation != -1)
					cout << "The index of " << key1 << " was found at index " << keyLocation << endl;
				else
					cout << "The key " << key1 << " was NOT found." << endl;
				break;
			}
			case 3:
			{
				cout << "\n10 element String array" << endl;
				BinarySearch<string>::copyArray(list2,10); // make copy of string array and sort it

				cout << "Please enter a key to search for: ";
				cin >> key2;
				cout << endl;
				keyLocation = BinarySearch<string>::binarySearch(key2); // search string array for entered key

				if (keyLocation != -1)
					cout << "The index of " << key2 << " was found at " << keyLocation << endl;
				else
					cout << "The key " << key2 << " was NOT found." << endl;
				break;
			}
			default:
			{
				cout << "I thought we were friends... Why are you trying to break me?" << endl;
			}
		} // end switch

		cout << "Exit Program? (Y | N): "; 
		cin >> exitLoop;
		cout << endl;
	} while ( exitLoop == 'N' ); // end do...while loop

	getchar(); // pause window before exiting

	return 0;
} // end main