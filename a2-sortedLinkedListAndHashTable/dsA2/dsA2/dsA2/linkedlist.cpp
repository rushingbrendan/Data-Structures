/*
* FILE : linkedlist.cpp
* PROJECT : PROG1370 - Data Structures - Assignment #2
* PROGRAMMER : Brendan Rushing
* FIRST VERSION : 2018-07-05
* DESCRIPTION :

Instead of getting the words to load into the hash table from the user,
you must load at least 2000 words from a file called words.txt as input (using file I/O).
It is OK if you share the words with classmates for this.
Make sure that your words are sorted in random order (more about this later).
The words.txt file must be in the same directory as your source code.
It's OK to use more than 2000 words but don't have more than 10000.

When you load a word into the hash table, also load the words into one very long sorted linked list.
You must use the same function for inserting into the sorted linked list as for inserting into the hash table bucket's linked list.

Make the hash table 127 buckets in size.

You must create a function called searchLinkedList that searches a sorted linked list for a word and returns a pointer to the node containing the word (if found) or NULL.
This function must return NULL immediately after you pass the point in the linked list where the word would have been found if it was in the linked list.
The function takes three parameters:
char * searchWord: word to search for (entered by the user)
struct linkedList * linkedList: linked list to search (in your program, you can call the linked list node struct anything that makes sense)
int * comparisonCount: pointer to int filled in by the function with the count of strcmp comparisons done in searching the linked list

Create a search function called searchForWordTwice. It returns nothing and will have the following parameters:
char * searchWord: word to search for (entered by the user)
struct linkedList * linkedList: linked list to search
struct linkedList * hashTable[]: hash table to search
int comparisonCount[2]: array containing the count of strcmp comparisons done in searching the extremely-long sorted linked list (element 0) and in searching the hash table (element 1)
It must call your linked list search function and then displays one of the following messages once the search is done:
"word was found in the list in number comparisons", where word is the word being searched for, list is either "linked list" or "hash table bucket" and number equals the number of times that strcmp was called
"word was NOT found in the list in number comparisons"
You will use this search function to search the hash table bucket and the sorted linked list.
Don't worry about the grammatical inconsistency of possibly displaying "1 comparisons".
Indent the message displayed by one TAB ('\t').

Once you are finished the loop, display the total number of searches, the total number of comparisons done by searching the sorted linked list, and the total number of comparisons done by searching the hash table.

*
*/

//INCLUDE FILES

#include "dsA2.h"
#include "linkedlist.h"
//eo INCLUDE FILES







 /*
 * FUNCTION : insertIntoListSortedByName
 *
 * DESCRIPTION : This function inserts a node into the linked list that is sorted by name.

 *
 * PARAMETERS :char* inputArtistName, char* inputSongTitle, int inputRating, songInfo_t **head, songInfo_t **tail
 * RETURNS : int
 */
int insertIntoListSortedByName(char* inputName, nameInfo_t **head){

	nameInfo_t *newBlock = NULL;
	nameInfo_t *beforeElement = NULL;
	nameInfo_t *afterElement = NULL;
	int length = 0;

	// allocate a block of memory for new record
	newBlock = (nameInfo_t *)malloc(sizeof(nameInfo_t));
	if (newBlock == NULL)
	{
		printf("Error! No more memory!\n");
		return 0;
	}

	//malloc name
	length = (int)strlen(inputName);
	if ((newBlock->name = (char *)malloc(length + 1)) == NULL) {

		printf("\nMalloc ERROR");

	}//eo if

	strcpy(newBlock->name, inputName);

	newBlock->next = NULL;

	// now link this record to the list in the appropriate place
	if (*head == NULL)
	{
		// empty list, so set head and tail
		*head = newBlock;
		return 1;
	}

	else if (strcmp((*head)->name, inputName) >= 0)
	{
		// we're inserting at the front of the list

		// set the next pointer for the newBlock record to be the
		// location that used to be at the front of the list
		newBlock->next = *head;
		// set the old head's prev to point to the new start of the list
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
			if (strcmp(afterElement->name, inputName) >= 0)
			{
				// we've found a name in the list that is either equal to or greater 
				// than the one we're entering now
				break;
			}
			beforeElement = afterElement;
			afterElement = afterElement->next;
		}

		// add the new node here, between beforeElement and afterElement

		newBlock->next = afterElement;
		beforeElement->next = newBlock;
	
	}

	return 1;

}//eo int insertIntoListSortedByName(char* inputArtistName, char* inputSongTitle, int inputRating, struct songInfo **head, struct songInfo **tail) {






 /*
 * FUNCTION : printNameInfo
 *
 * DESCRIPTION : This function prints the name and artist from all the songs to the screen

 *
 * PARAMETERS : struct nameInfo *head
 * RETURNS : none
 */

