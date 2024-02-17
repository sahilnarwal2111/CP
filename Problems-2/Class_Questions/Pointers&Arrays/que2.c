#include<stdio.h>
#include <stdlib.h>

void add(int *a , int * b , int * result){
    *result = *a + *b;
}

int main()
{
    int * ptr ;
    ptr = (int *)malloc(sizeof(int));
    *ptr = 5;
    printf("%d\n", *ptr);
    
    // -----------
    int n = 10;
    int m = 15;
    int sum ;
    int * ptr1 = &n;
    int * ptr2 = &m;
    int * ptr3 = &sum;

    add(ptr1,ptr2,ptr3);

    printf("%d\n", *ptr3);
    printf("%d\n", sum);



    return 0;
}