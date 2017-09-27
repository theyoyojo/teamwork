#include <stdio.h>
#include <stdlib.h>

int sort(int [], int);
void printarray(int [], int);
int * arraycopy(int [], int);
int issorted(int [], int);
void swap (int [], int);
int* getPossibleSwaps(int [], int);
int bruteforce(int [], int, int, int*);

int main(int argc, char* argv[]) {
    int ncars = 10;
    int mindepth = 0;

    // Get input
    printf("Length of train: ");
    scanf("%d",&ncars);
    int* train = (int *)malloc(ncars * sizeof(int));
    for (int i = 0; i < ncars; i++) {
        printf("Car %d: ", i + 1);
        scanf("%d", &train[i]);
    }

    for (int i = 0; i < ncars; ++i) {
        printf("%d ", train[i]);
    }
    printf("\n");
    // Done getting input

    bruteforce(train, ncars, 0, &mindepth);
    int bs = sort(train, ncars);

    printf("Bruteforce: %d\nBubble sort: %d\n", mindepth, bs);

    return 0;
}

int bruteforce(int train[], int ncars, int depth, int* mindepth) {
    if (!issorted(train, ncars)) {
        int *possibleswaps = getPossibleSwaps(train, ncars);
        for (int i = 0; i < ncars - 1; i++) {
            if (possibleswaps[i]) {
                int *copy = arraycopy(train, ncars);
                swap(copy, i);
                //printarray(copy, ncars);
                //printf("Swapping element %d. Depth: %d\n", i, depth, mindepth);
                bruteforce(copy, ncars, depth + 1, mindepth);
            }
        }
    } else {
        if (*mindepth == 0 || depth < *mindepth) {
            *mindepth = depth;
        }
    }
}

int sort(int train[], int ncars) {
    int nswaps = 0;
    for (int i = 0; i < ncars; i++) {
        for (int j = 0; j < ncars - i - 1; j++) {
            if (train[j] > train[j + 1]) {
                nswaps++;
                int tmp = train[j];
                train[j] = train[j + 1];
                train[j + 1] = tmp;
            }
        }
    }
    return nswaps;
}

int * arraycopy(int array[], int len) {
    int* copy = (int *)malloc(sizeof(int)*len);

    for (int i = 0; i < len; i++) {
        copy[i] = array[i];
    }

    return copy;
}

int issorted(int array[], int len) {
    int sorted = 1;
    for (int i = 0; i < len - 1 ; i++) {
        if (array[i] > array[i + 1]) {
            sorted = 0;
        }
    }
    return sorted;
}

void swap (int train[], int i) {
    int tmp = train[i];
    train[i] = train[i + 1];
    train[i + 1] = tmp;
}

void printarray(int train[], int ncars) {
    for (int i = 0; i < ncars; i++) {
        printf("%d\n", train[i]);
    }
}

int* getPossibleSwaps(int array[], int ncars) {
    int i;
    int*  canSwapLeft = (int *)malloc(sizeof(int) *  ncars-1);

    for(i = 0; i < ncars - 1; ++i) {
        if (array[i] > array[i + 1])
            canSwapLeft[i] = 1;
        else
            canSwapLeft[i] = 0;
    }
    return canSwapLeft;
}
