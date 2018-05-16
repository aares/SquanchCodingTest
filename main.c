#include <stdio.h>
#include <stdbool.h>

//Aaron Taylor
//15 May 2018
//String word counter without using string library for the sake of, I guess.

int CountNumWordsInString(const char* InString)
{
	int i = 0; //i is for iterator, which moves the loop along
	int wordCount = 0;

	char whiteSpace = ' ';

	//only issue here is getting passed a null array, I think.
	while (InString[i] != '\0')
	{
		//if whitespace, skip
		if (InString[i] == whiteSpace)
		{
			i++;
		}
		//if anything except a whitespace
		if (InString[i] != whiteSpace)
		{
			//while not whitespace or null, continues to move until next whitespace/null
			//upon reaching, breaks the loop and adds a word count
			//had a bug where after the end of the word, it would continue to iterate the array
			//(despite the original condition breaking on null, had to repeat here)
			while (InString[i] != whiteSpace && InString[i] != '\0')
			{
				i++;
			}
			wordCount++;
		}
	}
	return wordCount;
}

void main()
{
	int wordCount = 0; //honestly the program could do without this variable, but for the sake of not jumbling up future code 
	char inStr[50]; //and for the sake of adding unnecessary comments, I added more lines up here

	printf("Type some bullshit in the console: "); //prompt the monkeyughhhhhhhhhuser to use the program
	fgets(inStr, 50, stdin);

	printf("\nYou managed to summon the brain cells to type: "); //congrats, he used the program
	puts(inStr);

	printf("\nIn case you couldn't count the amount of words in your sentence: "); //ya know, for if the user actually had an arithmetic related disability

	char testStr[50] = { ' ', ' ', 'e', 'a', 't', ' ', 's', 'h', 'i', 't', ' ', 'i', 'd', 'i', 'o', 't' };
	wordCount = CountNumWordsInString(testStr);
	printf("%d", wordCount);
}

