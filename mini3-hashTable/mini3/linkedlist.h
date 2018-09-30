/*
* FILE : linkedlist.h
* PROJECT : PROG1370 - Data Structures
* PROGRAMMER : Brendan Rushing
* FIRST VERSION : 2018-05-25
* DESCRIPTION :
Program will take 10 words and use hash tables to store into memory
*
*/

#pragma once

//INCLUDE FILES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "djb2.h"


//eo INCLUDE FILES


//CONSTANTS
#define STRING_LENGTH 21
#define ARRAY_SIZE 11

#pragma warning(disable: 4996)


typedef struct wordNode {

	char word[STRING_LENGTH];
	struct wordNode *next;
}wordNode_t;

//eo CONSTANTS


//PROTOTYPES

int insertIntoListSortedByName(char* inputName, wordNode_t **head, wordNode_t **tail);
void printSongInfo(wordNode_t *head);
wordNode_t *freeSongInfo(wordNode_t *head);

//eo PROTOTYPES


