#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <cstdlib>
#include <sstream>
#define int long long
using namespace std;
int chk(int n){
    int cnt = 0;
    while(n){
        if(!(n & 1)) cnt++;
        n >>= 1;
    }
    return cnt;
}
void solve(){
    int n;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;
    int mod = 1e9 + 7;
    map<int,vector<int> > mp;
    for(int i = 0; i < n ; i++) mp[arr[i]].push_back(i);
    map<int, vector<int> > smallerEvens;
    for(auto itr = mp.rbegin() ; itr != mp.rend(); itr++){
        int cur = itr->first;
        for(auto jtr : mp){
            if(jtr.first >= itr->first) break;
            if(!(jtr.first)){
                vector<int> cur = jtr.second;
                for(auto i : cur){
                    if(i < )
                }
            }

        }
    }

}
signed main(){
    int tt;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}