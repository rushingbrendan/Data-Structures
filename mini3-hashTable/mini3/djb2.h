/*
* FILE : djb2.h
* PROJECT : PROG1370 - Data Structures
* PROGRAMMER : Brendan Rushing
* FIRST VERSION : 2018-05-25
* DESCRIPTION :
Program will take 10 words and use hash tables to store into memory
*
*/


#pragma once

#include <string.h>

unsigned long djb2hash(char* str);
unsigned long hashFunction(char* inputString);