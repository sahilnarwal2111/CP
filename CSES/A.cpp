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
    int q;
    cin >> q;
    int f1 = 1, f2 = 1;
    bool tContainsB = false;
    bool sContainsB = false;
    while(q--){
        int d, k;
        cin >> d >> k;
        string x; 
        cin >> x;
        if(d == 1){
            for(auto &ch : x){
                int idx = ch - 'a';
                if(idx > 0){
                    sContainsB = true;
                }
                if(idx == 0)
                    f1 += k;
            }
        }else{
            for(auto &ch : x){
                int idx = ch - 'a';
                if(idx > 0){
                    tContainsB = true;
                }
                if(idx == 0)
                    f2 += k;
            }
        }
        if(tContainsB){
            cout << "YES" << '\n';
        }else{
            if(sContainsB){
                cout << "NO" << '\n';

            }else{
                if(f2 > f1){
                    cout << "YES" << '\n';
                }else{
                    cout << "NO" << '\n';
                }
            }
            
        }
        
    }
}    
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    int tt;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}