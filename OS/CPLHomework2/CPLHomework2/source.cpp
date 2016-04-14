// CPLproject2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#define TEXT "String manipulation is not that difficult once you get the hang of it"

//resets the buffer string to TEXT
void resetBuffer(char text[], int len)
{
	for (int i = 0; i < len; i++)
	{
		text[i] = TEXT[i];
	}
}

// reverse the string
void reverse(char text[], int len)
{
	for (int i = 0; i < len / 2; i++)
	{
		// use xor to change without buffer
		text[i] ^= text[len-1-i];
		text[len - 1 - i] ^= text[i];
		text[i] ^= text[len - 1 - i];
	}
}

// make all uppercase letters lower case
void lower(char text[], int len)
{
	for (int i = 0; i < len; i++)
	{
		if (text[i] >= 65 && text[i] <= 90)
			text[i] += 32;
	}
}

// uppercase the first letter fo each word
void upper(char text[], int len)
{
	// for the first letter make sure its capped
	if (text[0] >= 97 && text[0] <= 122)
		text -= 32;

	for (int i = 0; i < len; i++)
	{
		if (text[i] == 32 && (text[i + 1] >= 97 && text[i + 1] <= 122)) // if space and letter is lowercase
			text[i + 1] -= 32; // capitalize it
	}
}

// revese the order of words in the string
void reverseWord(char text[], int len)
{
	// reverse the whole string so the words are in the right spots
	reverse(text, len);

	// now fix just the words
	int iter1 = 0, iter2 = 0;
	while (iter2 < len)
	{		
		if (text[iter2] == 32) // if space
		{
			for (int i = 0; i < (iter2-iter1)/2; i++) // use xor to change posisitons of the letters in that word
			{
				text[iter1+i] ^= text[iter2 - 1 - i];
				text[iter2 - 1 - i] ^= text[iter1 + i];
				text[iter1 + i] ^= text[iter2 - 1 - i];
			}
			iter1 = iter2 + 1; // start of the next word.
		}	
		iter2++;
	}

	// the last word still needs to be done
	for (int i = 0; i < (len - iter1) / 2; i++)
	{
		text[iter1 + i] ^= text[len - 1 - i];
		text[len - 1 - i] ^= text[iter1 + i];
		text[iter1 + i] ^= text[len - 1 - i];
	}
}

int main()
{
	// string buffer
	char text[1024] = TEXT;

	// get the strings length
	int len;
	int i = 0;
	for (; i < 1024; i++)
	{
		// exit if equal to null
		if (text[i] == '\0')
			break;
	}
	len = i;
	
	// send the reverse function
	reverse(text, len);
	cout << text << endl;
	resetBuffer(text, len);

	// lowercase all
	lower(text, len);
	cout << text << endl;
	resetBuffer(text, len);

	// uppercase the first letter of a word
	upper(text, len);
	cout << text << endl;
	resetBuffer(text, len);

	// send the reverse function
	reverseWord(text, len);
	cout << text << endl;
	resetBuffer(text, len);
	

	system("pause");
    return 0;
}

