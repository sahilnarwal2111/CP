#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include <cstdlib>
#define mod (ll)(1e9+7)
#define ll long long
using namespace std;

int prefixSum(int arr[], int size, int start, int end){
    int pre [size] ;
    pre[0] = arr[0];
    for(int i = 1 ; i < size; i++){
        pre[i] = pre[i-1] + arr[i];
    }
    if(start == 0){
        return pre[end];
    }
    else return pre[end] - pre[start-1];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int arr[5] ={1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"Sum of index 1 - 4: "<<prefixSum(arr, size,1,4)<<endl;
    return 0;
}