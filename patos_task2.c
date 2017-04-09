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

#define MAX 4

/* Local Libraries */


/* Function Prototypes */
void Usage(void);
void ReadFile(char *file, float nums[], float x[], float y[]);
void Sum(float nums[], float* sum);

/* Main Program */
int main(int argc, char *argv[])
{
	float x[MAX], y[MAX], xy[MAX], x2[MAX], nums[10];
	float sumx = 0.0, sumy = 0.0, sumxy = 0.0, sumx2 = 0.0;
	float m, b;
	int sum2x;

	if(argc != 2)
	{
		Usage();
	}

	ReadFile(argv[1], nums, x, y);

	for(int i = 0; i < MAX; i++)
	{
		xy[i] = (x[i] * y[i]);
		x2[i] = (x[i] * x[i]);
	}

	Sum(x, &sumx);
	Sum(y, &sumy);
	Sum(xy, &sumxy);
	Sum(x2, &sumx2);

	sum2x = (sumx * sumx);
	m = (((sumx * sumy) - (MAX * sumxy)) / (sum2x - (MAX * sumx2)));
	b = (((sumx * sumxy) - (sumx2 * sumy)) / (sum2x - (MAX * sumx2)));

	printf("Range of altitudes in km:\n%.2f to %.2f\n\n", x[0], x[MAX - 1]);
	printf("Linear model:");
	printf("ozone-mix-ratio = %.2f altitude + %.2f\n", m, b);

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

void Sum(float nums[], float* sum)
{
	for(int i = 0; i < MAX; i++)
	{
		(*sum) += nums[i];
	}

	return;
}

