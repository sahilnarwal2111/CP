#include<stdio.h>

void pattern(int n){
    for(int i = 1; i <= n ;i++){
        //gap
        for(int j = 1; j <= n-i ; j++){
            printf(" ");
        }
        for(int j = 1; j <= i*2 -1; j++){
            printf("%d",j);
        }
        printf("\n");
    }
    for(int i = n-1; i >=1  ;i--){
        //gap
        for(int j = 1; j <= n-i ; j++){
            printf(" ");
        }
        for(int j = 1; j <= i*2 -1; j++){
            printf("%d",j);
        }
        printf("\n");
    }
}


int main()
{
    pattern(4);
    return 0;
}