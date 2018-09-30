/*
* FILE : mini2.cpp
* PROJECT : PROG1370 - Data Structures
* PROGRAMMER : Brendan Rushing
* FIRST VERSION : 2018-05-25
* DESCRIPTION :
Program will take 10 song information from the user that includes an artist and song name.
The program will store the information in a struct of pointers and use malloc to store the information.
*
*/


//INCLUDE FILES
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
//eo INCLUDE FILES



int main(void) {

	struct songInfo *head = NULL;

	//get songInfo from user and put into Linked List
	head = getSongInfo(head);
	
	//print songInfo
	printSongInfo(head);

	//free songInfo
	freeSongInfo(head);
	

	return EXIT_SUCCESS;


}//eo main







