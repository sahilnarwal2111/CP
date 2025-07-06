#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#define ll long long
#define mod (ll)(1e9+7)
using namespace std;

ll func(ll n, ll k){
    ll ans = 1;
    while(k > 0){
        if(k&1 == 1){
            ans = (ans * n) % mod;
        }
        n = (n * n) % mod;
        k>>=1;
    }
    return ans;
}


int main(){
    int t; cin>>t;
    while(t--){
        ll n, k; cin>>n>>k;
        cout<<func(n,k)<<endl;
    }
    return 0;
}