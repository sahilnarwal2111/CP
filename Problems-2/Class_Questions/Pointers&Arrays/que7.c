#include<stdio.h>

void reverse(int * arr, int size){
    for(int i = 0 ; i < size/2 ; i++){
        // *(arr + i ) ans *(arr + size-i-1)
        *(arr+i) = *(arr + i) + *(arr + size - i-1) - (*(arr + size - i-1) = *(arr+i));
    }
}

int main()
{
    int arr1[5] = {1,2,3,4,5};
    int size = 5;
    reverse(arr1,size);
    for(int i = 0 ; i < size; i++){
        printf("%d ", *(arr1+i));
    }
    return 0;
}