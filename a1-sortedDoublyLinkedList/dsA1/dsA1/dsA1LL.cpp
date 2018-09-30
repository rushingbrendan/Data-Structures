/*
* FILE : dsA1LL.cpp
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




/*
* FUNCTION : insertIntoListSortedByRating
*
* DESCRIPTION : This function inserts a node into the linked list that is sorted by rating.

*
* PARAMETERS :char* inputArtistName, char* inputSongTitle, int inputRating, songInfo_t **head, songInfo_t **tail
* RETURNS : int
*/
int insertIntoListSortedByRating(char* inputArtistName, char* inputSongTitle, int inputRating, songInfo_t **head, songInfo_t **tail) {

	songInfo_t *newBlock = NULL;
	songInfo_t *beforeElement = NULL;
	songInfo_t *afterElement = NULL;
	int length = 0;

	// allocate a block of memory for new record
	newBlock = (songInfo_t *)malloc(sizeof(songInfo_t));
	if (newBlock == NULL)
	{
		printf("Error! No more memory!\n");
		return 0;
	}


	//malloc name
	length = strlen(inputSongTitle);
	if ((newBlock->title = (char *)malloc(length + 1)) == NULL) {

		printf("Error! No more memory!\n");

	}//eo if

	strcpy(newBlock->title, inputSongTitle);


	//malloc artist
	length = strlen(inputArtistName);
	if ((newBlock->artist = (char *)malloc(length + 1)) == NULL) {

		printf("Error! No more memory!\n");

	}//eo if

	strcpy(newBlock->artist, inputArtistName);

	newBlock->rating = inputRating;

	newBlock->prev = newBlock->next = NULL;

	// now link this record to the list in the appropriate place
	if (*head == NULL)
	{
		// empty list, so set head and tail
		*head = *tail = newBlock;
		return 1;
	}

	else if ((*head)->rating >= inputRating) 
	{
		// we're inserting at the front of the list

		// set the next pointer for the newBlock record to be the
		// location that used to be at the front of the list
		newBlock->next = *head;
		// set the old head's prev to point to the new start of the list
		(*head)->prev = newBlock;
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

		beforeElement = *head;		// first item in list
		afterElement = (*head)->next;	// second item in list 

		while (afterElement != NULL)
		{
			if (afterElement->rating >= inputRating)
			{
				// we've found a name in the list that is either equal to or greater 
				// than the one we're entering now
				break;
			}
			beforeElement = afterElement;
			afterElement = afterElement->next;
		}	

			// add the new node here, between beforeElement and afterElement
		newBlock->prev = beforeElement;
		newBlock->next = afterElement;
		beforeElement->next = newBlock;
		// are we at the end?
		if (afterElement == NULL)
		{
			*tail = newBlock;
		}
		else
		{
			afterElement->prev = newBlock;
		}

	}	

	return 1;


}//eo int insertIntoListSortedByRating(char* inputArtistName, char* inputSongTitle, int inputRating, struct songInfo **head, struct songInfo **tail) {








 /*
 * FUNCTION : insertIntoListSortedByName
 *
 * DESCRIPTION : This function inserts a node into the linked list that is sorted by name.

 *
 * PARAMETERS :char* inputArtistName, char* inputSongTitle, int inputRating, songInfo_t **head, songInfo_t **tail
 * RETURNS : int
 */
