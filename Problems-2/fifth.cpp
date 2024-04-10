#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include <map>
#include <queue>
#include <unordered_set>

#include <stack>
#include <cstdlib>
#define mod (ll)(1e9+7)
#define int long long
#define endl '\n'
using namespace std;


void solve(){
    int n; cin>>n;
    int a, b ; cin>>a>>b;
    if(a == 1 && b == 1){
        if( n & 1){
            cout<<"Alice"<<endl;
        }
        else{
            cout<<"Bob"<<endl;
        }
        return;
    }
    if(a >= n){
        cout<<"Alice"<<endl;
        return;
    }

    if(n % (a + n) == 0){
        cout<<"Bob"<<endl;
        return;
    }
    int remain = n % ( a + b );

    if(remain <= a ){
        cout<<"Alice"<<endl;
        return;
    }
    cout<<"Bob"<<endl;


}


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }

}

