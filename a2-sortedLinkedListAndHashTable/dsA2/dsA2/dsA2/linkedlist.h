/*
* FILE : linkedlist.h
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


//CONSTANTS
#pragma once


typedef struct nameInfo {

	char* name;
	struct nameInfo *next;
}nameInfo_t;

//eo CONSTANTS


//PROTOTYPES
int insertIntoListSortedByName(char* inputName, nameInfo_t **head);
void printNameInfo(struct nameInfo *head);
nameInfo *freeNameInfo(struct nameInfo *head);
nameInfo_t *searchLinkedList(struct nameInfo *head, char* inputName, int* comparisonCount);
void searchForWordTwice(char *searchWord, nameInfo_t *linkedList, nameInfo_t *hashTable[], int comparisonCount[2]);
//eo PROTOTYPES

