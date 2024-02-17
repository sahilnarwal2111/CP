#include<stdio.h>

void swap1(int *p1, int *p2){
    *p1 = (*p1) ^ (*p2);
    *p2 = (*p1) ^ (*p2);
    *p1 = (*p1) ^ (*p2);
}

void swap2(int * p1, int *p2){
    *p1 = (*p1) + (*p2) - (*p2 = *p1);
}

void swap3(int *p1 ,int * p2){
    *p1 = *p1 + *p2;
    *p2 = *p1 - *p2;
    *p1 = *p1 - *p2;
}

int main()
{
    int n = 5, m= 10;
    int *ptr1 = &n, *ptr2 = &m;
    
    // swap1(ptr1,ptr2);
    // printf("n =  %d\tm = %d\n", n,m);
    
    // swap2(ptr1,ptr2);
    // printf("n =  %d\t m = %d\n", n,m);
    
    swap3(ptr1,ptr2);
    printf("n =  %d\t m = %d\n", n,m);

    return 0;
}