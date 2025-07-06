#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
#include <climits>
#define mod (ll)(1e9+7)
#define ll long long
using namespace std;

vector<vector<int> > dp(mod + 1, vector<int>(mod + 1, -1));

void rec(int a, int b, int i , int *res){
    if( a < 1 || b < 1 || a > mod || b > mod){
        return;
    }
    if( a == b){
        *res = min(*res, i-1);
        dp[a][b] = *res;
        return;
    }
    if(dp[a][b]==-1) {
        if(i&1){ 
            rec(a + i , b, i + 1, res);
            rec(a, b + i , i + 1, res);
        }
        else
        { 
            if (a >= i) 
                rec(a - i, b, i + 1, res);
            
            if (b >= i) 
                rec(a, b - i, i + 1, res);
        }
    }

}

void solve(){
    int res = INT_MAX;
    int a,b; cin>>a>>b;

    if(a == b) {
        cout<<0<<endl;
        return;
    }

    rec(a,b,1, &res);
    cout<<dp[a][b]<<endl;

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}