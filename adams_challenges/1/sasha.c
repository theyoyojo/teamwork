#include <stdio.h>
#include <stdlib.h>

int sort(int [], int);
void printarray(int [], int);
int * arraycopy(int [], int);
int issorted(int [], int);
int* getPossibleSwaps(int [], int);

int main(int argc, char* argv[]) {

    int train[] = {5, 10, 3, 6, 4, 1, 8, 2, 9, 7};
    //int train[] = {1, 2, 3, 4, 5};
    int ncars = 10;


    //for (int i = 0; i < ncars; i++) {
    //    train[i] = ncars - i;
    //}



    //sort(train, ncars);
    //printarray(train, ncars);

    //int sorted = issorted(train, ncars);
    //printf("%d\n", sorted);
    int mindepth = 0;
    bruteforce(train, ncars, 0, &mindepth);
    int bs = sort(train, ncars);

    printf("Bruteforce: %d\nBubble sort: %d\n", mindepth, bs);

    return 0;
}

int bruteforce(int train[], int ncars, int depth, int* mindepth) {
    if (!issorted(train, ncars)) {
        int nswaps = 0;
        int *possibleswaps = getPossibleSwaps(train, ncars);
        for (int i = 0; i < ncars - 1; i++) {
            if (possibleswaps[i]) {
                int *copy = arraycopy(train, ncars);
                swap(copy, i);
                printf("Swapping element %d. Depth: %d\n", i, depth, mindepth);
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

int* getPossibleSwaps(int array[], int length) {
    int i;
    int*  canSwapLeft = (int *)malloc(sizeof(int) * (length-1));

    for(i = 0; i < length - 1; ++i) {
        if (array[i] > array[i + 1])
            canSwapLeft[i] = 1;
        else
            canSwapLeft[i] = 0;
    }
    return canSwapLeft;
}
