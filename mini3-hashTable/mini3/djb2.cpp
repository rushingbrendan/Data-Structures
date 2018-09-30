/*
* FILE : djb2.cpp
* PROJECT : PROG1370 - Data Structures
* PROGRAMMER : Brendan Rushing
* FIRST VERSION : 2018-05-25
* DESCRIPTION :
Program will take 10 words and use hash tables to store into memory
*
*/

#include "dsA1.h"
#include "djb2.h"

unsigned long hashFunction(char* inputString) {

	unsigned long result = 0;
	int length = 0;


	result = djb2hash(inputString);

	result = result%10;

	return result;

}//eo int hashFunction(char* inputString) {





unsigned long djb2hash(char* str) {

	unsigned long hash = 5381;
	int c = 0;

	while ((c = *str++) != '\0')

		hash = ((hash << 5) + hash) + c;

	return hash;


}//eo unsigned long djb2hash(char* str) {