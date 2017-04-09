/*
 * =====================================================================================
 *
 *       Filename:  patos_task2.c
 *       	Usage:  ./patos_task2.c
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/09/2017 01:27:06 AM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Tyler Madsen (), tylermadsen@mail.weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

/* Local Libraries */


/* Function Prototypes */
void Usage(void);
void ReadFile(char *file, float nums[], float x[], float y[]);

/* Main Program */
int main(int argc, char *argv[])
{
	float x[4], y[4], nums[10];
	float sumx = 0.0, sumy = 0.0, sumxy = 0.0, sumx2 = 0.0;

	if(argc != 2)
	{
		Usage();
	}

	ReadFile(argv[1], nums, x, y);

	for(int i = 0; i < 4; i++)
	{
		printf("x[%d] = %.2f, y[%d] = %.2f\n", i, x[i], i, y[i]);
	}

	return 0;
}


/* Function Definitions */
void Usage(void)
{
	printf("Error!\nCouldn't open file\n");
	printf("Expecting read file.\n./task2 <file>\n");
	exit(1);

	return;
}

void ReadFile(char *file, float nums[], float x[], float y[])
{
	int i, n, m;
	int count = 0;
	FILE *inFile = fopen(file, "r");

	if(inFile == NULL)
	{
		Usage();
		exit(2);
	}

	while(fscanf(inFile, "%f", &nums[i])!= EOF)
	{
		if(count == 0)
		{
			x[n] = nums[i];
			n++;
			count = 1;
		}
		else
		{
			y[m] = nums[i];
			m++;
			count = 0;
		}
		i++;
	}

	return;
}


