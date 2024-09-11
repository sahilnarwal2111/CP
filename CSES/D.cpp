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
#define int long long int
#define endl '\n'
using namespace std;



void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto &i : arr)
        cin >> i;
    
    int ans = 0;
    set<int> s;
    
    int l = 0, r = 0;
    for(r = 0 ; r < n ; r++){
        s.insert(arr[r]);
        if(s.size() > k){
            int window = r - l;
            cout << l << " " << r << endl;
            ans += ((window * (window + 1)) / 2); 
            while(s.size() > k){
                s.erase(arr[l++]);
            }
        }
    }
    cout << l << " " << r << " " << s.size() << endl;
    cout << ans << endl;
    
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE 
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout); 
    // #endif
    // int tt ;
    // cin >> tt;
    // while(tt--)
        solve();
    return 0;
}