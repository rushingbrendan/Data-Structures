/*
* FILE : dsA1.cpp
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


//INCLUDE FILES

#include "dsA1.h"
//eo INCLUDE FILES



int main(void) {

	struct songInfo *head_sortby_name = NULL;
	struct songInfo *tail_sortby_name = NULL;


	struct songInfo *head_sortby_rating = NULL;
	struct songInfo *tail_sortby_rating = NULL;

	songInfo_t *songInfoToDelete = NULL;


	char songName[STRING_LENGTH] = { 0 };
	char songArtist[STRING_LENGTH] = { 0 };
	int songRating = 0;
	int i = 0;




		//GET NEW RECORD******************************************************

	while ((songRating >= 0) && (songRating <= 5))
 {

	
			printf("Enter #%d Artist Name: ", i);
			scanf("%s", songArtist);

			printf("Enter #%d Song Name: ", i);
			scanf("%s", songName);

			printf("Enter #%d Song Rating (1 to 5): ", i);
			scanf("%d", &songRating);

			if (!((songRating < 0) || (songRating > 5))) {

				insertIntoListSortedByName(songArtist, songName, songRating, &head_sortby_name, &tail_sortby_name);
				insertIntoListSortedByRating(songArtist, songName, songRating, &head_sortby_rating, &tail_sortby_rating);

			}

			i++;
} 

	//} while (1);


	//print songInfo
	printf("\n______________________________________________________________________________");
	printf("\n List Sorted by Rating: ");
	printf("\n______________________________________________________________________________");
	printSongInfo(head_sortby_rating);

	printf("\n\n______________________________________________________________________________");
	printf("\n List Sorted by Name: ");
	printf("\n______________________________________________________________________________");
	printSongInfo(head_sortby_name);
	printf("\n______________________________________________________________________________");

	//ask user for song name input
	printf("\n\nEnter song information to be searched for in the list");
	printf("\nEnter Artist Name: ");
	scanf("%s", songArtist);

	printf("Enter Song Name: ");
	scanf("%s", songName);

	printf("Enter Song Rating (1 to 5): ");
	scanf("%d", &songRating);

	songInfoToDelete = findSong(head_sortby_name, songArtist, songName, songRating);

	if (songInfoToDelete != NULL) {

		//copy data back into variables to retain original case
		songRating = songInfoToDelete->rating;
		strcpy(songArtist, songInfoToDelete->artist);
		strcpy(songName, songInfoToDelete->title);
		
		//deletenode
		deleteNode(songInfoToDelete, &head_sortby_name, &tail_sortby_name);

		//insert back into list and it will be sorted at insertion
		insertIntoListSortedByName(songArtist, songName, songRating, &head_sortby_name, &tail_sortby_name);
		

	}//eo if (!songInfoToDelete == NULL) {



	//print songInfo
	printf("\n______________________________________________________________________________");
	printf("\nList Sorted by Rating: ");
	printf("\n______________________________________________________________________________");
	printSongInfo(head_sortby_rating);

	printf("\n\n______________________________________________________________________________");
	printf("\nList Sorted by Name: ");
	printf("\n______________________________________________________________________________");
	printSongInfo(head_sortby_name);
	printf("\n______________________________________________________________________________");




	//free songInfo
	freeSongInfo(head_sortby_name);
	freeSongInfo(head_sortby_rating);


	return EXIT_SUCCESS;


}//eo main







