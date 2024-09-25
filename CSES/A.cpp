#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<numeric>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
#include <iomanip>
#include <ios>
// #define ll long long
#define int long long
using namespace std;
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(auto &i : arr)
        cin >> i;
    map<int, int> mp;
    for(auto &i : arr)
        mp[i]++;
    sort(arr.begin(), arr.end());
    auto it = unique(arr.begin(), arr.end());
    arr.erase(it, arr.end());
    for(auto &i : arr)
        cout << i << " ";
    cout << endl;
    int ans = 0;
    int l = 0, r = 0;
    for(r = 0; r < n ; r++){
        if(r - l + 1 == m){
            if(arr[r] - arr[l] < m){
                int cur = 1;
                for(int i = l ; i <= r; i++){
                    cur *= mp[arr[i]];
                }
                ans += cur;
            }
        }
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    int tt;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}