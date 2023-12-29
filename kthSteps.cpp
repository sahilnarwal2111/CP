#include<iostream>
using namespace std;

const int MOD = 1e9+7;

int k = 7;

int number_of_ways(int n){
    if(n ==0 ) return 1;
    int ans = 0;
    for(int i = 1; i <=k; i++)
        if(n-i>=0)
            ans = (ans + number_of_ways(n-i)) % MOD;
    
    return ans;
}


int main(){
    
    return 0;
}