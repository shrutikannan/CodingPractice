#include <stdio.h>
#include <stdlib.h>

void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void sort_array_des(int* arr, int n) {
    int temp;
    // Moving smaller elements to the front
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sort_array_asc(int* arr, int n) {
    int temp;
    // moving bigger elements to the end
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            
            if (arr[i] < arr[j]) {
                temp = arr[i]; 
                arr[i] = arr[j];
                arr[j] = temp;
            }
            
        }
    }
}

int main (void) {

    int arr[20];
    int count;
    printf("Array sorting\n");
    printf("Number of elements=");
    scanf("%1d",&count);
    printf("Enter the elements=\n");
    for (int i = 0; i < count; i++) {
        printf("[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    // print_array(arr, count);

    sort_array_des(arr,count);
    print_array(arr, count);
    sort_array_asc(arr,count);
    print_array(arr, count);

    return 0;
}