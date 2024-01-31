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
#include <unordered_set>
#include <climits>
#define mod (ll)(1e9+7)
#define ll long long
#define int unsigned long long
using namespace std;
int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}




void solve(){
    int a, b, r;
    cin>>a>>b>>r;
    
    
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t ; cin>>t;
    while(t--){
        solve();
    }
    // cout<<(256-92)<<endl;

}