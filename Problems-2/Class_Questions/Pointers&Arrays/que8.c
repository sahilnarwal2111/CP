#include<stdio.h>

int main()
{
    int arr[4][4] = {
        {1,2,3,4},
        {5,6,7,7},
        {9,10,11,12},
        {13,14,15,16}
    };

    // for(int * p = &arr[0][0]; p <= &arr[3][3]; p++){
    //     printf("%d ", *p);
    // }
    // printf("\n");
    // for(int * p = &arr[0][0]; p < &arr[0][0] + 16; p++){
    //     printf("%d ", *p);
    // }
    // printf("\n");
    // printf("%u %u", &arr, &arr[0][0]);

    int row = 4;
    int col = 4;

    int * ptr = arr;

    // printf("%d %d", arr, &arr[0][0]);

    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < col ; j++){
            printf("%d ", *(ptr + i * col + j));
        }
        printf("\n");
    }

    return 0;
}