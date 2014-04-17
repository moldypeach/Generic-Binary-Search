/*
 * FILE:			SignatureBlock.cpp
 * LAST REVISED:	28 Jan 2014
 * AUTHOR:			Todd Parker
 * EMAIL:			todd.i.parker@maine.edu
 * COURSE:			CIS354 - Algorithms and Data Structures
 *
 * SingatureBlock.cpp has only one static method, printHeader(), that prints a simple header to a command
 * window with a signature block.
*/
#include <iostream>
#include <iomanip>
#include "SignatureBlock.h"
using namespace std;

const char SignatureBlock::star = '*';
const char SignatureBlock::blank = ' '; 

void SignatureBlock::printHeader()         //print command window header with signature block information
{  
 for(int l=1;l<=80;l++)
  {
   cout << star;
  }
 cout << setfill(blank) << left <<  setw(40) << star << right << setw(40)
      << star;
 cout << setfill(blank) << left <<  setw(4) << star << setw(72) 
      << "AUTHOR:  Todd Parker" << right << setw(4) << star;
 cout << setfill(blank) << left <<  setw(4) << star << left << setw(73)
      << "COURSE:  CIS354 - Algorithms and Data Structures"
      << right << setw(3) << star;
 cout << setfill(blank) << left <<  setw(4) << star << left << setw(73)
      << "EMAIL:   todd.i.parker@maine.edu"
      << right << setw(3) << star;
 cout << setfill(blank) << left <<  setw(40) << star << right << setw(40)
      << star;
 for(int l=1;l<=80;l++)
  {
   cout << star;
  }
 cout << endl; 
} // end printHeader method
