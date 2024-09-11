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

bool chk(int x, vector<int> & arr){
    if(arr.back() < x) return false;
    int n = arr.size();
    vector<int> tmp (n, 0);

    for(int i = n - 1 ; i >= 2 ; i--){
        if(arr[i] + tmp[i] < x) 
            return false;
        
        int d = min(arr[i], arr[i] + tmp[i] - x);

        tmp[i-1] += d / 3;
        tmp[i-2] += (2 * (d / 3));

    }

    if(arr[0] + tmp[0] >= x && arr[1] + tmp[1] >= x) return true;
    return false;
    
}


void solve(){
    int n; 
    cin >> n;
    vector<int> arr(n);
    for(auto &i : arr)
        cin >> i;
    
    int l = 0, h = 1e9;
    int mid, ans;
    while(l <= h){
        mid = (l + h) / 2;
        if(chk(mid, arr) == 1){
            // cout << mid << endl;
            ans = mid;
            l = mid + 1;
        }else{
            h = mid - 1;
        }
    }

    cout << ans << endl;
    // cout << chk(8, arr);
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}