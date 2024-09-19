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
#include <iomanip>
#include <ios>
#define ll long long
using namespace std;

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<ll> fact(n + 1, 1);
    for(ll i = 1; i <= n ; i++){
        fact[i] = (i * fact[i-1]) % m;
    }
    ll ans = 0;
    for(ll l = 1 ; l <= n ; l++){
        for(ll r = l ; r <= n; r++){
            ll ws = r - l + 1LL;
            ll  possibleWindows = n - ws + 1LL;
            ll total = (fact[ws] * possibleWindows) % m;
            cout << l << " " << r << " ";
            cout << total << endl;
            ans = (ans + total) % m;
        }
    }
    cout << ans << endl;

    
    

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}