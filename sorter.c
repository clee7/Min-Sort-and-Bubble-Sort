#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define MAX_ARG  32

void swap(int array[], int index1, int index2) {
    int temp; 
    temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void min_sort(int numbers[], int num_elements) {
    int start;
    int smallest;
    int i;
    for (start = 0; start < num_elements; start++) { 
        /* loop through entire array */ 
        smallest = start;
        for (i = start; i < num_elements; i++) {
            if (numbers[i] < numbers[smallest]) {
                smallest = i; 
                /* compare all numbers in array to the smallest 
                number */
            }
        }
        swap(numbers, smallest, start);
        /* switch the position of the smallest and the start */
    } 
    /* Check that the array is sorted correctly. */
    for (i = 1; i < num_elements; i++)
    {
        assert(numbers[i] >= numbers[i - 1]);
    }
}

void bubble_sort(int numbers[], int num_elements) {
    int i;
    int swapped = 1; /* 1 = swapped, 0 = not swapped */
    while (swapped == 1) {
        swapped = 0;
        for (i = 1; i < num_elements; i++) {
            if (numbers[i - 1] > numbers[i]) {
                /* if it is out of order */
                swap(numbers, i - 1, i);
                assert(numbers[i - 1] < numbers[i]);
                swapped = 1;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int numbers[MAX_ARG]; /* array that contains the integers */
    int i; /* index of input array */
    int num_elements; /* number of integers */
    int opb, opq; /* 1 = optional, 0 = no optional */
    int k; /* index for print loop */
    num_elements = 0;
    for (i = 1; i < argc; i++) { 
        if (strcmp(argv[i], "-b") == 0) {
            opb = 1;
        }
        else if (strcmp(argv[i], "-q") == 0) {
            opq = 1;
        }
        /* checking for optionals */
        else {
            if (num_elements == MAX_ARG) {
                num_elements++;
                break;
            }
            else {
            numbers[num_elements] = atoi(argv[i]);
            num_elements++;
            }
        }
    }
    if ((num_elements < 1) || (num_elements > MAX_ARG)) {
        fprintf(stderr, "usage: %s [-b] [-q] number1 [number2...]\n", \
                 argv[0]);
        exit(1);
    }
    if (opb == 1) {
        bubble_sort(numbers, num_elements);
    }
    else {
        min_sort(numbers, num_elements);
    }
    if (opq != 1) {
        for (k = 0; k < num_elements; k++) {
            printf("%d\n", numbers[k]);
        }
    }
    return 0;
}
