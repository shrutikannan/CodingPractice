// one loop for each element
// second loop for the rest of the elements, and find smallest
#include <stdlib.h>
#include <stdio.h>

#define COUNT 20

void display_arr(int *arr, int length);
void selection_sort_asc(int *arr, int length);
void selection_sort_des (int *arr, int length);

int main () {
    int length;
    int arr[COUNT]; 

    printf("Enter the length (MAX 20):");
    scanf("%d", &length);

    printf("Enter the elements:");
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }

    display_arr(arr, length);
    
    selection_sort_asc(arr, length);
    display_arr(arr, length);
    
    selection_sort_des(arr, length);
    display_arr(arr, length);

    return 0;
}

void display_arr(int *arr, int length) {
    for (int i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort_asc(int *arr, int length) {
    int min, temp;
    for (int i = 0; i < length; i++) {
        min = i;
        for (int j = i+1; j < length; j++) {
            // Look for the smallest value in the rest of the array
            if (arr[j] < arr [min]) {
                min = j;
            }
        }
        if (i != min) {
            // If ith ele is not the smallest, exchange with i.
            temp =  arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void selection_sort_des (int *arr, int length) {
    int max, temp;

    for (int i = 0; i < length; i++) {
        max = i;
        for (int j = i+1; j < length; j++) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        if (i != max) {
            temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
        }
    }
}

