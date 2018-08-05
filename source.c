#include <stdio.h>
#include <stdlib.h>

#define MaxIntensity 255

int ReadNumber(FILE *File);
char ReadInfo(File *InputFile);
Pixel ReadPixel(FILE *File);
void WriteOutputPixel(FILE *File, Pixel OutputPixel, int MaxIntensity);
void OuputFile(char* DescriptionLine,int nRows, int nColumns, char* OutName);

typedef struct Pixel {		//a struct defining each pixel in the image
	int R;
	int G;
	int B;
	int Intensity;
}Pixel;



void main (int argc, char* argv[])

	{
		char* InputName;
		char* OutputName;
		int Display =0;
		float Scale=0;


		FILE* InputFile;
		InputFile = NULL;

		File* OutputFile;

		int nRows;
		int nColumns;
		char DescriptionLine;
		Pixel Value;

		if(argc == 3)
		{
			InputName = argv[1];
			OutputName = argv[2];
		}
		else if(argc == 4 )
		{
			InputName = argv[2];
			OutputName = argv[3];
			if(argv[1][1] == "d")
			{
				Display = 1;
			}
			elseif(argv[1][1] == "s")
			{
				Scale = 1;
			}

			else
			{
			printf("Invalid number of arguments");
			}

		}
		else if (argc == 5)
		{
			Display = 1;
			Scale = 1;
			InputName = argv[3];
			OutputName = argv[4];

		}

		fopen_s(&InputFile, InputName,"r");
		fopen_s(&OutputFile,OutputName,"w");

		nRows = ReadNumber(InputFile);
		nColumns = ReadNumber(InputFile);

		DescriptionLine = ReadInfo(InputFile);
		fputs("P2",OutputFile);
		fputs("\n", OutputFile);
		fputs(DescriptionLine,OutputFile);
		fputs("\n",OutputFile);
		fputs(nRows,OutputFile);
		fputs(" ",OutputFile);
		fputs(nColumns,OutputFile);
		fputs("\n",OutputFile);




		Pixel **PixelArray = (Pixel **)malloc(nRows * sizeof(Pixel *));			//creates the 2d array


		for (int i = 0; i < nRows; i++)
		{														//goes through each row of the array and allocates a column of pixels
		PixelArray[i] = (Pixel *)malloc(nRows * sizeof(Pixel));
		}

		for(int i=0; i< nRows;i++)
		{
			for(intj=0; j <n; Columns, j++)
			{
				PixelArray[i][j]= ReadPixel(InputFile);

			}
			fputs("\n",OutputFile);

		}



		{
			//call function
		}

		for(int i=0; i< nRows;i++)
		{
			for(intj=0; j <n; Columns, j++)
			{

				fprintf_s(OutputFile,"%d",PixelArray[i][j].Intensity);
			}
			fputs("\n",OutputFile);

		}

}


//Function 4
void WriteOutputPixel(FILE *File, Pixel OutputPixel)
	{
		Pixel PixIntensity= ReadPixel()
		fputs(pix.Intensity, OutputFile);

	}
//Function 3
Pixel ReadPixel(FILE *File)
	{
		//function to find the intensity of the pixel
		//this is done by averaging the red, green and blue values

		Pixel pix;

		pix.R = ReadNumber(File);
		pix.G = ReadNumber(File);
		pix.B = ReadNumber(File);

		pix.Intensity = ((pix.R + pix.G + pix.B)/3);
		return(pix);

	}




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

		char InputString[15];          										//Creating a character array to store the data from the file being read in
		int Integer;
		char* StopAddress;													//Stores the address of where the the fscanf stops to variable StopAddress

		fscanf_s(file, "%15s", InputString, 15);          			        //Reads in the information from the file and stores it to the variable InputString
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
			printf("The input file is not valid!"\n);	                    //Error message to let user know the file is not valid
		}
}
