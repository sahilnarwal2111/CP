#include<stdio.h>

void pattern(int n){
    for(int i = 1 ; i <= n ; i++){
        //gap
        for(int j = 1; j <= i-1 ; j++) {
            printf(" ");

        }
        if(i == 1){
            for(int j = 1; j <= 2*n -1 ; j++) printf("*");
        }
        else{
            printf("*");
            //middle gap
            for(int j = 1; j <= n-i; j++) printf(" ");
            for(int j = 1; j <= n-i-1; j++) printf(" ");
            if(i != n)
            printf("*");

        }
        printf("\n");
    }
    for(int i = 2 ; i <= n ; i++){
        //gap
        for(int j = 1; j <= n-i;j++) printf(" ");
        for(int j = 1; j <= i ; j++) printf("*");
        for(int j = 1; j <= i-1 ; j++) printf("*");
        printf("\n");
    }
}

int main()
{
    pattern(10);
    return 0;
}