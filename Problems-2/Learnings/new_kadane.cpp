#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cstdlib>
#define mod (ll)(1e9+7)
#define ll long long
using namespace std;

int maxSum(vector<int> &arr ){
    int curSum = 0;
    int maxSum = INT_MIN;
    int start = 0, end = 0, tmp = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        curSum += arr[i];
        // maxSum = max(maxSum, curSum);
        if(maxSum < curSum){
            maxSum = curSum;
            start = tmp;
            end = i;
        }
        if(curSum < 0){
            curSum = 0;
            tmp = i + 1;
        }
    }
    cout<<start<<" "<<end<<endl;
    return maxSum;
}

int minSum(vector<int> & arr){
    int start = 0, end = 0 , tmp = 0;
    int curSum = 0; 
    int minSum = INT_MAX;
    for(int i = 0 ; i < arr.size() ; i++){
        curSum += arr[i];
        if(curSum < minSum){
            start = tmp;
            end = i;
            minSum = curSum;
        }
        if(curSum > 0){
            curSum = 0;
            tmp = i + 1;
        }
    }
    cout<<start<<" "<<end<<endl;
    return minSum;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> arr{1,2,3,1,4,5,-9};
    cout<<minSum(arr);
    return 0;
}