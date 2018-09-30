#pragma once

//INCLUDE FILES
#include <stdio.h>
#include <stdlib.h>
//eo INCLUDE FILES


//CONSTANTS
#define ARRAY_LENGTH 10
#define STRING_LENGTH 40

#pragma warning(disable: 4996)


struct songInfo {

	char* artist;
	char* title;
	struct songInfo *next;
};
//eo CONSTANTS


//PROTOTYPES
songInfo *getSongInfo(struct songInfo *newHead);
void printSongInfo(struct songInfo *head);
songInfo *freeSongInfo(struct songInfo *head);
//eo PROTOTYPES


