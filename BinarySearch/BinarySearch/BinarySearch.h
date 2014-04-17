/*
 * FILE:			BinarySearch.h
 * LAST REVISED:	28 Jan 2014
 * AUTHOR:			Todd Parker
 * EMAIL:			todd.i.parker@maine.edu
 * COURSE:			CIS354 - Algorithms and Data Structures
 *
 * NOTE: Code for methods binarySearch() and sort() is adopted from the textbook "Introduction To C++ Programming 9th Edition"
 *
 * BinarySearch.h is a template class definition and implementation that provides printing, sorting, and searching utilities
 * for any array passed to it, regardless of the data type of the passed array. A copy is made via the copyArray() method so
 * the original does not get modified. All the methods and fields are static methods such that an object of BinarySearch is
 * not required.
*/
#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <iostream>
#include <string>
#include <conio.h> // for getch() - used to halt program before exiting

using namespace std;

/* 
	CLASS DEFINITON

*/

// Template class declaration
template<typename T>
class BinarySearch
{
public:
	static int binarySearch(T); // Array search template. Receives one parameter, the key to search for
	static void copyArray(const T*, int); // copies user-passed array
private:
	static T* searchArray; // copy of array user-passed array
	static int searchArraySize; // size of user-passed array
	static int sorted; // print messaged "sorted" or "unsorted"
	static void sort(); // sort the copied array (required for Binary Search to work)
	static int getArraySize(); // Accessor to get size of user-defined array
	static void setArraySize(int); // Mutator to set size of user-defined array dynamically
	static void printArray(); // Utility method to print the copied array to screen
}; // end BinarySearch class

/* 
	CLASS IMPLEMENTATION
*/

template<typename T>
int BinarySearch<T>::searchArraySize = 0;
template<typename T>
int BinarySearch<T>::sorted = 0;
template<typename T>
T* BinarySearch<T>::searchArray;

// set size of searchArray
template<typename T>
void BinarySearch<T>::setArraySize(int size)
{
	searchArraySize = size;
} // end setArraySize mutator

// return current size of searchArray
template<typename T>
int BinarySearch<T>::getArraySize()
{
	return searchArraySize;
} // end getArraySize accessor

template<typename T>
int BinarySearch<T>::binarySearch(T key)
{
	int low = 0;
	int high = getArraySize() - 1;

	while (high >= low)
	{
		int mid = (low + high) / 2;
		if (key < searchArray[mid])
		high = mid - 1;
		else if (key == searchArray[mid])
		return mid;
		else
		low = mid + 1;
	}

	return -1;
} // end binarySearch template

// template copy function to copy user-passed array
template<typename T>
void BinarySearch<T>::copyArray(const T* arrayIn, int listSize )
{
	setArraySize(listSize); // initialize internal searchArraySize
	searchArray = new T[getArraySize()]; // initialize internal searchArray

	for (int i = 0; i < getArraySize(); i++)
	{
		searchArray[i] = arrayIn[i];
	} // end for

	printArray(); // print the unsorted array
	sort(); // sort internal searchArray, which is required for binarySearch to work
	printArray(); // print the sorted array
} // end copyAndSort template


template<typename T>
void BinarySearch<T>::sort() 
{
  for (int i = 0; i < getArraySize(); i++) 
  {
    // Find the minimum in the list[i..listSize-1]
    T currentMin = searchArray[i];
    int currentMinIndex = i;

    for (int j = i + 1; j < searchArraySize; j++) 
    {
      if (currentMin > searchArray[j]) 
      {
        currentMin = searchArray[j];
        currentMinIndex = j;
      }
    }

    // Swap list[i] with list[currentMinIndex] if necessary;
    if (currentMinIndex != i) 
    {
      searchArray[currentMinIndex] = searchArray[i];
      searchArray[i] = currentMin;
    }
  } // end for
} // end sort template

template<typename T>
void BinarySearch<T>::printArray()
{
    for (int i = 0; i < getArraySize(); i++)
    {
		if ( (i == 0) && (sorted == 0) )
		{
			cout << "\nUNSORTED:" << "\n\t";
			sorted++;
		}
		else if ( (i == 0) && (sorted == 1) )
		{
			cout << "\nSORTED:" << "\n\t";
			sorted = 0;
		}
		cout << searchArray[i] << " ";
    } // end for
    cout << "\n" << endl;
} // end printArray template

#endif