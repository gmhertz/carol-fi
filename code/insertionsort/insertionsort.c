#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN 10    //Length of the array

void insertionSort();
void printArray();

//Input and output array
float array[ARRAY_LEN] = {7.23, 9.1, 6.66, 5.64, 7.23, 11.127, 15.7, 3.3, 4.6, 9.2};   //Hardcoded for testing purposes

void main(){
    //Printing for debugging purposes
    printf("Initial Array: ");
    printArray();

    insertionSort();

    //Printing for debugging purposes
    printf("Sorted array: ");
    printArray();
}

//Sorts the array in ascending order
void insertionSort(){
    int i, j;
    float value;  //Value to be sorted (must match the type of array)
    for(i = 1; i < ARRAY_LEN; i++){
        value = array[i];
        j = i-1;

        while(j >= 0 && array[j] > value){
            array[j+1] = array[j];
            j--;
        }

        array[j+1] = value;
    }
}

//Prints the array numbers separated by spaces ("1 2 3 4\n")
void printArray(){
    int i;
    for(i = 0; i < ARRAY_LEN; i++){
        printf("%f ", array[i]);
    }
    printf("\n");
}
