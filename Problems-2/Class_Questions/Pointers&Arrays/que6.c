#include<stdio.h>

void swap(int * arr1, int * arr2 ,int size){
    for(int i = 0 ; i < size ; i++){
        *(arr1 + i) = (*(arr2 + i))  ^ (*(arr1 + i));
        *(arr2 + i) = (*(arr2 + i))  ^ (*(arr1 + i));
        *(arr1 + i) = (*(arr2 + i))  ^ (*(arr1 + i));
    }
}

int main()
{
    int arr1[5] = {1,2,3,4,5};
    int arr2[5] = {5,4,3,2,1};
    int size = 5;
    swap(arr1,arr2,size);
    for(int i = 0  ;i < size ; i++){
        printf("%d\t", *(arr2+i));
    }
    return 0;
}