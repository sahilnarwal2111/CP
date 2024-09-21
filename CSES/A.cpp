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

int binaryExpo(int x, int n, int mod){
    int ans = 1;
    while(n > 0){
        if(n & 1){
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return ans % mod;
}

int ncr(int n, int r, int mod, vector<int> &fact, vector<int> & ifact){
    return (((fact[n] * ifact[n-r]) % mod) * ifact[r]) % mod;
}

void solve(){
    string str;
    cin >> str;
    int n = str.size(); 
    int mod = 1e9 + 7;
    vector<int> fact(n + 1, 1);
    vector<int> ifact(n + 1, 1);
    for(int i = 1 ; i <= n ; i++) 
        fact[i] = (fact[i-1] * i) % mod;
    
    ifact[n] = binaryExpo(fact[n], mod - 2, mod);

    for(int i = n - 1; i >= 0; i--){
        ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
    }
    
    string s = "";
    for(auto &ch : str){
        if(ch == 'a'){
            s += ch;
        }else if(ch == 'b'){
            s += ch;
        }
    }
    int totalA = 0;
    int cur = 0;
    int ans = 1;
    for(auto &ch : s){
        if(ch == 'a'){
            cur++;
        }else if(ch == 'b'){
            if(cur == 0) 
                continue;
            
            cur++;
            ans = (ans * cur) % mod;
            cur = 0;
        }
    }
    // totalA += cur;
    ans = (ans * (cur + 1)) % mod;
    cout << ans - 1 << endl;

}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int tt;
    // cin >> tt;
    // while(tt--)
        solve();
    return 0;
}