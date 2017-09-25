#include <stdio.h>
#include <stdlib.h>

/* Bubble sort, return number of swaps */
int sort(int length, int array[]);

/* Check if the array is sorted */
int isSorted(int length, int array[]);

/* Get a pointer to an array that lets the user know whether the element at an indice is greater the one that follows (except at the last indice) */
int* getPossibleSwaps(int length, int array[]);
	
int main(int argc, char* argv)
{
	int i,length,steps, hasInput;
	int trains[50]; 
	int* canSwap;

	while((hasInput = scanf("%d",&length)) == 1)
	{
		for(i=0;i<length;++i)
			scanf("%d",&trains[i]);

		//steps = sort(length,trains);
		
		canSwap = getPossibleSwaps(length,trains);
		for(i=0;i<length-1;++i)
			printf("%d ",canSwap[i]);
		printf("\n");

		for(i=0;i<length;++i)
			printf("%d ",trains[i]);
		printf("\n");
		/*
		printf("Optimal train swapping takes %d swaps.\n",steps);
		*/
	}

	return 0;
}

int isSorted(int length, int array[])
{
	int swaps;

	swaps = sort(length, array);

	return swaps > 0 ? 0 : 1;
}

int sort(int length, int array[])
{
	int sumSwaps, iSwaps, i, next;
	
	sumSwaps =  0;
	do 
	{
		iSwaps = 0;
		for(i = 0; i < length-1; ++i)
		{
			if(array[i] > array [i+1])
			{
				next = array[i+1];
				array[i+1] = array[i];
				array[i] = next;
				++iSwaps;
			}
		}
		sumSwaps += iSwaps;
	} while (iSwaps > 0);

	return sumSwaps;
}

int* getPossibleSwaps(int length, int array[])
{
	int i;
	int*  canSwapLeft = (int *)malloc(sizeof(int) * (length-1));

	for(i = 0; i < length - 1; ++i)
		if (array[i] > array[i+1])
			canSwapLeft[i] = 1;
		else
			canSwapLeft[i] = 0;

	return canSwapLeft;
}
