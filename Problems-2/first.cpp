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
#include <numeric>
#include <climits>
#define mod (ll)(1e9+7)
#define int long long
#define ll long long
#define endl '\n'
using namespace std;

void solve() {   
    int n; cin>>n;
    int arr[n]; for(int i =0 ; i < n ; i++) cin>>arr[i];
    int minSoFar = INT_MAX;
    int minEndingHere = 0;
    int start =0, end = 0, s =0;
    for(int i = 0 ; i < n ; i++){
        minEndingHere += arr[i];
        // minSoFar = min(minSoFar, minEndingHere);
        if(minSoFar > minEndingHere){
            minSoFar = minEndingHere;
            start = s;
            end = i;
        }
        if(minEndingHere > 0){
            minEndingHere = 0;
            s = i + 1;
        }
    }
    int total = 0;
    for(int i = 0 ; i < n ; i++) total += arr[i];
    if(n == 2){
        cout<<abs(total)<<endl;
        return;
    }
    if(start != end){
        int sum = 0;
        for(int i = start ; i <= end; i++){
            sum +=arr[i];
        }
        sum = sum * 2;
        sum *= -1;
        total = total + sum;
        cout<<total<<endl;
        return;
    }
    else{
        // cout<<abs(total)<<endl;
        

    }

}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
