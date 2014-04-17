/*
 * FILE:			SignatureBlock.h
 * LAST REVISED:	28 Jan 2014
 * AUTHOR:			Todd Parker
 * EMAIL:			todd.i.parker@maine.edu
 * COURSE:			CIS354 - Algorithms and Data Structures
 *
*/
#ifndef SIGNATUREBLOCK_H
#define SIGNATUREBLOCK_H

class SignatureBlock
{
public:
	static void printHeader(); // Print signature block to command window
private:
	static const char star;
	static const char blank;
}; // end SignatureBlock class

#endif