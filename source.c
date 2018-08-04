#include <stdio.h>
#include <stdlib.h>



void main (int argc, char* argv[])

	{
		FILE* FilePointer;
		FilePointer = NULL;

		fopen_s(&FilePointer, argv[1],"r");






	}


//maria, this whole function should be rewritten with different variable names and comments

int read1Int(FILE *file) {
/*this function accepts a file 'object' and returns an integer,
from the space seperated file. it leverages the fscanf function which reads
from a file until it reaches a 'space' character. this is very convenient */

	char tempBuffer[15];          					 //will allow this to work with numbers up to 10^1024 (ish)
	int number;
	char* delimiter;
	fscanf_s(file, "%15s", tempBuffer, 15);          //read from the file object, determines that it is a string type and stores in the buffer
	number = strtol(tempBuffer, &delimiter, 10);	//returns an integer into number and a char pointer to delimiter
	if (*delimiter != *tempBuffer){					//if a conversion didnt happen, the delimiter will be equal to the original value of tempbuffer. error condition.
		return(number);								//if it happened, return it.
	}
	else{
		//figure out a nice way to exit the program
	}
}
