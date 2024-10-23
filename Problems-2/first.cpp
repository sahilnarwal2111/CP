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
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i: arr)   
        cin >> i;
    int mp[1000001] = {0};
    int ans = 1;
    for(auto &i : arr){
        int num = i;
        for(int j = 1 ; j * j <= num; j++){
            if(num % j == 0){
                int f1 = j;
                int f2 = num / j;
                mp[f1]++;
                if(f1 != f2){
                    mp[f2]++;
                }
                if(mp[f1] >= 2){
                    ans = max(ans, f1);
                }
                if(mp[f2] >= 2){
                    ans = max(ans, f2);
                }
            }
        }
    }
    
    
    cout << ans << '\n';
}


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int tt;
    // cin >> tt;
    // while(tt--)
        solve();
    return 0;
}