// || =================================================================== ||
// ||                                                                     ||
// ||                   Reach Expert by May 2025                          ||
// ||                                                                     ||
// || =================================================================== ||
#include <bits/stdc++.h>
#define int long long
#define endl "\n";
#define all(a) a.begin(), a.end()     
using namespace std;
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
void solve() {
    int num = 1e9;
    int cnt = 0;
    while(num){
        num /=2 ;
        cnt++;
    }
    cout << cnt << endl;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin);  
        freopen("output.txt", "w", stdout); 
    #endif  
    int t;
    cin >> t;
    while(t--)
        solve();
   
} 