int insertIntoListSortedByName(char* inputArtistName, char* inputSongTitle, int inputRating, songInfo_t **head, songInfo_t **tail) {

	songInfo_t *newBlock = NULL;
	songInfo_t *beforeElement = NULL;
	songInfo_t *afterElement = NULL;
	int length = 0;

	// allocate a block of memory for new record
	newBlock = (songInfo_t *)malloc(sizeof(songInfo_t));
	if (newBlock == NULL)
	{
		printf("Error! No more memory!\n");
		return 0;
	}

	//malloc name
	length = strlen(inputSongTitle);
	if ((newBlock->title = (char *)malloc(length + 1)) == NULL) {

		printf("\nMalloc ERROR");

	}//eo if

	strcpy(newBlock->title, inputSongTitle);


	//malloc artist
	length = strlen(inputArtistName);
	if ((newBlock->artist = (char *)malloc(length + 1)) == NULL) {

		printf("\nMalloc ERROR");

	}//eo if

	strcpy(newBlock->artist, inputArtistName);

	newBlock->rating = inputRating;

	newBlock->prev = newBlock->next = NULL;

	// now link this record to the list in the appropriate place
	if (*head == NULL)
	{
		// empty list, so set head and tail
		*head = *tail = newBlock;
		return 1;
	}

	else if (strcmp((*head)->artist, inputArtistName) >= 0) 
	{
		// we're inserting at the front of the list

		// set the next pointer for the newBlock record to be the
		// location that used to be at the front of the list
		newBlock->next = *head;
		// set the old head's prev to point to the new start of the list
		(*head)->prev = newBlock;
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

		beforeElement = *head;		// first item in list
		afterElement = (*head)->next;	// second item in list 

		while (afterElement != NULL)
		{
			if (strcmp(afterElement->artist, inputArtistName) >= 0)
			{
				// we've found a name in the list that is either equal to or greater 
				// than the one we're entering now
				break;
			}
			beforeElement = afterElement;
			afterElement = afterElement->next;
		}	

		// add the new node here, between beforeElement and afterElement
		newBlock->prev = beforeElement;
		newBlock->next = afterElement;
		beforeElement->next = newBlock;
		// are we at the end?
		if (afterElement == NULL)
		{
			*tail = newBlock;
		}
		else
		{
			afterElement->prev = newBlock;
		}

	}	

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

void printSongInfo(struct songInfo *head) {

	songInfo *ptr = head;
	// follow the chain until the pointer is null


	printf("\nSong Artist ----------------------- Song Name ------------------------- Rating");


	while (ptr != NULL)
	{

		printf("\n%-35s %-35s %-5d", ptr->artist, ptr->title, ptr->rating);

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





 /*
 * FUNCTION : findSong
 *
 * DESCRIPTION : This function finds a song by searching with the name, title and rating. 
 If match is found, a ptr to the location is returned.

 If not found, NULL is returned.

 *
 * PARAMETERS : struct songInfo *head, char* inputArtistName, char* inputSongTitle, int inputRating
 * RETURNS : songInfo_t *
 */

songInfo_t *findSong (struct songInfo *head, char* inputArtistName, char* inputSongTitle, int inputRating){

	songInfo_t *ptr = head;
	// follow the chain until the pointer is null
	int newSongRating = 0;


	while (ptr != NULL)
	{

		if (stricmp(ptr->artist, inputArtistName) == 0) {
				
			if (stricmp(ptr->title, inputSongTitle) == 0) {

				if (ptr->rating == inputRating) {

					printf("Enter New Song Rating (1 to 5): ");
					scanf("%d", &newSongRating);

					if (newSongRating == ptr->rating) {

						break;

					}//eo if (newSongRating == ptr->rating) {

					else if ((newSongRating > 0) && (newSongRating <= 5)) {
						ptr->rating = newSongRating;

						return ptr;
						
					}//eo else if ((newSongRating > 0) && (newSongRating < 5)) {
	
				}//eo if (ptr->rating == inputRating) {

			}//eo if (strcmp(ptr->title, inputSongTitle) == 0) {

		}//eo if (strcmp((*head)->artist, inputArtistName) == 0) {


		ptr = ptr->next;

	}//eo while (ptr != NULL)

	return NULL;

}//eo  void printSongInfo(struct songInfo *head){




 /*
 * FUNCTION : deleteNode
 *
 * DESCRIPTION : This function deletes a requested node from the linked list.

 *
 * PARAMETERS :songInfo_t *node, songInfo_t **head, songInfo_t **tail
 * RETURNS : none
 */

void deleteNode(songInfo_t *node, songInfo_t **head, songInfo_t **tail) {

	if ((node == *head) && (node == *tail )) {
		//then there is only 1 item in the list.

		*head = NULL;
		*tail = NULL;
		free(node);
		
	}//eo if (*head == *tail ) {

	 //are we at the beginning of list?
	else if (node == *head) {
		
		//capture the next data block
		songInfo_t *secondElement = node->next;

		//head needs to equal next data block
		*head = node->next;

		//prev is now start so = NULL
		secondElement->prev = NULL;

	}//eo else if (node == *head) {

	else {

		if (node == *tail) {

			songInfo_t *secondlastElement = node->prev;
			
			//adjust the tail
			*tail = node->prev;
			//null out the next pointer for what used to be the second last item
			secondlastElement->next = NULL;

		}//eo if (node == *tail) {

		else {

			songInfo_t *precedingElement = node->prev;
			songInfo_t *followingElement = node->next;

			followingElement->prev = precedingElement;

			precedingElement->next = followingElement;

		}//eo else

	}//eo else

	free(node);

	
}//eo  void deleteNode(songInfo_t *node, songInfo_t **head, songInfo_t **tail) {

