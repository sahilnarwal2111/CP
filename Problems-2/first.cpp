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
    int n, k; cin>>n>>k;
    int arr[n]; for(int i = 0 ; i < n ; i++) cin>>arr[i];
    sort(arr, arr + n);
    int ans = 0;
    int cnt =0;
    for(int i = 1; i < n ; i++){
        if(arr[i] - arr[i-1] <= k){
            cnt++;
            ans = max(cnt, ans);
        }
        else{
            cnt = 0;
        }
    }
    cout<<n - ans - 1<<endl;
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
