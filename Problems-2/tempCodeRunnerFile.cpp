// || =================================================================== ||
// ||                                                                     ||
// ||                   Reach Expert by May 2025                          ||
// ||                                                                     ||
// || =================================================================== ||
#include <bits/stdc++.h>
#include <sstream>
#include <iomanip>
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
    int n, x;
    cin >> n >> x;
    vector<int> arr(n), brr(n);
    for(auto &i : arr)
        cin >> i;
    for(auto &i : brr)
        cin >> i;
    multiset<int> ms1, ms2;
    for(auto i : arr)
        ms1.insert(i);
    for(auto i : brr)
        ms2.insert(i);

    // sanity check
    if(*ms1.begin() > *ms2.rbegin()){
        // x can be only equal to n
        if(x == n){
            for(auto i : brr)
                cout << i <<  " ";
            cout << endl;
        }else{
            cout << "NO" << endl;
        }
        return;
    }
    if(*ms1.rbegin() < *ms2.begin()){
        // x can be zero only
        if(x == 0){
            for(auto i : brr)
                cout << i << " ";
            cout << endl;
        }else{
            cout << "NO" << endl;
        }
        return;
    }
    vector<int> ans(n, 0);
    map<int, set<int>> mp; // for storing the positions of arr elements
    for(int i = 0 ; i < n; i++) mp[arr[i]].insert(i);

    for(int i = 0 ; i < x; i++){
        // till this point we will match last of first with first of second
        int last = *ms1.rbegin();
        int first = *ms2.begin();
        cout << first << " " << last << endl;
        int idx = *mp[last].begin();
        mp[last].erase(idx);
        if(last > first){
            ans[idx] = first;
        }else{
            cout << "NO" << endl;
        }
        ms1.erase(ms1.find(first));
        ms2.erase(ms2.find(last));
    }
    for(auto i : ans)
        cout << i << " ";
    cout << endl;

}


signed main(){
    int t;
    cin >> t;
    while(t--)
        solve();
}