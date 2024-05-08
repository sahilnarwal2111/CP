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

vector<int> factors(int n){
    vector<int> ans;
    ans.push_back(1);
    for(int i = 2; i * i <= n ; i++){
        while(n % i == 0){
            ans.push_back(i);
            n /= i;
        }
    }
    if(n > 1) ans.push_back(n);
    return ans;
}


int gcd(int a, int b){
    vector<int> f1 = factors(a);
    vector<int> f2 = factors(b);
    // for(auto el : f1) cout<<el<<" ";
    // cout<<endl;
    // for(auto el : f2) cout<<el<<" ";
    // cout<<endl;
    unordered_map<int, int > um1, um2;
    for(auto el : f1) um1[el]++;
    for(auto el : f2) um2[el]++;
    int ans = 1;
    for(auto itr = um1.begin(); itr != um1.end(); itr++){
        int pn = itr->first;
        if(um2[itr->first] > 0){
            int f = min(itr->second, um2[itr->first]);
            while(f--){
                ans *= (itr->first);
            }
        }
    }
    return ans;
}

void solve() {   
    int n, q; cin>>n>>q;
    int arr[n];
    for(int i = 0 ; i < n ; i++) cin>>arr[i];
    int sum = 0;
    int pre[n];
    pre[0] = arr[0];
    for(int i = 1 ; i < n ; i++){
        pre[i] = pre[i-1] + arr[i];
    }
    for(int i = 0 ; i < n ; i++) sum += arr[i];
    while(q--){
        int l, r, k ; 
        cin>>l>>r>>k;
        int tmp = k * (r - l + 1);
        int s = 0;
        if(l == 1){
            s = pre[r-1];
        }
        else{
            s = pre[r-1] - pre[l-2];
        }
        int v1 = sum - s;
        int v2 = tmp;
        int f = v1 + v2;
        if(f & 1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
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
