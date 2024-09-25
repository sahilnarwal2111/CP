#include<stdio.h>

void pattern(int n){
    for(int i = 1; i <= n-1 ; i++){
        printf("*");
        //gap
        for(int j =1; j <= n-2;j++) printf(" ");
        if(i == 1){
            for(int j = 1; j <= n ; j++) printf("*");
        }
        else printf("*");
        printf("\n");
    }
    for(int i = 1; i <= 2*n-1; i++ ) printf("*");
    printf("\n");
    for(int i = 2; i <= n-1 ; i++){
        //gap
        for(int j = 1; j <= n-1; j++) printf(" ");
        printf("*");
        for(int j = 1; j <= n-2; j++) printf(" ");
        printf("*");
        printf("\n");

    }
    for(int i = 1; i <= n ; i++) printf("*");
    //gap
    for(int i = 1 ; i <= n-2 ; i++) printf(" ");
    printf("*");
    printf("\n");
}

int main()
{   
    printf("\n");
    pattern(10);
    return 0;
}