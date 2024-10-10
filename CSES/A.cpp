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
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    if(k >= 25){
        for(int i = 0; i < n ; i++)
            cout << 'a';
        cout << '\n';
        return;
    }
    int maxTillGreaterThanEqualToK = 0;
    int firstGreaterThanK = -1;
    for(int i = 0 ; i < n ; i++){
        if(str[i] - 'a' > k){
            firstGreaterThanK = i;
            break;
        }else{
            maxTillGreaterThanEqualToK = max(maxTillGreaterThanEqualToK, (int)(str[i] - 'a'));
        }
    }
    k = k - maxTillGreaterThanEqualToK;
    int ref = str[firstGreaterThanK] - 'a' - k;
    int tmp = str[firstGreaterThanK] - 'a';
    for(int i = 0 ; i < n ; i++){
        int idx = str[i] - 'a';
        if(idx == 0)
            continue;
        if(idx <= maxTillGreaterThanEqualToK){
            str[i] = 'a';
        }else if(idx >= ref && idx <= tmp){
            str[i] = (char) ref + 'a' ;
        }
    }
    
    cout << str << '\n';
    
}    
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    int tt;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}
