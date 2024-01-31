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
#define mod (ll)(1e9+7)
#define ll long long
#define endl '\n'
using namespace std;

void solve(){
    int n,m; cin>>n>>m;
    vector<int> a(n,0);
    vector<int> b(m,0);
    for(int i = 0 ; i < n ; i++) cin>>a[i];
    for(int i = 0 ; i < m ; i++) cin>>b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int num = 1;
    int ans = 0;
    int la = 0;
    int lb = 0;
    int ra = n-1;
    int rb = m-1;
    while(num <= n){
        if(abs(a[la]-b[rb]) > abs(a[ra]-b[lb])){
            ans+= abs(a[la]-b[rb]);
            la++, rb--;
        }else{
            ans += abs(a[ra]-b[lb]);
            ra--, lb++;
        }
        num++;
    }
    cout<<ans<<endl;
    return;

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t ; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}