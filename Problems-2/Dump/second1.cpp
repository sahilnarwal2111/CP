#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
#define mod (ll)(1e9+7)
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n ;cin>>n;
        int arr[n];
        for(int i = 0 ; i < n ; i++) cin>>arr[i];

        bool sorted = true;

        for(int i = 0 ; i < n-1 ; i++){
            if(arr[i] > arr[i+1]){
                sorted = false;
                break;
            }
        }
        if(!sorted) cout<<0<<endl;
        else{
            int diff = INT_MAX;
            for(int i = 0 ; i < n-1; i++){
                diff = min(diff, arr[i+1]-arr[i]);
            }
            diff = diff/2;
            cout<<diff+1<<endl;
        }

    }
    return 0;
}