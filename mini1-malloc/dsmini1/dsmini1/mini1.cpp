/*
* FILE : mini1.cpp
* PROJECT : PROG1370 - Data Structures
* PROGRAMMER : Brendan Rushing
* FIRST VERSION : 2018-05-14
* DESCRIPTION :
Program will take 10 song information from the user that includes an artist and song name.
The program will store the information in a struct of pointers and use malloc to store the information.
*
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>



//CONSTANTS
#define TRUE 1
#define FALSE 0

#define ARRAY_LENGTH 10
#define STRING_LENGTH 40


struct songInfo {

	char* artist;
	char* title;
};


//eo CONSTANTS


//PROTOTYPES
void getSongInfo(struct songInfo *pSongInfo, char pArtist[], char pSong[]);
void printSongInfo(songInfo mySongs[]);

//eo PROTOTYPES

#pragma warning(disable: 4996)

int main(void) {

	char i = 0;
	char songName [STRING_LENGTH] = { 0 };		
	char songArtist [STRING_LENGTH]  = { 0 };

	struct songInfo mySongs[ARRAY_LENGTH];



	while (i != ARRAY_LENGTH) {

		printf("Enter #%d Song Name followed by Song Artist: ",i);
		scanf("%s %s", songName, songArtist);
		
		getSongInfo(&mySongs[i], songName, songArtist);
		
		i++;	//increment counter

}//eo 	while (i != 10) 


	printSongInfo(mySongs);


	i = 0;		//reset counter

	while (i != ARRAY_LENGTH) {

		//free memory
		free(mySongs[i].artist);
		free(mySongs[i].title);

		i++;

}//eo 	while (i != 10) 



	return 0;


}//eo main




 /*
 * FUNCTION : getSongInfo
 *
 * DESCRIPTION : This function takes the name of song title and artist and uses malloc
 to free memory and assign the memory location to the array of struct pointers.

 *
 * PARAMETERS : struct songInfo *pSongInfo, char pArtist[], pSong[]
 * RETURNS : none
 */

void getSongInfo(struct songInfo *pSongInfo, char pArtist[], char pSong[]) {

	int length = 0;

	length = strlen(pArtist);

	if ((pSongInfo->artist = (char *)malloc(length + 1)) == NULL) {

		printf("\nMalloc ERROR");

	}//eo if
	
	strcpy(pSongInfo->artist, pArtist);

	length = strlen(pSong);

	if ((pSongInfo->title = (char *)malloc(length + 1)) == NULL) {

		printf("\nMalloc ERROR");

	}//eo if


	strcpy(pSongInfo->title, pSong);



}//eo void getSongInfo(struct songInfo *pSongInfo, char pArtist[], char pSong[])





 /*
 * FUNCTION : printSongInfo
 *
 * DESCRIPTION : This function prints the name and artist from all the songs in array to the screen

 *
 * PARAMETERS : songInfo mySongs[]
 * RETURNS : none
 */

void printSongInfo(songInfo mySongs[]){

	char i = 0;

	while (i != ARRAY_LENGTH) {

		printf("\n %-40s %-40s", mySongs[i].artist, mySongs[i].title);


		i++;

	}//eo while


}//eo  void printSongInfo(mySongs[])


