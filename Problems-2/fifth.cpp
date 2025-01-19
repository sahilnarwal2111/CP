// || =================================================================== ||
// ||                                                                     ||
// ||                   Reach Expert by May 2025                          ||
// ||                                                                     ||
// || =================================================================== ||
#include <bits/stdc++.h>
#include <sstream>
#include <iomanip>
// #define int long long
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
    int n;
    cin >> n;
    if(n == 1){
        cout << 'a' << endl;
        return;
    }
    set<int> st;
    for(int i =1; i * i <= n; i++){
        if(n % i == 0){
            st.insert(i);
            st.insert(n / i);
        }
    }
    string ans (n + 1, '.');
    ans[0] = '$';
    

    
        
}
signed main(){
    int t;
    cin >> t;
    while(t--)
        solve();
}