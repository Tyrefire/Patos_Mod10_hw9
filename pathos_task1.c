/*
 * =====================================================================================
 *
 *       Filename:  pathos_task1.c
 *    Description:  reads an input file and creates an output file with that data
 *
 *        Created:  04/07/2017 12:31:17 AM
 *         Author:  Christopher Bowen (), christopherbowen@mail.weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>
#include <string.h>
/* Function Prototypes */
void Usage(char *argv[]);
void ReadFile(char *fname, float num[]);
FILE *OpenCheckFile(char *name);
void WriteFile(FILE *sFile, float num[]);
/* Main Program */
int main(int argc, char *argv[])
{
	float total, avg;
	float num[30];
	if(strcmp(argv[1],"--help")==0 || argc != 3)
	{
		Usage(argv);
	}
	ReadFile(argv[1], num);
	FILE *outFile = OpenCheckFile(argv[2]);
	if(outFile == NULL)
	{
		printf("awesome\n");
	}
	WriteFile(outFile, num);
	for(int i=0; i<12; i++)
	{
		total+=num[i];
	}
	avg = total/12;
	fprintf(outFile, "--------\n\n");
	fprintf(outFile, "Total:");
	fprintf(outFile, "%.4f\n\n", total);
	fprintf(outFile, "Avg:");
	fprintf(outFile, "%.4f\n", avg);
	return 0;
}


/* Function Defenitions */
void Usage(char *argv[])
{
	if(strcmp(argv[1],"--help")==0)
	{
		printf("Help info\n");
	}
	printf("first parameter is input file and second is output file name\n");
	printf("./Task1 <input> <output>\n");
}

void ReadFile(char *fname, float num[])
{
	FILE *inFile = fopen(fname, "r");
	if(inFile == NULL)
	{
		printf("couldn't open file");
		Usage(&fname);
		exit(1);
	}
	printf("succesfully opened file\n");
	int i = 0;
	while(fscanf(inFile, "%f", &num[i])!= EOF)
	{
		i++;
	}
	return;
}

FILE *OpenCheckFile(char *name)
{
	char i;
	FILE *inFile = fopen(name, "r");
	if(inFile == NULL)
	{
		inFile = fopen(name, "w");
	}
	else
	{
		printf("would you like to overwrite the output file (y or n): ");
		scanf(" %c", &i);
		if(i == 121)
		{
			inFile = fopen(name, "w");
		}
		else
		{
			exit(1);
		}
	}
	return inFile;
}

void WriteFile(FILE *sFile, float num[])
{
	for(int i=0; i< 12; i++)
	{
		fprintf(sFile, "%.4f", num[i]);
		fprintf(sFile, "\n");
	}
	printf("the file has successfully been written\n");
	return;
}



