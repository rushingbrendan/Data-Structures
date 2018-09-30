/*
* FILE : dsA2.cpp
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



int main(void) {

	char inputFile[FILE_NAME_LENGTH];
	bool endCheck = false;
	std::string inputSearch = { 0 };
	int searchCount = 0;

	struct nameInfo *head_sortby_name = NULL;
	int comparisonCount[2] = { 0 };
	int totalcomparisonCount[2] = { 0 };

	nameInfo_t *songInfoToDelete = NULL;
	nameInfo_t *hashTables[NUMBER_OF_BUCKETS] = { NULL };

	strcpy(inputFile, fileName);
	
	//get names from text file
	loadData(inputFile, &head_sortby_name, hashTables);
		
	//get names until user enters a "."
	while (endCheck == false){
		
		printf("\n");
		std::getline(std::cin, inputSearch);

		if (inputSearch[0] == '.') {

			endCheck = true;
			printf("\n\tTotal Number of Searches: %d", searchCount);
			printf("\n\tTotal Number of Comparisons in Linked Lists: %d", totalcomparisonCount[0]);
			printf("\n\tTotal Number of Comparisons in Hash Table: %d\n", totalcomparisonCount[1]);

		}

		if (!endCheck) {

			searchForWordTwice(&inputSearch[0], head_sortby_name, hashTables, comparisonCount);
			totalcomparisonCount[0] = totalcomparisonCount[0] + comparisonCount[0];
			totalcomparisonCount[1] = totalcomparisonCount[1] + comparisonCount[1];

		}
			
		searchCount++;
	} //eo while (endCheck == false){

	
	//free linked list
	freeNameInfo(head_sortby_name);

	//free all hash tables
	for (int i = 0; i < NUMBER_OF_BUCKETS; i++) {

		freeNameInfo(hashTables[i]);
	}

	return EXIT_SUCCESS;


}//eo main





 /*
 * FUNCTION : loadData
 *
 * DESCRIPTION : This function reads the names from the text file and puts them into the linked list and hash tables

 *
 * PARAMETERS :char* FILENAME, nameInfo_t **head, nameInfo_t *hashTables[]
 * RETURNS : int
 */
int loadData(char* FILENAME, nameInfo_t **head, nameInfo_t *hashTables[]) {

	unsigned long hashResult = 0;
	int count = 0;


	std::ifstream inFile(FILENAME);

	std::string inputLine;


	while (std::getline(inFile, inputLine)) {

		//insert name into linked list
		insertIntoListSortedByName(&inputLine[0], head);
		
		//get has result
		hashResult = hashFunction(&inputLine[0]);

		//insert name into hash table linked list
		insertIntoListSortedByName(&inputLine[0], &hashTables[hashResult]);
		
		//get names until count is reached
		if (count == MAX_NAME_COUNT) {

			break;

		}//eo count

		
	}//eo while (std::getline(infile, inputLine)) {

	//close file
	inFile.close();


	return SUCCESS;

}//eo int loadData(void) {









