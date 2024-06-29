// Linear search - look through entire list one by one Time-O(N)
// Binary search- Time O(Log2N) 4 searches 16 results


#include <stdio.h>
#include <stdlib.h>

#define COUNT 20

void display (int *arr, int length);
void binary_search(int *arr, int length, int value);

int main () {
    int length1=10, length2=11, value, arr[COUNT];

    int arr1[] = {5,6,10,32,36,42,56,58,67,69};
    int arr2[] = {5,6,10,32,36,42,56,56,56,69,75};

    printf("Arr1: ");
    display(arr1, length1);

    printf("Arr2: ");
    display(arr2, length2);

    printf("Enter value to be searched:");
    scanf("%d", &value);

    binary_search(arr1, length1, value);
    binary_search(arr2, length2, value);
    return 0;
}

void display (int *arr, int length) {
    for (int i = 0; i < length; i++) {
        printf ("%d ", arr[i]);
    }
    printf("\n");
}

void binary_search(int *arr, int length, int value) {
    int low = 0;
    int high = length-1;
    int mid = (low + high) / 2;
    
    while (low <= high) {
        if (value == arr[mid]) {
            printf("Found element %d at index [%d]\n", value, mid);
            break;
        } else if(value < arr[mid]) {
            high = mid - 1;
            mid = (low + high) / 2;
        } else {
            low = mid + 1;
            mid = (low + high) / 2;
        }
    }
    if (low > high) {
        printf("Not found\n");
    }
}

