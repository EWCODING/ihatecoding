#include <stdio.h>
#include <stdlib.h>


int ReadNumber(FILE *File);
char ReadInfo(FilePointer);


typedef struct Pixel {		//a struct defining each pixel in the image
	int R;
	int G;
	int B;
}Pixel;



void main (int argc, char* argv[])

	{
		FILE* FilePointer;
		FilePointer = NULL;

		int nRows;
		int nColumns;
		char DescriptionLine;

		fopen_s(&FilePointer, argv[1],"r");

		nRows = ReadNumber(FilePointer);
		nColumns = ReadNumber(FilePointer);

		DescriptionLine = ReadInfo(FilePointer);


		Pixel **InputImage = (Pixel **)malloc(nRows * sizeof(Pixel *));			//defines 2d array



	}
//Function 3




	//Function 2
char* ReadInfo (FILE *File)
{
	//function to read in the desctription information from the second line
	//Characters read in from the line saved to variable DescriptionLine
	//and then assigned to CurrentCharacter

	char DescriptionLine[255];
	char CurrentCharacter;
	int i=0;

	while((i<255) && (CurrentCharacter!='\n'))
	{
		scanf_s(file,"%1s",CurrentCharacter);
		DescriptionLine[i] = CurrentCharacter;
		i++;
	}
		DescriptionLine[i] = \0;				//makes the last part of the string a terminator
}


	//Function 1
	int ReadNumber(FILE *File)
{
		//Function reads in an integer from the input file as a string
		//and then converts it to an integer. The fscanf_s function
		//stops when a space is reached. Strtoll ignores anyhting
		//that's not an integer.

		char InputString[15];          													 //Creating a character array to store the data from the fil being read in
		int Integer;
		char* StopAddress;																			//stores the address of where the the fscanf stops to variable StopAddress

		fscanf_s(file, "%15s", InputString, 15);          			//Reads in the information from the file and stores it to the variable InputString
		Integer = strtol(InputString, &StopAddress, 10);				//Converts the string InputString to an integer value stored as Integer

		                                                        //If statement to check whether or not the string has been converted
																														//Works by comparing the start address to the end address of the InputString
																														//If they are different a conversion has been made otherwise the conversion
																														//has failed and there has been an error
		if (*StopAddress != *InputString)
		{
			return(Integer);
		}																												//If a string was converted to an integer, the integer is returned
		else
		{
			printf("The input file is not valid!"\n);	           //Error message to let user know the file is not valid
		}
}
