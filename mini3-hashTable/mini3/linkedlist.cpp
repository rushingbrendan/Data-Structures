/*
* FILE : linkedlist.cpp
* PROJECT : PROG1370 - Data Structures
* PROGRAMMER : Brendan Rushing
* FIRST VERSION : 2018-05-25
* DESCRIPTION :
Program will take 10 words and use hash tables to store into memory
*
*/


//INCLUDE FILES

#include "dsA1.h"
//eo INCLUDE FILES


int insertIntoListSortedByName(char* inputName, wordNode_t **head, wordNode_t **tail) {

	wordNode_t *newBlock = NULL;
	wordNode_t *afterElement = NULL;
	int length = 0;

	// allocate a block of memory for new record
	newBlock = (wordNode_t*)malloc(sizeof(wordNode_t));
	if (newBlock == NULL)
	{
		printf("Error! No more memory!\n");
		return 0;
	}

	strcpy(newBlock->word, inputName);


	// now link this record to the list in the appropriate place
	if (*head == NULL)
	{
		// empty list, so set head and tail
		*head = *tail = newBlock;
		return 1;
	}

	else if (strcmp((*head)->word, inputName) >= 0) // special case!
	{
		// we're inserting at the front of the list

		// set the next pointer for the newBlock record to be the
		// location that used to be at the front of the list
		newBlock->next = *head;
		// set head to point to the new start of the list
		*head = newBlock;
	}

	else
	{
		/*
		* non-empty list where we're not inserting at the front
		* of the list, so use ptr to follow links until we reach the
		* right place, according to the sorting order
		*/

		afterElement = (*head)->next;	// second item in list 

		while (afterElement != NULL)
		{
			if (strcmp(afterElement->word, inputName) >= 0)
			{
				// we've found a name in the list that is either equal to or greater 
				// than the one we're entering now
				break;
			}
			afterElement = afterElement->next;
		}	/* end while */

			// add the new node here, between beforeElement and afterElement
		newBlock->next = afterElement;
		// are we at the end?
		if (afterElement == NULL)
		{
			*tail = newBlock;
		}

	}	/* endif */

	return 1;


}//eo int insertIntoListSortedByName(char* inputArtistName, char* inputSongTitle, int inputRating, struct songInfo **head, struct songInfo **tail) {






 /*
 * FUNCTION : printSongInfo
 *
 * DESCRIPTION : This function prints the name and artist from all the songs to the screen

 *
 * PARAMETERS : struct songInfo *head
 * RETURNS : none
 */

void printSongInfo(wordNode_t *head) {

	wordNode_t *ptr = head;
	// follow the chain until the pointer is null


	printf("\nWord");


	while (ptr != NULL)
	{

		printf("\n%s", ptr->word);

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

wordNode_t *freeSongInfo(wordNode_t *head) {

	wordNode_t *ptr = head;
	wordNode_t *curr = head;

	// follow the chain until the pointer is null


	while (ptr != NULL)
	{

		curr = ptr;
		ptr = ptr->next;

		free(curr->word);
		free(curr);

	}//eo while (ptr != NULL)

	return NULL;
}//eo  void freeSongInfo(struct songInfo *head) {