void printNameInfo(struct nameInfo *head) {

	nameInfo *ptr = head;
	// follow the chain until the pointer is null
	int count = 0;

	printf("\n NAME LIST - SORTED ALPHABETICALLY");


	while (ptr != NULL)
	{
		count++;
		printf("\n #%d  - %s", count, ptr->name);

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

nameInfo *freeNameInfo(struct nameInfo *head) {

	nameInfo *ptr = head;
	nameInfo *curr = head;

	// follow the chain until the pointer is null


	while (ptr != NULL)
	{

		curr = ptr;
		ptr = ptr->next;

		free(curr->name);
		free(curr);

	}//eo while (ptr != NULL)

	return NULL;
}//eo  void freeSongInfo(struct songInfo *head) {





 /*
 * FUNCTION : searchLinkedList
 *
 * DESCRIPTION : This function finds a song by searching with the name, title and rating.
 If match is found, a ptr to the location is returned.

 If not found, NULL is returned.

 *
 * PARAMETERS : struct nameInfo *head, char* inputName, int* comparisonCount
 * RETURNS : nameInfo_t *
 */

nameInfo_t *searchLinkedList(struct nameInfo *head, char* inputName, int* comparisonCount) {

	nameInfo_t *ptr = head;
	int counter = 0;
	// follow the chain until the pointer is null

	while (ptr != NULL)
	{
		counter++;
		int retCode = stricmp(ptr->name, inputName);

		if (retCode == 0) {

			*comparisonCount = counter;
			return ptr;

		}//eo if (strcmp((*head)->artist, inputArtistName) == 0) {

		if (retCode > 0) {

			*comparisonCount = counter;
			return NULL;
		}

		ptr = ptr->next;

	}//eo while (ptr != NULL)

	return NULL;

}//eo  void printSongInfo(struct songInfo *head){






 /*
 * FUNCTION : searchForWordTwice
 *
 * DESCRIPTION : This function finds a song by searching with the name, title and rating.
 If match is found, a ptr to the location is returned.

 If not found, NULL is returned.

 *
 * PARAMETERS : char *searchWord, nameInfo_t *linkedList, nameInfo_t *hashTable[NUMBER_OF_BUCKETS], int comparisonCount[2]
 * RETURNS : none
 */

void searchForWordTwice(char *searchWord, nameInfo_t *linkedList, nameInfo_t *hashTable[NUMBER_OF_BUCKETS], int comparisonCount[2]) {

	struct nameInfo *searchReturn = NULL;
	unsigned long hashResult = 0;

	searchReturn = searchLinkedList(linkedList,searchWord, &comparisonCount[0]);

	printf("\n\t%s was ", searchWord);
	if (searchReturn == NULL) {

		printf("NOT ");
	}

	printf("found in the linked list in %d comparisons.",comparisonCount[0]);
	

	hashResult = hashFunction(searchWord);
	//hashResult = hashResult + 1;
	searchReturn = searchLinkedList(hashTable[hashResult], searchWord, &comparisonCount[1]);

	printf("\n\t%s was ", searchWord);
	if (searchReturn == NULL) {

		printf("NOT ");
	}

	printf("found in the hash table bucket in %d comparisons.", comparisonCount[1]);

	

}//eo void searchForWordTwice(char *searchWord, nameInfo_t *linkedList, nameInfo_t *hashTable[]) {
