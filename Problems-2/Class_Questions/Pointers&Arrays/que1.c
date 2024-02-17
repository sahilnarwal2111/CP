#include<stdio.h>

int main()
{
    int * ptr;
    int a = 5;
    ptr = &a;
    printf("%d\n", *ptr);
    printf("%d\n", a);

    //void pointer
    void * p;
    p = &a;
    printf("%d\n", *((int *)p));

    return 0;
}