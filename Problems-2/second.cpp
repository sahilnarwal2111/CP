// || =================================================================== ||
// ||                                                                     ||
// ||                   Reach Expert by May 2025                          ||
// ||                                                                     ||
// || =================================================================== ||
#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define all(a) a.begin(), a.end()   
#define INF (int)1e18
// #define ONLINE_JUDGE
#define sz(x) ((int)(x).size())
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// using namespace __gnu_pbds; 
long long mod_exp(long long base, long long exp, long long mod) {long long result = 1; while (exp > 0) {if (exp % 2 == 1) {result = (result * base) % mod;} base = (base * base) % mod; exp /= 2; }return result;}
void solve(int t, int curTest){
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> factors;
    vector<int> occ(26, 0);
    for(auto ch : str) occ[ch-'a']++;
    for(int i = 1; i < n; i++) if(n % i == 0) factors.push_back(i);
    int ans = n;
    // for(auto u : factors)
    //     cout << u << " ";
    // cout << endl;
    // for(auto u : occ) cout << u << " ";
    // cout << endl;
    for(auto f : factors){
        // means we are selecting a string of length f
        int o = n / f;
        int faults = 0;
        int idx = -1;
        for(int i = 0; i < 26; i++){
            if(!occ[i]) continue;
            if(occ[i] != o){
                faults++;
                idx = i;
            }
        }
        int len = f;
        if(faults <= 2){
            // may be this is the possible one
            string s1, s2;
            for(int i = 0; i < f; i++) s1 += str[i];
            for(int i = f; i < n; i+=len) {
                string cur = str.substr(i, len);
                // cout << cur << endl;
                if(cur != s1) {
                    s2 = cur;
                    break;
                }else{
                    s2 = cur;
                }
            }
            // cout << s1 << " " << s2 << endl;
            int notMatching =0 ;
            for(int i = 0; i < len; i++) notMatching += (s1[i] != s2[i]);
            if(notMatching > 1) continue;
            int cnt1 = 0, cnt2 = 0;
            for(int i = 0; i < n; i+= len){
                string cur = str.substr(i, len);
                if(cur == s1) cnt1++;
                else if(cur == s2) cnt2++;
                else{
                    break;
                }
            }
            if(max(cnt1, cnt2) * len + min(cnt1, cnt2) * len == n && min(cnt1, cnt2) <= 1ll){
                ans = min(ans, len);
            }
            // cout << cnt1 << " " << cnt2 << endl;


        }
    }
    cout << ans << endl;

}
signed main(){
    #ifndef ONLINE_JUDGE
        auto begin = std::chrono::high_resolution_clock::now();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE 
        freopen("Error.txt", "w", stderr);
        freopen("input.txt", "r", stdin);  
        freopen("output.txt", "w", stdout); 
    #endif  
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve(t, i);
    }

    #ifndef ONLINE_JUDGE
        auto end = std::chrono::high_resolution_clock::now();
        cerr << setprecision(4) << fixed;
        cerr << "Execution time: " << chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
    #endif
} 
