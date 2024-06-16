#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void string_reverse(char* str);
void swap_by_value(int a, int b);
void swap_by_reference(int *ptra, int *ptrb);

int main() {

    // int a = 25;
    // int *ptra = &a;

    // printf("a = %d\n", a);
    // printf("&a = %p\n", &a);
    // printf("ptra = %p\n", ptr1);
    // printf("*ptra = %d\n", *ptr1);

    // *ptr1 = 35;
    // printf("a = %d\n", a);
    // printf("--------------------------------------\n");


    // DIFFERENT DATATYPES
    // long int la = 30;
    // long int *ptrla = &la;
    // printf("ptrla = %p\n", ptrla);
    // printf("*ptrla = %ld\n", *ptrla);

    // double da = 30;
    // double *ptrda = &da;
    // printf("ptrda = %p\n", ptrda);
    // printf("*ptrda = %ld\n", *ptrda);

    // float fa = 30;
    // float *ptrfa = &fa;
    // printf("ptrda = %p\n", ptrda);
    // printf("*ptrda = %ld\n", *ptrda);

    // char ca = 'b';
    // char *ptrca = &ca;
    // printf("ptrca = %p\n", ptrca);
    // printf("*ptrca = %c\n", *ptrca);
    // printf("--------------------------------------\n");


    // POINTER INCREMENT/DECREMENT
    // Go to next location
    // Change based on length of data type
    // printf("ptra = %p\n", ptra++);
    // printf("ptra = %p\n\n", ptra); // 4 bytes away

    // printf("ptrla = %p\n", ptrla++);
    // printf("ptrla = %p\n\n", ptrla); // 4 or 8?

    // printf("ptrda = %p\n", ptrda++);
    // printf("ptrda = %p\n\n", ptrda); // 8 bytes

    // printf("ptrfa = %p\n", ptrfa++);
    // printf("ptrfa = %p\n\n", ptrfa); // 4 bytes away

    // printf("ptrc = %p\n", ptrca++);
    // printf("ptrc = %p\n", ptrca); // 1 byte away
    // printf("--------------------------------------\n");


    // GO AHEAD BY MULTIPLE LOCATIONS
    // printf("size of int = %d\n", sizeof(a));    
    // printf("ptra = %p\n", ptra);
    // ptra = ptra+ 4;
    // printf("ptra = %p\n\n", ptra); // 4 bytes away
    // printf("--------------------------------------\n");

    // ACCESS AN ARRAY
    // int a[5] = {10,20,30,40,50};
    // int count = 5;
    // int *ptra = a;
    
    // for (int i = 0; i < count; i++) {
    //     printf("%d ", a[i]);
    // } printf("\n");

    // for (int i = 0; i < count; i++) {
    //     printf("%d ", *ptra++);
    // } printf("\n");

    // STRING OPERATIONS
    // int vowels = 0;
    // char a[30];
    // char *ptra = a;
    // printf("Enter string:");
    // fgets(ptra,30,stdin);
    // Prints all 30 characters
    // for (int i = 0; i < count; i++) {
    //     printf("%c\n", *ptra++);
    // } 
    // Prints only till actual length
    // while(*ptra != '\0') {
    //     printf("%c \n", *ptra++);
    // } 
    
    // string_reverse(ptra);
    // printf("%s", ptra);

    int a = 22;
    int *ptra = &a;
    int b = 35;
    int *ptrb = &b;
    printf("Original: a = %d, b = %d\n", a, b);
    swap_by_value(a, b);
    printf("By Value: a = %d, b = %d\n", a, b);

    swap_by_reference(ptra, ptrb);
    printf("By Ref: a = %d, b = %d\n", a, b);
    return 0;
}

void string_reverse(char* ptrStr){
    char *ptrRev, temp;
    int length =  strlen(ptrStr);
    ptrRev = ptrStr + length - 1 - 1; // second one for the Enter in fgets
    
    while (ptrStr < ptrRev) {
        temp = *ptrStr;
        *ptrStr = *ptrRev;
        *ptrRev = temp;

        ptrStr++;
        ptrRev--;
    }

}

void swap_by_value(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_by_reference(int *ptra, int *ptrb) {
    int temp;
    temp = *ptra;
    *ptra = *ptrb;
    *ptrb = temp;
}

