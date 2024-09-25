#include<stdio.h>

void pattern(int n){
    for(int i = 1; i <= n ; i++){
        //gap = (n-i) * 2
        for(int j = 1 ; j <= (n-i)*2; j++){
            printf("  ");
        }
        //first range
        for(int j = 1; j <= i ; j++){
            printf("%d ", j);
        }
        //middle gap
        if(i!=1){
            int gap = (i-1)*2;
            for(int j = 1; j <= gap; j++){
                printf(" ");
            }
            for(int j = 2; j < gap; j++){
                printf(" ");
            }
        }
        if(i!=1)
        for(int j = i ; j >=1 ; j--){
            printf("%d ",j);
        }
        printf("\n");
    }
    for(int i = n-1; i >= 1 ; i--){
        //gap = (n-i) * 2
        for(int j = 1 ; j <= (n-i)*2; j++){
            printf("  ");
        }
        //first range
        for(int j = 1; j <= i ; j++){
            printf("%d ", j);
        }
        //middle gap
        if(i!=1){
            int gap = (i-1)*2;
            for(int j = 1; j <= gap; j++){
                printf(" ");
            }
            for(int j = 2; j < gap; j++){
                printf(" ");
            }
        }
        if(i!=1)
        for(int j = i ; j >=1 ; j--){
            printf("%d ",j);
        }
        printf("\n");
    }
}


int main()
{
    pattern(10);
    return 0;
}