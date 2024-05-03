#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cstdlib>
#include <numeric>
#include <climits>
#define mod (ll)(1e9+7)
// #define int long long
#define ll long long
#define endl '\n'
using namespace std;

void solve() {   
    int n, k;
    cin>>n>>k;
    string str; cin>>str;
    int f[26];
    for(int i = 0 ; i < 26 ; i++) f[i]  = 0;
    for(int i = 0 ; i < n ; i++){
        int idx = str[i] - 'a';
        f[idx]++;
    }
    int odd = 0;
    int even = 0;
    for(int i = 0 ; i < 26 ; i++){
        if(f[i] & 1) odd++;
        else even++;
    }
    if(odd == 1) {
        cout<<"YES"<<endl;
        return ;
    }
    if(odd - 1 > k ){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;

}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


    // int v1, v2;
    // int ans = 0;
    // // up a //left b
    // v1 = y1 + a;
    // v2 = x1 - b;
    // //check
    //     cout<<v1<<" "<<v2<<endl;
    // if(v2 - b == x2 && v1 - a == y2) {
    //     ans++;
    // }

    // //up a // right b
    // v1 = y1 + a;
    // v2 = x1 + b;
    //     cout<<v1<<" "<<v2<<endl;
    // if(v2 + b == x2 && v1 - a == y2) {
    //     ans++;
    // }

    // // left a // up b
    // v1 = y1 + b;
    // v2 = x1 + a;
    //     cout<<v1<<" "<<v2<<endl;
    // if(v1 + b == y2 && v2 - a == x2) {
    //     ans++;
    // }

    // //left a // down b
    // v1 = y1 - b;
    // v2 = x1 + a;
    //     cout<<v1<<" "<<v2<<endl;
    // if(v1 - b == y2 && v2 - a == x2) {
    //     ans++;
    // }

    // // down a right b
    // v1 = y1 - a;
    // v2 = x1 + b;
    //     cout<<v1<<" "<<v2<<endl;
    // if(v2 + b == x2 && v1 +a == y2) {
    //     ans++;
    // }

    // //down a left b
    // v1 = y1 - a;
    // v2 = x1 - b;
    //     cout<<v1<<" "<<v2<<endl;
    // if(v2 - b == x2 && v1 + a == y2) {
    //     ans++;
    // }

    // //left a down b
    // v1 = y1 - b;
    // v2 = x1 - a;
    //     cout<<v1<<" "<<v2<<endl;
    // if(v1 - b == y2 && v2 + a == x2) {
    //     ans++;
    // }

    // //left a up b
    // v1 = y1 + b;
    // v2 = x1 - a;
    //     cout<<v1<<" "<<v2<<endl;
    // if(v1 + b == y2 && v2 + a == x2) {
    //     ans++;
    // }


    // //     // up a //left b
    // // v1 = y1 + b;
    // // v2 = x1 - a;
    // // //check
    // // if(v2 - a == x2 && v1 - b == y2) ans++;

    // // //up a // right b
    // // v1 = y1 + b;
    // // v2 = x1 + a;
    // // if(v2 + a == x2 && v1 - b == y2) ans++;

    // // // left a // up b
    // // v1 = y1 + a;
    // // v2 = x1 + b;
    // // if(v1 + a == y2 && v2 - b == x2) ans++;

    // // //left a // down b
    // // v1 = y1 - a;
    // // v2 = x1 + b;
    // // if(v1 - a == y2 && v2 - b == x2) ans++;

    // // // down a right b
    // // v1 = y1 - b;
    // // v2 = x1 + a;
    // // if(v2 + a == x2 && v1 +b == y2) ans++;

    // // //down a left b
    // // v1 = y1 - b;
    // // v2 = x1 - a;
    // // if(v2 - a == x2 && v1 + b == y2) ans++;

    // // //left a down b
    // // v1 = y1 - a;
    // // v2 = x1 - b;
    // // if(v1 - a == y2 && v2 + b == x2) ans++;

    // // //left a up b
    // // v1 = y1 + a;
    // // v2 = x1 - b;
    // // if(v1 + a == y2 && v2 + b == x2) ans++;

    // cout<<ans<<endl;