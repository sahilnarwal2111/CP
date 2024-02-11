#include<stdio.h>

int fun(){
    char str1[] = "bvvf";
    return printf("str1: %s\n", str1);
}

int main()
{
    // int ans = fun();
    // printf("%d\n",ans);
    // int len = printf("%s","sahil\n");
    // printf("%d\n",len);
    int arr[] = {9,7,3,1,10,2,5,4,8,6};
    int done = 0;
    for(int i = 0 ; i < 10 ; i++){
        int cnt = 0;
        int cur = i + 1;
        for(int j = 0 ; j < 10 ; j++){
            if(arr[j] == cur){
                break;
            }
            else if(arr[j] <= done){
                continue;
            }
            else{
                cnt++;
            }

        }
        done = cur;
        printf("%d -> %d\n",cur, cnt);
    }
    
    return 0;
}