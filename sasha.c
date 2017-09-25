#include <stdio.h>
#include <stdlib.h>

void sort(int [], int);
void printarray(int [], int);
int * arraycopy(int [], int);
int issorted(int [], int);

int main(int argc, char* argv[]) {

    int train[] = {1, 5, 3, 2, 4};
    //int train[] = {1, 2, 3, 4, 5};
    int ncars = 5;


    //for (int i = 0; i < ncars; i++) {
    //    train[i] = ncars - i;
    //}



    //sort(train, ncars);
    //printarray(train, ncars);

    int sorted = issorted(train, ncars);
    printf("%d\n", sorted);

    return 0;
}

void bruteforce(int train[], int ncars) {

}

void sort(int train[], int ncars) {
    for (int i = 0; i < ncars; i++) {
        for (int j = 0; j < ncars - i - 1; j++) {
            if (train[j] > train[j + 1]) {
                int tmp = train[j];
                train[j] = train[j + 1];
                train[j + 1] = tmp;
            }
        }
    }
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

void printarray(int train[], int ncars) {
    for (int i = 0; i < ncars; i++) {
        printf("%d\n", train[i]);
    }
}
