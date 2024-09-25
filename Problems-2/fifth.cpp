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
    if(n == 1) {
        cout<<0<<endl;
        return;
    }
    int maxi = arr[n-1] - arr[0];
    for(int i = 1 ; i < n; i++){
        maxi = max(maxi, arr[i] - arr[i-1]);
    }
    //second case minimuma at first and as it at last
    int mini = INT_MAX;
    int iMini = -1;
    for(int i = 0 ; i < n ; i++){
        if(mini > arr[i]){
            mini = arr[i];
            iMini = i;
        }
    }
    if(iMini != n - 1){
        maxi = max(arr[n-1] - mini, maxi);
    }
    //third case maximum at last and first as it as
    int maximum = INT_MIN;
    int iMax = -1;
    for(int i = 0 ; i < n ; i++){
        if(maximum < arr[i]){
            maximum = arr[i];
            iMax = i;
        }
    }
    if(iMax != 0){
        maxi = max(maximum - arr[0], maxi);
    }
    // if(iMax == 0 && iMini == n-1){
    //     maxi = max(arr[0]-arr[1], maxi);
    //     maxi = max(arr[n-2] - arr[n-1], maxi);
    // }
    cout<<maxi<<endl;
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

/*
5 -1 5 -13
*/