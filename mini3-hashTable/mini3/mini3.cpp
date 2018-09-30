/*
* FILE : mini3.cpp
* PROJECT : PROG1370 - Data Structures
* PROGRAMMER : Brendan Rushing
* FIRST VERSION : 2018-05-25
* DESCRIPTION :
Program will take 10 words and use hash tables to store into memory
*
*/


//INCLUDE FILES

#include "dsA1.h"
#include "djb2.h"
//eo INCLUDE FILES



int main(void) {

	wordNode_t *head_sortby_name = NULL;
	wordNode_t *tail_sortby_name = NULL;
	char inputBuffer[STRING_LENGTH] = { 0 };

	wordNode_t arrayOfWords[ARRAY_SIZE];
	unsigned long returnHash = 0;
	int length = 0;
	
	for (int i = 0; i < ARRAY_SIZE; i++) {

		strcpy(arrayOfWords[i].word, "");
		arrayOfWords->next = NULL;

	}


	//GET NEW RECORD******************************************************

	while (!strcmp(inputBuffer, ".") == 0) {

		printf("\n Enter a word: ");
		scanf("%s", inputBuffer);

		returnHash = hashFunction(inputBuffer);

		printf("\n hash result: %lu", returnHash);

		length = strlen(arrayOfWords[returnHash].word);
		while (strlen(arrayOfWords[returnHash].word) != 0) {

			returnHash++;

			if (returnHash >= ARRAY_SIZE) {

				returnHash = 0;
			}
		}

		strcpy(arrayOfWords[returnHash].word, inputBuffer);
		insertIntoListSortedByName(inputBuffer, &head_sortby_name, &tail_sortby_name);



	}//eo while (!strcmp(inputBuffer, ".") == 0) {
 




	free songInfo
	freeSongInfo(head_sortby_name);



	return EXIT_SUCCESS;


}//eo main







