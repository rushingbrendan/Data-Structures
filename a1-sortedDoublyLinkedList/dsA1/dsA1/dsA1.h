
/*
* FILE : dsA1.h
* PROJECT : PROG1370 - Data Structures - Assignment #1
* PROGRAMMER : Brendan Rushing
* FIRST VERSION : 2018-05-25
* DESCRIPTION :
Program will take 10 song information from the user that includes an artist and song name.
The program will store the information in a struct of pointers and use malloc to store the information.
Program will store the data in doubly linekd list.
Search functionality included as well.
All memory is freed at the end.
*
*/

#pragma once

//INCLUDE FILES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//eo INCLUDE FILES


//CONSTANTS
#define STRING_LENGTH 30

#pragma warning(disable: 4996)


typedef struct songInfo {

	char* artist;
	char* title;
	int rating;
	struct songInfo *prev;
	struct songInfo *next;
}songInfo_t;
//eo CONSTANTS


//PROTOTYPES
songInfo_t *getSongInfo(struct songInfo *newHead);
void printSongInfo(struct songInfo *head);
songInfo_t *findSong(struct songInfo *head, char* inputArtistName, char* inputSongTitle, int inputRating);
songInfo_t *freeSongInfo(struct songInfo *head);
int insertIntoListSortedByName(char* inputArtistName, char* inputSongTitle, int inputRating, songInfo_t **head, songInfo_t **tail);
int insertIntoListSortedByRating(char* inputArtistName, char* inputSongTitle, int inputRating, songInfo_t **head, songInfo_t **tail);
void deleteNode(songInfo_t *node, songInfo_t **head, songInfo_t **tail);
//int searchList(char* inputArtistName, char* inputSongTitle, int inputRating, songInfo_t **head, songInfo_t **tail);
//eo PROTOTYPES


