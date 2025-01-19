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
void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;
    int allValues = -1;
    int sum = 0;
    for(auto &i : arr) sum += i;
    map<int,int> mp;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int i ;
            cin >> i;
            int newValue;
            cin >> newValue;

            if(allValues == -1){
                sum -= arr[i-1];
                sum += newValue;
            }else{
                if(mp.count(i-1)){
                    sum -= mp[i-1];
                }else{
                    sum -= allValues;
                }
                sum += newValue;
            }
            arr[i-1] = newValue;
            mp[i-1] = newValue;
            cout << sum << endl;

        }else{
            int newValue;
            cin >> newValue;
            mp.clear();
            allValues = newValue;
            sum = allValues * n;
            cout << sum << endl;

        }
    }
}    
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);    
    // int tt;
    // cin >> tt;
    // while(tt--)
        solve();
    return 0;
}