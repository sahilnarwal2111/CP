// || =================================================================== ||
// ||                                                                     ||
// ||                   Reach Expert by June 2025                          ||
// ||                                                                     ||
// || =================================================================== ||
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ll long long
#define endl "\n";
#define all(a) a.begin(), a.end()  
#define sz(a) (int)size(a)         
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;     
        }
        base = (base * base) % mod; 
        exp /= 2; 
    }
    return result;
}
bool thisTest = 0;
int bs(vector<ll>&b, int el){
    int l = 0, h = sz(b)-1;
    int mid , ans = -1;
    while(l <= h){
        mid = l + (h - l)/2;
        if(b[mid] < el){
            ans = mid;
            l = mid + 1;
        }else{
            h = mid - 1;
        }
    }
    return ans;
}
set<ll> faults;
ll bs(ll x){
    ll ans = -1;
    ll l = 1, h = 1e6;
    ll mid;
    while(l <= h){
        mid = l + (h - l)/2ll;
        if((mid * (mid + 1ll)) == 2ll * x){
            ans = mid;
            return ans;
        }
        if((mid * (mid + 1ll)) > 2ll * x){
            h = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return ans;
}
void solve(int t, int cx) {
    ll n;
    cin >> n;
    if(faults.count(n)){
        cout << -1 << endl;
        return;
    }
    vector<ll> ans(n + 1);
    for(int i = 1; i <= n; i++){
        ans[i] = i;
    }

    for(int i = 1; i <= n; i++){
        // cout << i << endl;
        if(faults.count(i)){
            // we need to swap it with ahead element
            if(i + 1 <= n){
                swap(ans[i], ans[i + 1]);
                i++;
            }else{
                cout << -1 << endl;
            }
        }
    }
    for(int i = 1; i<= n; i++)
        cout << ans[i] << " ";
    cout << endl;

}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //precomputations
    ll i;
    for(ll j = 1; j <= 1e6 ; j++){
        i = j * j;
        int n = bs(i);
        if(n != -1){
            // cout << j << " " << i << " " << n << endl;
            faults.insert(n);
        }
    }
    // for(auto i : faults) cout << i << " ";
    // cout << endl;
    // cout << bs(131328) << endl;
    int t;
    cin >> t;
    for(int i = 0;i < t; i++){
        solve(t, i);
    }
}
