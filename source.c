#include <stdio.h>
#include <stdlib.h>

#define MaxIntensity 255	//Maximum possible intensity defined

//a struct defining each pixel in the image
typedef struct Pixel {		
	int R;
	int G;
	int B;
	int Intensity;
}Pixel;

// functions declared
int ReadNumber(FILE *File);
void ReadInfo(FILE *InputFile, char* DescriptionLine);
Pixel ReadPixel(FILE *File);
void OuputFile(char* DescriptionLine, int nRows, int nColumns, char* OutName);





void main(int argc, char* argv[])

{
	
	char* InputName	;
	char* OutputName ;
	int Display = 0;
	float Scale = 0;

	
	FILE* InputFile;			//input and output files created
	InputFile = NULL;

	FILE* OutputFile;
	
	
	
	int nRows;					//variables created for the information being read from the input file
	int nColumns;
	char DescriptionLine[255];

	if ((argc < 3) || (argc > 5))
	{
		printf("Invalid number of input arguments!");
	}
	else if (argc == 3)				//if statement to assign the inputs to the correct 
	{							//input arguments are assigned to the correct 
		InputName = argv[1];	//variable names 
		OutputName = argv[2];
	}
	else if (argc == 4)
	{
		InputName = argv[2];
		OutputName = argv[3];
		if (argv[1][1] == 'd')
		{
			Display = 1;
		}
		else if(argv[1][1] == 's')
		{
			Scale = 1;
		}

		else
		{
			printf("Invalid format of arguments");
		}

	}
	else if (argc == 5)
	{
		Display = 1;
		Scale = 1;
		InputName = argv[3];
		OutputName = argv[4];

	}
	
	fopen_s(&InputFile, InputName, "r");			//files opened such that, the input file is opened 
	
	if (&InputFile == NULL) {						//error to let the user know that the file they tried to open is 
		perror("ERROR! \n");						//empty 
		while (1);
	}
	
	fopen_s(&OutputFile, OutputName, "w");			//for reading and the output is opened for writing



	nRows = ReadNumber(InputFile);					//the ReadNumber function is called to read in the number 
	nColumns = ReadNumber(InputFile);				//of rows and columns of data from the input file and
													//assign them to variable names

	char trash = 't';

	fscanf_s(InputFile, "%c", &trash , 1);
	ReadInfo(InputFile, DescriptionLine);			//ReadInfo function is called to read in the description line
													//and assign it to a variable

	fprintf_s(OutputFile, "%s", "P2");				//writes to the output file the things
	fprintf_s(OutputFile, "%c", '\n');				//that appear on all of them
	fprintf_s(OutputFile, "%s", DescriptionLine);
	fprintf_s(OutputFile, "%c", '\n');
	fprintf_s(OutputFile, "%d", nRows);
	fprintf_s(OutputFile, "%c", ' ');
	fprintf_s(OutputFile, "%d", nColumns);
	fprintf_s(OutputFile, "%c", '\n');	
	fprintf_s(OutputFile, "%d", MaxIntensity);
	fprintf_s(OutputFile, "%c", '\n');	



	Pixel **PixelArray = (Pixel **)malloc(nRows * sizeof(Pixel *));			//creates the 2d array by allocating memory to it


	for (int i = 0; i < nRows; i++)
	{																		//goes through each row of the array and allocates a column of pixels
		PixelArray[i] = (Pixel *)malloc(nRows * sizeof(Pixel));
	}

																			//the array is then iterated through twice
	for (int i = 0; i< nRows;i++)											//the first iteration goes through and reads the pixel values 
	{																		//into the array using the ReadPixel function
		for (int j = 0; j <nColumns; j++)
		{
			PixelArray[i][j] = ReadPixel(InputFile);

		}

	}


	if (Display == 1)								//if statement to let the program know whether or not the user wants the image displayed
	{


		for (int i = 0; i < nRows;i++)											//the second iteration goes through and writes the pixel
		{																		//values to the file
			for (int j = 0; j < nColumns; j++)
			{

				fprintf_s(OutputFile, "%d", PixelArray[i][j].Intensity);
				fprintf_s(OutputFile, "%c", ' ');								//this ensures a space between each value
			}
			fputs("\n", OutputFile);

		}
	}
}



//Function 3
//This function is responsible for carrying out the actual 
//conversion between the integer triplet from the couloured
//image data into a single integer greyscale value
Pixel ReadPixel(FILE *File)
{
	//function to find the intensity of the pixel
	//this is done by averaging the red, green and blue values

	Pixel pix;

	pix.R = ReadNumber(File);		//calls on the ReadNumber function to
	pix.G = ReadNumber(File);		//to read in each of the integers
	pix.B = ReadNumber(File);

	pix.Intensity = ((pix.R + pix.G + pix.B) / 3); //greyscale value worked out
												   //by averaging colour values
	
	return(pix);		//function returns a pix, which is of type Pixel

}




//Function 2
void ReadInfo(FILE *InputFile, char* DescriptionLine)
{
	//function to read in the description information from the second line
	//Characters read in from the line saved to variable DescriptionLine
	//and then assigned to CurrentCharacter

	char CurrentCharacter = 'j';				//initialisations of Current Character
	int i = 0;									//and i

	while ((i<255) && (CurrentCharacter != '\n'))
	{
		fscanf_s(InputFile, "%c", &CurrentCharacter, 1);
		DescriptionLine[i] = CurrentCharacter;
		i++;			//i incremented every loop
	}
	DescriptionLine[i] = '\0';		//terminator to tell the program the string
									//has ended
	return;
}


//Function 1
int ReadNumber(FILE *File)
{
	//Function reads in an integer from the input file as a string
	//and then converts it to an integer. The fscanf_s function
	//stops when a space is reached. Strtoll ignores anyhting
	//that's not an integer.

	char InputString[15];          										//Creating a character array to store the data from the file being read in
	int Integer;
	char* StopAddress;													//Stores the address of where the the fscanf stops to variable StopAddress

	fscanf_s(File, "%15s", InputString, 15);          			        //Reads in the information from the file and stores it to the variable InputString
	Integer = strtol(InputString, &StopAddress, 10);				    //Converts the string InputString to an integer value stored as Integer

																		//If statement to check whether or not the string has been converted
																		//Works by comparing the start address to the end address of the InputString
																		//If they are different a conversion has been made otherwise the conversion
																		//has failed and there has been an error
	if (*StopAddress != *InputString)
	{
		return(Integer);
	}																	//If a string was converted to an integer, the integer is returned
	else
	{
		printf("The input file is not valid\n");	                    //Error message to let user know the file is not valid
		return(1);
	}
}
