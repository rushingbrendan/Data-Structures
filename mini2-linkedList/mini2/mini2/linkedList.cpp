
//INCLUDE FILES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
//eo INCLUDE FILES

/*
* FUNCTION : getSongInfo
*
* DESCRIPTION : This function takes the name of song title and artist and uses malloc
to free memory and assign the memory location to the array of struct pointers.

*
* PARAMETERS : struct songInfo *newHead)
* RETURNS : songInfo
*/

songInfo *getSongInfo(struct songInfo *newHead) {

	char i = 0;

	while (i != ARRAY_LENGTH) {

		//VARIABLES************************************************************
		int length = 0;

		songInfo *newBlock = NULL;
		songInfo *ptr = NULL;
		char* pArtist = NULL;
		char* pSong = NULL;
		char songName[STRING_LENGTH] = { 0 };
		char songArtist[STRING_LENGTH] = { 0 };
		//eo VARIABLES*********************************************************

		//malloc struct
		if ((newBlock = (songInfo *)malloc(sizeof(songInfo))) == NULL) {

			printf("\nMalloc ERROR");
			return newHead;

		}//eo if


		 //GET NEW RECORD******************************************************
		printf("Enter #%d Song Name followed by Song Artist: ", i);
		scanf("%s %s", songName, songArtist);
		//END OF GET NEW RECORD************************************************


		//STORE IN MEMORY******************************************************
		pArtist = songArtist;
		pSong = songName;

		length = strlen(pArtist);

		//malloc artist
		if ((newBlock->artist = (char *)malloc(length + 1)) == NULL) {

			printf("\nMalloc ERROR");
			return newHead;

		}//eo if

		strcpy(newBlock->artist, pArtist);

		length = strlen(pSong);

		//malloc name
		if ((newBlock->title = (char *)malloc(length + 1)) == NULL) {

			printf("\nMalloc ERROR");
			return newHead;

		}//eo if

		strcpy(newBlock->title, pSong);

		//eo STORE IN MEMORY***************************************************


		//STORE IN LINKED LIST*************************************************
		newBlock->next = NULL;

		// link this record to the current list

		if (newHead == NULL)
		{
			// empty list, so set first pointer
			newHead = newBlock;

		}//eo if (newHead == NULL)

		else
		{

			ptr = newHead;
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}//eo while (ptr->next != NULL)

				// we are at end since ptr->next is NULL
				// append the new record into ptr->next

			ptr->next = newBlock;
		}//eo else

		 //eo STORE IN LINKED LIST*********************************************




		i++;	//increment counter

	}//eo 	while (i != 10) 

	i = 0;		//reset counter


	// return the new head pointer
	return newHead;


}//eo void getSongInfo(struct songInfo *pSongInfo, char pArtist[], char pSong[])






 /*
 * FUNCTION : printSongInfo
 *
 * DESCRIPTION : This function prints the name and artist from all the songs to the screen

 *
 * PARAMETERS : struct songInfo *head
 * RETURNS : none
 */

void printSongInfo(struct songInfo *head) {

	songInfo *ptr = head;
	// follow the chain until the pointer is null


	while (ptr != NULL)
	{

		printf("\n%-40s %-40s", ptr->artist, ptr->title);

		ptr = ptr->next;


	}//eo while (ptr != NULL)


}//eo  void printSongInfo(struct songInfo *head){







 /*
 * FUNCTION : freeSongInfo
 *
 * DESCRIPTION : This function free the memory taken up by the 10 songInfo structs

 *
 * PARAMETERS : songInfo mySongs[]
 * RETURNS : songInfo 
 */

songInfo *freeSongInfo(struct songInfo *head) {

	songInfo *ptr = head;
	songInfo *curr = head;

	// follow the chain until the pointer is null


	while (ptr != NULL)
	{

		curr = ptr;
		ptr = ptr->next;

		free(curr->artist);
		free(curr->title);
		free(curr);

	}//eo while (ptr != NULL)

	return NULL;
}//eo  void freeSongInfo(struct songInfo *head) {



