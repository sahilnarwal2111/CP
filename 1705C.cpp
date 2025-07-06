
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
    int n, c, q;
    cin >> n >> c >> q;
    string str;
    cin >> str;
    vector<pair<int,int>> vec(c);
    for(auto &i : vec)
        cin >> i.first >> i.second ;
    vector<set<int>> dp(26);
    //setting ops zero th
    for(int i = 1; i <= n; i++){
        int cur = str[i-1] - 'a';
        dp[cur].insert(i);
    }
    int len = n;
    for(auto p : vec){
        int st = p.first;
        int end = p.second;
        // its just this part that you have to miss somehow ?
        for(int k = st; k <= end; k++){
            for(int i = 0; i < 26; i++){
                if(dp[i].count(k)){
                    dp[i].insert(++len);
                    break;
                }
            }
        }
    }
    // for(int i = 0; i < 26; i++){
    //     cout << i << " : ";
    //     for(auto j : dp[i])
    //         cout << j << " ";
    //     cout << endl;
    // }
    
    while(q--){
        int k;
        cin >> k;
        for(int i = 0; i < 26; i++){
            if(dp[i].count(k)){
                cout << (char) (i + 'a') << endl;
                break;
            }
        }
    }    

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