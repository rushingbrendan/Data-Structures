/*
* FILE : mini4.cpp
* PROJECT : PROG1370 - Data Structures - Mini4
* PROGRAMMER : Brendan Rushing
* FIRST VERSION : 2018-07-06
* DESCRIPTION :

You will keep track of strings as C++ string objects.

In main, declare a vector variable to contain your strings.

Create a loop that gets one word at a time from the user until they enter "." as the only thing on the input line.For this assignment, it is adequate to limit strings to one word at a time.Put the word into the vector.

Once the user is done entering words, set up a separate loop to search for words in the vector.Similar to the previous loop, get the searchable words one at a time until they enter ".".When you find the word, use printf() (or cout) to display "Success!".If you don't find the word, use printf() (or cout) to display "Not there!".

You should comment as normal.
*
*/


//INCLUDE FILES
#include <vector>
#include <malloc.h>	

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include <iostream>


//eo INCLUDE FILES

//CONSTANTS
#define WORD_LENGTH 41
//eo CONSTANTS



int main(void)
{
	std:: vector<char *> vectorStrings;	//create vector
	char *str = NULL;
	size_t s = 0;
	const int kStringLength = WORD_LENGTH;
	bool doneEnteringWords = false;
	bool wordFound = false;
	

	//ADD WORDS INTO LIST UNTIL . IS ENTERED

	while (doneEnteringWords == false){

		if (!doneEnteringWords) {

			std::cout << "Enter words (enter . when done ) : ";

			str = (char *)malloc(kStringLength);	//malloc the string

			if (str == NULL)
			{
				std::cout << "Out of memory" << std::endl;
				return EXIT_FAILURE;	
			}

			std::cin.getline(str, kStringLength);	//get line of max 41 chars

			if (strcmp(str, ".") == 0) {

				doneEnteringWords = true;
				break;
			}

			vectorStrings.push_back(str);			//add the string to end of vector
		}
		
	}//eo while

	
	doneEnteringWords = false;	//reset flag

	//GET WORDS TO SEARCH FOR - END WHEN . IS ENTERED

	while (doneEnteringWords == false) {
		
		wordFound = false;
		std::string inputSearch = { 0 };	//input search word
		doneEnteringWords = false;

		std::cout << "\nEnter a word to search for (enter . when done ) : ";

		std::getline(std::cin, inputSearch);	//get word

		//BREAK IF . IS ENTERED
		if (strcmp(&inputSearch[0], ".") == 0) {

			doneEnteringWords = true;
			break;
		}


		//LOOP THROUGH THE VECTOR TO SEARCH FOR WORD
		for (s = 0; s < vectorStrings.size(); ++s) {

			if (strcmp(&inputSearch[0], vectorStrings[s]) == 0) {

				wordFound = true;

			}//eo if (!doneEnteringWords) {		
		}


	if (wordFound) {

		printf("\nSuccess!");
	}

	else {

		printf("\nNot there");

	}

	}//eo while




	//FREE STRINGS STORED IN VECTOR
	while (vectorStrings.size() > 0){

		free(vectorStrings.back());
		vectorStrings.pop_back();

	}//eo while (vectorStrings.size() > 0)

	return EXIT_SUCCESS;
}
